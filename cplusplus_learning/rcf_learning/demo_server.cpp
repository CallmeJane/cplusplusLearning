#include<iostream>
//#include<algorithm>
#include<iterator>					//std::back_inserter()

#include<RCF/RCF.hpp>
#include"demo_interface.h"			//��ͷ�ļ����Ѿ����˺���������

class DemoService {

public:
	//��תvector�е��ַ���
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

	std::cout << "server����Ҫ��" << ip << ":" <<port<<"����\n";
	DemoService demoserve;
	RCF::RcfServer server(RCF::TcpEndpoint(ip, port));
	server.bind<I_DemoService>(demoserve);					//��ע��Ķ���������ʵ�ʶ����

	server.start();

	std::cout << "��������˳�\n";
	std::cin.get();
	return 0;
}