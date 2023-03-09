#include <iostream>
#include <vector>
using namespace std;

int findMissingElement(vector<int> arr)
{
    int start = 0;
    int end = arr.size() - 1;
    int mid = start + (end - start) / 2;

    while (end > start + 1)
    {
        if (arr[start] - start != arr[mid] - mid)
        {
            end = mid;
        }
        else if (arr[end] - end != arr[mid] - mid)
        {
            start = mid;
        }
        mid = start + (end - start) / 2;
    }
    return mid + 1;
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 6, 7, 8};
    int ans = findMissingElement(arr);
    cout << "Missing Element at index " << ans << endl;
    return 0;
}