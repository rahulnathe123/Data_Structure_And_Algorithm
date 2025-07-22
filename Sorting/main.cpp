#include "sort.hpp"
#include<iostream>


void test(void);
void test1(void);
int main(void)
{

    test();
    std::cout<<std::endl<<std::endl<<"========================================================="<<std::endl;
    test1();
    return 0;
}

void test(void)
{
    int N = 10;
    int arr1[10] = {9,8,7,6,5,4,3,2,1,0};

    show<int>(arr1,N,"\n\nBefore Bubble Sort Apply");
    bubbleSort<int>(arr1 , N);
    show<int>(arr1 , N ,"\n\nAfter Bubble Sort Apply");

    int arr2[] = {150 , 250 , 100 ,125 ,175 , 200 , 270 ,230,190,165};
    show<int>(arr2 , N ,"\n\nBefore Apply Insertion Sort");
    insertionSort<int>(arr2 , N);
    show<int>(arr2,N,"After Apply Insertion Sort");

    int arr3[] = {950 , 850 , 700 ,525 ,675 , 400 , 170 ,330,790,265};
    show<int>(arr3 , N , "\n\nBefore Apply Selection Sort");
    selectionSort<int>(arr3,N);
    show<int>(arr3 , N , "After Apply Selection Sort");

    int arr4[] = {1150 , 2250 , 1100 ,3125 ,2175 , 2200 , 1270 ,2230,3190,4165};
    show<int>(arr4 , N , "\nBefore Apply Merge Sort");
    mergeSort(arr4 , 0, N-1);
    show<int>(arr4 , N , "After Apply Merge Sort");

    int arr5[] = {50 , 20 , 10 ,12 ,15 , 2 , 70 ,23,19,16};
    show<int>(arr5 , N , "\nBefore Apply Quick Sort");
    quickSort(arr5 , 0 , N-1);
    show<int>(arr5 , N , "\nAfter Apply Quick Sort");


}

void test1(void)
{
    double arr1[7] = {56.7 , 49.9 , 43.6 , 51.9 , 53.7 , 47.6 , 52.6};

    show<double>(arr1 , 7 , "Before Applying Merge Sort");
    mergeSort<double>(arr1 , 0 ,6);
    show<double>(arr1 , 7 , "After Applying Merge Sort");
    
    std::cout<<std::endl<<"-----------------------"<<std::endl;
    
    char c_arr[8] = {'t','b','w','s','m','g','r','q'};
    show<char>(c_arr , 7 , "Before Applying Quick Sort");
    quickSort(c_arr , 0 ,7);
    show<char>(c_arr , 7 , "After Applying Quick Sort");
    std::cout<<std::endl<<"-----------------------"<<std::endl;
}