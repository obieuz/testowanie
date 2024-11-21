#include "file_func.h"

#include <iostream>
#include <iomanip>

void SaveToFilePerRecord(allDane data) {
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

    file << std::endl;

    for (int i = 0; i < data.values.size(); i++) {
        file << std::left << std::setw(nameWidth) << data.values[i].name;
        file << std::setw(timeWidth) << data.values[i].type;

        for (size_t j = 0; j < data.values[i].time.size(); ++j) {
            file << std::setw(timeWidth) << data.values[i].time[j];
        }

        file << std::endl;
    }

    
}

std::string GetFileContent(std::string filePath)
{
    std::ifstream file(filePath);
    if (!file) {
        std::cerr << "Could not open the file!" << std::endl;
        return "Nie otwarto pliku";
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string content = buffer.str();

    file.close();
    return content;
}