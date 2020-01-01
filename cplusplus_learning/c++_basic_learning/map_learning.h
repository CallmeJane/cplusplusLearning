#pragma once
#include <map>
#include <string>
#include <iostream>
#include<unordered_map> //hash
#include <functional>

using std::cout;
using std::endl;
using std::string;
using std::map;

/*
	map的insert的key是按照从小到大排序的，而key一定要重载<运算符

	map的key-value的映射使用的是红黑树

	map的应用：
	（1）统计每个单词的出现次数
	（2）对于查找有着较高的要求
*/
//map的增删改查的特点
//insert 4种，删除1种，修改2中，查找2种
void map_iecs()
{
	//insert
	map<string, int> m;
	m.insert(std::make_pair("123", 1));
	m.insert(std::pair<string, int>("234", 2));
	m.insert(map<string,int>::value_type("345", 3));
	m["aaa"] = 4;

	//erease
	int n = m.erase("aaa");			//返回删除的元素个数

	//update
	m["123"] = 100;
	map<string, int>::iterator iter = m.begin();
	iter->second = 10;

	//search
	auto i = m["234"];				//若是查找的值不存在，返回0，有缺陷
	auto ret = m.find("123");
	if (ret != m.end())
		cout << "未找到" << endl;
}

//自定义map的排序方式（普通类型或者结构体）
struct myComp
{
	bool operator()(const int&a,const int&b)
	{
		return a > b;
	}
};

struct Info
{
	float score;
	string name;
	bool operator<(Info a) const
	{
		return score < a.score;
	}
};
void map_named_sort()
{
	map<int, string, myComp> m;
	m.insert(std::pair<int, string>(1, "111"));
	m.insert(std::pair<int, string>(2, "222"));
	m.insert(std::pair<int, string>(3, "333"));

	map<Info, int> m_info;
	Info info;
	info.name = "aaa";
	info.score = 1.1;
	m_info.insert(std::pair<Info, int>(info, 1));
	info.name = "bbb";
	info.score = 2.2;
	m_info.insert(std::pair<Info, int>(info, 2));
	info.name = "ccc";
	info.score = 3.3;
	m_info.insert(std::pair<Info, int>(info, 3));
}

//string和int的转换可以用map做桥梁，当然也可以利用相减的关系，
//当数量不太多时，可以利用一一映射关系

/*
	hash_map:尤其是string/自定义类型做key时，更加倾向于使用unordered_map
*/
struct Person
{
	int age;
	string name;
	Person(string _n,int _a)
	{
		name = _n;
		age = _a;
	}
	//当unordered_map的key是struct时，需要重载==和实现hash_value
	bool operator==(const Person& per) const
	{
		return per.age == age && per.name == name;
	}
};

size_t hash_value(const Person& per)
{
	return std::hash<string>()(per.name) ^ std::hash<int>()(per.age);
}

void unordered_map_named_test()
{
	std::unordered_map<Person, int,std::function<size_t(const Person&)>> m(100,hash_value);
	m[Person("Mark", 19)] = 19;
	m[Person("Jane", 23)] = 23;
}