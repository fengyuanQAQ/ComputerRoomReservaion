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

	//�鿴�Լ���ԤԼ
	void selforder(map<int, map<string, string>> &m_all);

	//�鿴���е�ԤԼ
	void allorder(map<int, map<string, string>> &m_all);

	//����һ��ԤԼ
	void makeAnOrder(map<int, map<string, string>> &m_all,int &number);

	//ȡ��ԤԼ
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