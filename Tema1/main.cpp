#include <iostream>
#include "Polinom.h"

using namespace std;

void readPolynoms(int n)
{
    Polinom *arr = new Polinom[n];

    for (int i = 0; i < n; ++i)
    {
        cout << "==== Input polynom number " << i << " ====" << endl;
        cin >> arr[i];
    }

    for (int i = 0; i < n; ++i)
    {
        cout << "==== Output polynom number " << i << " ====" << endl;
        cout << arr[i];
    }

    delete [] arr;
}

int main()
{
    int n1 = 2, n2 = 5;
    double arr1[] = {1, 2, 3};
    double arr2[] = {-2, 4, 5, 6, 0, 2};

    Polinom *p1 = new Polinom(n1, arr1);
    Polinom *p2 = new Polinom(n2, arr2);
    Polinom *p3 = new Polinom(p1);
    Polinom *p4 = new Polinom();

    cout << *p1;
    cout << "p1(3) = " << p1->value(3) << endl;
    cout << "p2(1) = " << p2->value(1) << endl;
    cout << "p3(1) = " << p3->value(1) << endl;

    Polinom res1 = (*p1) + (*p2);
    cout << "(p1 + p2)(1) = " << res1.value(1) << endl;

    Polinom res2 = (*p1) - (*p2);
    cout << "(p1 - p2)(1) = " << res2.value(1) << endl;

    Polinom res3 = (*p1) * (*p2);
    cout << "(p1 * p2)(1) = " << res3.value(1) << endl;

    int n;
    cout << "Enter number of polynoms: ";
    cin >> n;
    readPolynoms(n);

    delete p1;
    delete p2;
    delete p3;
    delete p4;

    return 0;
}