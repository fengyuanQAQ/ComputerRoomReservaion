#include "Administor.h"

//��ʼ��
 Administor::Administor(string name, string pwd)
{
	this->m_name = name;
	this->m_pwd = pwd;
}

void Administor::subMenu()
{
	cout << "��ӭ��" << this->m_name << "��ʿ" << endl;
	cout << "\t|------------------------------------|" << endl;
	cout << "\t-------------------------------------|" << endl;
	cout << "\t|-------------1 ����˺�-------------|" << endl;
	cout << "\t|-------------2 �鿴�˺�-------------|" << endl;
	cout << "\t|-------------3 �鿴����-------------|" << endl;
	cout << "\t|-------------4 ���ԤԼ-------------|" << endl;
	cout << "\t|-------------0 ע����¼-------------|" << endl;
	cout << "\t|------------------------------------|" << endl;
	cout << "\t|------------------------------------|" << endl;
}

//����˺�
void Administor::addaccount()
{
	int choice;
	cout << "ѡ��һ�������~" << endl;
	cout << "1 ѧ�� " << endl;
	cout << "2 ��ʦ" << endl;
	cout << "3 ����Ա" << endl;
	cin >> choice;

	string filename;
	string name;
	int id;
	int	pwd;
	ofstream ofs;
	if (choice == 1)
	{
		filename = STUDENTFILE;
		ofs.open(filename, ios::app | ios::out);
		cout << "����ѧ��������";
		cin >> name;
		cout << "����ѧ��ѧ�ţ�";
		cin >> id;
		cout << "����ѧ�����룺";
		cin >> pwd;
		ofs << name << " " << id << " " << pwd << endl;
	}
	else if (choice == 2)
	{
		filename = TEACHAERFILE;
		ofs.open(filename, ios::app | ios::out);
		cout << "�����ʦ������";
		cin >> name;
		cout << "�����ʦְ���ţ�";
		cin >> id;
		cout << "�����ʦ���룺";
		cin >> pwd;
		ofs << name << " " << id << " " << pwd << endl;
	}
	else if (choice == 3)
	{
		filename = ADNIMISTORFILE;
		ofs.open(filename, ios::app | ios::out);
		cout << "�������Ա������";
		cin >> name;
		cout << "�������Ա���룺";
		cin >> pwd;
		ofs << name << " "<< pwd << endl;
	}
	else
	{
		cout << "����û�й����������� �㻹���߰�~" << endl;
		system("pasue");
		return;
	}
	ofs.close();
	system("pause");
	system("cls");
}

//�鿴�˺�
void Administor::lookaccount()
{
	string name;
	int id;
	int pwd;
	ifstream ifs1(STUDENTFILE, ios::in);
	cout << "--------------ѧ������--------------" << endl;
	while (ifs1 >> name && ifs1 >> id && ifs1 >> pwd)
	{
		cout << name << " " << id << " " << pwd << endl;
	}
	ifs1.close();

	ifstream ifs2(TEACHAERFILE, ios::in);
	cout << "---------------��ʦ����--------------" << endl;
	while (ifs2 >> name && ifs2 >> id && ifs2 >> pwd)
	{
		cout << name << " " << id << " " << pwd << endl;
	}
	ifs2.close();

	ifstream ifs3(ADNIMISTORFILE, ios::in);
	cout << "---------------����Ա����--------------" << endl;
	while (ifs3 >> name && ifs3 >> pwd)
	{
		cout << name <<  " " << pwd << endl;
	}
	ifs3.close();
	system("pause");
	system("cls");
}

//�鿴����
void Administor::lookComputerRoom(vector<ComputerRoom> &v)
{
	for (vector<ComputerRoom>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << "������ţ�" << it->m_id << "\t������С:" << it->m_size
			<< "\t��������" << it->m_capacity << endl;
	}
	system("pause");
	system("cls");
}

//���ԤԼ
void Administor::clearAppointment()
{
	//�жϵ�ǰ�ļ��Ƿ����
	ifstream ifs(APPOINTMENTFILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "��ǰ�ļ�������" << endl;
		system("pause");
		system("cls");
		return;
	}

	ofstream ofs;
	ofs.open(APPOINTMENTFILE, ios::trunc);//�ض��ļ�
	cout << "ԤԼ�ļ������" << endl;
	ofs.close();
	system("pause");
	system("cls");
}
