#include <iostream>
#include "Person.h"
#include <map>
#include <string>

class Teacher :public Person
{
public:
	virtual void subMenu();

	//�鿴����ԤԼ
	void allOerder(map<int, map<string, string>> &m_all);

	//���ԤԼ
	void checkOrder(map<int, map<string, string>> &m_all);
public:
	string m_name;
	string m_id;
	string m_pwd;
	Teacher(string name,string id,string pwd)
	{
		this->m_name = name;
		this->m_id = id;
		this->m_pwd = pwd;
	}
};