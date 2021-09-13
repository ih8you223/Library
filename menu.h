#pragma once
#include "book.h"
#include "reader.h"
#include <string>
#include <set>
#include <list>

int menu(std::set<Book> &books,std::list<Reader> &readers, std::string &first_command);