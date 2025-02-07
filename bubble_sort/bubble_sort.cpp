#include "testing_func.h"
#include "testing_func.cpp"
#include <string>

int main(int argc, char* argv[])
{
    if (argc != 2) {
		std::cout << "Add number of elements to sort" << std::endl;
        return 1;
    }

    //std::ofstream logFile("C:\\Users\\robiz\\Desktop\\testowanie_sortowanie_cpp\\console_output.log");
    //if (!logFile) {
    //    std::cerr << "Unable to open log file" << std::endl;
    //    return 1;
    //}

    //std::streambuf* coutBuf = std::cout.rdbuf();
    //std::cout.rdbuf(logFile.rdbuf());

    daneContainer dane;

    std::vector<size_t> vector_n;
    vector_n.push_back(std::stoi(argv[1]));

    dane = przetestuj_z_typem_roznie<int>(vector_n);

    auto dane_float = przetestuj_z_typem_roznie<float>(vector_n).values;

    dane.values.insert(dane.values.begin(),dane_float.begin(),dane_float.end());

    GenerateResults(dane);

    GenerateInputAndOutput(dane);

    //std::cout.rdbuf(coutBuf);

    return 0;
}
