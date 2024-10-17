#include <stdio.h>

#include "menu.h"

void static addChoice(struct Book **start);

void static chooseOption(struct Book *start, int choice);

void static searchChoice(struct Book *start);

void static changeCategoryChoice(struct Book *start);

void static selectCatchoice(struct Book *start);



void showMenu(struct Book *start) {
    int choice;
    do {
        printf("\nBienvenue dans le programme de gestion de livre\n"
                 "\n"
                 "1) Encoder un nouveau livre\n"
                 "2) Rechercher un livre\n"
                 "3) Encoder la catégorie d'un livre\n"
                 "4) Afficher les livres d'une catégorie\n"
                 "5) Quitter\n"
                 "Choisissez une option: ");
        scanf("%d%*c", &choice);
        chooseOption(start, choice);
    }while(choice != 5);
}

void static chooseOption(struct Book *start, const int choice) {
    switch(choice) {
        case 1:
            addChoice(&start);
            break;
        case 2:
            searchChoice(start);
            break;

        case 3:
            changeCategoryChoice(start);
            break;

        case 4:
            selectCatchoice(start);
            break;

        case 5:
            break;
        default:
            return;
    }
}

void static addChoice(struct Book **start) {
    char title[200+1];
    char author[200+1];
    char editor[200+1];
    char category[100+1];
    int year;

    printf("Titre: ");
    fgets(title, 200, stdin);
    printf("Auteur: ");
    fgets(author, 200, stdin);
    printf("Editeur: ");
    fgets(editor, 200, stdin);
    printf("Categorie: ");
    fgets(category, 100, stdin);
    printf("Annee: ");
    scanf("%d", &year);

    addBook(start, title, author, editor, category, year);
}

void static searchChoice(struct Book *start) {
    char title[200+1];

    printf("Titre: ");
    scanf("%s", title);
    getchar();

    if(searchBook(title, start) != NULL) {
        showBook(searchBook(title, start));
    }
}

void static changeCategoryChoice(struct Book *start) {
    char title[200+1];
    char category[100+1];

    printf("Titre: ");
    fgets(title, 200, stdin);
    printf("Nouvelle categorie: ");
    fgets(category, 100, stdin);

    if(searchBook(title, start) != NULL) {
        changeCategory(searchBook(title, start), category);
    }
}

void static selectCatchoice(struct Book *start) {
    char category[100+1];
    fgets(category, 100, stdin);

    selectBookByCategory(start, category);
}