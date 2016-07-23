#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <float.h>
#include <time.h>

const int SQEQ_INF = -1;
const int LINEQ = 3;

//! Check if all coefficients of square equation are "equal" to zero 
//! @param a 1st coefficient of square equation
//! @param b 2nd coefficient of square equation
//! @param c 3d  coefficient of square equation 
//! @returns -1 in case of all coefficients are "equal" to zero, otherwise 0   
int IsZero(double a, double b, double c)
{
    if ((fabs(a) <= DBL_EPSILON) && (fabs(b) <= DBL_EPSILON) && (fabs(c) <= DBL_EPSILON))
    {
        return -1;
    }
    else return 0;
}

//! Solves a square equation
//! @param a, b, c coefficients of square equation
//! @param x1, x2 pointers to 1st and 2nd square roots accordingly
//! @returns SQEQ_INF in case of infinite number of solutions, corresponding numbers of roots in other cases 
//! and also two values of square roots 
int SqEquation(double a, double b, double c, double* x1, double* x2)
{
    assert(x1 && x2); 
    assert(x1 != x2);

    double d = b * b - 4 * a * c;

    if (IsZero(a, b, c) != 0) 
    {
        return SQEQ_INF;
    }

    if (d == 0)
    {
        if (a != 0) 
        {
            *x1 = -b / 2 / a;
            *x2 = -b / 2 / a;
            return 1;
        }
        else 
        {
            if (b != 0) 
            {
                *x1 = -c / b;
                return LINEQ;
            }
            else return 0;
        }
    }

    if (d < 0)
    {
        return 0;
    }

    if (d > 0)
    {
        if (a != 0) 
        {
            *x1 = (-b + sqrt(d)) / 2 / a;
            *x2 = (-b - sqrt(d)) / 2 / a;
            return 2;
        }
        else return 0;
    }
}

//! Main function
//! @return 0 if compilation is finished without errors
int main()
{
    double x1 = 0, x2 = 0;
    double a = 0, b = 0, c = 0;

    srand(time(NULL));

    for (int i = 0; i < 20; i++) 
    {
        a = -10 + (rand() % 21);
        b = -10 + (rand() % 21);
        c = -10 + (rand() % 21);

        int nRoots = SqEquation(a, b, c, &x1, &x2);

        if(nRoots == SQEQ_INF)
            printf("an infinite number of roots \n");
        if(nRoots == LINEQ)
            printf("linear equation %3f", x1);
        if (nRoots == 0)
            printf ("no roots \n");
        else printf("%d | % -5f | % -5f \n", nRoots, x1, x2);
    }
    return 0;
}
