#include <fstream>
#include <iostream>
#include <set>
#include "book.h"
#include <string>

int add_book(std::set<Book> &books){
    std::ofstream book("book.txt", std::ios::app);
    std::string book_name;
    std::cout << "\nEnter the title of the book you want to add to the library : ";
    std::cin.ignore(10000,'\n');
    std::getline(std::cin,book_name);
    auto it = books.begin();
    //Проверяем, есть ли уже в библиотеке книга с введенным нами названием, что бы не было дубля по названию.
    //Если название книги такое уже есть, она не добавится дублем и выведится , что такая книга уже имеется.
    for(auto i : books){
        if(i.name == book_name){
            std::cout << "\nThis book is already in the library.\n\n";
            return 0;
        }
    }
    std::cout << "\n\n";
    // Добавляем книгу в библиотеку с введенным названием
    Book add;
    add.name = book_name;
    books.insert(add);
    if(!book) return EXIT_FAILURE;
    book << book_name << "\n";
    return 0;
}