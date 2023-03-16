#include <iostream>
#include <vector>
using namespace std;

double getDoubleValueOfAns(int ans, int target)
{
    int precision = 2;
    double finalAns = ans;
    double step = 0.1;

    for (int i = 0; i < precision; i++)
    {
        for (double j = finalAns; j * j <= target; j = j + step)
        {
            finalAns = j;
        }
        step = step / 10;
    }
    return finalAns;
}

double squareRoot(int target)
{
    int start = 0;
    int end = target;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while (start <= end)
    {
        if (mid * mid == target)
        {
            return mid;
        }
        if (mid * mid > target)
        {
            end = mid - 1;
        }
        else
        {
            ans = mid;
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }

    // To find the answer with decimal value
    return getDoubleValueOfAns(ans, target);
}

int main()
{
    int target = 80;
    cout << "Square Root of " << target << " is " << squareRoot(target) << endl;
    return 0;
}