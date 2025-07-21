#include "BinarySearch.hpp"
#include "Student.hpp"
#include<iostream>

void test1(void);
void test2(void);
void test3(void);
void test4(void);


int main(void)
{
    test1();
    std::cout<<"---------------------------------------------"<<std::endl;
    test2();
    std::cout<<"---------------------------------------------"<<std::endl;
    test3();
    std::cout<<"---------------------------------------------"<<std::endl;
    test4();
    return 0;
}

void test1(void)
{
    int N = 5;
    int i_arr[5] = {100 , 200 , 300 ,400 ,500};
    int target = 400;
    show<int>(i_arr , N , "Array Elements Are ");
    binarySearch<int>(i_arr , N , target);
    target = 150;
    binarySearch<int>(i_arr , N , target);
}

void test2(void)
{
    int N = 5;
    double d_arr[5] = {15.4 , 19.6 , 25.4 , 25.8 , 25.9};
    double target  = 15.4;
    show<double>(d_arr , N , "Array Elements Are");
    binarySearch<double>(d_arr , N , target);
    target = 25.9;
    std::cout<<std::endl;
    binarySearch(d_arr , N , target);
}

void test3(void)
{
    int N = 5;
    char c_arr[5] = {'A','G','Z','a','s'};
    char target = 'Z';
    show<char>(c_arr , N , "Array Elements Are");
    binarySearch<char>(c_arr , N,target);
    target = 's';
    std::cout<<std::endl;
    binarySearch<char>(c_arr, N ,target);
}

void test4(void)
{
    int N = 5;
    Student S[5] = {
        Student(110 , "Rahul Nathe" , "Male" , 95.60),
        Student(115 , "Ambadas Deshmukh","Male",90.20),
        Student(125 , "Hrushikesh Rajput","Male",92.50),
        Student(137 , "Atharv Upasani","Male" , 96.50),
        Student(148 , "Sanskar Dikondwar","Male",92.10)
    };

    Student target(110 , "Rahul Nathe","Male",95.60);
    show<Student>(S,N , "\nInformation of All Student \n");
    binarySearch<Student>(S , N , target);
    std::cin>>target;
    binarySearch<Student>(S , N , target);
}