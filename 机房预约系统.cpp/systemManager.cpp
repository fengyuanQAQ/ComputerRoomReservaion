#include "systemManager.h"

//��ʼ��������Ϣ
void systemManager::initComputer()
{
	//��ȡ�ļ�
	ifstream ifs(COMPUTERROOMFILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "��ǰ�ļ�������" << endl;
		return;
	}
	int id;
	int size;
	int capacity;
	while (ifs >> id && ifs >> size && ifs >> capacity)
	{
		this->m_v.push_back(ComputerRoom(capacity, size, id));
	}
	ifs.close();
}

void systemManager::ReadInfo(string temp)
{
	int start = 0;
	int pos;
	pos = temp.find(":");
	if (pos == -1)
		return;
	string key = temp.substr(0, pos - start);
	string value = temp.substr(pos + 1, temp.size()-1-pos);
	this->m_single.insert(make_pair(key, value));
}
//��ʼ������ԤԼ��Ϣ
void systemManager::ReadAppointment()
{
	//��ԤԼ�ļ�
	ifstream ifs(APPOINTMENTFILE, ios::in);
	//�ж��ļ��ǹ�����
	if (!ifs.is_open())
	{
		cout << "��ǰ�ļ�������" << endl;
		system("pause");
		system("cls");
		return;
	}
	//�жϵ�ǰ�ļ��Ƿ�Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "��ǰ�ļ�Ϊ��" << endl;
		return;
	}
	ifs.putback(ch);//�����ַ�

	string datetime;
	string interval;
	string id;
	string name;
	string cid;
	string status;
	while (ifs >> datetime && ifs >> interval && ifs >> id && ifs >> name && ifs >> cid&&ifs>>status)
	{
		this->ReadInfo(datetime);
		this->ReadInfo(interval); 
		this->ReadInfo(id);
		this->ReadInfo(name);
		this->ReadInfo(cid);
		this->ReadInfo(status);
		this->m_all.insert(make_pair(this->Appnum, this->m_single));
		this->m_single.clear();
		this->Appnum++;
	}
	ifs.close();
}

//���캯��
systemManager::systemManager()
{
	this->Appnum = 0;
	this->initComputer();//��ʼ��������Ϣ
	this->ReadAppointment();//��ʼ��ԤԼ��Ϣ
}

//���˵���ʾ
void systemManager::showMainMenu()
{
	cout << "\t----ɧ��Ļ���ԤԼϵͳv1.0-----" << endl;
	cout << "\t*******************************" << endl;
	cout << "\t|-----------------------------|" << endl;
	cout << "\t|-----------------------------|" << endl;
	cout << "\t|---------1 ѧ����¼----------|" << endl;
	cout << "\t|---------2 ��ʦ��¼----------|" << endl;
	cout << "\t|---------3 ����Ա��¼--------|" << endl;
	cout << "\t|---------0 �˳�ϵͳ----------|" << endl;
	cout << "\t|-----------------------------|" << endl;
	cout << "\t|-----------------------------|" << endl;
}


//�Ӳ˵�����
void systemManager::SubMenuModule(int type)
{
	int select;
	bool flag = true;
	while (flag)
	{
		system("cls");
		this->p_idt->subMenu();
		cout << "��үѡһ�������~:";
		cin >> select;
		if (type == 1)
		{
			Student* p_as = (Student*)(this->p_idt);
			switch (select)
			{
			case 1://����ԤԼ
				p_as->makeAnOrder(this->m_all,this->Appnum);
				break;//
			case 2://�鿴����ԤԼ
				p_as->selforder(this->m_all);
				break;
			case 3://�鿴����ԤԼ
				p_as->allorder(this->m_all);
				break;
			case 4://ȡ��ԤԼ
				p_as->cancelOrder(this->m_all,this->Appnum);
				this->saveAppfile();//�����ļ�
				break;
			case 0://�˳���¼
				cout << "ˬ���� �´μǵö����Ǯ!" << endl;
				system("pause");
				system("cls");
				flag = false;
				break;
			default:
				break;
			}
		}
		else if (type == 2)
		{
			Teacher* p_as = (Teacher*)(this->p_idt);
			switch (select)
			{
			case 1://�鿴����ԤԼ
				p_as->allOerder(this->m_all);
				break;//
			case 2://�����ԤԼ
				p_as->checkOrder(this->m_all);
				this->saveAppfile();//�����ļ�
				break;
			case 0://�˳���¼
				cout << "ˬ���� �´μǵö����Ǯ!" << endl;
				system("pause");
				system("cls");
				flag = false;
				break;
			default:
				break;
			}
		}
		else if (type == 3)
		{
			Administor* p_as = (Administor*)(this->p_idt);
			switch (select)
			{
			case 1://����˺�
				p_as->addaccount();
				break;
			case 2://�鿴�˺�
				p_as->lookaccount();
				break;
			case 3://�鿴����
				p_as->lookComputerRoom(this->m_v);
				break;
			case 4://���ԤԼ
			    p_as->clearAppointment();
				break;
			case 0://�˳���¼
				cout << "ˬ���� �´μǵö����Ǯ!" << endl;
				system("pause");
				system("cls");
				flag = false;
				break;
			default:
				break;
			}
		}
		else
		{
			cout << "�����������!!!!!!" << endl;
			system("pause");
			return;
		}
	}
}

