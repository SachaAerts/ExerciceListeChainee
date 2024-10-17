//
// Created by sacha on 17-10-24.
//

#ifndef LIBRARY_H
#define LIBRARY_H

struct Book{
    char title[200+1];
    char author[200+1];
    char editor[200+1];
    int year;
    char category[100+1];
    struct Book* next;
};

struct Book *createBook(char title[200+1], char author[200+1], char editor[200+1], int year, char category[200+1]);

struct Book *addBook(struct Book *book);

#endif //LIBRARY_H
