/******************************************************
** FILE:
**
** ABSTRACT:
**design and implementation of CManager.
**
**
** AUTHOR:
**
** CREATION DATE:
**
*******************************************************/

#ifndef CMANAGER_H
#define CMANAGER_H
#include <vector>
using std::vector;
#include <algorithm>
using std::swap;
#include<iostream>
using std::cout; using std::endl;
#include "CEmployee.h"

class CManager: public CEmployee{
protected:
	string m_depName;
	vector<CEmployee*> m_empManaged;
public:
	CManager():CEmployee() {
		m_depName = "";
	}
	CManager(const string &first, const string &last, const unsigned int &yr, const unsigned int &sal, const string &dep, const vector<CEmployee*> &vect) :CEmployee(first,last,yr,sal) {
		m_depName = dep;
		m_empManaged = vect;
	}
	//copy constructor
	CManager(const CManager &man):CEmployee(man){
		m_depName = man.m_depName;
		m_empManaged = man.m_empManaged;
	}
	// = operator
	CManager& operator=(CManager man) {
		CEmployee::operator=(man);
		swap(m_depName, man.m_depName);
		swap(m_empManaged, man.m_empManaged);
	}
	void setDepartment(const string &dep) {
		m_depName = dep;
	}
	void setManaged(const vector<CEmployee*> &vect) { // 
		m_empManaged = vect; 
	}
	string getDepartment() const{
		return m_depName;
	}
	vector<CEmployee*> getManaged() const{
		return m_empManaged;
	}
	virtual void DisplayEmployee() const {
		CEmployee::DisplayEmployee();
		cout << getDepartment() << "      Subordinates:" << (getManaged()).size() << endl;
		if ((getManaged()).size >= 1) {
			for (auto i : getManaged()) {
				cout << "       ";
				(*i).CEmployee::DisplayEmployee();
			}
		}
	}
};

#endif