//��¼����
void systemManager::Login(int type)
{
	string filename;
	if (type == 1)
		filename = STUDENTFILE;
	else if (type == 2)
		filename = TEACHAERFILE;
	else if (type == 3)
		filename = ADNIMISTORFILE;
	else
	{ 
	cout << "�����������" << endl;
	system("pause");
	system("cls");
	return;
	}

	//�ж��ļ��Ƿ����
	ifstream ifs(filename, ios::in);
	if (!ifs.is_open())
	{
		cout << "��ǰ�ļ�������" << endl;
		system("pause");
		system("cls");
		return;
	}
	//�ж��ļ��Ƿ�Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "��ǰ�ļ�Ϊ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	//�����ļ���һ���ַ�
	ifs.putback(ch);
	string name;
	string id;
	string pwd;
	bool flag = false;
	if (type == 1)
	{
		//��ǰ���Ϊѧ��
		cout << "����ѧ��������";
		cin >> name;
		cout << "����ѧ��ѧ�ţ�";
		cin >> id;
		cout << "����ѧ�����룺";
		cin >> pwd;

		//�ж�������Ϣ�Ƿ���ȷ
		string fname;
		string fid;
		string faccount;
		while (ifs >> fname && ifs >> fid && ifs >> faccount)
		{
			if (fname == name && fid == id && faccount == pwd)
			{
				//��¼�ɹ�
				this->p_idt = new Student(name, id, pwd);
				this->SubMenuModule(1);
				flag = true;
				break;
			}
		}
	}
	else if (type == 2)
	{
		cout << "�����ʦ������";
		cin >> name;
		cout << "�����ʦְ���ţ�";
		cin >> id;
		cout << "�������룺";
		cin >> pwd;

		//�ж�������Ϣ�Ƿ���ȷ

		string fname;
		string fid;
		string faccount;
		while (ifs >> fname && ifs >> fid && ifs >> faccount)
		{
			//�ж���Ϣ�Ƿ�ƥ��
			if (fname == name && fid == id && faccount == pwd)
			{
				//��¼�ɹ�
				flag = true;
				this->p_idt = new Teacher(name, id, pwd);
				this->SubMenuModule(2);
				break;
			}
			
		}
	}
	else if (type == 3)
	{
		cout << "�������Ա���ƣ�";
		cin >> name;
		cout << "�������Ա���룺";
		cin >> pwd;

		//�ж���Ϣ�Ƿ�������ȷ
		string fname;
		string faccount;
		while (ifs >> fname && ifs >> faccount)
		{
			//�ж���Ϣ�Ƿ�ƥ��
			if (fname == name &&  faccount == pwd)
			{
				//��¼�ɹ�
				flag = true;
				this->p_idt = new Administor(name,pwd);
				this->SubMenuModule(3);
				break;
			}
		}
	}
	else
	{
		cout << "�����������" << endl;
		system("pause");
		system("cls");
		return;
	}
	ifs.close();
	if (!flag)
	{
		//��¼ʧ��
		cout << "��¼ʧ��!!! ������������Ϣ�Ƿ�����- -" << endl;
		system("pause");
		system("cls");
	}
}

//�����ļ�
void systemManager::saveAppfile()
{
	ofstream ofs(APPOINTMENTFILE, ios::out);
	for (map<int, map<string, string>>::iterator it = this->m_all.begin(); it != this->m_all.end(); ++it)
	{
		ofs << "datetime:" << it->second["datetime"]<<" " << "interval:" << it->second["interval"] << " "
			<< "id:" << it->second["id"] << " " << "name:" << it->second["name"] << " "
			<< "computerid:" << it->second["computerid"] << " " << "status:" << it->second["status"] << endl;
	}
	ofs.close();
}









