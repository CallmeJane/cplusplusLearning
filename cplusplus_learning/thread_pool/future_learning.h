#pragma once
#include<iostream>
#include<type_traits>
#include<future>				//std::async
#include<thread>				

//一般和std::bind或者lambda函数配合使用，用于函数回调，使用不同的回调函数产生不同的结果
#include<functional>			//包含函数指针的概念，一般用户函数回调
void f(int& i, int& j, const int& k)
{
	std::cout << "in function i=" << i << " j=" << j << " k=" << k << std::endl;
	i++;
	j++;
	//k++;		//k是不可修改的值	
}
/*
	练习std::ref的使用
	std::ref    包装按照引用传递的值
	std::cref   包含const修饰的按照引用传递的值
	作用：使用bind时由于不知道生成函数执行时传进来的参数是否有效，所以使用参数传递，
	而不是引用传递
*/

void function_param(std::function<void(int& i, int& j, const int& k)> bound)
{
	//std::function<函数返回值（函数参数）>
	//https://www.jianshu.com/p/c4c84b073413
	int i, j, k;
	i = j = k = 1;
	bound(i, j, k);
	//注意：这样使用就不会出现引用不能传递回来的问题
	std::cout << "out function i=" << i << " j=" << j << " k=" << k << std::endl;
}
void ref_learning_main()
{
	int i,j,k;
	i = j = k = 1;
	//std::bind一般用于使用函数指针(传递函数指针一般用于回调)，传递函数参数
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
		p.set_value_at_thread_exit(4);		//线程退出时，才设置p的值
	}, std::ref(promise_param));

	std::future<int> future_prama = promise_param.get_future();
	auto r = future_prama.get();		//主线程将会被阻塞，直到子线程退出

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
		std::async  用于异步实现，返回一个std::future<>类型的函数，
		用于保存函数的返回值
		参数可以是函数对象，函数指针，lambda函数
	*/
	std::future<bool> fut = std::async(is_prime, 444444443);
	//做一些事情，当等待函数设置fut的值
	std::chrono::microseconds span(10000);		//设置超时时间,Waits for the shared state to be ready for up to the time specified by rel_time.
	while (fut.wait_for(span) == std::future_status::timeout)
		std::cout << "." << std::flush;
	//fut.wait();			//Waits for the shared state to be ready
	bool x=fut.get();				//获取返回值
	std::cout << "444444443 " << (x ? "is" : "is not") << " prime\n";
}