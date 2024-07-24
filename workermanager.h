#pragma once
#include <iostream>
using namespace std;
#include "worker.h"
#include "employ.h"
#include"boss.h"
#include"manager.h"
#include "fstream"
#define FILENAME "empfile.txt"
class workermanager
{
public:
	workermanager();

	void show_menu();

	void add_emp();

	void save();

	bool m_filempty;
	 
	int get_empnum();

	void init_emp();
	
	void show_emp();

	int isexit(int id);

	void del_emp();

	void alteremp();

	void findemp();

	void sort_emp();

	void clean_file();

	void exitsystem();

	int m_empnum;
	worker * * m_emparray;

	~workermanager();

};