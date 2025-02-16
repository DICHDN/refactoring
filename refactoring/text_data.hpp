#ifndef TEXT_DATA_HPP
#define TEXT_DATA_HPP

#include "printable.hpp"
#include <string>

class TextData : public TextPrintable {
public:
    explicit TextData(std::string data);
    std::string printAsText() const override;

private:
    std::string data_;
};

#endif // TEXT_DATA_HPP