#include <iostream>
#include <fstream>
#include "reader.h"
#include <list>
#include <string>



int add_reader(std::list<Reader> &readers){
    std::ofstream reader("reader.txt", std::ios::app);
    std::ofstream reader_books("reader_books.txt",std::ios::app);
    std::string reader_name;
    static int add_count = 0;
    const int reader_books_count = 5;
    std::cout << "\nEnter first and last name of the reader you want to add to the library : ";
    std::cin.ignore(10000,'\n');
    std::getline(std::cin,reader_name);
    auto it = readers.begin();
    //Проверяем, есть ли уже в библиотеке читатель с введенным нами именем и фамилией, что бы не было дубля.
    //Если имя и фамилия читателя такая уже есть, она не добавится дублем и выведится , что такой читатель уже есть.
    for(auto i : readers){
        if(i.name == reader_name){
            std::cout << "\nThis reader is already in the library.\n\n";
            return 0;
        }
    }
    std::cout << "\n\n";
    // Добавляем читателя в библиотеку с введенным именем и фамилией
    Reader add;
    add.name = reader_name;
    readers.push_front(add);
    if(!reader) return EXIT_FAILURE;
    if(!reader_books) return EXIT_FAILURE;
    reader << reader_name << "\n";
    for( int r = 0; r < reader_books_count; r++){
        reader_books << add.arr[r] << "\n";
    }
    return 0;
}