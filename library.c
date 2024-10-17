#include "library.h"

#include <stdlib.h>
#include <string.h>

struct Book *createBook(char title[200+1], char author[200+1], char editor[200+1], int year, char category[200+1]) {
    struct Book *book = (struct Book*)malloc(sizeof(struct Book));

    strcpy(book->title, title);
    strcpy(book->author, author);
    strcpy(book->editor, editor);
    strcpy(book->category, category);
    book->year = year;
    book->next = NULL;

    return book;
}

void addBook(struct Book **start, char title[200+1], char author[200+1], char editor[200+1], char category[200+1],int year) {
    struct Book *newBook = createBook(title, author, editor, year, category);
    if(*start == NULL) {
        *start = newBook;
    }else {
        struct Book *current = *start;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = newBook;
    }
}


