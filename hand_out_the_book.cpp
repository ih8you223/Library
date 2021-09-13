#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <list>
#include "reader.h"
#include "book.h"

int hand_out_the_book(std::set<Book> &books,std::list<Reader> &readers){
    std::ofstream out_book("book.txt", std::ios::app);
    if(!out_book) return EXIT_FAILURE;
    const int max_book_count = 5;
    std::string book_name;
    std::string reader_name;
    std::cout << "\nEnter the first and last name of the reader to whom you want to issue the book : ";
    std::cin.ignore(10000,'\n');
    std::getline(std::cin,reader_name);
    bool check_reader = false;
    //Проверяем, есть ли в библиотеке читатель с введенным именем и фамилией, которому хотим выдать книгу
    for(auto reader3 : readers){
        if(reader3.name == reader_name){
            check_reader = true;
        }
    }
    //Если нету, выводим сообщение об этом и выходим в главное меню
    if(!check_reader){
        std::cout << "\nThere is no such reader.\n\n";
        return 0;
    }
    std::cout << "\nEnter the title of the book you want to give out to the reader : ";
    std::getline(std::cin,book_name);
    bool check_book = false;
    //Проверяем, если ли в библиотеке книга с введенным названием, которую мы хотим выдать
    for(auto reader : books){
        if(reader.name == book_name){
            check_book = true;
        }
    }
    //Если нету, выводим сообщение об этом и выходим в главное меню
    if(!check_book){
        std::cout << "\nNo books with this name have been found .\n\n";
        return 0;
    }
    std::string copy_book_name = book_name;
    //Проверяем, можно ли выдать читателю книгу, максимум на руках у читателя может быть не более 5 книг
    //Если у него уже есть 5 книг, ему выдать новую книгу нельзя, выводим об этом сообщение и выходим в главное меню
    for( auto reader1 : readers){
        if(reader1.name == reader_name){
            if(reader1.arr[0] != "" && reader1.arr[1] != "" && reader1.arr[2] != "" && reader1.arr[3] != "" && reader1.arr[4] != "" ){
                std::cout << "\nThe reader already has the maximum number of books, a new one cannot be issued\n\n.";
                return 0;
            }
        }
    }
    out_book.close();
    //Удаляем из доступных книг в библиотеке книгу, которую выдаем читателю
    Book temporary;
    for(auto &temporary_book : books){
        if(temporary_book.name == book_name){
            temporary = temporary_book;
        }
    }
    books.erase(temporary);
    //Перезаписываем данные о книгах в библиотеке с учетом того, что книга выдана читателю и она не доступна
    std::ofstream copy_book("book.txt");
    if(!copy_book) return EXIT_FAILURE;
    for(auto u : books){
        if(u.name != ""){
            copy_book << u.name << "\n";
        }
    }
    copy_book.close();
    //Переписываем данные в файле с книгами студентов с учетом того, что выдали ему книгу
    std::ofstream out_reader_books("reader_books.txt",std::ios::out);
    if(!out_reader_books) return EXIT_FAILURE;
    for( auto reader2 : readers){
        if(reader2.name == reader_name){
            for( int r = 0; r < max_book_count; r++){
                if(reader2.arr[r] == ""){
                    reader2.arr[r] = book_name;
                    out_reader_books << reader2.arr[r] << "\n";
                    book_name = "";
                }
                else{
                    out_reader_books << reader2.arr[r] << "\n";
                } 
            }
        }
        else if(reader2.name == ""){
            break;
        }
        else{
            for( int x = 0; x < max_book_count; x++){
                out_reader_books << reader2.arr[x] << "\n";
            }
        }
    }
    out_reader_books.close();
    book_name = copy_book_name;
    //Считываем актуальные данные с файла по книгам читателей, которые у них есть и выходим в главное меню.
    std::ifstream in_reader_books("reader_books.txt", std::ios::out);
    if(!in_reader_books) return EXIT_FAILURE;
    while(!in_reader_books.eof()){
        std::string empty_book_name = "";
        for(auto it = readers.begin(); it != readers.end(); it++ ){
            for(int j = 0 ; j < max_book_count; j++){
                getline(in_reader_books,book_name);
                if(book_name == empty_book_name ){
                    it->arr[j] = empty_book_name;
                }
                else{
                    it->arr[j] = book_name;
                }
            }
            if(it->name == ""){
                std::cout << "\nPress any key to return main menu.\n\n";
                std::cin.get();
                return 0;
            }
        }
    }
    return 0;
}