#include <iostream>
#include <list>
#include <string>
#include "reader.h"

int display_readers(std::list<Reader> &readers){
    auto count = 1;
    std::cout << "\nReader list :\n";
    //Выводим в консоль имена и фамилии читателей
    for(auto reader : readers){
        if (reader.name == ""){
            std::cout << "\nPress any key to return main menu...\n\n";
            std::cin.get();
            return 0;
        }
        std::cout << count << ". " << reader.name << std::endl;
        ++count;
    }
    return 0;
}