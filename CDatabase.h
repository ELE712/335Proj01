/******************************************************
 ** FILE: CDatabase.h
 **
 ** ABSTRACT:
 ** Design and implementation of CDatabase holding records of CEmployees
 **
 **
 ** AUTHOR: Ezekiel Zandbergen, Matthew Eaton
 **
 ** CREATION DATE: 1-27-16
 **
 *******************************************************/

#ifndef _CDATABASE_H
#define _CDATABASE_H
#include <vector>
using std::vector;
#include <string>
using std::string;

#include "CManager.h"

class CDatabase{
private:
    CDatabase() {} //default constructor not needed
protected:
    vector<CEmployee*> m_allEmp; //to hold all employees
public:
    CDatabase(vector<CEmployee*> emp_vec){ 
        //constructs vector from referenced vector
        for (auto i : emp_vec)
            AddRecord(i);
    }
    CDatabase(const CDatabase &data) {
        //copy constructor
        m_allEmp = data.m_allEmp;
    }
    virtual ~CDatabase() {
        //destructor
        for (auto i : m_allEmp)
            delete i;
    }
    CDatabase& operator=(CDatabase data) {
        //assignment operator
        swap(m_allEmp, data.m_allEmp);
        return *this;
    }
    void AddRecord(CEmployee* emp) {
        //adds employee to vector
        m_allEmp.push_back(emp);
    }
    void DisplayRecords() {
        //display all managers and employees in database
        for (auto i : m_allEmp)
            (*i).DisplayEmployee();
    }
};

#endif
