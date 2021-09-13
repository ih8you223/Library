#include <iostream>
#include <list>
#include <string>
#include "reader.h"

int see_reader_books(std::list<Reader> &readers){
    std::string reader_name;
    std::cout << "\nEnter the first and last name of the reader : ";
    std::cin.ignore(10000,'\n');
    std::getline(std::cin,reader_name);
    auto it = readers.begin();
    std::cout << "\nA list of the reader's books " << reader_name << std::endl;
    //Выводим книги, которые есть у читателя по введенному имени и фамилии, если такого читателя нету
    //тогда выводим об этом сообщение и выходим в главное меню
    for(auto reader : readers){
        if(reader.name == reader_name){
            int count = 1;
            for(auto j : reader.arr){
                std::cout << count << ". " << j << std::endl;
                ++count;
            }
            std::cout << "\nPress any key to return main menu.\n";
            std::cin.get();
            return 0;
        }
    }
    std::cout << "\nThere is no such reader.\n\n";
    return 0;
}