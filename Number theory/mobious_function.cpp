#include <bits/stdc++.h>
using namespace std;

const int VALMAX = 2e7;

int mobius[VALMAX];

void mobius_function()
{
    mobius[1] = -1;
    for (int i = 1; i < VALMAX; i++)
    {
        if (mobius[i])
        {
            mobius[i] = -mobius[i];
            for (int j = 2 * i; j < VALMAX; j += i)
            {
                mobius[j] += mobius[i];
            }
        }
    }
}

int main()
{
    mobius_function();
}
