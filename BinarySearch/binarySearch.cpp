#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int size, int target)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;

    while (start < end)
    {
        if (target == arr[mid])
        {
            return mid;
        }
        if (target > arr[mid])
        {
            // right search
            start = mid + 1;
        }
        else
        {
            // left search
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}

void binarySearchSTL(vector<int> arr, int size, int target)
{
    cout << endl
         << "Binary Search STL with vector!" << endl;
    if (binary_search(arr.begin(), arr.end(), target))
    {
        cout << "Found!" << endl;
    }
    else
    {
        cout << "Not Found!" << endl;
    }
    cout << "Binary Seach STL with Array!" << endl;
    int arr1[] = {1,
                  2,
                  3,
                  4,
                  5,
                  6,
                  7,
                  8};

    if (binary_search(arr1, arr1 + 8, 9))
    {
        cout << "Found!" << endl;
    }
    else
    {
        cout << "Not Found!" << endl;
    }
}

int main()
{
    vector<int> arr{1, 2, 4, 7, 8, 10, 12, 14, 15, 20};
    cout << "Binary Search Code!" << endl;
    int target = 15;
    int size = 10;
    int ans = binarySearch(arr, size, target);
    if (ans == -1)
    {
        cout << "Target not Found!" << endl;
    }
    else
    {
        cout << "Target Found!";
        cout << endl;
    }

    // Using Predefined Methods
    binarySearchSTL(arr, size, target);
    return 0;
}