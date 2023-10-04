
// TYPO L2-3.cpp NO L2-1.cpp


//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//* Program name    :  Ackerman function / L2-3.ccp                     * 
//*                                                                     * 
//* Written by      : Peter Sivak                                       * 
//*                                                                     * 
//* Purpose         : Program is testing Ackerman function.             * 
//*                                                                     * 
//*                                                                     * 
//* Inputs          : User enters 2 nonnegative integers                * 
//*                                                                     * 
//* Outputs         : Program answer question: How many times has the   * 
//*                   Ackerman Function been recursively called.        * 
//*                                                                     * 
//* Calls           : No internal or external calls, other than system  * 
//*                                                                     * 
//* Structure       : BEGIN                                             * 
//*                        Program prompts the user to enter 2          *
//                        nonnegative integers                          * 
//*                   STOP                                              * 
//*                       Program display how many times was Ackerman   * 
//*                       Function recursively called                   * 
//*---------------------------------------------------------------------* 
//* Collaboration   : Got help from Prof. John Urrutia                  * 
//*                                                                     * 
//*                                                                     * 
//*---------------------------------------------------------------------* 
//* Change Log:                                                         * 
//*                         Revision                                    * 
//*       Date    Changed  Rel Ver Mod Purpose                          * 
//*  10/02/23      psivak   000.000.000 Initial release of program      *  
//*                                                                     * 
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *


#include <iostream>
#include <stdexcept> 

using namespace std;


const int MAX_RECURSION_COUNT = 100000;


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
