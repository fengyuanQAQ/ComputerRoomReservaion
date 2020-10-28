#include "systemManager.h"

//初始化机房信息
void systemManager::initComputer()
{
	//读取文件
	ifstream ifs(COMPUTERROOMFILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "当前文件不存在" << endl;
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
//初始化所有预约信息
void systemManager::ReadAppointment()
{
	//打开预约文件
	ifstream ifs(APPOINTMENTFILE, ios::in);
	//判断文件是够存在
	if (!ifs.is_open())
	{
		cout << "当前文件不存在" << endl;
		system("pause");
		system("cls");
		return;
	}
	//判断当前文件是否为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "当前文件为空" << endl;
		return;
	}
	ifs.putback(ch);//传回字符

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

//构造函数
systemManager::systemManager()
{
	this->Appnum = 0;
	this->initComputer();//初始化机房信息
	this->ReadAppointment();//初始化预约信息
}

//主菜单显示
void systemManager::showMainMenu()
{
	cout << "\t----骚猪的机房预约系统v1.0-----" << endl;
	cout << "\t*******************************" << endl;
	cout << "\t|-----------------------------|" << endl;
	cout << "\t|-----------------------------|" << endl;
	cout << "\t|---------1 学生登录----------|" << endl;
	cout << "\t|---------2 教师登录----------|" << endl;
	cout << "\t|---------3 管理员登录--------|" << endl;
	cout << "\t|---------0 退出系统----------|" << endl;
	cout << "\t|-----------------------------|" << endl;
	cout << "\t|-----------------------------|" << endl;
}


//子菜单功能
void systemManager::SubMenuModule(int type)
{
	int select;
	bool flag = true;
	while (flag)
	{
		system("cls");
		this->p_idt->subMenu();
		cout << "大爷选一个服务吧~:";
		cin >> select;
		if (type == 1)
		{
			Student* p_as = (Student*)(this->p_idt);
			switch (select)
			{
			case 1://申请预约
				p_as->makeAnOrder(this->m_all,this->Appnum);
				break;//
			case 2://查看自身预约
				p_as->selforder(this->m_all);
				break;
			case 3://查看所有预约
				p_as->allorder(this->m_all);
				break;
			case 4://取消预约
				p_as->cancelOrder(this->m_all,this->Appnum);
				this->saveAppfile();//保存文件
				break;
			case 0://退出登录
				cout << "爽够了 下次记得多带点钱!" << endl;
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
			case 1://查看所有预约
				p_as->allOerder(this->m_all);
				break;//
			case 2://审核与预约
				p_as->checkOrder(this->m_all);
				this->saveAppfile();//保存文件
				break;
			case 0://退出登录
				cout << "爽够了 下次记得多带点钱!" << endl;
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
			case 1://添加账号
				p_as->addaccount();
				break;
			case 2://查看账号
				p_as->lookaccount();
				break;
			case 3://查看机房
				p_as->lookComputerRoom(this->m_v);
				break;
			case 4://清空预约
			    p_as->clearAppointment();
				break;
			case 0://退出登录
				cout << "爽够了 下次记得多带点钱!" << endl;
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
			cout << "传入参数错误!!!!!!" << endl;
			system("pause");
			return;
		}
	}
}

//登录操作
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
	cout << "传入参数错误" << endl;
	system("pause");
	system("cls");
	return;
	}

	//判断文件是否存在
	ifstream ifs(filename, ios::in);
	if (!ifs.is_open())
	{
		cout << "当前文件不存在" << endl;
		system("pause");
		system("cls");
		return;
	}
	//判断文件是否为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "当前文件为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	//读回文件的一个字符
	ifs.putback(ch);
	string name;
	string id;
	string pwd;
	bool flag = false;
	if (type == 1)
	{
		//当前身份为学生
		cout << "输入学生姓名：";
		cin >> name;
		cout << "输入学生学号：";
		cin >> id;
		cout << "输入学生密码：";
		cin >> pwd;

		//判断输入信息是否正确
		string fname;
		string fid;
		string faccount;
		while (ifs >> fname && ifs >> fid && ifs >> faccount)
		{
			if (fname == name && fid == id && faccount == pwd)
			{
				//登录成功
				this->p_idt = new Student(name, id, pwd);
				this->SubMenuModule(1);
				flag = true;
				break;
			}
		}
	}
	else if (type == 2)
	{
		cout << "输入教师姓名：";
		cin >> name;
		cout << "输入教师职工号：";
		cin >> id;
		cout << "输入密码：";
		cin >> pwd;

		//判断输入信息是否正确

		string fname;
		string fid;
		string faccount;
		while (ifs >> fname && ifs >> fid && ifs >> faccount)
		{
			//判断信息是否匹配
			if (fname == name && fid == id && faccount == pwd)
			{
				//登录成功
				flag = true;
				this->p_idt = new Teacher(name, id, pwd);
				this->SubMenuModule(2);
				break;
			}
			
		}
	}
	else if (type == 3)
	{
		cout << "输入管理员名称：";
		cin >> name;
		cout << "输入管理员密码：";
		cin >> pwd;

		//判断信息是否输入正确
		string fname;
		string faccount;
		while (ifs >> fname && ifs >> faccount)
		{
			//判断信息是否匹配
			if (fname == name &&  faccount == pwd)
			{
				//登录成功
				flag = true;
				this->p_idt = new Administor(name,pwd);
				this->SubMenuModule(3);
				break;
			}
		}
	}
	else
	{
		cout << "传入参数错误" << endl;
		system("pause");
		system("cls");
		return;
	}
	ifs.close();
	if (!flag)
	{
		//登录失败
		cout << "登录失败!!! 检测你输入的信息是否有误- -" << endl;
		system("pause");
		system("cls");
	}
}

//保存文件
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









