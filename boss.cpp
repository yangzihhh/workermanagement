#include "boss.h"

boss::boss(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_did = did;
}

void boss::showinfo()
{

	cout << "Ա�����:" << this->m_id
		<< "\tԱ��������" << this->m_name
		<< "\tԱ��ְ��:" << this->getdepname()
		<< endl;
}

string boss::getdepname()
{
	return string("�ϰ�");
}