#include "Teacher.h"

void Teacher::subMenu()
{
	cout << "欢迎您" << this->m_name << "博士" << endl;
	cout << "\t|------------------------------------|"<<endl;
	cout << "\t-------------------------------------|" << endl;
	cout << "\t|-------------1 查看所有预约---------|" << endl;
	cout << "\t|-------------2 审核预约-------------|" << endl;
	cout << "\t|-------------0 注销登录-------------|" << endl;
	cout << "\t|------------------------------------|" << endl;
	cout << "\t|------------------------------------|" << endl;
}

//查看所有预约
void Teacher::allOerder(map<int, map<string, string>> &m_all)
{
	//遍历元素
	for (map<int, map<string, string>>::iterator it = m_all.begin(); it != m_all.end(); ++it)
	{
		cout << "预约" << it->first + 1 << ":";
		cout << "日期：" << it->second["datetime"] << " " << "间隔：" << it->second["interval"]
			<< " " << "id号：" << it->second["id"] << " " << "姓名：" << it->second["name"]
			<< " " << "机房编号：" << it->second["computerid"]
			<< " " << "当前状态：" << it->second["status"] << endl;
	}
	system("pause");
	system("cls");
}

//审核预约
void Teacher::checkOrder(map<int, map<string, string>> &m_all)
{
	if (m_all.empty())
	{
		cout << "还没有同学预约" << endl;
		system("pause");
		system("cls");
		return;
	}
	string id;
	cout << "输入待审核的id：";
	cin >> id;

	bool flag = false;
	for (map<int, map<string, string>>::iterator it = m_all.begin(); it != m_all.end(); ++it)
	{
		int num;
		if (it->second["id"] == id)
		{
			flag = true;
			if (it->second["status"] == "待审核")
			{
				cout << "是否让其嫖娼?" << endl;
				cout << "0 是" << endl;
				cout << "1 否" << endl;
				cin >> num;
				if (num == 0)
				{
					it->second["status"] = "通过";
				}
				else
				{
					it->second["status"] = "未通过";
				}
			}
			else{
				cout << "当前记录已经审核过" << endl;
			}
		}
	}

         if(!flag)
cout << "找不到id" << endl;
	system("pause");
	system("cls");
}