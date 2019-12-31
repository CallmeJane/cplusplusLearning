#include"error.h"
#include <fstream>

//USING_LINKER_NAMESPACE

ErrorConfigPtr ErrorConfig::e_ptr = ErrorConfigPtr();

ErrorConfig::ErrorConfig(string config_path) :config_path(config_path)
{
	/*this->config_path = "/shared/etc/error.json";
	std::ifstream i(config_path);
	if (!i.good())
	{
		llog::critical("[error_config] file cannot be found in {}", config_path);
		throw linker_exception("config file does not exists");
	}
	i >> m_obj;

	json errors = m_obj["errors"];
	if (!errors.is_null())
	{
		for (const auto& info : errors)
		{
			e_obj[info["err_name"]] = info;
		}
	}
	for (auto iter = e_obj.begin(); iter != e_obj.end(); iter++)
	{
		llog::info("err_name {}", iter->second.err_name);
		llog::info("err_id {}", iter->second.err_id);
	}
	*/

}

//ErrInfo* ErrorConfig::get_err_by_name(string name)
//{
//	return &e_obj[name];
//}
//
//int ErrorConfig::get_err_id_by_name(string name)
//{
//	return e_obj[name].err_id;
//}
//
//string ErrorConfig::get_err_msg_by_id(int id)
//{
//	for (auto iter = e_obj.begin(); iter != e_obj.end(); iter++)
//	{
//		if (iter->second.err_id == id)
//			return iter->second.err_msg;
//	}
//	return "";
//}
//
//string ErrorConfig::get_err_msg_by_name(string name)
//{
//	return e_obj[name].err_msg;
//}
//
//void ErrorConfig::set_config_path(string config_path)
//{
//	e_ptr = ErrorConfigPtr(new ErrorConfig(config_path));
//}
//
//string ErrorConfig::get_config_path()
//{
//	//return (e_ptr == nullptr) ? ERROR_CONFIG_PATH : e_ptr->config_path;
//	return "";
//}

/*map<string,ErrInfo>& ErrorConfig::get_err_map()
{
return e_obj;
return e_obj;
}
*/



