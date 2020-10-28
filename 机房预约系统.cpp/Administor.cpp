#include "Administor.h"

//初始化
 Administor::Administor(string name, string pwd)
{
	this->m_name = name;
	this->m_pwd = pwd;
}

void Administor::subMenu()
{
	cout << "欢迎您" << this->m_name << "博士" << endl;
	cout << "\t|------------------------------------|" << endl;
	cout << "\t-------------------------------------|" << endl;
	cout << "\t|-------------1 添加账号-------------|" << endl;
	cout << "\t|-------------2 查看账号-------------|" << endl;
	cout << "\t|-------------3 查看机房-------------|" << endl;
	cout << "\t|-------------4 清空预约-------------|" << endl;
	cout << "\t|-------------0 注销登录-------------|" << endl;
	cout << "\t|------------------------------------|" << endl;
	cout << "\t|------------------------------------|" << endl;
}

//添加账号
void Administor::addaccount()
{
	int choice;
	cout << "选择一个姑娘吧~" << endl;
	cout << "1 学生 " << endl;
	cout << "2 老师" << endl;
	cout << "3 管理员" << endl;
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
		cout << "输入学生姓名：";
		cin >> name;
		cout << "输入学生学号：";
		cin >> id;
		cout << "输入学生密码：";
		cin >> pwd;
		ofs << name << " " << id << " " << pwd << endl;
	}
	else if (choice == 2)
	{
		filename = TEACHAERFILE;
		ofs.open(filename, ios::app | ios::out);
		cout << "输入教师姓名：";
		cin >> name;
		cout << "输入教师职工号：";
		cin >> id;
		cout << "输入教师密码：";
		cin >> pwd;
		ofs << name << " " << id << " " << pwd << endl;
	}
	else if (choice == 3)
	{
		filename = ADNIMISTORFILE;
		ofs.open(filename, ios::app | ios::out);
		cout << "输入管理员姓名：";
		cin >> name;
		cout << "输入管理员密码：";
		cin >> pwd;
		ofs << name << " "<< pwd << endl;
	}
	else
	{
		cout << "看来没有姑娘能满足你 你还是走吧~" << endl;
		system("pasue");
		return;
	}
	ofs.close();
	system("pause");
	system("cls");
}

//查看账号
void Administor::lookaccount()
{
	string name;
	int id;
	int pwd;
	ifstream ifs1(STUDENTFILE, ios::in);
	cout << "--------------学生区↓--------------" << endl;
	while (ifs1 >> name && ifs1 >> id && ifs1 >> pwd)
	{
		cout << name << " " << id << " " << pwd << endl;
	}
	ifs1.close();

	ifstream ifs2(TEACHAERFILE, ios::in);
	cout << "---------------教师区↓--------------" << endl;
	while (ifs2 >> name && ifs2 >> id && ifs2 >> pwd)
	{
		cout << name << " " << id << " " << pwd << endl;
	}
	ifs2.close();

	ifstream ifs3(ADNIMISTORFILE, ios::in);
	cout << "---------------管理员区↓--------------" << endl;
	while (ifs3 >> name && ifs3 >> pwd)
	{
		cout << name <<  " " << pwd << endl;
	}
	ifs3.close();
	system("pause");
	system("cls");
}

//查看机房
void Administor::lookComputerRoom(vector<ComputerRoom> &v)
{
	for (vector<ComputerRoom>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << "机房编号；" << it->m_id << "\t机房大小:" << it->m_size
			<< "\t机房容量" << it->m_capacity << endl;
	}
	system("pause");
	system("cls");
}

//清空预约
void Administor::clearAppointment()
{
	//判断当前文件是否存在
	ifstream ifs(APPOINTMENTFILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "当前文件不存在" << endl;
		system("pause");
		system("cls");
		return;
	}

	ofstream ofs;
	ofs.open(APPOINTMENTFILE, ios::trunc);//截断文件
	cout << "预约文件已清空" << endl;
	ofs.close();
	system("pause");
	system("cls");
}
