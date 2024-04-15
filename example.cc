/* Needed to compile with clang-17.0.6 and not gcc=13.2.1 to get desired effect */

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void sort(long* array) {
    int i;
    bool sorted;

    do {
    sorted = true;

    for( i = 0; i < 31; i++ ) {
    long* item_one = &array[i];
    long* item_two = &array[i+1];
    long swap_store;

    if( *item_one <= *item_two ) {
    continue;
    }

    sorted = false;
    swap_store = *item_two;
    *item_two = *item_one;
    *item_one = swap_store;
    }
    } while( !sorted );
}

int main() {
    long array[32];
    int i, numbers;

    srand(time(NULL));
    numbers = rand() % sizeof array / 4;
    for( i = 0; i < numbers; i++ ) {
    array[i] = rand();
    }

    sort(array);

    return 0;
}
