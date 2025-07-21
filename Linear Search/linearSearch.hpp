#ifndef _LINEAR__SEARCH
#define _LINEAR__SEARCH

typedef long long ssize_t;
template <typename  T>
int Linear_Search(T* Arr ,int N,T target)
{
    for(ssize_t i =0;i<N;i++)
    {
        if(Arr[i] == target)
        {
            return i+1;
        }
    }
    return 0;
}


template <typename T>
void show(T* Arr , ssize_t N ,char* msg=0)
{
    if(msg)
    {
        std::cout<<msg<<std::endl;
    }
    for(ssize_t i = 0;i<N;i++)
    {
        std::cout<<"Arr["<<i<<"] : "<<Arr[i]<<std::endl;
    }
}





#endif //_LINEAR__SEARCH