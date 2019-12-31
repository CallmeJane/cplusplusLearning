#pragma once
#include <string>
#include <iostream>
#include<sstream>		//std::istringstream;std::ostringstream;std::sstringstream
#include<algorithm>		//std::copy
#include<iterator>		//std::back_insert
using std::string;
using std::cout;
using std::endl;

/*
	string 考点1：string和char*的转换(\0)
	scanf输入比cin快很多，若是有速度要求，一般能用c的就用c
*/
void string_chars_func()
{
	string s = "";
	char ss[11] = {};
	cout << ss << endl;
	for (int i = 0; i < 10; i++)
	{
		ss[i] = 65 + i;
	}
	ss[10] = '\0';			//若是末尾不追加‘\0’，在string和char[]相互转换时，会出现问题
	s = ss;

	char dec[10];
	memcpy(dec, s.c_str(), s.size());
	cout << dec << endl;

}

/*
	string 考点2:string对象的插入、删除都是用迭代器进行的操作
*/

/*
	string 考点3：string的清理和判空操作
*/
void string_clear_empty()
{
	string s = "123";
	cout << s.size() << endl;
	s.clear();				//s对象并没有被销毁，只是内容清空了
	cout << s.empty() << endl;
}

/*
	string 考点5：string的replace操作
*/

void string_replace()
{
	string s = "abc1234567";
	s.replace(3, 1, "good");		//将s从3开始的4个字符替换为"good",可以一个替换后才能多个
}

//string的查找，比较
void string_find_compare()
{
	string s = "123456";
	//string::npos
	auto ret = s.find('1', 3);			//从3之后开始找‘1’
	
	string str = "abc abc";
	cout << "str:" << (str == "abc") << std::endl;

	cout << str.compare("abc") << endl;

	cout << str.compare("dog") << endl;

}
//string与int的相互转换或对string的每一位进行操作
void string_each_int()
{
	string str = "123456";
	int sum = 0;
	for (string::const_iterator iter = str.begin(); iter != str.end(); iter++)
	{
		sum += *iter - '0';
	}
	cout << "sum=" << sum << endl;
}

string convert_num_to_string()
{
	double a = 2.0;
	std::ostringstream o;
	o.put(a);
	if (o << a)
		return o.str();
	else
		return "error";
}

void convert_string_to_num(string s)
{
	string temp;
	std::copy(s.begin() + 1, s.end(),std::back_inserter(temp));
	std::istringstream i(temp);
	double x;
	i >> x;
}

void istringstream_test()
{
	string s = "123 12.3 c hello ,234";
	std::istringstream i(s);
	int i_in;
	float f_in;
	char c_in;
	char buf_in[10];
	i >> i_in;
	i >> f_in;
	i >> c_in;
	i >> buf_in;
	i.ignore(100, ',');		//最大读取100个字符，忽略‘,’之前的
	int i_in_t;
	i >> i_in_t;


	//istringstream对象以空格作为字符串的结束
	std::istringstream istring("abc,123,234,111,222");
	string tmp;
	while (getline(istring, tmp, ','))
		cout << tmp << endl;
}

//string的字符串截取
void string_sub_string()
{
	string s = "12345678";
	string tmp = s.substr(1, s.length()-1);
	//与上式等价
	string t = s.substr(1);			//从1到末尾
	char*p = const_cast<char*>(t.c_str());
}

//去掉字符串左右的空格
void string_strip_space()
{
	string s = "   123   ";
	string ret = "";
	int first = s.find_first_not_of(' ');
	int last = s.find_last_not_of(' ');
	std::copy(s.begin() + first, s.begin() + last + 1, std::back_inserter(ret));
}