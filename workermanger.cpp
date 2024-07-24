#include "workermanager.h"
#include"worker.h"
workermanager::workermanager()
{
	//�ж��ļ��Ƿ����
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;

		this->m_empnum = 0;

		this->m_emparray = NULL;

		this->m_filempty = true;

		ifs.close();
		return;
	}
	//�ж��ļ��Ƿ�Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��" << endl;

		this->m_empnum = 0;

		this->m_emparray = NULL;

		this->m_filempty = true;

		ifs.close();
		return;
		}
	//�ļ���Ϊ�տ����ж��ļ��д����˶���Ա������Ϣ
	int num = 0;

	num=this->get_empnum();
	
	//cout << "����Ա��������" << num << "��" << endl;
	this->m_empnum = num;
	//�����������ļ��е���Ϣ�������
	this->m_emparray = new worker * [this->m_empnum];

	this->init_emp();
	/*for (int i = 0; i < this->m_empnum; i++)
	{
		cout << "Ա����ţ�" << this->m_emparray[i]->m_id
			<< "\tԱ��������" << this->m_emparray[i]->m_name
			<< "\tԱ��ְ��" << this->m_emparray[i]->getdepname()
			<< endl;
	}*/

}

void workermanager::show_menu()
{
	cout << "************************" << endl;
	cout << "**��ӭʹ��ְ������ϵͳ**" << endl;
	cout << "*****0.�˳��������*****" << endl;
	cout << "*****1.����ְ����Ϣ*****" << endl;
	cout << "*****2.��ʾְ����Ϣ*****" << endl;
	cout << "*****3.ɾ����ְְ��*****" << endl;
	cout << "*****4.�޸�ְ����Ϣ*****" << endl;
	cout << "*****5.����ְ����Ϣ*****" << endl;
	cout << "*****6.���ձ���ź�*****" << endl;
	cout << "*****7.���������Ϣ*****" << endl;
	cout << "************************" << endl;
	cout <<  endl;
}
 void workermanager::exitsystem()
{
	 cout << "��ӭ�´�ʹ��" << endl;
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
	 cout << "������Ҫ��ӵ�Ա������" << endl;

	 int addnum;//��ʼ���������

	 cin >> addnum;//�����������

	 int newsize = m_empnum + addnum;//������Ա��������С
	 
	 if (addnum > 0)
	 {
		 worker** newspace = new worker * [newsize];//�ڶ�������һ�������鴢��ԭ��Ա�����¼ӵ�Ա��
		 
		 //��ԭ����Ա����Ϣ��������������
		 for (int i = 0; i < this->m_empnum; i++)
		 {
			 newspace[i] = this->m_emparray[i];
		 }
		 for (int i = 0; i < addnum; i++)
		 {
			 cout << "��������ӵĵ�" << i+1 << "���˵ı��" << endl;
			 int id;
			 cin >> id;
			 cout << "��������ӵĵ�" << i+1 << "���˵�����" << endl;
			 string name;
			 cin >> name;
			 cout << "��ѡ�������˵�ְ��" << endl;
			 cout << "1.��ͨԱ��" << endl;
			 cout << "2.����" << endl; 
			 cout << "3.�ϰ�" << endl;
			 int did;
			 cin >> did;

			 worker* newemp = NULL;//����new��ָ��

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
			 newspace[this->m_empnum + i] = newemp;//����ӵ����˼����±����������

		 }
		 delete[] this->m_emparray;

		 m_emparray = newspace;

		 m_empnum = newsize;

		 this->m_filempty = false;

		 cout << "�ɹ����" <<addnum<<"��Ա��"<< endl;

		 this->save();
	 }
	 else
		 cout << "������������" << endl;

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
 //��ȡ�ļ��е�Ա����Ϣ
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
 //��ʾ��ǰϵͳ������Ա������Ϣ
 void workermanager::show_emp()
 {
	 if (m_filempty)
	 {
		 cout << "��ǰ��˾û��Ա��" << endl;
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
		 cout << "�ļ�������ְ��" << endl;
	 }
	 else
	 {
		 cout << "������Ҫɾ����Ա���ı��" << endl;
		 int id;
		 cin >> id;
		 int index =this->isexit(id);
		 if (index != -1)
		 {
			 for (int i=index; i < this->m_empnum - 1; i++)
			 {
				 this->m_emparray[i] = this->m_emparray[i + 1];
			 }
			 this->m_empnum--;//����ϵͳ�г�Ա������
			 this->save();
			 cout << "ɾ���ɹ���" << endl;
			
		 }
		 else
		 {
			 cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
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
		 cout << "�ļ�������ְ��" << endl;
	 }
	 else
	 {
		 cout << "������Ҫ�޸ĵ�Ա���ı��" << endl;
		 int id;
		 cin >> id;
		 int index = this->isexit(id);
		 if (index != -1)
		 {
			 cout << "��������" << endl;
			 int alid;
			 cin >> alid;
			 this->m_emparray[index]->m_id = alid;
			 
			 cout << "����������" << endl;
			 string alname;
			 cin >> alname;
			 this->m_emparray[index]->m_name= alname;

			 cout << "��ѡ�������˵�ְ��" << endl;
			 cout << "1.��ͨԱ��" << endl;
			 cout << "2.����" << endl;
			 cout << "3.�ϰ�" << endl;
			 int aldid;
			 cin >> aldid;

			 this->m_emparray[index]->m_did = aldid;

			 cout << "�޸ĳɹ�" << endl;
		 }
		 else
		 {
			 cout << "�޸�ʧ�ܣ�δ�ҵ���ְ��" << endl;
		 }
	}
	 system("pause");
	 system("cls");
 }

 void workermanager::findemp()
 {
	 if (this->m_filempty)
	 {
		 cout << "�ļ�������ְ��" << endl;
	 }
	 else
	 {
		 cout << "������Ҫ��ѯ��Ա���ı��" << endl;
		 int id;
		 cin >> id;
		 if (id != -1)
		 {
			 int i = this->isexit(id);
			 this->m_emparray[i]->showinfo();
		 }
		 else
		 {
			 cout << "���޴���" << endl;
		 }
	 }
	 system("pause");
	 system("cls");
 }

 void workermanager::clean_file()
 {
	 cout << "�Ƿ�Ҫ���" << endl;
	 cout << "1.���" << endl;
	 cout << "2.����" << endl;
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
		 cout << "��ճɹ�" << endl;
	 }
	 system("pause");
	 system("cls");
 }

 void workermanager::sort_emp()
 {
	 if (this->m_filempty)
	 {
		 cout << "�ļ�������ְ��" << endl;
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
		 cout << "ְ���������!" << endl;
	 }

 }


workermanager::~workermanager()
{

}
