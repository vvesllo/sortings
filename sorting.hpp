#ifndef PMI_SORTING_HPP
#define PMI_SORTING_HPP

#define MIN(a, b) a < b ? a : b
#define MAX(a, b) a > b ? a : b

#include <random>

bool is_sorted(int* arr, size_t size);
void shuffle(int* arr, size_t size);
void swap(int& a, int& b);

void insertion_sort(int* arr, size_t size);
void selection_sort(int* arr, size_t size);
void comb_sort(int* arr, size_t size);
void gnome_sort(int* arr, size_t size);
void shaker_sort(int* arr, size_t size);
void counting_sort(int* arr, size_t size);
void quick_sort(int* arr, size_t size, int low, int high);
void quick_sort_random(int* arr, size_t size, int low, int high);
void merge_sort(int* arr, size_t size, int left, int right);
void merge_sort_no_recurse(int* arr, size_t size, int left, int right);
void shell_sort(int* arr, size_t size);

#endif