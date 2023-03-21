// Find the odd occuring element in an array.
// All elements occur even number of times. EXCEPT ONE
// All repeating occurance element appear in pairs and similar pairs are not adjacent.
// There cannot be more than 2 occurances of an element
// Find the element that appear odd number of times.
#include <iostream>
#include <vector>
using namespace std;

int findOddOccurance(vector<int> arr)
{
    // From our observations we concludede that our answer will always be at EVEN index.
    // In the array before the answer a pattern of [EVEN ODD] will be followed for similar element pairs
    // In the array after the answer a pattern of [ODD EVEN] will be followed for similar element pairs
    int start = 0;
    int end = arr.size() - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (start == end)
        {
            // Single Element
            return start;
        }
        if (mid % 2 == 0)
        {
            // Even
            if (arr[mid] == arr[mid + 1])
            {
                // We are at Left side. Shift Right
                start = mid + 2;
            }
            else
            {
                // We are at Right side or at answer
                end = mid;
            }
        }
        else
        {
            // Odd
            if (arr[mid] == arr[mid - 1])
            {
                // We are at Left side. Shift Right
                start = mid + 1;
            }
            else
            {
                // We are at Right Side. Shift Left
                end = mid - 1;
            }
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}

int main()
{
    vector<int> arr{1, 1, 2, 2, 3, 3, 4, 4, 3, 600, 600, 4, 4};
    int ans = findOddOccurance(arr);
    cout << "Element that appear odd number of times is " << arr[ans] << " at index " << ans << endl;
    return 0;
}