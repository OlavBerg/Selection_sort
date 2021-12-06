#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#define ARRAY_SIZE(array) sizeof(array) / sizeof(array[0])

void print_array(int array[], size_t array_size) {
    printf("{");
    for (size_t i = 0; i < array_size; i++) {
        printf("%d, ", array[i]);
    }
    printf("}\n");
} 

void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void selectionsort(int array[], size_t array_size) {
    bool sorted = false;
    for (size_t begin = 0; begin <= array_size - 2 && !sorted; begin++) {
        size_t lowest = begin + 1;
        sorted = true;

        for (size_t i = begin + 1; i <= array_size - 1; i++) {
            if (array[i] < array[lowest]) {
                lowest = i;
                sorted = false;
            }
        }

        if (!sorted) {
            swap(&array[begin], &array[lowest]);
        }
        print_array(array, array_size);
    }
}

int main() {    

    int array[] = {5, 4, 3, 2, 1};
    size_t array_size = ARRAY_SIZE(array);
    print_array(array, array_size);
    selectionsort(array, array_size);
    print_array(array, array_size);

    return 0;
}