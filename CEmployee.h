/******************************************************
** FILE:
**
** ABSTRACT:
** design and implementation of CEmployee class.
**
**
** AUTHOR:
**
** CREATION DATE:
**
*******************************************************/

#ifndef CEMPLOYEE_H
#define CEMPLOYEE_H
#include <string>
using std::string;
#include <algorithm>
using std::swap;
#include<iostream>
using std::cout;
class CEmployee{
protected:
	string m_firstName;
	string m_lastName;
	unsigned int m_hiringYear;
	unsigned int m_salary;
public:
	// default constructor
	CEmployee() {
		m_firstName = "";
		m_lastName = "";
		m_hiringYear = 0;
		m_salary = 0;
	}
	CEmployee(const string &first, const string &last, const unsigned int &yr, const unsigned int &sal){
		m_firstName = first;
		m_lastName = last;
		m_hiringYear = yr;
		m_salary = sal;
	}
	CEmployee(const CEmployee &emp) {
		m_firstName = emp.m_firstName;
		m_lastName = emp.m_lastName;
		m_hiringYear = emp.m_hiringYear;
		m_salary = emp.m_salary;
	}
	virtual ~CEmployee() {
		m_firstName.~string();
		m_lastName.~string();
		//m_hiringYear.~unsigned(); // might not work, check
		//m_salary.~unsigned();
	}
	// copy and swap
	CEmployee& operator=(CEmployee emp) {
		swap(m_firstName, emp.m_firstName);
		swap(m_lastName, emp.m_lastName);
		swap(m_hiringYear, emp.m_hiringYear);
		swap(m_salary, emp.m_salary);
		return *this;
	}
	void setFirstName(const string &name) {
		m_firstName = name;
	}
	void setLastName(const string &name) {
		m_lastName = name;
	}
	void setYear(const unsigned int &yr) {
		m_hiringYear = yr;
	}
	void setSal(const unsigned int &sal) {
		m_salary = sal;
	}
	string getFirstName() const{
		return m_firstName;
	}
	string getLastName() const{
		return m_lastName;
	}
	unsigned int getYear() const{
		return m_hiringYear;
	}
	unsigned int getSal() const{
		return m_salary;
	}
	virtual void DisplayEmployee() const{
		cout << getFirstName() << " " << getLastName() << "  " << "Salary:" << getSal() << "  Hiring year:" << getYear();
	}
};


#endif
