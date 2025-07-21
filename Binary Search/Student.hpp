#ifndef _STUDENT__HPP
#define _STUDENT__HPP

#include<iostream>
class Student
{
    friend std::ostream& operator<<(std::ostream& , const Student&);
    friend std::istream& operator>>(std::istream& , Student&);

    private:
        int rollNo;
        std::string name;
        std::string gender;
        double percentage;
    public:
        Student(int _rollNo =0 , std::string name="" , std::string gender ="" , double percentage=0.0);
        bool operator==(const Student&)const;
        bool operator<(const Student&)const;
};

#endif