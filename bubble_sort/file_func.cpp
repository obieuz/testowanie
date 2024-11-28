#include "file_func.h"

#include <iostream>
#include <iomanip>

void GenerateResults(daneContainer data) {
    std::string filePath = "C:\\Users\\robiz\\Desktop\\wyniki\\wyniki.txt";

    std::ofstream file(filePath);
    
    const int nameWidth = 40;
    const int timeWidth = 10;

    file << std::left << std::setw(nameWidth) << "Nazwa";
    file << std::setw(timeWidth) << "Typ";

    for (size_t i = 0; i < data.values[0].n.size(); i++)
    {
        file << std::setw(timeWidth) << data.values[0].n[i];
    }

    file << std::setw(timeWidth) << "CzyPosortowane";

    file << std::endl;

    for (int i = 0; i < data.values.size(); i++) {
        file << std::left << std::setw(nameWidth) << data.values[i].name;
        file << std::setw(timeWidth) << data.values[i].type;

        for (size_t j = 0; j < data.values[i].time.size(); ++j) {
            file << std::setw(timeWidth) << data.values[i].time[j] + "ms";
        }

        file << data.values[i].isSorted;

        file << std::endl;
    }
}

void GenerateInputAndOutput(daneContainer data)
{
    const int nameWidth = 40;

    std::string filePath = "C:\\Users\\robiz\\Desktop\\wyniki\\tablice[" + std::to_string(data.values[0].n[data.values[0].n.size() - 1]) + "].txt";

    std::ofstream fileTablice(filePath);

    const int tabWidth = 5;

    for (int j = 0; j < data.values.size(); j++)
    {
        fileTablice << std::left << std::setw(nameWidth) << "Nazwa";
        fileTablice << std::endl;

        fileTablice << std::setw(nameWidth) << data.values[j].name;

        fileTablice << std::endl;

        fileTablice << std::left << std::setw(nameWidth) << "Typ";
        fileTablice << std::endl;

        fileTablice << std::setw(nameWidth) << data.values[j].type;

        fileTablice << std::endl;

        fileTablice << std::setw(nameWidth) << "Input";
        fileTablice << std::endl;

        for (int i = 0; i < data.values[j].input.size(); i++)
        {
            fileTablice << data.values[j].input[i];
            fileTablice << " ";
        }

        fileTablice << std::endl;

        fileTablice << std::setw(nameWidth) << "Output";
        fileTablice << std::endl;

        for (int i = 0; i < data.values[j].output.size(); i++)
        {
            fileTablice << data.values[j].output[i];
            fileTablice << " ";
        }

        fileTablice << std::endl;
    }
}