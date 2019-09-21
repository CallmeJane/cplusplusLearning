#include<iostream>
#include<iterator>

#include<RCF/RCF.hpp>
#include"demo_interface.h"


int main()
{
	RCF::RcfInit rcfInit;

	std::string ip = "127.0.0.1";
	int port = 50001;
	std::cout << "将要连接到" << ip << ":" << port << "\n";

	std::vector<std::string> v;
	v.push_back("one");
	v.push_back("two");
	v.push_back("three");

	try
	{
		std::cout << "Before\n";
		std::copy(v.begin(), v.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
		//RcfClient<I_DemoService>(RCF::TcpEndpoint(ip, port)).Reverse(v);
		
		//RcfClient<I_DemoService> client = RcfClient<I_DemoService>(RCF::TcpEndpoint(ip,
		//	port));

		RcfClient<I_DemoService> client((RCF::TcpEndpoint(ip,port)));
		client.Reverse(v);
		
		
		std::cout << "After\n";
		std::copy(v.begin(), v.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
	}
	catch (const RCF::Exception& e)
	{
		std::cout << "get exception\n";
		std::cout << e.getErrorMessage();
	}

	std::cout << "按任意键退出\n";
	std::cin.get();
		
	return 0;
}