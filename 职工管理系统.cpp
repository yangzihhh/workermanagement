#include <iostream>
using namespace std;
#include<string>
//�����������ͷ�ļ�
#include "workermanager.h"
#include "worker.h"
#include "employ.h"
#include"manager.h"
#include "boss.h"
int main()
{
	//ʵ�����������
	workermanager wm;

	int choice = 0;
	while (true)
	{
		//���ù�������еĲ˵�����
		wm.show_menu();

		cout << "���������ѡ��" << endl;
		cin >> choice;
		
			switch (choice)
			{
			case 0://�˳�ְ������ϵͳ
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