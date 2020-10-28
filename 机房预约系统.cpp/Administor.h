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

	//����˺�
	void addaccount();

	//�鿴�˺�
	void lookaccount();

	//�鿴����
	void lookComputerRoom(vector<ComputerRoom> &v);

	//���ԤԼ
	void clearAppointment();

public:
	string m_name;
	string m_pwd;
	Administor(string name, string pwd);

	//��Ż�����Ϣ������
	vector<ComputerRoom> m_v;

};