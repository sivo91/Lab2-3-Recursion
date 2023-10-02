
#include <iostream>
#include <stdexcept> // page 1020

using namespace std;


const int MAX_RECURSION_COUNT = 100000;

// recursive func
int Ackerman(int m, int n, int& recursiveCallCount)
{
    recursiveCallCount++; // increment the count for each recursive call

    // throw err if recursion is looping around
    if (recursiveCallCount > MAX_RECURSION_COUNT)
    {
        throw runtime_error("Exceeded maximum recursion limit, program most likely crash!");
    }

    if (m == 0)
    {
        return n + 1;
    }
    else if (n == 0)
    {
        return Ackerman(m - 1, 1, recursiveCallCount);
    }
    else
    {
        return Ackerman(m - 1, Ackerman(m, n - 1, recursiveCallCount), recursiveCallCount);
    }
}

int main()
{
    int m, n;

    do
    {
        cout << "Enter non-negative value of m: ";
        cin >> m;
    } while (m < 0);

    do
    {
        cout << "Enter non-negative value of n: ";
        cin >> n;
    } while (n < 0);

    try 
    {
        int recursiveCallCount = 0; // initialize the count of recursive calls

        // calculate A(m, n) and count the recursive calls
        int result = Ackerman(m, n, recursiveCallCount);

        cout << "A(" << m << ", " << n << ") = " << result << endl;
        cout << "Ackermann Function been recursively called : " << recursiveCallCount << endl;
    }
    catch (runtime_error& e)
    {
        cout << "Error: " << e.what() << endl;
    }

    

    return 0;
}
