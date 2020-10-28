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

	//���캯��
	systemManager();

	//���˵���ʾ
	void showMainMenu();

	//��¼����
	void Login(int type);

	//�Ӳ˵�����
	void SubMenuModule(int type);

	//��ʼ��������Ϣ
	void initComputer();

	//��ʼ��ԤԼ
	void ReadAppointment();
	void ReadInfo(string temp);

	//�����ļ�
	void saveAppfile();

	//��������
	~systemManager()
	{
		if (this->p_idt != NULL)
		{
			delete this->p_idt;
			this->p_idt = NULL;
			cout << "�����������óɹ�" << endl;
		}
	}
public:
	//����ʦ���ĸ���
	Person* p_idt;
	vector<ComputerRoom> m_v;//��Ż�����Ϣ������
	map<int, map<string, string>> m_all;//�������ԤԼ��Ϣ
	map<string, string> m_single;//��ʱ��ŵ�����Ϣ
	int Appnum;
};