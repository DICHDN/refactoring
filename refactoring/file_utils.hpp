#ifndef FILE_UTILS_HPP
#define FILE_UTILS_HPP

#include <fstream>
#include "printable.hpp"

void saveTo(std::ofstream& file, const TextPrintable& printable);
void saveTo(std::ofstream& file, const HTMLPrintable& printable);
void saveTo(std::ofstream& file, const JSONPrintable& printable);

#endif // FILE_UTILS_HPP