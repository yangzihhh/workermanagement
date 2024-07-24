#pragma once
#include "worker.h"
class employ :public worker
{
public:
	employ(int id,string name,int did);

	virtual void showinfo();

	virtual string getdepname();
};