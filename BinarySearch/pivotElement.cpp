#include <iostream>
#include <vector>
using namespace std;

int pivotElement(vector<int> arr)
{
    int start = 0;
    int end = arr.size() - 1;
    int mid = start + (end - start) / 2;

    while (start < end)
    {
        if ((mid + 1 < arr.size()) && (arr[mid] > arr[mid + 1]))
        {
            return mid;
        }
        if ((mid - 1 > 0) && arr[mid] < arr[mid - 1])
        {
            return mid - 1;
        }
        if (arr[start] >= arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}

int main()
{
    vector<int> arr{3, 4, 5, 6, 7, 1, 2};
    cout << "Pivot Element is " << arr[pivotElement(arr)] << endl;
    return 0;
}