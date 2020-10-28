#include "Student.h"

void Student::subMenu()
{
	cout << "欢迎您" << this->m_name << "博士" << endl;
	cout << "\t|------------------------------------|" << endl;
	cout << "\t-------------------------------------|" << endl;
	cout << "\t|-------------1 申请预约-------------|" << endl;
	cout << "\t|-------------2 查看我的预约---------|" << endl;
	cout << "\t|-------------3 查看所有预约---------|" << endl;
	cout << "\t|-------------4 取消预约-------------|" << endl;
	cout << "\t|-------------0 注销登录-------------|" << endl;
	cout << "\t|------------------------------------|" << endl;
	cout << "\t|------------------------------------|" << endl;
}

// 查看自己的预约
void Student::selforder(map<int, map<string, string>> &m_all)
{
   //在容器中查找与自己匹配的信息
	for (map<int, map<string, string>>::iterator it = m_all.begin(); it != m_all.end(); ++it)
	{
		if (this->m_id == it->second["id"])
		{
			cout << "日期：" << it->second["datetime"] << " " << "间隔：" << it->second["interval"]
				<< " " << "id号：" << it->second["id"] << " " << "姓名：" << it->second["name"]
				<< " " << "机房编号：" << it->second["computerid"]
				<< " " << "当前状态：" << it->second["status"] << endl;
		}
    }
	system("pause");
	system("cls");
}

//查看所有的预约
void Student::allorder(map<int, map<string, string>> &m_all)
{
	//遍历元素
	for (map<int, map<string, string>>::iterator it=m_all.begin(); it != m_all.end(); ++it)
	{
		cout << "预约" << it->first+1 << ":";
		cout << "日期：" << it->second["datetime"] << " " << "间隔：" << it->second["interval"]
			<< " " << "id号：" << it->second["id"]<<" "<<"姓名："<<it->second["name"]
			<< " " << "机房编号：" << it->second["computerid"]
			<< " " << "当前状态：" << it->second["status"] << endl;
	}
	system("pause");
	system("cls");
}

//申请一个预约
void Student::makeAnOrder(map<int, map<string, string>> &m_all,int &num)
{
	//打开文件
	ofstream ofs;
	ofs.open(APPOINTMENTFILE, ios::app | ios::out);

	string timetable[5] = { "星期一","星期二" ,"星期三", "星期四" ,"星期五" };
	int datetime;
	cout << "选择星期几：" << endl;
	cout << "0 星期一" << endl;
	cout << "1 星期二" << endl;
	cout << "2 星期三" << endl;
	cout << "3 星期四" << endl;
	cout << "4 星期五" << endl;
	cin >> datetime;

	string nametable[3] = { "上午","下午" ,"晚上" };
	int time;
	cout << "选择时段：" << endl;
	cout << "0 上午" << endl;
	cout << "1下午" << endl;
	cout << "2 晚上" << endl;
	cin >> time;

	string number;
	cout << "选择一个机房号：" << endl;
	cout << "1 机房一" << endl;
	cout << "2 机房二" << endl;
	cout << "3 机房三" << endl;
	cin >> number;

	//写入文件
	ofs << "datetime:" << timetable[datetime] << " " << "interval:" << nametable[time] << " "
		<< "id:" << this->m_id << " " << "name:" << this->m_name << " "
		<< "computerid:" << number << " " << "status:" << "待审核" << endl;

	ofs.close();

	//更新当前预约
	map<string, string> temp;
	temp.insert(make_pair("datetime", timetable[datetime]));
	temp.insert(make_pair("interval", nametable[time]));
	temp.insert(make_pair("id", this->m_id));
	temp.insert(make_pair("name", this->m_name));
	temp.insert(make_pair("computerid", number));
	temp.insert(make_pair("status", "待审核"));
	m_all.insert(make_pair(num, temp));

	num++;
	system("pause");
	system("cls");


}

//取消预约
void Student::cancelOrder(map<int, map<string, string>> &m_all,int &num)
{
	bool flag = false;

	vector<map<int, map<string, string>>::iterator> Arrit;
	for (map<int, map<string, string>>::iterator it = m_all.begin(); it != m_all.end(); ++it)
	{
		if (it->second["id"] == this->m_id&&it->second["status"]=="待审核")
		{
			Arrit.push_back(it);//将迭代器暂时保存数组中
			--num;
			flag = true;
		}
	}
	for (vector<map<int, map<string, string>>::iterator>::iterator it = Arrit.begin(); it != Arrit.end(); ++it)
	{
		m_all.erase(*it);
	}


	if (flag)
		cout << "取消预约成功" << endl;
	else
		cout << "取消预约失败 当前已审核通过或者输入id不正确" << endl;
	system("pause");
	system("cls");
}
