#include <iostream>
#include <fstream>
#include "reader.h"
#include "book.h"
#include <set>
#include <list>
#include <string>

int return_reader_book(std::set<Book> &books,std::list<Reader> &readers){
    std::string reader_name;
    std::string book_name;
    std::string copy_book_name;
    const int max_book_count = 5;
    std::cout << "\nEnter the first and last name of the reader from whom you are accepting the book back : ";
    std::cin.ignore(10000,'\n');
    std::getline(std::cin,reader_name);
    bool check_reader = false;
    //Проверяем, есть ли в библиотеке читатель с введенным именем и фамилией, от которого хотим принять книгу обратно
    for(auto reader : readers){
        if(reader.name == reader_name){
            check_reader = true;
        }
    }
    //Если нету, выводим сообщение об этом и выходим в главное меню
    if(!check_reader){
        std::cout << "\nThere is no such reader.\n\n";
        return 0;
    }
    std::cout << "\nEnter the title of the book you want to return  : ";
    std::getline(std::cin,book_name);
    bool check_book = false;
    //Проверяем, есть ли у читателя книга с введенным названием
    for( auto book : readers){
        if(book.name == reader_name){
            for(int a = 0; a < max_book_count; a++){
                if(book.arr[a] == book_name){
                    check_book = true;
                }
            }
        }
    }
    //Если нету, выводим об этом сообщение и выходим в главное меню
    if(!check_book){
        std::cout << "\nThis reader does not have a book with that title. \n\n";
        return 0;
    }
    copy_book_name = book_name;
    //Удаляем название введенной книги у этого читателя
    for( auto reader1 : readers){
        if(reader1.name == reader_name){
            for(int a = 0; a < max_book_count; a++){
                if(reader1.arr[a] == book_name){
                    reader1.arr[a] = "";
                }
            }
        }
    }
    //Добавляем в файл с книгами библиотеки название той книги, которую принимаем от читателя
    std::ofstream out_book("book.txt", std::ios::app);
    if(!out_book) return EXIT_FAILURE;
    Book add;
    add.name = book_name;
    books.insert(add);
    out_book << book_name << "\n";
    out_book.close();
    //Перезаписываем файл с книгами читателя с учетом того, что забрали у него книгу с введенным названием
    std::ofstream out_reader_books("reader_books.txt",std::ios::out);
    if(!out_reader_books) return EXIT_FAILURE;
    for( auto reader2 : readers){
        if(reader2.name == reader_name){
            for( int r = 0; r < max_book_count; r++){
                if(reader2.arr[r] == book_name){
                    reader2.arr[r] = "";
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