#pragma once
#include <string>

class Book final {
public:
    std::string name;
    bool operator<(const Book &one) const{
        bool result = this->name < one.name ;
        return result;
    }
};