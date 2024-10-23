#include <iostream>

void buble_sort_for_for(int n, int* tab)
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
        std::cout << "Array length is over 30 elements, the console will show only 30 elements" << std::endl;
        n = 30;
    }
    std::cout<<"\nArray:"<<std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << tab[i] << std::endl;
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

int main()
{
    int n = 50;
    int* tab = new int[n] { 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

    buble_sort_for_for(n, tab);
    //buble_sort_while_for_index(n, tab);
    //buble_sort_for_shorten_for_index(n, tab);



    if (!check_if_sorted(n, tab))
    {
        std::cout << "Failed to sort array";
        return 1;
    }
    std::cout << "\nArray is sorted propery" << std::endl;

    cout_array(n, tab);
}