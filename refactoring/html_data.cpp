#include "html_data.hpp"

HTMLData::HTMLData(std::string data) : data_(std::move(data)) {}

std::string HTMLData::printAsHTML() const {
    return "<html>" + data_ + "</html>";
}