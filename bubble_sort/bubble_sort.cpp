#include "testing_func.h"
#include "testing_func.cpp"

int main()
{
    allDane dane;

    dane = przetestuj_z_typem_roznie<int>();

    auto dane_float = przetestuj_z_typem_roznie<float>().values;

    dane.values.insert(dane.values.begin(),dane_float.begin(),dane_float.end());

    SaveToFilePerRecord(dane);

    return 0;
}
