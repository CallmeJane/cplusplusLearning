#pragma once
#include <string>
struct RspCancelActiveOrders
{
	int err_id;
	char err_msg[80];
}; 
void init_struct_main()
{
	std::string st = "12";
	RspCancelActiveOrders rsp = { 1,"" };
	strncpy(rsp.err_msg, st.c_str(), 80);
}
