#include"employ.h"
employ::employ(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_did = did;
}
void employ::showinfo()
{
	cout << "Ա�����:" << this->m_id
		<< "\tԱ��������" << this->m_name
		<< "\tԱ��ְ��:" << this->getdepname()
		<< endl;
}

string  employ::getdepname()
{
	return string("Ա��");
}
