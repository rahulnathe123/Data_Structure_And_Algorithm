#include "Date.hpp"

Date::Date(int dd ,int mm,int yy):day(dd),month(mm),year(yy)
{

}

bool Date::operator==(const Date& other)const
{
    if(this->day == other.day && this->month == other.month && this->year == other.year)
    {
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& out , const Date& other)
{
    std::cout<<"Date : "<<other.day<<"-"<<other.month<<"-"<<other.year;
    return out;
}

std::istream& operator>>(std::istream& in ,  Date& other)
{
    std::cout<<"Enter day , month and Year : "<<std::endl;
    in>>other.day>>other.month>>other.year;
    return in;
}