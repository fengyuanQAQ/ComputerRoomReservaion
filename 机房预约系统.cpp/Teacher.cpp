#include "Teacher.h"

void Teacher::subMenu()
{
	cout << "��ӭ��" << this->m_name << "��ʿ" << endl;
	cout << "\t|------------------------------------|"<<endl;
	cout << "\t-------------------------------------|" << endl;
	cout << "\t|-------------1 �鿴����ԤԼ---------|" << endl;
	cout << "\t|-------------2 ���ԤԼ-------------|" << endl;
	cout << "\t|-------------0 ע����¼-------------|" << endl;
	cout << "\t|------------------------------------|" << endl;
	cout << "\t|------------------------------------|" << endl;
}

//�鿴����ԤԼ
void Teacher::allOerder(map<int, map<string, string>> &m_all)
{
	//����Ԫ��
	for (map<int, map<string, string>>::iterator it = m_all.begin(); it != m_all.end(); ++it)
	{
		cout << "ԤԼ" << it->first + 1 << ":";
		cout << "���ڣ�" << it->second["datetime"] << " " << "�����" << it->second["interval"]
			<< " " << "id�ţ�" << it->second["id"] << " " << "������" << it->second["name"]
			<< " " << "������ţ�" << it->second["computerid"]
			<< " " << "��ǰ״̬��" << it->second["status"] << endl;
	}
	system("pause");
	system("cls");
}

//���ԤԼ
void Teacher::checkOrder(map<int, map<string, string>> &m_all)
{
	if (m_all.empty())
	{
		cout << "��û��ͬѧԤԼ" << endl;
		system("pause");
		system("cls");
		return;
	}
	string id;
	cout << "�������˵�id��";
	cin >> id;

	bool flag = false;
	for (map<int, map<string, string>>::iterator it = m_all.begin(); it != m_all.end(); ++it)
	{
		int num;
		if (it->second["id"] == id)
		{
			flag = true;
			if (it->second["status"] == "�����")
			{
				cout << "�Ƿ��������?" << endl;
				cout << "0 ��" << endl;
				cout << "1 ��" << endl;
				cin >> num;
				if (num == 0)
				{
					it->second["status"] = "ͨ��";
				}
				else
				{
					it->second["status"] = "δͨ��";
				}
			}
			else{
				cout << "��ǰ��¼�Ѿ���˹�" << endl;
			}
		}
	}

         if(!flag)
cout << "�Ҳ���id" << endl;
	system("pause");
	system("cls");
}