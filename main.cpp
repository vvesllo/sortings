#include <iostream>
#include <iomanip>
#include <sstream>
#include <cassert>
#include <conio.h>

#include "sorting.hpp"


void tests(int* arr, size_t n);
int test_sort(void(*sort_f)(int*, size_t), std::string name, int* arr, size_t size);
int test_hard_sort(void(*sort_f)(int*, size_t, int, int), std::string name, int* arr, size_t size);
std::string array_to_str(int* arr, size_t size);

int main()
{
    srand(time(NULL));


    size_t n = 0;
    std::cout << "array size: ";
    std::cin >> n;
    
    
    int* arr = new int[n];
    for (int i=0; i < n; i++) std::cin >> arr[i];

    tests(arr, n);

    delete[] arr;

    getch();
}
void tests(int* arr, size_t n)
{
    // сортировка вставками
    assert(test_sort(insertion_sort, "insertion sort", arr, n));

    // сортировка выбором
    assert(test_sort(selection_sort, "selection sort", arr, n));

    // сортировка расчесткой
    assert(test_sort(comb_sort, "comb sort", arr, n));

    // сортировка гном
    assert(test_sort(gnome_sort, "gnome sort", arr, n));

    // сортировка шейкер
    assert(test_sort(shaker_sort, "shaker sort", arr, n));

    // сортировка подсчетом
    assert(test_sort(counting_sort, "counting sort", arr, n));

    // сортировка быстрая 1
    assert(test_hard_sort(quick_sort, "quick sort(1)", arr, n));

    // сортировка быстрая 2
    assert(test_hard_sort(quick_sort_random, "quick sort(2)", arr, n));

    // сортировка слиянием 1
    assert(test_hard_sort(merge_sort, "merge sort(1)", arr, n));

    // сортировка слиянием 2
    assert(test_hard_sort(merge_sort_no_recurse, "merge sort(2)", arr, n));

    // сортировка шелла
    assert(test_sort(shell_sort, "shell sort", arr, n));
}

std::string array_to_str(int* arr, size_t size)
{
    std::stringstream ss;
    ss << "[" << size << "] -> ";

    for (int i = 0; i < size; i++) 
        ss << arr[i] << ' ';

    return ss.str();
}

int test_sort(void(*sort_f)(int*, size_t), std::string name, int* arr, size_t size)
{   
    shuffle(arr, size);
    sort_f(arr, size);
    std::cout << name << ":\t" << std::setw(8) << array_to_str(arr, size) << '\n';
    return is_sorted(arr, size);
}

int test_hard_sort(void(*sort_f)(int*, size_t, int, int), std::string name, int* arr, size_t size)
{   
    shuffle(arr, size);
    sort_f(arr, size, 0, size-1);
    std::cout << name << ":\t" << std::setw(8) << array_to_str(arr, size) << '\n';
    return is_sorted(arr, size);
}