#include "file_utils.hpp"

void saveTo(std::ofstream& file, const TextPrintable& printable) {
    file << printable.printAsText();
}

void saveTo(std::ofstream& file, const HTMLPrintable& printable) {
    file << printable.printAsHTML();
}

void saveTo(std::ofstream& file, const JSONPrintable& printable) {
    file << printable.printAsJSON();
}