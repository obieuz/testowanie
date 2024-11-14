#include "testing_func.h"
#include "sorting_func.h"
#include "generate_array_func.h"
#include "sorting_func.cpp"
#include "generate_array_func.cpp"

#include <iostream>
#include <chrono>

#define FUNCTION_NAME(func) #func

template <typename T>
void copyArray(T* source, T* destination, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        destination[i] = source[i];
    }
}

template <typename T>
bool check_if_sorted(size_t n, T* tab)
{
    for (size_t i = 0; i < n - 1; i++)
    {
        if (tab[i] > tab[i + 1])
        {
            return false;
        }
    }
    return true;
}

template <typename T>
void cout_array(size_t n, T* tab)
{
    if (n > 30)
    {
        std::cout << "\nArray length is over 30 elements, the console will show only 30 elements" << std::endl;
        n = 30;
    }
    std::cout << "\nArray:" << std::endl;
    for (size_t i = 0; i < n; i++)
    {
        std::cout << i << "\t" << tab[i] << std::endl;
    }
}

template <typename T>
void przetestuj(void (*sorting_func)(size_t, T*), size_t n, const char* func_name)
{
    auto start = std::chrono::high_resolution_clock::now();

    T* tab = generate_array_by_rand<T>(n);

    if (check_if_sorted(n, tab))
    {
        std::cout << "\nArray was already sorted";
        return;
    }

    sorting_func(n, tab);

    auto end = std::chrono::high_resolution_clock::now();

    if (!check_if_sorted(n, tab))
    {
        std::cout << std::endl << func_name << " is not sorted";
        return;
    }
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    // std::cout<<"\nArray is sorted";

    std::cout << std::endl << func_name << " " << duration.count() << " milliseconds";

    // cout_array(n,tab);
}

template <typename T>
void przetestuj_z_tablica(void (*sorting_func)(size_t, T*), size_t n, const char* func_name, T* tab)
{
    auto start = std::chrono::high_resolution_clock::now();

    if (check_if_sorted(n, tab))
    {
        std::cout << "\nArray was already sorted";
        return;
    }

    sorting_func(n, tab);

    auto end = std::chrono::high_resolution_clock::now();

    if (!check_if_sorted(n, tab))
    {
        std::cout << std::endl << func_name << " is not sorted";
        return;
    }
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << std::endl << func_name << " " << duration.count() << " milliseconds";

}

template <typename T>
void przetestuj_all(size_t n)
{
    std::cout << "\nArray length: " << n << std::endl;

    przetestuj<T>(&bubble_sort_for_for_index<T>, n, FUNCTION_NAME(bubble_sort_for_for_index));
    przetestuj<T>(&bubble_sort_for_for_pointer<T>, n, FUNCTION_NAME(bubble_sort_for_for_pointer));
    przetestuj<T>(&bubble_sort_for_shorten_for_index<T>, n, FUNCTION_NAME(bubble_sort_for_shorten_for_index));
    przetestuj<T>(&bubble_sort_for_shorten_for_pointer<T>, n, FUNCTION_NAME(bubble_sort_for_shorten_for_pointer));
    przetestuj<T>(&bubble_sort_while_for_index<T>, n, FUNCTION_NAME(bubble_sort_while_for_index));
    przetestuj<T>(&bubble_sort_while_for_pointer<T>, n, FUNCTION_NAME(bubble_sort_while_for_pointer));
}

template <typename T>
void przetestuj_all_z_tablica(size_t n)
{
    std::cout << "\nArray length: " << n << std::endl;

    T* tab = generate_array_by_rand<T>(n);
    T* copied = new T[n];



    copyArray(tab, copied, n);
    przetestuj_z_tablica<T>(&bubble_sort_for_for_pointer<T>, n, FUNCTION_NAME(bubble_sort_for_for_pointer), copied);

    copyArray(tab, copied, n);
    przetestuj_z_tablica<T>(&bubble_sort_for_for_pointer<T>, n, FUNCTION_NAME(bubble_sort_for_for_pointer), copied);

    copyArray(tab, copied, n);
    przetestuj_z_tablica<T>(&bubble_sort_for_shorten_for_index<T>, n, FUNCTION_NAME(bubble_sort_for_shorten_for_index), copied);

    copyArray(tab, copied, n);
    przetestuj_z_tablica<T>(&bubble_sort_for_shorten_for_pointer<T>, n, FUNCTION_NAME(bubble_sort_for_shorten_for_pointer), copied);

    copyArray(tab, copied, n);
    przetestuj_z_tablica<T>(&bubble_sort_while_for_index<T>, n, FUNCTION_NAME(bubble_sort_while_for_index), copied);

    copyArray(tab, copied, n);
    przetestuj_z_tablica<T>(&bubble_sort_while_for_pointer<T>, n, FUNCTION_NAME(bubble_sort_while_for_pointer), copied);
}


