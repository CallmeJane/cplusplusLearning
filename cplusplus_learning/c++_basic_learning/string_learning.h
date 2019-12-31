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
	string ����1��string��char*��ת��(\0)
	scanf�����cin��ܶ࣬�������ٶ�Ҫ��һ������c�ľ���c
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
	ss[10] = '\0';			//����ĩβ��׷�ӡ�\0������string��char[]�໥ת��ʱ�����������
	s = ss;

	char dec[10];
	memcpy(dec, s.c_str(), s.size());
	cout << dec << endl;

}

/*
	string ����2:string����Ĳ��롢ɾ�������õ��������еĲ���
*/

/*
	string ����3��string��������пղ���
*/
void string_clear_empty()
{
	string s = "123";
	cout << s.size() << endl;
	s.clear();				//s����û�б����٣�ֻ�����������
	cout << s.empty() << endl;
}

/*
	string ����5��string��replace����
*/

void string_replace()
{
	string s = "abc1234567";
	s.replace(3, 1, "good");		//��s��3��ʼ��4���ַ��滻Ϊ"good",����һ���滻����ܶ��
}

//string�Ĳ��ң��Ƚ�
void string_find_compare()
{
	string s = "123456";
	//string::npos
	auto ret = s.find('1', 3);			//��3֮��ʼ�ҡ�1��
	
	string str = "abc abc";
	cout << "str:" << (str == "abc") << std::endl;

	cout << str.compare("abc") << endl;

	cout << str.compare("dog") << endl;

}
//string��int���໥ת�����string��ÿһλ���в���
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
	i.ignore(100, ',');		//����ȡ100���ַ������ԡ�,��֮ǰ��
	int i_in_t;
	i >> i_in_t;


	//istringstream�����Կո���Ϊ�ַ����Ľ���
	std::istringstream istring("abc,123,234,111,222");
	string tmp;
	while (getline(istring, tmp, ','))
		cout << tmp << endl;
}

//string���ַ�����ȡ
void string_sub_string()
{
	string s = "12345678";
	string tmp = s.substr(1, s.length()-1);
	//����ʽ�ȼ�
	string t = s.substr(1);			//��1��ĩβ
	char*p = const_cast<char*>(t.c_str());
}

//ȥ���ַ������ҵĿո�
void string_strip_space()
{
	string s = "   123   ";
	string ret = "";
	int first = s.find_first_not_of(' ');
	int last = s.find_last_not_of(' ');
	std::copy(s.begin() + first, s.begin() + last + 1, std::back_inserter(ret));
}