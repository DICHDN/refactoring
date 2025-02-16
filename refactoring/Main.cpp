#include <fstream>
#include "html_data.hpp"
#include "text_data.hpp"
#include "json_data.hpp"
#include "file_utils.hpp"

int main() {
    std::ofstream htmlFile("output.html");
    std::ofstream textFile("output.txt");
    std::ofstream jsonFile("output.json");

    HTMLData htmlData("Hello, World!");
    TextData textData("Hello, World!");
    JSONData jsonData("Hello, World!");

    saveTo(htmlFile, htmlData);
    saveTo(textFile, textData);
    saveTo(jsonFile, jsonData);

    return 0;
}