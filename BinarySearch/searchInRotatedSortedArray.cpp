#include <iostream>
#include <vector>
using namespace std;

int pivotIndex(vector<int> arr)
{
    int start = 0;
    int end = arr.size() - 1;
    int mid = start + (end - start) / 2;

    while (start < end)
    {
        if (arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        if (arr[mid - 1] > arr[mid])
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

int binarySearch(vector<int> arr, int start, int end, int target)
{
    int mid = start + (end - start) / 2;
    while (start < end)
    {
        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}

int searchEle(vector<int> arr, int target)
{
    int pivotInd = pivotIndex(arr);
    cout << "Pivot Index is " << pivotInd << endl;
    if (target >= arr[0] && target <= arr[pivotInd])
    {
        // Search in array 1
        cout << "Entered Arr - 1" << endl;
        return binarySearch(arr, 0, pivotInd, target);
    }
    if (target >= arr[pivotInd + 1] && target <= arr[arr.size() - 1])
    {
        // Search in array 2
        cout << "Entered Arr - 2" << endl;
        return binarySearch(arr, pivotInd + 1, arr.size() - 1, target);
    }
    return -1;
}
int main()
{
    vector<int> arr{4, 5, 6, 1, 2, 3};
    int target = 2;
    cout << "Element Found at Index " << searchEle(arr, target) << endl;
    return 0;
}