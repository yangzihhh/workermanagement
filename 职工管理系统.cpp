#include <iostream>
using namespace std;
#include<string>
//包含管理对象头文件
#include "workermanager.h"
#include "worker.h"
#include "employ.h"
#include"manager.h"
#include "boss.h"
int main()
{
	//实例化管理对象
	workermanager wm;

	int choice = 0;
	while (true)
	{
		//调用管理对象中的菜单函数
		wm.show_menu();

		cout << "请输入你的选择" << endl;
		cin >> choice;
		
			switch (choice)
			{
			case 0://退出职工管理系统
				wm.exitsystem();
				break;
			case 1:
				wm.add_emp();
				break;
			case 2:
				wm.show_emp();

				break;
			case 3:
				wm.del_emp();

				break;
				
			case 4:
				wm.alteremp();

				break;
			case 5:
				wm.findemp();
				break;
			case 6:
				wm.sort_emp();
				break;
			case 7:
				wm.clean_file();
				break;
			
			default:
				break;
		
			}
	}
	
	system("pause");
	return 0;
}