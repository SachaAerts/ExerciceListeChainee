#include "library.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Book *createBook(char title[200+1], char author[200+1], char editor[200+1], const int year, char category[100+1]) {
    struct Book *book = (struct Book*)malloc(sizeof(struct Book));
    if(book == NULL) {
        perror("Error in creating new book");
        exit(EXIT_FAILURE);
    }

    strcpy(book->title, title);
    strcpy(book->author, author);
    strcpy(book->editor, editor);
    strcpy(book->category, category);
    book->year = year;
    book->next = NULL;

    return book;
}

void addBook(struct Book **start, char title[200+1], char author[200+1], char editor[200+1], char category[100+1],int year) {
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

struct Book *searchBook(const char title[200 + 1], struct Book *start) {
    struct Book *current = start;
    if (start == NULL) {
        printf("Aucun livre trouvé, la liste est vide.\n");
        return NULL;
    }

    while(current != NULL) {
        if(strcmp(current->title, title) == 0) {
            return current;
        }
        current = current->next;
    }
    printf("Aucun livre de ce nom n'a été trouvé\n");
    return NULL;
}

void changeCategory(struct Book *book, char newCategory[100+1]) {
    strcpy(book->category, newCategory);
}

void selectBookByCategory(struct Book *start, char category[100+1]) {
    struct Book *current = start;
    int counter = 0;
    while(current != NULL) {
        if(strcmp(current->category, category) == 0) {
            showBook(current);
            counter++;
        }
        current = current->next;
    }
    if(counter == 0) {
        printf("Aucun livre ne correspond à la catégorie choisie");
    }
}

void showBook(struct Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Editor: %s\n", book->editor);
    printf("Category: %s\n", book->category);
    printf("\n");
}

void destroyList(struct Book *start) {
    struct Book *current = start;
    struct Book *next;
    while(current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}