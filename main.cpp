#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <set>
#include "copying_data.h"
#include "book.h"
#include "reader.h"
#include "menu.h"


int main(){
    std::set<Book> book;
    std::list<Reader> reader;
    std::string command;
    copying_data(book,reader);
    menu(book,reader,command);
}