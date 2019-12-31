//#pragma once
#ifndef __SOMEFILE_H__
#define __SOMEFILE_H__


#include<string>
#include<memory>
#include<map>
//#include "linker_declare.h"
//#include "structure.h"

using std::string;
using std::shared_ptr;
using std::map;

struct ErrInfo {
	string err_name;
	int err_id;
	string err_msg;
};

class ErrorConfig;
typedef shared_ptr<ErrorConfig> ErrorConfigPtr;


class ErrorConfig {
public:
	/*static ErrInfo* get_err_by_name(string name);
	static int get_err_id_by_name(string name);
	static string get_err_msg_by_name(string name);
	static string get_err_msg_by_id(int id);
	static void set_config_path(string config_path);
	static string get_config_path();*/
	
	//static void set_err_map();
	//static map<string,ErrInfo>& get_err_map();
	//static map<string, ErrInfo> e_obj;
	static  int i;
private:
	ErrorConfig(string config_path);
	string config_path;
	static ErrorConfigPtr e_ptr;
	//json m_obj;
	static map<string, ErrInfo> e_obj;

	
};
map<string, ErrInfo> ErrorConfig::e_obj;
#endif



