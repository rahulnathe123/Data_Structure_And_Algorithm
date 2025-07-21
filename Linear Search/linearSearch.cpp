#include "linearSearch.hpp"
#include "Date.hpp"
#include<iostream>


void test1(void);
void test2(void);
void test3(void);
void test4(void);
void test5(void);
int main(void)
{
    test1();
    std::cout<<std::endl<<"------------------------------------"<<std::endl;
    test2();
    std::cout<<std::endl<<"------------------------------------"<<std::endl;
    test3();
    std::cout<<std::endl<<"------------------------------------"<<std::endl;
    test4();
    std::cout<<std::endl<<"------------------------------------"<<std::endl;
    test5();
    return 0;
}

void test1(void)
{
    int N = 5;
    int arr[5] = {15,20,35,10,25};
    int target = 20;
    show<int>(arr,N,"Array Elements Are :");
    int index = Linear_Search(arr,N,target);
    if(index == 0)
    {
        std::cout<<"Element Not Found in Array"<<std::endl;
    }
    else{
        std::cout<<target<<" Found at "<<index<<" index in Array"<<std::endl;
    }
}

void test2(void)
{
    int N = 5;
    double d_Arr[5] ={12.3 , 17.8 , 19.8 , 25.3 , 11.1};
    double target = 25.3;
    show<double>(d_Arr , N , "\nArray Elements Are : ");
    int index  = Linear_Search<double>(d_Arr , N , target);
    if(index == 0)
    {
        std::cout<<target<<"Not Found in Array"<<std::endl;
    }
    else{
        std::cout<<target<<" Found At "<<index<<" index in Array"<<std::endl; 
    }
    target = 10.5;
    index = Linear_Search<double>(d_Arr , N , target);
    if(index == 0)
    {
        std::cout<<target<<" Not Found in Array"<<std::endl;
    }
    else{
        std::cout<<target<<" Found At "<<index<<" index in Array"<<std::endl; 
    }
}

void test3(void)
{
    int N = 5;
    char c_arr[5] = {'A','C','S','Z','R'};
    char target = 'C';
    show<char>(c_arr , N , "\nArray elements are : ");
    int index = Linear_Search<char>(c_arr , N , target);
    if(index == 0)
    {
        std::cout<<target<<" Not Found in Array"<<std::endl;
    }
    else{
        std::cout<<target<<" Found at "<<index<<" index in the array"<<std::endl;
    }
}

void test4(void)
{
    int N = 5;
    float f_arr[5]={13.4f , 15.6f , 19.6f , 25.2f,19.1f};
    float target = 25.2f;
    show<float>(f_arr , N , "Array Elements Are");
    int index = Linear_Search<float>(f_arr , N , target);
    if(index == 0)
    {
        std::cout<<target<<" Not Found in array"<<std::endl;
    }
    else
        std::cout<<target<<" Found at "<<index<<" index in Array"<<std::endl;
}

void test5(void)
{
    int N = 5;
    Date date_arr[5] = {
        Date(20,5,2003),
        Date(13 ,9,1985),
        Date(1,6,1976),
        Date(23,6,2001),
        Date(19,1,1995)
    };
    Date target(23,6,2001);
    show<Date>(date_arr , N , "Date Class Array Elements Are : ");
    int index = Linear_Search<Date>(date_arr,N,target);
    if(index == 0)
    {
        std::cout<<target<<" Not Found in Array elements"<<std::endl;
    }
    else
        std::cout<<target<<" Found at "<<index<<" Position in array Elements"<<std::endl;
}
