#include "testing_func.h"
#include "sorting_func.h"
#include "file_func.h"
#include "generate_array_func.h"
#include "sorting_func.cpp"
#include "generate_array_func.cpp"

#include <iostream>
#include <chrono>
#include <typeinfo>

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
    std::cout << std::endl << func_name << " : " << duration.count() << " milliseconds";

    // cout_array(n,tab);
}

template <typename T>
void przetestuj_z_tablica(void (*sorting_func)(size_t, T*), std::string func_name, size_t n, T* tab, dane* data)
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

    data->time.push_back(std::to_string(duration.count()));

    std::cout << std::endl << func_name << " ilosc " << n << " " << duration.count() << " milliseconds";


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
    //std::cout << "\nArray length: " << n << std::endl;

    //T* tab = generate_array_by_rand<T>(n);
    /*T* copied = new T[n];

    std::string* fileContent = new std::string();

    *fileContent += typeid(T).name();

    *fileContent +=" | " + std::to_string(n) + " |\n";

    copyArray(tab, copied, n);
    *fileContent += FUNCTION_NAME(bubble_sort_for_for_pointer);
    przetestuj_z_tablica<T>(&bubble_sort_for_for_pointer<T>, n, FUNCTION_NAME(bubble_sort_for_for_pointer), copied, fileContent);

    copyArray(tab, copied, n);
    *fileContent += FUNCTION_NAME(bubble_sort_for_for_index);
    przetestuj_z_tablica<T>(&bubble_sort_for_for_index<T>, n, FUNCTION_NAME(bubble_sort_for_for_index), copied, fileContent);

    copyArray(tab, copied, n);
    *fileContent += FUNCTION_NAME(bubble_sort_for_shorten_for_index);
    przetestuj_z_tablica<T>(&bubble_sort_for_shorten_for_index<T>, n, FUNCTION_NAME(bubble_sort_for_shorten_for_index), copied, fileContent);

    copyArray(tab, copied, n);
    *fileContent += FUNCTION_NAME(bubble_sort_for_shorten_for_pointer);
    przetestuj_z_tablica<T>(&bubble_sort_for_shorten_for_pointer<T>, n, FUNCTION_NAME(bubble_sort_for_shorten_for_pointer), copied, fileContent);

    copyArray(tab, copied, n);
    *fileContent += FUNCTION_NAME(bubble_sort_while_for_index);
    przetestuj_z_tablica<T>(&bubble_sort_while_for_index<T>, n, FUNCTION_NAME(bubble_sort_while_for_index), copied, fileContent);

    copyArray(tab, copied, n);
    *fileContent += FUNCTION_NAME(bubble_sort_while_for_pointer);
    przetestuj_z_tablica<T>(&bubble_sort_while_for_pointer<T>, n, FUNCTION_NAME(bubble_sort_while_for_pointer), copied, fileContent);

    std::cout <<std::endl <<*fileContent;

    SaveToFile(fileContent);*/
}

template <typename T>
dane przetestuj_z_tablica_rozne(void (*sorting_func)(size_t, T*), std::string func_name)
{
    dane* data = new dane();

    data->name = func_name;
    data->type = typeid(T).name();

    size_t n = 100;
    data->n.push_back(n);
    T* tab = generate_array_by_rand<T>(n);

    przetestuj_z_tablica(sorting_func, func_name , n, tab, data);

    n = 1000;
    data->n.push_back(n);
    tab = generate_array_by_rand<T>(n);

    przetestuj_z_tablica(sorting_func,func_name, n, tab, data);

    n = 10000;
    data->n.push_back(n);
    tab = generate_array_by_rand<T>(n);

    przetestuj_z_tablica(sorting_func, func_name, n, tab, data);

    return *data;
}

template <typename T>
allDane przetestuj_z_typem_roznie()
{
    allDane dane;

    dane.values.push_back(przetestuj_z_tablica_rozne<T>(&bubble_sort_for_for_index, FUNCTION_NAME(bubble_sort_for_for_index)));

    dane.values.push_back(przetestuj_z_tablica_rozne<T>(&bubble_sort_for_for_pointer, FUNCTION_NAME(bubble_sort_for_for_pointer)));

    dane.values.push_back(przetestuj_z_tablica_rozne<T>(&bubble_sort_for_shorten_for_index, FUNCTION_NAME(bubble_sort_for_shorten_for_index)));

    dane.values.push_back(przetestuj_z_tablica_rozne<T>(&bubble_sort_for_shorten_for_pointer, FUNCTION_NAME(bubble_sort_for_shorten_for_pointer)));

    dane.values.push_back(przetestuj_z_tablica_rozne<T>(&bubble_sort_while_for_index, FUNCTION_NAME(bubble_sort_while_for_index)));

    dane.values.push_back(przetestuj_z_tablica_rozne<T>(&bubble_sort_while_for_pointer, FUNCTION_NAME(bubble_sort_while_for_pointer)));

    return dane;
}


