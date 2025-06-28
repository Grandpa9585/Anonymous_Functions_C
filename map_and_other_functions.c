#include <stdlib.h>
#include <stdio.h>

void map(int (*function)(int), int *arr, int lenght);
int *int_map_return(int (*function)(int), int arr[], int length);
int single_value_return_reduce(int (*function)(int, int), int arr[], int length, int start_value);
int filter(int (*function)(int), int arr[], int length);


int double_number(int number) {
    return number * 2;
}   

int add(int a, int b) {
    return a + b;
}

int is_even(int a) {
    return a % 2 == 0;
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int *array = arr;

    map(double_number, array, 4);
    array = int_map_return(double_number, array, 4);

    int sum_value = single_value_return_reduce(add, array, 4, 0);

    int new_len = filter(is_even, array, 4);
    
    printf("%d\n", sum_value);
    for (int *p = array, *sentinel = array + new_len - 1; p <= sentinel; p += 1)
        printf("%d\n", *p);
    

}

void map(int (*function)(int), int *arr, int lenght) {
    for (int *p = arr, *sentinel = arr + lenght - 1; p <= sentinel; p += 1)
        *p = function(*p);
}

int *int_map_return(int (*function)(int), int arr[], int length) {
    int *temp = malloc(sizeof(int) * length);
    for (int *p_a = arr, *sentinel = arr + length - 1, *p = temp; p_a <= sentinel; p_a += 1, p += 1)
        *p = function(*p_a);
    return temp;
}

int single_value_return_reduce(int (*function)(int, int), int arr[], int length, int start_value) {
    int out = start_value;
    for (int *p = arr, *sentinel = arr + length - 1; p <= sentinel; p += 1) {
        out = function(out, *p);
    }
    return out;
}

int filter(int (*function)(int), int arr[], int length) {
    /* The function returns the new length of the array */
    int new_len = 0;
    int *temp = malloc(sizeof(int) * length);
    for (int *p_a = temp, *p = arr, *sentinel = arr + length - 1; p <= sentinel; p += 1) {
        if (function(*p)) {
            *p_a = *p;
            p_a += 1;
            new_len++;
        }
    }
    for (int *p_a = temp, *p = arr, *sentinel = arr + length - 1; p <= sentinel; p += 1, p_a += 1) {
        *p = *p_a;
    }
    return new_len;

}