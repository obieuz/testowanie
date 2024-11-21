#include "sorting_func.h"

template <typename T>
void bubble_sort_for_for_index(size_t n, T* tab)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (tab[i] < tab[j])
            {
                T savedValueFromFirstArray = tab[i];
                tab[i] = tab[j];
                tab[j] = savedValueFromFirstArray;
            }
        }
    }
}

template <typename T>
void bubble_sort_while_for_index(size_t n, T* tab)
{
    bool zamiana = true;
    while (zamiana)
    {
        zamiana = false;
        for (size_t i = 0; i < n - 1; i++)
        {
            if (tab[i] > tab[i + 1])
            {
                zamiana = true;
                T savedValueFromElement = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = savedValueFromElement;
            }
        }
    }
}

template <typename T>
void bubble_sort_for_shorten_for_index(size_t n, T* tab)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n - i - 1; j++)
        {
            if (tab[j] > tab[j + 1])
            {
                T savedValueFromElement = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = savedValueFromElement;
            }
        }
    }
}

template <typename T>
void bubble_sort_for_for_pointer(size_t n, T* tab)
{
    T* w1, * w2, temp;
    for (size_t i = 0; i < n; i++)
    {
        w1 = tab;
        w2 = w1 + 1;
        for (size_t j = 0; j < n - 1; j++)
        {
            if (*w1 > *w2)
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
void bubble_sort_while_for_pointer(size_t n, T* tab)
{
    bool zamiana = true;
    T* w1, * w2, temp;
    while (zamiana)
    {
        zamiana = false;
        w1 = tab;
        w2 = w1 + 1;

        for (size_t i = 0; i < n - 1; i++)
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
void bubble_sort_for_shorten_for_pointer(size_t n, T* tab)
{
    T* w1, * w2, temp;
    for (size_t i = 0; i < n; i++)
    {
        w1 = tab;
        w2 = w1 + 1;
        for (size_t j = 0; j < n - i - 1; j++)
        {
            if (*w1 > *w2)
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

