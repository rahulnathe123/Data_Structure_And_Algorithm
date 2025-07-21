#include "Student.hpp"
#include<string>

Student::Student(int rollNo,std::string name,std::string gender,
                double percentage)
    :rollNo(rollNo),name(name),gender(gender),percentage(percentage)
{

}

bool Student::operator==(const Student& other)const
{
    if(this->rollNo == other.rollNo && this->name == other.name
    && this->gender == other.gender && this->percentage == other.percentage)
    {
        return true;
    }   
    return false;
}

std::ostream& operator<<(std::ostream& out,const Student& other)
{
    out<<other.rollNo<<"\t"<<other.name<<"\t"<<other.gender<<"\t"<<other.percentage<<std::endl;
    return out;
}

std::istream& operator>>(std::istream& in , Student& other)
{
    std::cout<<"Enter the Roll no : ";
    in>>other.rollNo;
    std::cout<<"Enter the Name : ";
    std::cin.ignore();
    std::getline(in,other.name);
    std::cout<<"Enter gender : ";
    std::getline(in,other.gender);
    std::cout<<"Enter percentage : ";
    in>>other.percentage;
    return in;
}

bool Student::operator<(const Student& other)const
{
    if(this->rollNo < other.rollNo)
    {
        return true;
    }
    return false;
}


