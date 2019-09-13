#include <iostream>
#include "spdlog/spdlog.h"

namespace spd = spdlog;				//命名空间也可以等价

class logger_get
{
private:
	std::shared_ptr<spdlog::logger> _logger;
public:
	void log_test()
	{
		//通过spdlog::get()来获取一个已经存在的logger对象
		_logger = spdlog::get("console");
	}

	void print_hello()
	{
		_logger->info("helloworld");
		return;
	}
};
int main(int, char*[])
{

	//(1)创建一个console logger的对象，将logger对象注册到全局对象中，并且返回指向这个logger对象的指针

	/*
	auto console = spdlog::stdout_color_mt("console");
	console->info("Welcome to spdlog");
	console->info("An info message example {}..", 1);
	console->error("Some error message with arg{}..", 1);
	console->warn("Easy padding in numbers like {:08d}", 12);
	console->critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
	console->info("Support for floats {:03.2f}", 1.23456);
	console->info("Positional args are {1} {0}..", "too", "supported");			//先输出supported,再输出too
	console->info("{:<30}", "left aligned");

	logger_get test;
	test.log_test();
	test.print_hello();

	spd::drop("console")						//关闭指定logger

	*/



	//(2)创建一个写入文件的logger
	//使用logs/basic.txt的前提是logs文件夹存在
	/*
	auto my_logger = spdlog::basic_logger_mt("basic_logger", "logs/basic.txt");
	for (int i = 0; i < 1000; i++)
	{
	my_logger->info("Test File Logger {}", i);
	}
	*/


	//(3)手动创建一个logger,这个不能用spdlog::get访问，因为没有注册到全局中
	/*
	auto sink = std::make_shared<spdlog::sinks::stdout_sink_mt>();
	auto my_logger = std::make_shared<spdlog::logger>("mylogger", sink);

	my_logger->info("HelloWorld");
	*/

	//(4)手动创建的logger想要用spdlog::ger访问，需要手动注册到全局中
	/*
	auto sink = std::make_shared<spdlog::sinks::stdout_sink_mt>();
	auto my_logger = std::make_shared<spdlog::logger>("mylogger", sink);

	my_logger->info("HelloWorld");

	spdlog::register_logger(my_logger);

	auto test_logger = spdlog::get("mylogger");
	test_logger->info("getlogger::helloworld");
	*/

	//(5)创建多个logger写到同一文件中
	/*
	auto sharedFileSink = std::make_shared<spdlog::sinks::simple_file_sink_mt>("basic.txt");
	auto firstLogger = std::make_shared<spdlog::logger>("loggerOne", sharedFileSink);
	auto secondLogger = std::make_shared<spdlog::logger>("loggerTwo", sharedFileSink);

	for (int i = 0; i < 10; i++)
	{
	firstLogger->info("[loggerOne]: Hello {}.", i);
	}

	for (int j = 0; j < 10; j++)
	{
	secondLogger->info("[loggerTwo]: Hello {}. ", j);
	}
	int i = 1;
	*/

	//（6）创建滚动文件来存储日志，最后一个参数是滚动文件的数目，比实际文件数多1
	//rotating是最新的，rotating1是次新的
	/*
	auto rotating_logger = spd::rotating_logger_mt("some_logger_name", "logs/rotating.txt", 256, 2);
	for (int i = 0; i < 10; ++i)
	rotating_logger->info("{} * {} equals {:>10}", i, i, i*i);
	*/

	//(7)每天创建一个日志文件（若是程序不退出，就是每天一个；若是退出了，就是每次启动产生一个）
	//若是最后两个参数是0,0,则会每天都像同一个文件中输出
	/*
	auto daily_logger = spd::daily_logger_mt("daily_logger", "logs/daily.txt", 0, 0);
	//遇到指定级别日志，立即写入到文件中，以免发生崩溃
	daily_logger->flush_on(spd::level::err);
	daily_logger->info(123.44);
	*/

	//(8)若是想每次启动都写到同一个日志文件中
	/*
	typedef spdlog::sinks::daily_file_sink<std::mutex, spdlog::sinks::dateonly_daily_file_name_calculator> dateonly_daily_file_sink_mt;
	auto m_logger = spdlog::create<dateonly_daily_file_sink_mt>("m_logger", "logs/dateonly.txt", 0, 0);
	m_logger->info("test daily info");
	m_logger->error("test daily error");
	*/

	std::string filename = "logs/simple_log";

	auto logger = spdlog::create<spdlog::sinks::simple_file_sink_mt>("logger", filename);
	//logger->set_pattern("%v");						//不显示日志的格式
	logger->set_level(spdlog::level::info);				//设置显示日志的级别，info以下日志不显示

	logger->trace("message 1");
	logger->info("message 2");
	logger->flush();

	spd::drop_all();	//关闭所有的logger
}