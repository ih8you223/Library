#include <iostream>
#include <set>
#include <string>
#include "book.h"


int find_book(std::set<Book> &books){
    std::string str;
    std::cout << "\nEnter the title of the book you are looking for : ";
    std::cin.ignore(10000,'\n');
    std::getline(std::cin,str);
    bool check = false;
    //Проверяем, есть ли книга по введенному названию в библиотеке или нет, выводим результат
    for(auto book : books){
        if( book.name == str){
            std::cout << "\nThis book is in the library. " <<std::endl;
            check = true;
        }
    }
    if(!check){
        std::cout << "\nThis book is not in the library." << std::endl;
    }
    std::cout << "\nPress any key to return main menu...\n\n";
    std::cin.get();
    return 0;
}