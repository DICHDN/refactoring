#ifndef HTML_DATA_HPP
#define HTML_DATA_HPP

#include "printable.hpp"
#include <string>

class HTMLData : public HTMLPrintable {
public:
    explicit HTMLData(std::string data);
    std::string printAsHTML() const override;

private:
    std::string data_;
};

#endif // HTML_DATA_HPP