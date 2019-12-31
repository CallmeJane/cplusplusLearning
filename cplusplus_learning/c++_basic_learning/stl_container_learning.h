#pragma once
#include<iostream>

//顺序容器
#include<vector>		//封装了数组
#include<string>		//封装了字符串
#include<queue>	
#include<stack>
#include<list>			//封装了链表
//不支持
//#include<heap>
//#include<priority_queue>
//#include<slist>


//关联容器
#include<map>			//封装了平衡检索二叉树（红黑树），插入删除效率相对于其他容器比较高
#include<set>			//封装了平衡检索二叉树（红黑树），插入删除效率相对于其他容器比较高
//#include<hash_map>		//即将被废除
//#include<hash_set>		//即将被废除
#include<unordered_map>
#include<unordered_set>
//boost支持
//#include<hash_table>
void std_container_learning_main()
{
	//vector可以自动增大，可变长度数组，快速随机访问
	std::vector<int> vi;
	vi.resize(10);		//既分配了空间也创建了对象，既修改capacity大小，也修改size大小
	vi.reserve(20);		//只是预留的空间，并没有创建对象，只修改capacity大小

	//set、map都是链式存储的，只需要移动指针就可以了

	//set插入数据时直接排好序，查询速度快
	std::set<int> si;
	si.insert(3);
	si.insert(1);
	si.insert(2);
	
	for (std::set<int>::iterator it = si.begin(); it != si.end(); it++)
	{
		std::cout << "data=" << *it << std::endl;
	}
	std::cout << "反向遍历\n";

	//反向遍历
	for (std::set<int>::reverse_iterator it = si.rbegin(); it != si.rend(); it++)
	{
		std::cout << "data=" << *it << std::endl;
	}
	si.find(1);				//find的用法应该比较好用

	//std::map是key-value类型的
	//Entry& e = _table[key]若是对应的key不存在，则自动创建
	std::map<int, std::string> mi;
	mi.insert(std::pair<const int, std::string>(10000000, "this is word1"));
	mi.insert(std::pair<const int, std::string>(1000001, "this is word2"));
	mi.insert(std::pair<const int, std::string>(9999999999, "this is word2"));
	std::map<int, std::string>::iterator iter;
	iter=mi.find(1);
	if (iter != mi.end())
	{
		std::cout << "found the value is " << iter->second;
	}
	else
	{
		std::cout << "not found\n";
	}
	std::string str = mi[1];			//若是不存在，会自动创建相应的对象
	iter = mi.find(1);
	if (iter != mi.end())
	{
		std::cout << "found the value is " << iter->second;
	}
	else
	{
		std::cout << "not found\n";
	}
}