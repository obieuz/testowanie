#ifndef TESTING_FUNC_H
#define TESTING_FUNC_H

template <typename T>
void przetestuj_all_z_tablica(size_t n);

template <typename T>
void przetestuj_all(size_t n);

template <typename T> 
void przetestuj_z_tablica(void (*sorting_func)(size_t, T*), size_t n, const char* func_name, T* tab);

template <typename T>
void przetestuj(void (*sorting_func)(size_t, T*), size_t n, const char* func_name);

template <typename T>
void cout_array(size_t n, T* tab);

template <typename T>
bool check_if_sorted(size_t n, T* tab);

template <typename T>
void copyArray(T* source, T* destination, size_t size);








#endif
