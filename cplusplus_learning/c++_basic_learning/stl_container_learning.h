#pragma once
#include<iostream>

//˳������
#include<vector>		//��װ������
#include<string>		//��װ���ַ���
#include<queue>	
#include<stack>
#include<list>			//��װ������
//��֧��
//#include<heap>
//#include<priority_queue>
//#include<slist>


//��������
#include<map>			//��װ��ƽ��������������������������ɾ��Ч����������������Ƚϸ�
#include<set>			//��װ��ƽ��������������������������ɾ��Ч����������������Ƚϸ�
//#include<hash_map>		//�������ϳ�
//#include<hash_set>		//�������ϳ�
#include<unordered_map>
#include<unordered_set>
//boost֧��
//#include<hash_table>
void std_container_learning_main()
{
	//vector�����Զ����󣬿ɱ䳤�����飬�����������
	std::vector<int> vi;
	vi.resize(10);		//�ȷ����˿ռ�Ҳ�����˶��󣬼��޸�capacity��С��Ҳ�޸�size��С
	vi.reserve(20);		//ֻ��Ԥ���Ŀռ䣬��û�д�������ֻ�޸�capacity��С

	//set��map������ʽ�洢�ģ�ֻ��Ҫ�ƶ�ָ��Ϳ�����

	//set��������ʱֱ���ź��򣬲�ѯ�ٶȿ�
	std::set<int> si;
	si.insert(3);
	si.insert(1);
	si.insert(2);
	
	for (std::set<int>::iterator it = si.begin(); it != si.end(); it++)
	{
		std::cout << "data=" << *it << std::endl;
	}
	std::cout << "�������\n";

	//�������
	for (std::set<int>::reverse_iterator it = si.rbegin(); it != si.rend(); it++)
	{
		std::cout << "data=" << *it << std::endl;
	}
	si.find(1);				//find���÷�Ӧ�ñȽϺ���

	//std::map��key-value���͵�
	//Entry& e = _table[key]���Ƕ�Ӧ��key�����ڣ����Զ�����
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
	std::string str = mi[1];			//���ǲ����ڣ����Զ�������Ӧ�Ķ���
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