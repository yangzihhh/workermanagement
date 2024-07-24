#include"employ.h"
employ::employ(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_did = did;
}
void employ::showinfo()
{
	cout << "员工编号:" << this->m_id
		<< "\t员工姓名：" << this->m_name
		<< "\t员工职务:" << this->getdepname()
		<< endl;
}

string  employ::getdepname()
{
	return string("员工");
}
