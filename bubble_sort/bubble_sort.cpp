#include "testing_func.h"
#include "testing_func.cpp"

int main()
{
    daneContainer dane;

    std::vector<size_t> vector_n;
    vector_n.push_back(100);
    vector_n.push_back(1000);
    vector_n.push_back(500);

    dane = przetestuj_z_typem_roznie<int>(vector_n);

    auto dane_float = przetestuj_z_typem_roznie<float>(vector_n).values;

    dane.values.insert(dane.values.begin(),dane_float.begin(),dane_float.end());

    GenerateResults(dane);

    GenerateInputAndOutput(dane);

    return 0;
}
