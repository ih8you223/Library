#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <set>
#include "book.h"
#include "reader.h"

int copying_data(std::set<Book> &books,std::list<Reader> &readers){
    std::ifstream book("book.txt");
    std::ifstream reader("reader.txt");
    std::ifstream reader_books("reader_books.txt");
    std::string book_name;
    std::string reader_name;
    Reader lucky;
    const int the_maximum_number_of_books_a_student_has {5};
    if(!book) return EXIT_FAILURE;
    if(!reader) return EXIT_FAILURE;
    if(!reader_books) return EXIT_FAILURE;
    //Считываем все данные с книгами из файла в программу
    while(!book.eof()){
        book_name = "";
        getline(book,book_name);
        Book first;
        first.name = book_name;
        books.insert(first);
    }
    //Считываем все данные с читателями из файла в программу
    while(!reader.eof()){
        reader_name = "";
        getline(reader,reader_name);
        lucky(reader_name);
        readers.push_back(lucky);
    }
    //Считываем все данные о книгах, которые есть у читателей из файла в программу
    while(!reader_books.eof()){
        book_name = "";
        for(auto it = readers.begin(); it != readers.end(); it++ ){
            for(int j = 0 ; j < the_maximum_number_of_books_a_student_has; j++){
                getline(reader_books,book_name);
                it->arr[j] = book_name;
            }
            if(it->name == ""){
                return 0;
            }
        }
    }
    return 0;
}