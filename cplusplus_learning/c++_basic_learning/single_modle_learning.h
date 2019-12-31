#pragma once
/*
	�����ԣ�����̳�https://www.runoob.com/design-pattern/singleton-pattern.html
	����ģʽ��
	��1��һ����ֻ��һ��ʵ��
	��2�������ഴ��Ψһ��ʵ��
	��3����������������������ṩ��һʵ��

	��Ҫ�����һ��ȫ�ֵ�ʵ��Ƶ������������

	��ν��������û�����ʵ��������û���򴴽����������򷵻�

	�ؼ����룺���캯����˽�е�

	Ӧ��ʵ����
	��1��һ����ֻ��һ��������
	��2��windows��һ�������/�߳�ͬʱ����һ���ļ������ļ����в���

	�ŵ㣺
	��1�������ڴ��Ƶ��������ͷ�
	��2�������˶���Դ����ռ�ã���д�ļ�������

	ȱ�㣺
	��1��û�нӿڣ����ܼ̳�
	��2���뵥һԭ���ͻ��һ����Ӧ��ֻ�����ڲ��߼����������ⲿ��ôʵ����
*/
#include<iostream>
#include<atomic>
#include<thread>

class Logger
{
private:
	Logger() {
		std::cout << "ֻ�ܵ���һ��\n";
	}			//���캯��˽�л�
	static Logger *single_instace;
	static std::atomic<int> count;
public:
	static Logger* get_instance()
	{
		return single_instace;
	}
	void read_logger() {
		std::cout << "read_logger\n";
	}
	void write_logger() {
		std::cout << "write_logger\n";
	}
	int increase_count() {
		return count++;
	}
};
Logger* Logger::single_instace = new Logger();			//�̰߳�ȫ�������˷ѿռ�
std::atomic<int> Logger::count = 0;

void call_single_instance()
{
	Logger* log = Logger::get_instance();
	int count=log->increase_count();
	std::cout << "count=" << count << "\n";
}
void single_modole_learning_main()
{
	std::thread threads[3];
	for (int i = 0; i < 3; i++)
	{
		threads[i] = std::thread(std::bind(call_single_instance));
	}
	for (int i = 0; i < 3; i++)
	{
		threads[i].join();
	}
	return;
}
