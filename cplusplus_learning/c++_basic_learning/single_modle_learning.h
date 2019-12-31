#pragma once
/*
	引用自：菜鸟教程https://www.runoob.com/design-pattern/singleton-pattern.html
	单例模式：
	（1）一个类只有一个实例
	（2）单例类创建唯一的实例
	（3）单例类给所有其他对象提供这一实例

	主要解决：一个全局的实例频繁创建和销毁

	如何解决：看有没有这个实例，若是没有则创建，若是有则返回

	关键代码：构造函数是私有的

	应用实例：
	（1）一个班只有一个班主任
	（2）windows上一个多进程/线程同时访问一个文件，对文件进行操作

	优点：
	（1）减少内存的频繁申请和释放
	（2）避免了对资源多重占用（如写文件操作）

	缺点：
	（1）没有接口，不能继承
	（2）与单一原则冲突，一个类应该只负责内部逻辑，不负责外部怎么实例化
*/
#include<iostream>
#include<atomic>
#include<thread>

class Logger
{
private:
	Logger() {
		std::cout << "只能调用一次\n";
	}			//构造函数私有化
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
Logger* Logger::single_instace = new Logger();			//线程安全，但是浪费空间
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
