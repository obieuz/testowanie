#include <vector>
#include <string>
#ifndef TESTING_FUNC_H
#define TESTING_FUNC_H

struct dane {
    std::string name;
    std::vector<size_t> n;
    std::vector<std::string> time;
    std::string type;
};

struct allDane {
    std::vector<dane> values;
};

template <typename T>
void przetestuj_all_z_tablica(size_t n);

template <typename T>
void przetestuj_all(size_t n);

template <typename T>
void przetestuj_z_tablica(void (*sorting_func)(size_t, T*), std::string func_name, size_t n, T* tab, dane* data);

template <typename T>
dane przetestuj_z_tablica_rozne(void (*sorting_func)(size_t, T*), std::string func_name);

template <typename T>
void przetestuj(void (*sorting_func)(size_t, T*), size_t n, const char* func_name);

template <typename T>
void cout_array(size_t n, T* tab);

template <typename T>
bool check_if_sorted(size_t n, T* tab);

template <typename T>
void copyArray(T* source, T* destination, size_t size);








#endif
