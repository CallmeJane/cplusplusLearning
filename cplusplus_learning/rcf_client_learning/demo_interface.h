#ifndef INCLUDE_DEMOINTERFACE_H
#define INCLUDE_DEMOINTERFACE_H

#include <string>
#include <vector>

#include<RCF/Idl.hpp>
#include<SF/vector.hpp>

RCF_BEGIN(I_DemoService, "I_DemoService")			//定义并且注册了I_DemoService类型
RCF_METHOD_V1(void, Reverse, std::vector<std::string>&);	//注册了一个无返回值的函数
RCF_END(I_DemoService);
#endif // !INCLUDE_DEMOINTERFACE_H

