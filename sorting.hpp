#ifndef PMI_SORTING_HPP
#define PMI_SORTING_HPP

#define MIN(a, b) a < b ? a : b
#define MAX(a, b) a > b ? a : b

#include <random>

extern bool is_sorted(int* arr, size_t size);
extern void shuffle(int* arr, size_t size);
extern void swap(int& a, int& b);

extern void insertion_sort(int* arr, size_t size);
extern void selection_sort(int* arr, size_t size);
extern void comb_sort(int* arr, size_t size);
extern void gnome_sort(int* arr, size_t size);
extern void shaker_sort(int* arr, size_t size);
extern void counting_sort(int* arr, size_t size);
extern void quick_sort(int* arr, size_t size, int low, int high);
extern void quick_sort_random(int* arr, size_t size, int low, int high);
extern void merge_sort(int* arr, size_t size, int left, int right);
extern void merge_sort_no_recurse(int* arr, size_t size, int left, int right);
extern void shell_sort(int* arr, size_t size);

#endif