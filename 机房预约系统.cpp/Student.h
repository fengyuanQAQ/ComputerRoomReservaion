#pragma once
#include "Person.h"
#include <fstream>
#include "File.h"
#include <map>
#include <string>
#include <vector>
class Student:public Person
{
public:
	virtual void subMenu();

	//查看自己的预约
	void selforder(map<int, map<string, string>> &m_all);

	//查看所有的预约
	void allorder(map<int, map<string, string>> &m_all);

	//申请一个预约
	void makeAnOrder(map<int, map<string, string>> &m_all,int &number);

	//取消预约
	void cancelOrder(map<int, map<string, string>> &m_all, int &num);


public:
	string m_name;
	string m_id;
	string m_pwd;
	Student(string name, string id, string pwd)
	{
		this->m_name = name;
		this->m_id = id;
		this->m_pwd = pwd;
	}

};