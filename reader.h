#pragma once
#include <string>
#include <array>

class Reader final{
public:
    static const int allowed_number_of_books{5};
    std::string name;
    std::array<std::string,allowed_number_of_books> arr;
    Reader(std::string name){
        this->name = name;
        this->arr.fill("");
    }
    Reader() = default;
    auto operator()(const std::string&name){
        this->name = name;
    }
};