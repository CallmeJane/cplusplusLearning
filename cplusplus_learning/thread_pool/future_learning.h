#pragma once
#include<iostream>
#include<type_traits>
#include<future>				//std::async
#include<thread>				

//һ���std::bind����lambda�������ʹ�ã����ں����ص���ʹ�ò�ͬ�Ļص�����������ͬ�Ľ��
#include<functional>			//��������ָ��ĸ��һ���û������ص�
void f(int& i, int& j, const int& k)
{
	std::cout << "in function i=" << i << " j=" << j << " k=" << k << std::endl;
	i++;
	j++;
	//k++;		//k�ǲ����޸ĵ�ֵ	
}
/*
	��ϰstd::ref��ʹ��
	std::ref    ��װ�������ô��ݵ�ֵ
	std::cref   ����const���εİ������ô��ݵ�ֵ
	���ã�ʹ��bindʱ���ڲ�֪�����ɺ���ִ��ʱ�������Ĳ����Ƿ���Ч������ʹ�ò������ݣ�
	���������ô���
*/

void function_param(std::function<void(int& i, int& j, const int& k)> bound)
{
	//std::function<��������ֵ������������>
	//https://www.jianshu.com/p/c4c84b073413
	int i, j, k;
	i = j = k = 1;
	bound(i, j, k);
	//ע�⣺����ʹ�þͲ���������ò��ܴ��ݻ���������
	std::cout << "out function i=" << i << " j=" << j << " k=" << k << std::endl;
}
void ref_learning_main()
{
	int i,j,k;
	i = j = k = 1;
	//std::bindһ������ʹ�ú���ָ��(���ݺ���ָ��һ�����ڻص�)�����ݺ�������
	//std::function<void(int& i, int& j, const int& k)> bound_f = std::bind(f, std::placeholders::_1,std::placeholders::_2, std::placeholders::_3);
	std::function<void(int& i, int& j, const int& k)> bound_f([](int& i, int& j, const int& k) {
		std::cout << "in function i=" << i << " j=" << j << " k=" << k << std::endl;
		i++;
		j++;
	});
	function_param(bound_f);
	
}
void future_learning_main1()
{
	std::promise<int> promise_param;
	std::thread t([](std::promise<int>& p) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		p.set_value_at_thread_exit(4);		//�߳��˳�ʱ��������p��ֵ
	}, std::ref(promise_param));

	std::future<int> future_prama = promise_param.get_future();
	auto r = future_prama.get();		//���߳̽��ᱻ������ֱ�����߳��˳�

	std::cout << "r=" << r << std::endl;
	return;
}

bool is_prime(int i)
{
	int end = i / 2;
	for (int index = 2; index <= end; index++)
	{
		if (i%index == 0)
			return false;
	}
	return true;
}
void future_learning_main()
{
	/*
		std::async  �����첽ʵ�֣�����һ��std::future<>���͵ĺ�����
		���ڱ��溯���ķ���ֵ
		���������Ǻ������󣬺���ָ�룬lambda����
	*/
	std::future<bool> fut = std::async(is_prime, 444444443);
	//��һЩ���飬���ȴ���������fut��ֵ
	std::chrono::microseconds span(10000);		//���ó�ʱʱ��,Waits for the shared state to be ready for up to the time specified by rel_time.
	while (fut.wait_for(span) == std::future_status::timeout)
		std::cout << "." << std::flush;
	//fut.wait();			//Waits for the shared state to be ready
	bool x=fut.get();				//��ȡ����ֵ
	std::cout << "444444443 " << (x ? "is" : "is not") << " prime\n";
}