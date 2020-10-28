#include "Student.h"

void Student::subMenu()
{
	cout << "��ӭ��" << this->m_name << "��ʿ" << endl;
	cout << "\t|------------------------------------|" << endl;
	cout << "\t-------------------------------------|" << endl;
	cout << "\t|-------------1 ����ԤԼ-------------|" << endl;
	cout << "\t|-------------2 �鿴�ҵ�ԤԼ---------|" << endl;
	cout << "\t|-------------3 �鿴����ԤԼ---------|" << endl;
	cout << "\t|-------------4 ȡ��ԤԼ-------------|" << endl;
	cout << "\t|-------------0 ע����¼-------------|" << endl;
	cout << "\t|------------------------------------|" << endl;
	cout << "\t|------------------------------------|" << endl;
}

// �鿴�Լ���ԤԼ
void Student::selforder(map<int, map<string, string>> &m_all)
{
   //�������в������Լ�ƥ�����Ϣ
	for (map<int, map<string, string>>::iterator it = m_all.begin(); it != m_all.end(); ++it)
	{
		if (this->m_id == it->second["id"])
		{
			cout << "���ڣ�" << it->second["datetime"] << " " << "�����" << it->second["interval"]
				<< " " << "id�ţ�" << it->second["id"] << " " << "������" << it->second["name"]
				<< " " << "������ţ�" << it->second["computerid"]
				<< " " << "��ǰ״̬��" << it->second["status"] << endl;
		}
    }
	system("pause");
	system("cls");
}

//�鿴���е�ԤԼ
void Student::allorder(map<int, map<string, string>> &m_all)
{
	//����Ԫ��
	for (map<int, map<string, string>>::iterator it=m_all.begin(); it != m_all.end(); ++it)
	{
		cout << "ԤԼ" << it->first+1 << ":";
		cout << "���ڣ�" << it->second["datetime"] << " " << "�����" << it->second["interval"]
			<< " " << "id�ţ�" << it->second["id"]<<" "<<"������"<<it->second["name"]
			<< " " << "������ţ�" << it->second["computerid"]
			<< " " << "��ǰ״̬��" << it->second["status"] << endl;
	}
	system("pause");
	system("cls");
}

//����һ��ԤԼ
void Student::makeAnOrder(map<int, map<string, string>> &m_all,int &num)
{
	//���ļ�
	ofstream ofs;
	ofs.open(APPOINTMENTFILE, ios::app | ios::out);

	string timetable[5] = { "����һ","���ڶ�" ,"������", "������" ,"������" };
	int datetime;
	cout << "ѡ�����ڼ���" << endl;
	cout << "0 ����һ" << endl;
	cout << "1 ���ڶ�" << endl;
	cout << "2 ������" << endl;
	cout << "3 ������" << endl;
	cout << "4 ������" << endl;
	cin >> datetime;

	string nametable[3] = { "����","����" ,"����" };
	int time;
	cout << "ѡ��ʱ�Σ�" << endl;
	cout << "0 ����" << endl;
	cout << "1����" << endl;
	cout << "2 ����" << endl;
	cin >> time;

	string number;
	cout << "ѡ��һ�������ţ�" << endl;
	cout << "1 ����һ" << endl;
	cout << "2 ������" << endl;
	cout << "3 ������" << endl;
	cin >> number;

	//д���ļ�
	ofs << "datetime:" << timetable[datetime] << " " << "interval:" << nametable[time] << " "
		<< "id:" << this->m_id << " " << "name:" << this->m_name << " "
		<< "computerid:" << number << " " << "status:" << "�����" << endl;

	ofs.close();

	//���µ�ǰԤԼ
	map<string, string> temp;
	temp.insert(make_pair("datetime", timetable[datetime]));
	temp.insert(make_pair("interval", nametable[time]));
	temp.insert(make_pair("id", this->m_id));
	temp.insert(make_pair("name", this->m_name));
	temp.insert(make_pair("computerid", number));
	temp.insert(make_pair("status", "�����"));
	m_all.insert(make_pair(num, temp));

	num++;
	system("pause");
	system("cls");


}

//ȡ��ԤԼ
void Student::cancelOrder(map<int, map<string, string>> &m_all,int &num)
{
	bool flag = false;

	vector<map<int, map<string, string>>::iterator> Arrit;
	for (map<int, map<string, string>>::iterator it = m_all.begin(); it != m_all.end(); ++it)
	{
		if (it->second["id"] == this->m_id&&it->second["status"]=="�����")
		{
			Arrit.push_back(it);//����������ʱ����������
			--num;
			flag = true;
		}
	}
	for (vector<map<int, map<string, string>>::iterator>::iterator it = Arrit.begin(); it != Arrit.end(); ++it)
	{
		m_all.erase(*it);
	}


	if (flag)
		cout << "ȡ��ԤԼ�ɹ�" << endl;
	else
		cout << "ȡ��ԤԼʧ�� ��ǰ�����ͨ����������id����ȷ" << endl;
	system("pause");
	system("cls");
}
