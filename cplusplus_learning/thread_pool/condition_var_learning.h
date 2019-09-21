#pragma once
#include<iostream>
#include<mutex>
#include<thread>
#include<atomic>
#include<condition_variable>
std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void do_print_id(int i)
{
	std::unique_lock<std::mutex> lck(mtx);				//独占mtx
	//while (!ready)
		cv.wait(lck);
	std::cout << "this is " << i << std::endl;

}
void go()
{
	std::unique_lock<std::mutex> lck(mtx);
	ready = true;
	for (int i = 0;i<10;i++)
		cv.notify_all();
}
void condition_variable_main1()
{
	std::thread threads[10];
	for (int i = 0; i < 10; i++)
		threads[i] = std::thread(do_print_id, i);
	std::cout << "10 threads are ready to race" << std::endl;
	go();

	for (int i = 0; i < 10; i++)
	{
		threads[i].join();
	}

	return;
}
int cangku[10];
std::mutex mutexs[10];					//生产者与生产者，生产者与消费者都要争这把锁
std::mutex is_empty;
std::atomic<int> count_e = 0;			//最大为10
std::atomic<int> product_index = -1;
std::atomic<int> consumer_index = -1;

std::condition_variable cv_empty;
void consumer(int i)
{
	std::unique_lock<std::mutex> lck(is_empty);
	cv_empty.wait(lck);
	std::lock_guard<std::mutex> lg(mutexs[(consumer_index + 1) % 10]);
	consumer_index = (consumer_index + 1) % 10;
	count_e--;
	std::cout << "消费者了" << consumer_index << std::endl;
	cv_empty.notify_one();
}
void productor(int i)
{
	std::lock_guard<std::mutex> lg(mutexs[(product_index + 1) % 10]);
	product_index = (product_index + 1) % 10;
	count_e--;
	std::cout << "生产一个产品，放在" << product_index << std::endl;
	//if (product_index == 0)
		cv_empty.notify_one();
	
}
void condition_variable_main()
{
	std::thread productors[10];
	std::thread consumers[10];

	for (int i = 0; i < 10; i++)
	{
		consumers[i] = std::thread(consumer, i);
	}
	for (int i = 0; i < 10; i++)
	{
		productors[i] = std::thread(productor, i);
	}
	
	for (int i = 0; i < 10; i++)
	{
		productors[i].join();
		consumers[i].join();
	}
	return;
}
