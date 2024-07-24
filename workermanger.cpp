#include "workermanager.h"
#include"worker.h"
workermanager::workermanager()
{
	//判断文件是否存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;

		this->m_empnum = 0;

		this->m_emparray = NULL;

		this->m_filempty = true;

		ifs.close();
		return;
	}
	//判断文件是否为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空" << endl;

		this->m_empnum = 0;

		this->m_emparray = NULL;

		this->m_filempty = true;

		ifs.close();
		return;
		}
	//文件不为空可以判断文件中储存了多少员工的信息
	int num = 0;

	num=this->get_empnum();
	
	//cout << "已有员工人数：" << num << "人" << endl;
	this->m_empnum = num;
	//创建堆区将文件中的信息读入堆区
	this->m_emparray = new worker * [this->m_empnum];

	this->init_emp();
	/*for (int i = 0; i < this->m_empnum; i++)
	{
		cout << "员工编号：" << this->m_emparray[i]->m_id
			<< "\t员工姓名：" << this->m_emparray[i]->m_name
			<< "\t员工职务：" << this->m_emparray[i]->getdepname()
			<< endl;
	}*/

}

void workermanager::show_menu()
{
	cout << "************************" << endl;
	cout << "**欢迎使用职工管理系统**" << endl;
	cout << "*****0.退出管理程序*****" << endl;
	cout << "*****1.增加职工信息*****" << endl;
	cout << "*****2.显示职工信息*****" << endl;
	cout << "*****3.删除离职职工*****" << endl;
	cout << "*****4.修改职工信息*****" << endl;
	cout << "*****5.查找职工信息*****" << endl;
	cout << "*****6.按照编号排号*****" << endl;
	cout << "*****7.清除所有信息*****" << endl;
	cout << "************************" << endl;
	cout <<  endl;
}
 void workermanager::exitsystem()
{
	 cout << "欢迎下次使用" << endl;
	 exit(0);
}
 void workermanager::save()
 {
	 ofstream ofs;
	 ofs.open(FILENAME, ios::out);
	 for (int i = 0; i < this->m_empnum; i++)
	 {
		 ofs << this->m_emparray[i]->m_id << " "
			 << this->m_emparray[i]->m_name << " "
			 << this->m_emparray[i]->m_did << endl;
		 ofs.close();
	 }
 }
 void workermanager::add_emp()
 {
	 cout << "请输入要添加的员工人数" << endl;

	 int addnum;//初始化添加人数

	 cin >> addnum;//输入添加人数

	 int newsize = m_empnum + addnum;//设置新员工人数大小
	 
	 if (addnum > 0)
	 {
		 worker** newspace = new worker * [newsize];//在堆区创建一个新数组储存原有员工和新加的员工
		 
		 //将原来的员工信息储存于新数组中
		 for (int i = 0; i < this->m_empnum; i++)
		 {
			 newspace[i] = this->m_emparray[i];
		 }
		 for (int i = 0; i < addnum; i++)
		 {
			 cout << "请输入添加的第" << i+1 << "个人的编号" << endl;
			 int id;
			 cin >> id;
			 cout << "请输入添加的第" << i+1 << "个人的姓名" << endl;
			 string name;
			 cin >> name;
			 cout << "请选择输入人的职务" << endl;
			 cout << "1.普通员工" << endl;
			 cout << "2.经理" << endl; 
			 cout << "3.老板" << endl;
			 int did;
			 cin >> did;

			 worker* newemp = NULL;//创建new的指针

			 switch (did)
			 {case 1:
				 newemp = new employ(id, name, did);
				 break;
			 case 2:
				newemp = new manager(id, name, did);
				 break;
			 case 3:
				newemp = new boss(id, name, did);
				 break;
			 default:
				 break;
			 }
			 newspace[this->m_empnum + i] = newemp;//将添加的新人加入新保存的数组中

		 }
		 delete[] this->m_emparray;

		 m_emparray = newspace;

		 m_empnum = newsize;

		 this->m_filempty = false;

		 cout << "成功添加" <<addnum<<"名员工"<< endl;

		 this->save();
	 }
	 else
		 cout << "输入人数有误" << endl;

	 system("pause");
	 system("cls");

 }

 int workermanager::get_empnum()
 {
	 ifstream ifs;
	 ifs.open(FILENAME, ios::in);

	 int num = 0;

	 int id;

	 string name;

	 int did;

	 while (ifs >> id && ifs >> name && ifs >> did)
	 {
		 num++;
	 }
	 this->m_empnum = num;

	 ifs.close();

	 return num;
 }
 //读取文件中的员工信息
 void  workermanager:: init_emp()
 {
	 ifstream ifs;
	 ifs.open(FILENAME, ios::in);
	 worker* p = NULL;
	 int index=0;
	 int id;
	 string name;
	 int did;
	 while (ifs >> id && ifs >> name && ifs >> did)
	 {
		 if (did == 1)
		 {
			 p = new employ(id, name, did);
		 }
		 else if (did ==2)
		 {
			 p = new manager(id, name, did);
		 }
		 else
		 {
			 p = new boss(id, name, did);
		 }
		 this->m_emparray[index] = p;
		 index++;
	 }

	 ifs.close();

 }
 //显示当前系统内所有员工的信息
 void workermanager::show_emp()
 {
	 if (m_filempty)
	 {
		 cout << "当前公司没有员工" << endl;
	 }
	 else
	 {
		 for (int i = 0; i < this->m_empnum; i++)
		 {
			 this->m_emparray[i]->showinfo();
		 }
	 }
	 system("pause");
	 system("cls");
 }

 void workermanager::del_emp()
 {
	 if (this->m_filempty)
	 {
		 cout << "文件不存在职工" << endl;
	 }
	 else
	 {
		 cout << "请输入要删除的员工的编号" << endl;
		 int id;
		 cin >> id;
		 int index =this->isexit(id);
		 if (index != -1)
		 {
			 for (int i=index; i < this->m_empnum - 1; i++)
			 {
				 this->m_emparray[i] = this->m_emparray[i + 1];
			 }
			 this->m_empnum--;//更新系统中成员的数量
			 this->save();
			 cout << "删除成功！" << endl;
			
		 }
		 else
		 {
			 cout << "删除失败，未找到该职工" << endl;
		 }
	 }
	 system("pause");
	 system("cls");
 }

 int workermanager::isexit(int id)
 {
	 int index = -1;
	 for (int i = 0; i < this->m_empnum; i++)
	 {
		 if (this->m_emparray[i]->m_id == id)
		 {
			 index = i;
			 break;
		 }
	}
	 return index;
 }

 void workermanager::alteremp()
 {
	 if(this->m_filempty)
	 {
		 cout << "文件不存在职工" << endl;
	 }
	 else
	 {
		 cout << "请输入要修改的员工的编号" << endl;
		 int id;
		 cin >> id;
		 int index = this->isexit(id);
		 if (index != -1)
		 {
			 cout << "请输入编号" << endl;
			 int alid;
			 cin >> alid;
			 this->m_emparray[index]->m_id = alid;
			 
			 cout << "请输入姓名" << endl;
			 string alname;
			 cin >> alname;
			 this->m_emparray[index]->m_name= alname;

			 cout << "请选择输入人的职务" << endl;
			 cout << "1.普通员工" << endl;
			 cout << "2.经理" << endl;
			 cout << "3.老板" << endl;
			 int aldid;
			 cin >> aldid;

			 this->m_emparray[index]->m_did = aldid;

			 cout << "修改成功" << endl;
		 }
		 else
		 {
			 cout << "修改失败，未找到该职工" << endl;
		 }
	}
	 system("pause");
	 system("cls");
 }

 void workermanager::findemp()
 {
	 if (this->m_filempty)
	 {
		 cout << "文件不存在职工" << endl;
	 }
	 else
	 {
		 cout << "请输入要查询的员工的编号" << endl;
		 int id;
		 cin >> id;
		 if (id != -1)
		 {
			 int i = this->isexit(id);
			 this->m_emparray[i]->showinfo();
		 }
		 else
		 {
			 cout << "查无此人" << endl;
		 }
	 }
	 system("pause");
	 system("cls");
 }

 void workermanager::clean_file()
 {
	 cout << "是否要清空" << endl;
	 cout << "1.清空" << endl;
	 cout << "2.返回" << endl;
	 int select;
	 cin >> select;
	 if (select == 1)
	 {
		 ofstream ofs(FILENAME, ios::trunc);
		 ofs.close();
		 if (this->m_emparray != NULL)
		 {
			 for (int i = 0; i < this->m_empnum; i++)
			 {
				 if (this->m_emparray[i] != NULL)
				 {
					 delete this->m_emparray[i];
				 }
			 }
			 this->m_empnum = 0;
			 delete[] this->m_emparray;
			 this->m_emparray = NULL;
			 this->m_filempty = true;
		 }
		 cout << "清空成功" << endl;
	 }
	 system("pause");
	 system("cls");
 }

 void workermanager::sort_emp()
 {
	 if (this->m_filempty)
	 {
		 cout << "文件不存在职工" << endl;
	 }
	 else
	 {
		 for (int i = 0; i < this->m_empnum - 1; i++)
		 {
			 for (int j = 0; j < this->m_empnum - 1 - i; j++)
			 {
				 if (this->m_emparray[j]->m_id > this->m_emparray[j + 1]->m_id)
				 {
					 worker* p = NULL;
					  p = this->m_emparray[j];
					  this->m_emparray[j] = this->m_emparray[j + 1];
					  this->m_emparray[j + 1] = p;
					  p = NULL;
				 }
			 }
		 }
		 this->show_emp();
		 cout << endl;
		 cout << "职工排序完成!" << endl;
	 }

 }


workermanager::~workermanager()
{

}
