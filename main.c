#include <stdio.h>

#include "menu.h"
#include "library.h"

int main(void) {
    struct Book *start = NULL;
    showMenu(&start);
    destroyList(start);
    return 0;
}
