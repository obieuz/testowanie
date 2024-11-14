#include "testing_func.h"
#include "testing_func.cpp"

int main()
{
    size_t n = 10000;
    
    przetestuj_all_z_tablica<double>(n);
    return 0;
}
