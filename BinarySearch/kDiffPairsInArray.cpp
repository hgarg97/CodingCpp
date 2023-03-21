#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int findPairs2Pointers(vector<int> arr, int k)
{
    sort(arr.begin(), arr.end());
    set<pair<int, int>> ans;
    int i = 0, j = 1;

    while (j < arr.size())
    {
        int diff = arr[j] - arr[i];
        if (diff == k)
        {
            ans.insert({arr[i], arr[j]});
            i++;
            j++;
        }
        else if (diff > k)
            i++;
        else
            j++;
        if (i == j)
            j++;
    }

    return ans.size();
}

bool binarySearch(vector<int> arr, int start, int end, int target)
{
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[mid] == target)
            return true;
        if (arr[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
        mid = start + (end - start) / 2;
    }
    return false;
}

int findPairsUsingBS(vector<int> arr, int k)
{
    sort(arr.begin(), arr.end());
    set<pair<int, int>> ans;

    for (int i = 0; i < arr.size(); i++)
    {
        if (binarySearch(arr, i + 1, arr.size() - 1, arr[i] + k))
            ans.insert({arr[i], arr[i] + k});
    }

    return ans.size();
}

int main()
{
    vector<int> arr{3, 1, 4, 1, 5};
    int k = 2;
    // cout << "Number of Pairs with K-Diff are " << findPairs2Pointers(arr, k) << endl;
    cout << "Number of Pairs with K-Diff are " << findPairsUsingBS(arr, k) << endl;
    return 0;
}