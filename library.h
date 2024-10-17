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

struct Book *createBook(char title[200+1], char author[200+1], char editor[200+1], int year, char category[100+1]);

void addBook(struct Book **start, char title[200+1], char author[200+1], char editor[200+1], char category[100+1],int year);

void destroyList(struct Book *start);

struct Book *searchBook(const char title[200 + 1], struct Book *start);

void selectBookByCategory(struct Book *start, char category[100+1]);

void showBook(struct Book *book);

void changeCategory(struct Book *book, char newCategory[100+1]);

#endif