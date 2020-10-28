#pragma once
#include <iostream>
#include "Person.h"
#include "File.h"
#include <fstream>
#include "ComputerRoom.h"
#include <vector>
#include <fstream>
class Administor :public Person
{
public:
	virtual void subMenu();

	//添加账号
	void addaccount();

	//查看账号
	void lookaccount();

	//查看机房
	void lookComputerRoom(vector<ComputerRoom> &v);

	//清空预约
	void clearAppointment();

public:
	string m_name;
	string m_pwd;
	Administor(string name, string pwd);

	//存放机房信息的容器
	vector<ComputerRoom> m_v;

};