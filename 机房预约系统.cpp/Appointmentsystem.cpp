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
		cout << "��ү ѡһ�����~~~~:";
		cin >> select;
		switch (select)
		{
		case 0://�˳�
			cout << "��ү������- - " << endl;
			system("pause");
			exit(0);
			break;
		case 1://ѧ����¼
			sm.Login(1);
			break;
		case 2://���ҵ�¼
			sm.Login(2);
			break;
		case 3://����Ա��¼
			sm.Login(3);
			break;
		default:
			cout << "���·���- -" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}