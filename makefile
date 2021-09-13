main : main.o copying_data.o menu.o display_the_books.o display_readers.o find_book.o find_reader.o \
	add_book.o add_reader.o see_reader_books.o hand_out_the_book.o return_reader_book.o
	g++ main.cpp copying_data.cpp menu.cpp display_the_books.cpp display_readers.cpp find_book.cpp \
	add_book.cpp find_reader.cpp add_reader.cpp see_reader_books.cpp  hand_out_the_book.cpp \
	return_reader_book.cpp -o main
main.o : main.cpp
	g++ -c main.cpp -o main.o
copying_data.o : copying_data.cpp
	g++ -c copying_data.cpp -o copying_data.o
menu.o : menu.cpp
	g++ -c menu.cpp -o menu.o
display_the_books.o : display_the_books.cpp
	g++ -c display_the_books.cpp -o display_the_books.o
display_readers.o : display_readers.cpp
	g++ -c display_readers.cpp -o display_readers.o
find_book.o : find_book.cpp
	g++ -c find_book.cpp -o find_book.o
find_reader.o : find_reader.cpp
	g++ -c find_reader.cpp -o find_reader.o
add_book.o : add_book.cpp
	g++ -c add_book.cpp -o add_book.o
add_reader.o : add_reader.cpp
	g++ -c add_reader.cpp -o add_reader.o
see_reader_books.o : see_reader_books.cpp
	g++ -c see_reader_books.cpp -o see_reader_books.o
hand_out_the_book.o : hand_out_the_book.cpp
	g++ -c hand_out_the_book.cpp -o hand_out_the_book.o
return_reader_book.o : return_reader_book.cpp
	g++ -c return_reader_book.cpp -o return_reader_book.o
