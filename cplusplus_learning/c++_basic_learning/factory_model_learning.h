#pragma once
/*
	工厂模式：用于不需要知道内部的过程，只需要知道相应的接口即可
	使用场景：用户连接不同的数据库、连接不同的协议接口
	关键代码：创建过程在其子类进行

*/
#include<iostream>
//#include<string>

enum DatabaseType {
	//DatabaseType是一个类型
	MYSQL,
	ORACLE,
	MONGODB,
	HBASE
};
//基类是抽象类
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
