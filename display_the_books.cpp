#include <iostream>
#include <set>
#include <string>
#include "book.h"




int display_the_books(std::set<Book> &books){
    auto count = 0;
    std::cout << "\nBook list :\n";
    //Выводим название книг, которые есть в библиотеке
    for(auto book : books ){
        if( count == 0){
            ++count;
        }
        else{
            std::cout << count <<". " << book.name << std::endl;
            ++count;
        }
    }
    std::cout << "\nPress any key to return main menu...\n\n";
    std::cin.get();
    return 0;
}