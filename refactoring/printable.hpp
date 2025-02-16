#ifndef PRINTABLE_HPP
#define PRINTABLE_HPP

#include <string>

class HTMLPrintable {
public:
    virtual ~HTMLPrintable() = default;
    virtual std::string printAsHTML() const = 0;
};

class TextPrintable {
public:
    virtual ~TextPrintable() = default;
    virtual std::string printAsText() const = 0;
};

class JSONPrintable {
public:
    virtual ~JSONPrintable() = default;
    virtual std::string printAsJSON() const = 0;
};

#endif // PRINTABLE_HPP