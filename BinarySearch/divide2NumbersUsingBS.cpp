#include <iostream>
#include <vector>
using namespace std;

double findDecimalOfAns(int ans, int divident, int divisor)
{
    int precision = 2;
    double step = 0.1;
    double finalAns = ans;
    for (int i = 0; i < precision; i++)
    {
        for (double j = finalAns; j * abs(divisor) <= abs(divident); j = j + step)
        {
            finalAns = j;
        }
        step = step / 10;
    }
    if ((divisor < 0 && divident < 0) || (divisor > 0 && divident > 0))
        return finalAns;
    else
        return finalAns * -1;
}

double findQuotient(int divident, int divisor)
{
    int start = 0;
    int end = abs(divident);
    int mid = start + (end - start) / 2;
    int ans = -1;
    while (start <= end)
    {
        if (mid * abs(divisor) == abs(divident))
            return mid;
        if (mid * abs(divisor) < abs(divident))
        {
            ans = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;
        mid = start + (end - start) / 2;
    }
    // Find Decimal Points
    return findDecimalOfAns(ans, divident, divisor);
}

int main()
{
    int divident = 13;
    int divisor = 2;
    cout << divident << " Divided by " << divisor << " is " << findQuotient(divident, divisor) << endl;
    return 0;
}