#include "text_data.hpp"

TextData::TextData(std::string data) : data_(std::move(data)) {}

std::string TextData::printAsText() const {
    return data_;
}