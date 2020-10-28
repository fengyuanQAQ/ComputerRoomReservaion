#pragma once
#include <iostream>
#include "Student.h"
#include "Teacher.h"
#include "Administor.h"
#include "Person.h"
#include <string>
#include "File.h"
#include <fstream>
#include <vector>
#include "ComputerRoom.h"
using namespace std;

class systemManager
{
public:

	//构造函数
	systemManager();

	//主菜单显示
	void showMainMenu();

	//登录操作
	void Login(int type);

	//子菜单功能
	void SubMenuModule(int type);

	//初始化电脑信息
	void initComputer();

	//初始化预约
	void ReadAppointment();
	void ReadInfo(string temp);

	//保存文件
	void saveAppfile();

	//析构函数
	~systemManager()
	{
		if (this->p_idt != NULL)
		{
			delete this->p_idt;
			this->p_idt = NULL;
			cout << "析构函数作用成功" << endl;
		}
	}
public:
	//管理师生的父类
	Person* p_idt;
	vector<ComputerRoom> m_v;//存放机房信息的容器
	map<int, map<string, string>> m_all;//存放所有预约信息
	map<string, string> m_single;//暂时存放单条信息
	int Appnum;
};