#include "generate_array_func.h"
#include <cstdlib>
#include <ctime>
#include <random>

template <typename T>
T* generate_array_by_rand_min_max(size_t n, int min, int max)
{
    srand(time(0));

    T* tab = new T[n];

    for (size_t i = 0; i < n; i++)
    {
        tab[i] = (rand() % (max - min + 1)) + min;
    }
    return tab;
}

template <typename T>
T* generate_array_by_rand(size_t n)
{
    srand(time(0));

    T* tab = new T[n];

    for (size_t i = 0; i < n; i++)
    {
        tab[i] = rand();
    }
    return tab;
}

template <typename T>
T* generate_array_by_random_min_max(size_t n, T min, T max)
{
    std::random_device rd;

    std::mt19937 gen(rd());

    std::uniform_int_distribution<> distrib(min, max);

    T* tab = new T[n];

    for (size_t i = 0; i < n; i++)
    {
        tab[i] = distrib(gen);
    }
    return tab;
}