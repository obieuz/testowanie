#ifndef FILE_FUNC_H
#define FILE_FUNC_H

#include <string> 
#include <fstream>
#include <sstream>
#include "testing_func.h"

void SaveToFilePerRecord(allDane data);

std::string GetFileContent(std::string filePath);


#endif