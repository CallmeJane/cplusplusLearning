#include <iostream>
#include "spdlog/spdlog.h"

namespace spd = spdlog;				//�����ռ�Ҳ���Եȼ�

class logger_get
{
private:
	std::shared_ptr<spdlog::logger> _logger;
public:
	void log_test()
	{
		//ͨ��spdlog::get()����ȡһ���Ѿ����ڵ�logger����
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

	//(1)����һ��console logger�Ķ��󣬽�logger����ע�ᵽȫ�ֶ����У����ҷ���ָ�����logger�����ָ��

	/*
	auto console = spdlog::stdout_color_mt("console");
	console->info("Welcome to spdlog");
	console->info("An info message example {}..", 1);
	console->error("Some error message with arg{}..", 1);
	console->warn("Easy padding in numbers like {:08d}", 12);
	console->critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
	console->info("Support for floats {:03.2f}", 1.23456);
	console->info("Positional args are {1} {0}..", "too", "supported");			//�����supported,�����too
	console->info("{:<30}", "left aligned");

	logger_get test;
	test.log_test();
	test.print_hello();

	spd::drop("console")						//�ر�ָ��logger

	*/



	//(2)����һ��д���ļ���logger
	//ʹ��logs/basic.txt��ǰ����logs�ļ��д���
	/*
	auto my_logger = spdlog::basic_logger_mt("basic_logger", "logs/basic.txt");
	for (int i = 0; i < 1000; i++)
	{
	my_logger->info("Test File Logger {}", i);
	}
	*/


	//(3)�ֶ�����һ��logger,���������spdlog::get���ʣ���Ϊû��ע�ᵽȫ����
	/*
	auto sink = std::make_shared<spdlog::sinks::stdout_sink_mt>();
	auto my_logger = std::make_shared<spdlog::logger>("mylogger", sink);

	my_logger->info("HelloWorld");
	*/

	//(4)�ֶ�������logger��Ҫ��spdlog::ger���ʣ���Ҫ�ֶ�ע�ᵽȫ����
	/*
	auto sink = std::make_shared<spdlog::sinks::stdout_sink_mt>();
	auto my_logger = std::make_shared<spdlog::logger>("mylogger", sink);

	my_logger->info("HelloWorld");

	spdlog::register_logger(my_logger);

	auto test_logger = spdlog::get("mylogger");
	test_logger->info("getlogger::helloworld");
	*/

	//(5)�������loggerд��ͬһ�ļ���
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

	//��6�����������ļ����洢��־�����һ�������ǹ����ļ�����Ŀ����ʵ���ļ�����1
	//rotating�����µģ�rotating1�Ǵ��µ�
	/*
	auto rotating_logger = spd::rotating_logger_mt("some_logger_name", "logs/rotating.txt", 256, 2);
	for (int i = 0; i < 10; ++i)
	rotating_logger->info("{} * {} equals {:>10}", i, i, i*i);
	*/

	//(7)ÿ�촴��һ����־�ļ������ǳ����˳�������ÿ��һ���������˳��ˣ�����ÿ����������һ����
	//�����������������0,0,���ÿ�춼��ͬһ���ļ������
	/*
	auto daily_logger = spd::daily_logger_mt("daily_logger", "logs/daily.txt", 0, 0);
	//����ָ��������־������д�뵽�ļ��У����ⷢ������
	daily_logger->flush_on(spd::level::err);
	daily_logger->info(123.44);
	*/

	//(8)������ÿ��������д��ͬһ����־�ļ���
	/*
	typedef spdlog::sinks::daily_file_sink<std::mutex, spdlog::sinks::dateonly_daily_file_name_calculator> dateonly_daily_file_sink_mt;
	auto m_logger = spdlog::create<dateonly_daily_file_sink_mt>("m_logger", "logs/dateonly.txt", 0, 0);
	m_logger->info("test daily info");
	m_logger->error("test daily error");
	*/

	std::string filename = "logs/simple_log";

	auto logger = spdlog::create<spdlog::sinks::simple_file_sink_mt>("logger", filename);
	//logger->set_pattern("%v");						//����ʾ��־�ĸ�ʽ
	logger->set_level(spdlog::level::info);				//������ʾ��־�ļ���info������־����ʾ

	logger->trace("message 1");
	logger->info("message 2");
	logger->flush();

	spd::drop_all();	//�ر����е�logger
}