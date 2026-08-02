// Write a C++ program using cin to take matrix sizes and elements from the user, verify if
// multiplication is possible, and compute the product.
#include <iostream>
using namespace std;
int main()
{
    int r1, c1, r2, c2;
    cout << "Enter the nuber of rows and column of 1st matrix:";
    cin >> r1 >> c1;
    cout << "Enter the nuber of rows and column of 2nd matrix:";
    cin >> r2 >> c2;
    if (c1 != r2)
    {
        cout << "Multiplication of these matrix is not possible";
        return 0;
    }
    cout << "Enter the elements of first matrix:";
    int a[r1][c1], b[r2][c2], c[r1][c2];
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << "Enter the element of second  matrix:";
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            cin >> b[i][j];
        }
    }

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < c1; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    cout << "Product of two matrix is : " << endl;
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
}