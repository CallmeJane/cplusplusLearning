#pragma once
/*
	����ģʽ�����ڲ���Ҫ֪���ڲ��Ĺ��̣�ֻ��Ҫ֪����Ӧ�Ľӿڼ���
	ʹ�ó������û����Ӳ�ͬ�����ݿ⡢���Ӳ�ͬ��Э��ӿ�
	�ؼ����룺�������������������

*/
#include<iostream>
//#include<string>

enum DatabaseType {
	//DatabaseType��һ������
	MYSQL,
	ORACLE,
	MONGODB,
	HBASE
};
//�����ǳ�����
class Database {
public:
	virtual void connect() = 0;
};
class Mysql:public Database{
public:
	void connect() {
		std::cout << "connect Mysql\n";
	}
};
class Oracle :public Database {
public:
	void connect()
	{
		std::cout << "connect Oracle\n";
	}
};
class Mongodb :public Database {
public:
	void connect()
	{
		std::cout << "connect Mongodb\n";
	}
};
class Hbase :public Database {
public:
	void connect()
	{
		std::cout << "connect Hbase\n";
	}
};

class Factory {
public:
	Database* get_instance(DatabaseType _type)
	{
		switch (_type)
		{
		case MYSQL: 
			return new Mysql();
		case ORACLE:
			return new Oracle();
		case MONGODB:
			return new Mongodb();
		case HBASE:
			return new Hbase();
		default:
			return nullptr;
		}
	}
};

void factor_model_learning_main()
{
	Factory f;
	Database* d=f.get_instance(MYSQL);
	if(d!=nullptr)
		d->connect();
}
