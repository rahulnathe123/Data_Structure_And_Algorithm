#ifndef _DATE__HPP
#define _DATE__HPP
#include<iostream>
class Date
{
    friend std::ostream& operator<<(std::ostream& , const Date&);
    friend std::istream& operator>>(std::istream& , Date&);
    private : 
        int day,month,year; 
    public:
        Date(int dd = 0 ,int mm = 0,int yy = 0);
        bool operator==(const Date&)const;
};


#endif //_DATE__HPP