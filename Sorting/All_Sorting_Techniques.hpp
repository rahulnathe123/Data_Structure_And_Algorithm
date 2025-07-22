#ifndef _SORTING__HPP
#define _SORTING__HPP
#include<iostream>
#include<vector>
#include<algorithm>
typedef int ssize_t;

//1. bubbleSort
//2. selectionSort
//3. insertionSort
//4. mergeSort
//5. RadixSort
//6. quickSort



template   <typename T>
void bubbleSort(T* arr , ssize_t N )
{

   
    ssize_t i , j ;
    for(i = 1;i<N;i++)
    {
        for(j=0;j<N-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                T temp;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


template <typename T>
void insertionSort(T* arr , ssize_t N)
{
   
    T key;
    int j = 0;
    for(std::vector<int>::size_type i = 1;i!=N;i++)
    {
        key = arr[i];
        j = i-1;
        while(j>-1 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}


template <typename T>
void selectionSort(T* arr , ssize_t N , char* msg = 0)
{
    
    ssize_t i , j;
    ssize_t pivot;
    for(i = 0 ;i<N;i++)
    {
        pivot =i;
        for(j = i;j<N;j++)
        {
            if(arr[j]<arr[pivot])
            {
                pivot = j;
            }
        }
        T temp = arr[i];
        arr[i] = arr[pivot];
        arr[pivot] = temp;
    }
}


template <typename T>
void merge(T* arr, ssize_t begin, ssize_t mid, ssize_t end) {
    ssize_t i = begin, j = mid + 1, k = 0;
    std::vector<T> temp(end - begin + 1);

    while (i <= mid && j <= end) {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= end)
        temp[k++] = arr[j++];

    for (ssize_t t = 0; t < k; ++t)
        arr[begin + t] = temp[t];
}

template <typename T>
void mergeSort(T* arr, ssize_t begin, ssize_t end) {
    if (begin < end) {
        ssize_t mid = (begin + end) / 2;
        mergeSort(arr, begin, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, begin, mid, end);
    }
}




template <typename T>
ssize_t partition(T* arr, ssize_t low, ssize_t high)
{
    T pivot = arr[low];
    ssize_t i = low + 1;
    ssize_t j = high;

    while (true)
    {
        while (i <= high && arr[i] < pivot)
            i++;

        while (j > low && arr[j] > pivot)
            j--;

        if (i >= j)
            break;

        std::swap(arr[i], arr[j]);
    }

    std::swap(arr[low], arr[j]);
    return j;
}

template <typename T>
void quickSort(T* arr, ssize_t low, ssize_t high)
{
    if (low < high)
    {
        ssize_t j = partition(arr, low, high);
        quickSort(arr, low, j - 1);
        quickSort(arr, j + 1, high);
    }
}


template <typename T>
void show(T* arr , int N,char *msg)
{
    if(msg)
    {
        std::cout<<msg<<std::endl;
    }

    ssize_t i = 0;
    for(i = 0;i<N;i++)
    {
        std::cout<<"arr["<<i<<"] : "<<arr[i]<<std::endl;
    }
}
#endif //_SORTING__HPP