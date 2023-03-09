#include <iostream>
#include <vector>
using namespace std;

int lastOccurance(vector<int> arr, int target)
{
    int start = 0;
    int end = arr.size() - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while (start <= end)
    {
        if (target == arr[mid])
        {
            ans = mid;
            start = mid + 1;
        }
        else if (target < arr[mid])
        {
            end = end - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }

    return ans;
}

int firstOccurance(vector<int> arr, int target)
{
    int start = 0;
    int end = arr.size() - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while (start <= end)
    {
        if (target == arr[mid])
        {
            ans = mid;
            end = mid - 1;
        }
        else if (target < arr[mid])
        {
            start = start + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

int main()
{
    vector<int> arr{2, 4, 4, 4, 4, 4, 4, 6, 8, 10};
    int target = 4;
    cout << "Total Occurance is : " << lastOccurance(arr, target) - firstOccurance(arr, target) + 1 << endl;
    // cout << lastOccurance(arr, target) << " " << firstOccurance(arr, target) << endl;
    return 0;
}