#ifndef JSON_DATA_HPP
#define JSON_DATA_HPP

#include "printable.hpp"
#include <string>

class JSONData : public JSONPrintable {
public:
    explicit JSONData(std::string data);
    std::string printAsJSON() const override;

private:
    std::string data_;
};

#endif // JSON_DATA_HPP