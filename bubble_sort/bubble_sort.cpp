#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

void buble_sort_for_for_index(int n, int* tab)
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

bool check_if_sorted(int n, int* tab)
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

void cout_array(int n, int* tab)
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

void buble_sort_while_for_index(int n, int* tab)
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

void buble_sort_for_shorten_for_index(int n, int* tab)
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

void buble_sort_for_for_pointer(int n, int* tab)
{
    int *w1,*w2,temp;
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

void buble_sort_while_for_pointer(int n, int* tab)
{
    bool zamiana = true;
    int *w1,*w2,temp;
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

void buble_sort_for_shorten_for_pointer(int n, int* tab)
{
    int *w1,*w2,temp;
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

int* generate_array_by_rand_min_max(int n,int min,int max)
{
    srand(time(0));
    
    int* tab = new int[n];
    
    for(int i=0;i<n;i++)
    {
        tab[i]=(rand()%(max-min+1)) + min;
    }
    return tab;
}

int* generate_array_by_rand(int n)
{
    srand(time(0));
    
    int* tab = new int[n];
    
    for(int i=0;i<n;i++)
    {
        tab[i]=rand();
    }
    return tab;
}

int* generate_array_by_random_min_max(int n,int min,int max)
{
    std::random_device rd;
    
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> distrib(min, max);
    
    int* tab = new int[n];
    
    for(int i=0;i<n;i++)
    {
        tab[i]=distrib(gen);
    }
    return tab;
}

void przetestuj(int n, void (*sorting_func)(int, int*))
{
    int* tab =generate_array_by_rand_min_max(n,10,100);
    
    if(check_if_sorted(n,tab))
    {
        std::cout<<"\nArray was already sorted";
        return;
    }
    
    sorting_func(n,tab);
    
    if(!check_if_sorted(n,tab))
    {
        std::cout<<"\nArray is not sorted";
        return;
    }
    std::cout<<"\nArray is sorted";
    
    cout_array(n,tab);
    
}
    
// int* generate_array_by_intel_min_max(int n,int min,int max)
// {
//     int* tab = new int[n];
        
//     VSLStreamStatePtr stream;
//     vslNewStream(&stream, VSL_BRNG_MT19937, 0);
    
//     viRngUniform(VSL_RNG_METHOD_UNIFORM_STD, stream, n, tab, min, max);

//     std::uniform_int_distribution<> distrib(min, max);

//     return tab;
    
//     cout_array(n,tab);
// }

int main()
{
    int n = 50;
    //int* tab = new int[n];
    
    // do{
    //     tab = generate_array_by_random_min_max(n,0,100);
    // }while(check_if_sorted(n,tab));
    
    przetestuj(n,&buble_sort_for_shorten_for_pointer);
    

    //buble_sort_for_for_index(n, tab);
    //buble_sort_while_for_index(n, tab);
    //buble_sort_for_shorten_for_index(n, tab);
    
    //buble_sort_for_for_pointer(n, tab);
    //buble_sort_while_for_pointer(n, tab);
    // buble_sort_for_shorten_for_pointer(n, tab);
    

    // if (!check_if_sorted(n, tab))
    // {
    //     std::cout << "Failed to sort array";
    //     return 1;
    // }
    // std::cout << "\nArray is sorted propery" << std::endl;

    // cout_array(n, tab);
}
