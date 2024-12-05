#include <iostream>
#include <iomanip>
#include <sstream>
#include <cassert>
#include <conio.h>

#include "sorting.hpp"

int random_seed = 0;

void tests(int* arr, size_t n);
void tests_reversed(int* arr, size_t n);
bool test_sort(void(*sort_f)(int*, size_t), std::string name, int* arr, size_t size);
bool test_sort(void(*sort_f)(int*, size_t, size_t, size_t), std::string name, int* arr, size_t size);
bool test_reversed(void(*sort_f)(int*, size_t), std::string name, int* arr, size_t size);
bool test_reversed(void(*sort_f)(int*, size_t, size_t, size_t), std::string name, int* arr, size_t size);


std::string array_to_str(int* arr, size_t size);
double function_execution_time(void(*f)(int*, size_t));
double function_execution_time(void(*f)(int*, size_t, size_t, size_t), int* arr, size_t size, size_t left, size_t right);

int main()
{
    size_t n = 100;
    // std::cout << "array size: ";
    // std::cin >> n;
    
    std::cout << "------------\ncount:\t\t\t" << n << '\n';
    
    int* arr = new int[n];
    for (size_t i=0; i < n; i++) arr[i] = i;
    
    random_seed = time(NULL) % 100000;
    std::cout << "shuffle seed:\t\t" << random_seed << '\n';

    // tests(arr, n);
    tests_reversed(arr, n);

    delete[] arr;

    getch();
}

void tests(int* arr, size_t n)
{
    assert(test_sort(insertion_sort, "insertion sort", arr, n));
    assert(test_sort(selection_sort, "selection sort", arr, n));
    assert(test_sort(comb_sort, "comb sort", arr, n));
    assert(test_sort(gnome_sort, "gnome sort", arr, n));
    assert(test_sort(shaker_sort, "shaker sort", arr, n));
    assert(test_sort(counting_sort, "counting sort", arr, n));
    assert(test_sort(quick_sort, "quick sort(1)", arr, n));
    assert(test_sort(quick_random_sort, "quick sort(2)", arr, n));
    assert(test_sort(merge_sort, "merge sort(1)", arr, n));
    assert(test_sort(merge_no_recurse_sort, "merge sort(2)", arr, n));
    assert(test_sort(shell_sort, "shell sort", arr, n));
}

void tests_reversed(int* arr, size_t n)
{
    assert(test_reversed(insertion_sort_reversed, "insertion sort reversed", arr, n));
    assert(test_reversed(selection_sort_reversed, "selection sort reversed", arr, n));
    assert(test_reversed(comb_sort_reversed, "comb sort reversed", arr, n));
    assert(test_reversed(gnome_sort_reversed, "gnome sort reversed", arr, n));
    assert(test_reversed(shaker_sort_reversed, "shaker sort reversed", arr, n));
    assert(test_reversed(counting_sort_reversed, "counting sort reversed", arr, n));
    assert(test_reversed(quick_sort_reversed, "quick sort reversed(1)", arr, n));
    assert(test_reversed(quick_random_sort_reversed, "quick sort reversed(2)", arr, n));
    assert(test_reversed(merge_sort_reversed, "merge sort reversed(1)", arr, n));
    assert(test_reversed(merge_no_recurse_sort_reversed, "merge sort reversed(2)", arr, n));
    assert(test_reversed(shell_sort_reversed, "shell sort reversed", arr, n));
}

std::string array_to_str(int* arr, size_t size)
{
    std::stringstream ss;
    ss << "[" << size << "] -> ";

    for (int i = 0; i < size; i++) 
        ss << arr[i] << ' ';

    return ss.str();
}


double function_execution_time(void(*f)(int*, size_t), int* arr, size_t size)
{
    clock_t start = clock();
    f(arr, size);
    return (double)(clock() - start) / CLOCKS_PER_SEC;
}

double function_execution_time(void(*f)(int*, size_t, size_t, size_t), int* arr, size_t size, size_t left, size_t right)
{
    clock_t start = clock();
    f(arr, size, left, right);
    return (double)(clock() - start) / CLOCKS_PER_SEC;
}

bool test_sort(void(*sort_f)(int*, size_t), std::string name, int* arr, size_t size)
{   
    shuffle(arr, size, random_seed);

    double time = function_execution_time(sort_f, arr, size);

    std::cout << name << ":\t\t" << std::fixed << std::setprecision(5) << time << "s\n";
    return is_sorted(arr, size);
}

bool test_sort(void(*sort_f)(int*, size_t, size_t, size_t), std::string name, int* arr, size_t size)
{   
    shuffle(arr, size, random_seed);

    double time = function_execution_time(sort_f, arr, size, 0, size-1);
    
    std::cout << name << ":\t\t" << std::fixed << std::setprecision(5) << time << "s\n";
    return is_sorted(arr, size);
}

bool test_reversed(void(*sort_f)(int*, size_t), std::string name, int* arr, size_t size)
{   
    shuffle(arr, size, random_seed);

    double time = function_execution_time(sort_f, arr, size);

    std::cout << name << ":\t\t" << std::fixed << std::setprecision(5) << time << "s\n";
    
    return is_reversed(arr, size);
}

bool test_reversed(void(*sort_f)(int*, size_t, size_t, size_t), std::string name, int* arr, size_t size)
{   
    shuffle(arr, size, random_seed);

    double time = function_execution_time(sort_f, arr, size, 0, size-1);
    
    std::cout << name << ":\t\t" << std::fixed << std::setprecision(5) << time << "s\n";
    return is_reversed(arr, size);
}