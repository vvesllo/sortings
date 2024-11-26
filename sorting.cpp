#include "sorting.hpp"

bool is_sorted(int* arr, size_t size)
{
    for (size_t i = 0; i < size-1; i++)
        if (arr[i] > arr[i+1]) return false;
    return true;
}

void shuffle(int* arr, size_t size)
{
    int j = 0;
    for (size_t i = 0; i < size-1; i++)
    {
        j = rand() % (i + 1);
        int _temp = arr[i];
        arr[i] = arr[j];
        arr[j] = _temp;
    }
}

void swap(int& a, int& b)
{
    int _temp = a;
    a = b;
    b = _temp;
}



void insertion_sort(int* arr, size_t size)
{
	for(int i = 1; i < size; i++)
    {
		for(int j = i; j > 0; j--)
        {
            if (arr[j-1] > arr[j])
            // if (arr[j-1] < arr[j]) // reverse
            {
                int _temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = _temp;
            }
		}
    }
}

void selection_sort(int* arr, size_t size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_j = i;
        for (int j = i + 1; j < size; j++)
            if (arr[j] < arr[min_j]) min_j = j;
            // if (arr[j] > arr[min_j]) min_j = j; // reverse

        if (min_j != i) swap(arr[i], arr[min_j]);
    }
}

void comb_sort(int* arr, size_t size)
{
    int k = size;
    bool flag = false;

    while (k > 1 || flag)
    {
        if (k > 1) k = k * 4 / 5;

        flag = false;
        int i = 0;

        while (i + k < size)
        {
            if (arr[i] > arr[i + k])
            // if (arr[i] < arr[i + k]) // reverse
            {
                swap(arr[i], arr[i + k]);
                flag = true;
            }
            i += k;
        }
    }
}

void gnome_sort(int* arr, size_t size)
{
    int i = 1;
    int j = 2;

    while (i < size)
    {
        if (arr[i - 1] < arr[i])
        {
            i = j;
            j++;
        }
        else
        {
            swap(arr[i - 1], arr[i]);
            i--;
            if (i == 0)
            {
                i = j;
                j++;
            }
        }
    }
}

void shaker_sort(int* arr, size_t size)
{
    int left = 0, right = size - 1;
    int last_swap;

    do
    {
        last_swap = 0;

        for (int i = left; i < right; ++i) 
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                last_swap = i;
            }
        right = last_swap;

        last_swap = 0;

        for (int i = right; i > left; --i)
            if (arr[i] < arr[i - 1])
            {
                swap(arr[i], arr[i - 1]);
                last_swap = i;
            }
        left = last_swap;

    } while (left < right);
}

void counting_sort(int* arr, size_t size)
{
    int max_value = arr[0];
    for (int i=0; i < size; i++) max_value = (max_value > arr[i] ? max_value : arr[i]);
    
    int* count = (int*)calloc(max_value+1, sizeof(int));

    for (int i=0; i < size; i++) count[arr[i]]++;

    int index = 0;
    for (int i = 0; i <= max_value; i++)
        while (count[i]-- > 0) arr[index++] = i;
}

void quick_sort(int* arr, size_t size, int low, int high)
{
    if (low < high)
    {
        int center = arr[low + (high - low) / 2];
        int left = low;
        int right = high;

        while (left <= right)
        {
            while (arr[left] < center) left++;
            while (arr[right] > center) right--;
        
            if (left <= right)
                swap(arr[left++], arr[right--]);
        }
        int center_index = left;

        quick_sort(arr, size, low, center_index - 1);
        quick_sort(arr, size, center_index, high);
    }
}

void quick_sort_random(int* arr, size_t size, int low, int high)
{
    if (low < high)
    {
        int randomIndex = low + rand() % (high - low + 1);
        swap(arr[randomIndex], arr[high]);
        int pivot = arr[high];
        int left = low;

        for (int right = low; right < high; ++right)
            if (arr[right] <= pivot) swap(arr[left++], arr[right]);
        
        swap(arr[left], arr[high]);
        
        int center_index = left;

        quick_sort(arr, size, low, center_index - 1);
        quick_sort(arr, size, center_index, high);
    }
}

void merge_sort(int* arr, size_t size, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        merge_sort(arr, size, left, mid);
        merge_sort(arr, size, mid + 1, right);

        int n1 = mid - left + 1;
        int n2 = right - mid;

        int* L = new int[n1];
        int* R = new int[n2];

        for (int i = 0; i < n1; i++) L[i] = arr[left + i];
        for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;

        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])   arr[k++] = L[i++];
            else                arr[k++] = R[j++];
        }

        while (i < n1)      arr[k++] = L[i++];
        while (j < n2)      arr[k++] = R[j++];

        delete[] L, R;
    }
}

void merge_sort_no_recurse(int* arr, size_t size, int left, int right)
{
    for (int curr_size = 1; curr_size < size; curr_size *= 2)
    {
        for (int left = 0; left < size - 1; left += 2 * curr_size)
        {
            int mid = MIN(left + curr_size - 1, size - 1);
            int right = MIN(left + 2 * curr_size - 1, size - 1);

            if (mid < right)
            {
                int n1 = mid - left + 1;
                int n2 = right - mid;

                int* L = new int[n1];
                int* R = new int[n2];

                for (int i = 0; i < n1; i++) L[i] = arr[left + i];
                for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

                int i = 0, j = 0, k = left;

                while (i < n1 && j < n2)
                {
                    if (L[i] <= R[j])   arr[k++] = L[i++];
                    else                arr[k++] = R[j++];
                }

                while (i < n1) arr[k++] = L[i++];
                while (j < n2) arr[k++] = R[j++];

                delete[] L, R;
            }
        }
    }
}

void shell_sort(int* arr, size_t size)
{
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i++)
        {
            int _temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > _temp; j -= gap)
                arr[j] = arr[j - gap];

            arr[j] = _temp;
        }
    }
}