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
void przetestuj(void (*sorting_func)(size_t, T*), size_t n, std::string func_name, dane* data)
{
    T* tab = generate_array_by_rand<T>(n);

    if (check_if_sorted(n, tab))
    {
        std::cout << "\n" << func_name << " was already sorted"<<std::endl;
        data->isSorted = false;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        data->input.push_back(std::to_string(tab[i]));
    }

    auto start = std::chrono::high_resolution_clock::now();

    sorting_func(n, tab);

    auto end = std::chrono::high_resolution_clock::now();

    for (int j = 0; j < n; j++)
    {
        data->output.push_back(std::to_string(tab[j]));
    }

    if (!check_if_sorted(n, tab))
    {
        std::cout << std::endl << func_name << " is not sorted" << std::endl;
        data->isSorted = false;
        return;
    }

    data->isSorted = true;
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    data->time.push_back(std::to_string(duration.count()));

    std::cout << std::endl << func_name << " ilosc " << n << " Czas :" << duration.count() << " milliseconds" << " Typ : "<< data->type;

}

template <typename T>
void przetestuj_z_tablica(void (*sorting_func)(size_t, T*), std::string func_name, size_t n, T* tab, dane* data)
{
    if (check_if_sorted(n, tab))
    {
        std::cout << "\n" << func_name << " was already sorted"<<std::endl;
        data->isSorted = false;
        return;
    }

    auto start = std::chrono::high_resolution_clock::now();

    sorting_func(n, tab);

    auto end = std::chrono::high_resolution_clock::now();

    if (!check_if_sorted(n, tab))
    {
        std::cout << std::endl << func_name << " is not sorted" << std::endl;
        data->isSorted = false;
        return;
    }
    data->isSorted = true;
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    data->time.push_back(std::to_string(duration.count()));

    std::cout << std::endl << func_name << " ilosc " << n << " Czas :" << duration.count() << " milliseconds" << " Typ : "<< data->type;


}

template <typename T>
dane przetestuj_z_tablica_rozne(void (*sorting_func)(size_t, T*), std::string func_name, std::vector<size_t> vector_n)
{
    dane* data = new dane();

    data->name = func_name;
    data->type = typeid(T).name();

    for (int i = 0; i < vector_n.size(); i++)
    {
        size_t n = vector_n[i];
        data->n.push_back(n);
        przetestuj(sorting_func, n, func_name, data);
    }
    return *data;
}

template <typename T>
daneContainer przetestuj_z_typem_roznie(std::vector<size_t> vector_n)
{
    daneContainer dane;

    dane.values.push_back(przetestuj_z_tablica_rozne<T>(&bubble_sort_for_for_index, FUNCTION_NAME(bubble_sort_for_for_index), vector_n));

    dane.values.push_back(przetestuj_z_tablica_rozne<T>(&bubble_sort_for_for_pointer, FUNCTION_NAME(bubble_sort_for_for_pointer), vector_n));

    dane.values.push_back(przetestuj_z_tablica_rozne<T>(&bubble_sort_for_shorten_for_index, FUNCTION_NAME(bubble_sort_for_shorten_for_index), vector_n));

    dane.values.push_back(przetestuj_z_tablica_rozne<T>(&bubble_sort_for_shorten_for_pointer, FUNCTION_NAME(bubble_sort_for_shorten_for_pointer), vector_n));

    dane.values.push_back(przetestuj_z_tablica_rozne<T>(&bubble_sort_while_for_index, FUNCTION_NAME(bubble_sort_while_for_index), vector_n));

    dane.values.push_back(przetestuj_z_tablica_rozne<T>(&bubble_sort_while_for_pointer, FUNCTION_NAME(bubble_sort_while_for_pointer), vector_n));

    return dane;
}


