#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <set>
#include "headers.h"



void return_book();


int menu(std::set<Book> &books,std::list<Reader> &readers, std::string &first_command){
    //Программа работает, пока в главном меню не будет введено Exit
    while(first_command != "Exit"){
        std::cout << "=================================  Menu  =================================" << std::endl;
        std::cout << "1. Display the books available in the library." << std::endl;
        std::cout << "2. Display all readers." << std::endl;
        std::cout << "3. Find book." << std::endl;
        std::cout << "4. Find reader." << std::endl;
        std::cout << "5. Add book." << std::endl;
        std::cout << "6. Add reader." << std::endl;
        std::cout << "7. Hand out the book to the reader." << std::endl;
        std::cout << "8. Return the reader's book." << std:: endl;
        std::cout << "9. See what books the reader has." << std::endl;
        std::cout << "To exit enter \"Exit\"." << std::endl;
        std::cout << "\nEnter action symbol : " ;
        //Вводим символ интересующего действия, если символ не из списка действий, то выводится информация об этом 
        // и начинается новая возможность ввести символ
        std::cin >> first_command;
        if(first_command == "1"){
            display_the_books(books);
        }
        else if(first_command == "2"){
            display_readers(readers);
        }
        else if(first_command == "3"){
            find_book(books);
        }
        else if(first_command == "4"){
            find_reader(readers);
        }
        else if(first_command == "5"){
            add_book(books);
        }
        else if(first_command == "6"){
            add_reader(readers);
        }
        else if(first_command == "7"){
            hand_out_the_book(books,readers);
        }
        else if(first_command == "8"){
            return_reader_book(books,readers);
        }
        else if(first_command == "9"){
            see_reader_books(readers);
        }
        else if(first_command == "Exit"){
            return 0;
        }
        else{
            std::cout <<"\nIncorrect symbol, try again.\n\n\n"<< std::endl;
        }
    }
    return 0;
}