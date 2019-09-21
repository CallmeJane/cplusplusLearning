#include<iostream>
//#include<algorithm>
#include<iterator>					//std::back_inserter()

#include<RCF/RCF.hpp>
#include"demo_interface.h"			//在头文件中已经有了函数的引用

class DemoService {

public:
	//反转vector中的字符串
	void Reverse(std::vector<std::string>& v)
	{
		std::cout << "start to reverse the vector\n";
		std::vector<std::string> w;
		std::copy(v.rbegin(), v.rend(), std::back_inserter(w));
		v.swap(w);
	}
};
int main()
{
	RCF::RcfInit rcfinit;

	std::string ip = "0.0.0.0";
	int port = 50001;

	std::cout << "server服务将要在" << ip << ":" <<port<<"启动\n";
	DemoService demoserve;
	RCF::RcfServer server(RCF::TcpEndpoint(ip, port));
	server.bind<I_DemoService>(demoserve);					//将注册的对象名称与实际对象绑定

	server.start();

	std::cout << "按任意键退出\n";
	std::cin.get();
	return 0;
}