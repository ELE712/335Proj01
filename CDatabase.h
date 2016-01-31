/******************************************************
** FILE: CDatabase.h
**
** ABSTRACT: Holds database class for employees
**
**
**
** AUTHOR: Ezekiel Zandbergen, 
**
** CREATION DATE: 01-27-16
**
*******************************************************/

#ifndef CDATABASE_H
#define CDATABASE_H

#include <vector>
#include <string>
#include "CEmployee.h"
#include "CManager.h"

using std::string;


class CDatabase{
private:
    CDatabase(){} //default constructor not needed
    
protected:
    vector<CEmployee*> m_allEmp; //to hold all employees
    
public:
    CDatabase(vector<CEmployee*> emp_vec){
        //constructs vector from referenced vector
        for (int i=0; i<allEmp.size(); ++i){
            AddRecord(emp_vec[i]);
        }
    }
    
    virtual ~CDatabase(){
        for (CEmployee e : m_allEmp)
            delete e; //deletes each employee in vector
    }
    
    void AddRecord(const CEmployee emp){
        m_allEmp.push_back(&emp);
    }
    
    void DisplayRecords(){
        for (int i=0; i<m_allEmp.size(); ++i)
            allEmp[i]->DisplayEmployee(); //might be allEmp[i].DisplayEmployee()
    }
    
};

#endif
