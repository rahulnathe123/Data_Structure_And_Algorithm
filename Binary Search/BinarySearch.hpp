#ifndef _BINARY__SEARCH
#define _BINARY__SEARCH

typedef long long ssize_t;
template <typename T>
void binarySearch(T* Arr , ssize_t N , T target)
{
    ssize_t begin = 0;
    ssize_t end = N-1;
    ssize_t mid ;
    while(begin<=end)
    {
        mid = (begin + end)/2;
        if(Arr[mid] == target)
        {
            std::cout<<target<<" Elements Found at "<<mid+1<<" Index in Array"<<std::endl;
            return ;
        }
        else if(Arr[mid] < target)
        {
            begin = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    std::cout<<target<<" Not Found in Array"<<std::endl;
}


template <typename T>
void show(T* Arr , int N , char* msg = 0)
{
    if(msg)
    {
        std::cout<<msg<<std::endl;
    }
    for(ssize_t i =0;i<N;i++)
    {
        std::cout<<"Arr["<<i<<"] : "<<Arr[i]<<std::endl;
    }
    std::cout<<std::endl;
}

#endif //_BINARY__SEARCH