#ifndef INCLUDE_DEMOINTERFACE_H
#define INCLUDE_DEMOINTERFACE_H

#include <string>
#include <vector>

#include<RCF/Idl.hpp>
#include<SF/vector.hpp>

RCF_BEGIN(I_DemoService, "I_DemoService")			//���岢��ע����I_DemoService����
RCF_METHOD_V1(void, Reverse, std::vector<std::string>&);	//ע����һ���޷���ֵ�ĺ���
RCF_END(I_DemoService);
#endif // !INCLUDE_DEMOINTERFACE_H

