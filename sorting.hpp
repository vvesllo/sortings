#ifndef PMI_SORTING_HPP
#define PMI_SORTING_HPP

#define MIN(a, b) a < b ? a : b
#define MAX(a, b) a > b ? a : b

#include <random>

extern bool is_sorted(int* arr, size_t size);
extern bool is_reversed(int* arr, size_t size);
extern void shuffle(int* arr, size_t size, int seed);
extern void swap(int& a, int& b);

extern void insertion_sort(int* arr, size_t size);
extern void selection_sort(int* arr, size_t size);
extern void comb_sort(int* arr, size_t size);
extern void gnome_sort(int* arr, size_t size);
extern void shaker_sort(int* arr, size_t size);
extern void counting_sort(int* arr, size_t size);
extern void quick_sort(int* arr, size_t size, size_t low, size_t high);
extern void quick_random_sort(int* arr, size_t size, size_t low, size_t high);
extern void merge_sort(int* arr, size_t size, size_t left, size_t right);
extern void merge_no_recurse_sort(int* arr, size_t size, size_t left, size_t right);
extern void shell_sort(int* arr, size_t size);


extern void insertion_sort_reversed(int* arr, size_t size);
extern void selection_sort_reversed(int* arr, size_t size);
extern void comb_sort_reversed(int* arr, size_t size);
extern void gnome_sort_reversed(int* arr, size_t size);
extern void shaker_sort_reversed(int* arr, size_t size);
extern void counting_sort_reversed(int* arr, size_t size);
extern void quick_sort_reversed(int* arr, size_t size, size_t low, size_t high);
extern void quick_random_sort_reversed(int* arr, size_t size, size_t low, size_t high);
extern void merge_sort_reversed(int* arr, size_t size, size_t left, size_t right);
extern void merge_no_recurse_sort_reversed(int* arr, size_t size, size_t left, size_t right);
extern void shell_sort_reversed(int* arr, size_t size);



#endif