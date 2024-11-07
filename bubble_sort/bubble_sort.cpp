#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <chrono>

#define FUNCTION_NAME(func) #func

template <typename T>
void buble_sort_for_for_index(int n, T* tab)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (tab[i] < tab[j])
            {
                int savedValueFromFirstArray = tab[i];
                tab[i] = tab[j];
                tab[j] = savedValueFromFirstArray;
            }
        }
    }
}

template <typename T>
bool check_if_sorted(int n, T* tab)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (tab[i] > tab[i + 1])
        {
            return false;
        }
    }
    return true;
}

template <typename T>
void cout_array(int n, T* tab)
{
    if (n > 30)
    {
        std::cout << "\nArray length is over 30 elements, the console will show only 30 elements" << std::endl;
        n = 30;
    }
    std::cout<<"\nArray:"<<std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << i<< "\t" << tab[i] << std::endl;
    }
}

template <typename T>
void buble_sort_while_for_index(int n, T* tab)
{
    bool zamiana = true;
    while (zamiana)
    {
        zamiana = false;
        for (int i = 0; i < n - 1; i++)
        {
            if (tab[i] > tab[i + 1])
            {
                zamiana = true;
                int savedValueFromElement = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = savedValueFromElement;
            }
        }
    }
}

template <typename T>
void buble_sort_for_shorten_for_index(int n, T* tab)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (tab[j] > tab[j + 1])
            {
                int savedValueFromElement = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = savedValueFromElement;
            }
        }
    }
}

template <typename T>
void buble_sort_for_for_pointer(int n, T* tab)
{
    T *w1,*w2,temp;
    for(int i=0;i<n;i++)
    {
        w1 = tab;
        w2 = w1 + 1;
        for(int j=0;j<n-1;j++)
        {
            if(*w1>*w2)
            {
                temp = *w2;
                *w2 = *w1;
                *w1 = temp;
            }
        w1++;
        w2++;
        }
    }
}

template <typename T>
void buble_sort_while_for_pointer(int n, T* tab)
{
    bool zamiana = true;
    T *w1,*w2,temp;
    while (zamiana)
    {
        zamiana = false;
        w1 = tab;
        w2 = w1+1;
        
        for (int i = 0; i < n - 1; i++)
        {
            if (*w1 > *w2)
            {
                zamiana = true;
                temp = *w1;
                *w1 = *w2;
                *w2 = temp;
            }
            w1++;
            w2++;
        }
    }
}

template <typename T>
void buble_sort_for_shorten_for_pointer(int n, T* tab)
{
    T *w1,*w2,temp;
    for (int i = 0; i < n; i++)
    {
        w1 = tab;
        w2 = w1 +1;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (*w1>*w2)
            {
                temp = *w1;
                *w1 = *w2;
                *w2 = temp;
            }
            w1++;
            w2++;
        }
    }
}

template <typename T>
T* generate_array_by_rand_min_max(int n,int min,int max)
{
    srand(time(0));
    
    T* tab = new T[n];
    
    for(int i=0;i<n;i++)
    {
        tab[i]=(rand()%(max-min+1)) + min;
    }
    return tab;
}

template <typename T>
T* generate_array_by_rand(int n)
{
    srand(time(0));
    
    T* tab = new T[n];
    
    for(int i=0;i<n;i++)
    {
        tab[i]=rand();
    }
    return tab;
}

template <typename T>
T* generate_array_by_random_min_max(int n,T min,T max)
{
    std::random_device rd;
    
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> distrib(min, max);
    
    T* tab = new T[n];
    
    for(int i=0;i<n;i++)
    {
        tab[i]=distrib(gen);
    }
    return tab;
}

template <typename T>
void przetestuj(void (*sorting_func)(int, T*), int n,const char* func_name)
{
    auto start = std::chrono::high_resolution_clock::now();
    
    T* tab = generate_array_by_rand<T>(n);
    
    if(check_if_sorted(n,tab))
    {
        std::cout<<"\nArray was already sorted";
        return;
    }
    
    sorting_func(n,tab);
    
    auto end = std::chrono::high_resolution_clock::now();
    
    if(!check_if_sorted(n,tab))
    {
        std::cout<<std::endl<<func_name<<" is not sorted";
        return;
    }
     auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    // std::cout<<"\nArray is sorted";

    std::cout<<std::endl<<func_name<<" "<<duration.count()<<" milliseconds";
    
    // cout_array(n,tab);
}
template <typename T>
void przetestuj_z_tablica(void (*sorting_func)(int, T*), int n,const char* func_name, T* tab)
{
    auto start = std::chrono::high_resolution_clock::now();
    
    if(check_if_sorted(n,tab))
    {
        std::cout<<"\nArray was already sorted";
        return;
    }
    
    sorting_func(n,tab);
    
    auto end = std::chrono::high_resolution_clock::now();
    
    if(!check_if_sorted(n,tab))
    {
        std::cout<<std::endl<<func_name<<" is not sorted";
        return;
    }
     auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    // std::cout<<"\nArray is sorted";

    std::cout<<std::endl<<func_name<<" "<<duration.count()<<" milliseconds";
    
    // cout_array(n,tab);
}
template <typename T>
void przetestuj_all(int n)
{
    T* tab = generate_array_by_rand(n);
    
    przetestuj_z_tablica<T>(&buble_sort_for_for_index<T>,n,FUNCTION_NAME(buble_sort_for_for_index), tab);
    
    przetestuj_z_tablica<T>(&buble_sort_while_for_index<T>,n,FUNCTION_NAME(buble_sort_while_for_index), tab);
    
    przetestuj_z_tablica<T>(&buble_sort_for_shorten_for_index<T>,n,FUNCTION_NAME(buble_sort_for_shorten_for_index), tab);
    
    przetestuj_z_tablica<T>(&buble_sort_for_for_pointer<T>,n,FUNCTION_NAME(buble_sort_for_for_pointer), tab);
    
    przetestuj_z_tablica<T>(&buble_sort_while_for_pointer<T>,n,FUNCTION_NAME(buble_sort_while_for_pointer), tab);
    
    przetestuj_z_tablica<T>(&buble_sort_for_shorten_for_pointer<T>,n,FUNCTION_NAME(buble_sort_for_shorten_for_pointer), tab);
}

int main()
{
    int n = 10000;
    
    przetestuj_all<double>(n);
    
}
