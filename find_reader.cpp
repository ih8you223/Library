#include <iostream>
#include "reader.h"
#include <list>
#include <string>

int find_reader(std::list<Reader> &readers){
    std::string str;
    std::cout << "\nEnter the first and last name of the reader you are looking for : ";
    std::cin.ignore(10000,'\n');
    std::getline(std::cin,str);
    bool check = false;
    //Проверяем, есть ли читатель по введенному имени и фамилии в библиотеке или нет, выводим результат
    for(auto reader : readers){
        if( reader.name == str){
            std::cout << "\nThis reader is found. " <<std::endl;
            check = true;
        }
    }
    if(!check){
        std::cout << "\nThis reader is not found ." << std::endl;
    }
    std::cout << "\nPress any key to return main menu...\n\n";
    std::cin.get();
    return 0;
}