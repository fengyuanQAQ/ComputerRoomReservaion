#include <iostream>
#include "systemManager.h"
using namespace std;
int main()
{
	systemManager sm;
	int select=0;
	while (true)
	{
		sm.showMainMenu();
		cout << "大爷 选一个玩吧~~~~:";
		cin >> select;
		switch (select)
		{
		case 0://退出
			cout << "大爷常来啊- - " << endl;
			system("pause");
			exit(0);
			break;
		case 1://学生登录
			sm.Login(1);
			break;
		case 2://教室登录
			sm.Login(2);
			break;
		case 3://管理员登录
			sm.Login(3);
			break;
		default:
			cout << "无事发生- -" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}