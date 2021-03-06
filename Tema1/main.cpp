#include <iostream>
#include "Polinom.h"

using namespace std;

void readPolynomials(int n)
{
    Polinom *arr = new Polinom[n];

    for (int i = 0; i < n; ++i)
    {
        cout << "\n==== Input polynomial " << i << " ====" << endl;
        cin >> arr[i];
    }

    for (int i = 0; i < n; ++i)
    {
        cout << "\n==== Output polynomial " << i << " ====" << endl;
        cout << arr[i];
    }

    delete[] arr;
}

int main()
{
    double arr1[] = {2, -4, -5, -6, 0, -2};
    double arr2[] = {-2, 4, 5, 6, 0, 2};
    double arr4[] = {3, -2, 0, -1, 1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]) - 1;
    int n2 = sizeof(arr2) / sizeof(arr2[0]) - 1;
    int n4 = sizeof(arr4) / sizeof(arr4[0]) - 1;

    Polinom *p1 = new Polinom(n1, arr1);
    Polinom *p2 = new Polinom(n2, arr2);
    Polinom *p1_copy_on_heap = new Polinom(*p1);
    Polinom p2_copy_on_stack(*p2);
    Polinom *p3 = new Polinom();
    Polinom p4(n4, arr4);
    Polinom p5 = Polinom();
    Polinom p6 = Polinom();
    Polinom p7 = p5 + p6;

    // Afisare p1 si p2 sub forma P(x) = a * x^n + b * x^(n - 1) + ...
    cout << *p1;
    cout << *p2;
    cout << "\n";

    // Afisare p1(3), p1_copy_on_heap(3), p2(2), p2_copy_on_stack(2) si p4(3)
    cout << "p1(3) = " << p1->value(3) << endl;
    cout << "p1_copy_on_heap(3) = " << p1_copy_on_heap->value(3) << endl;
    cout << "p2(2) = " << p2->value(2) << endl;
    cout << "p2_copy_on_stack(2) = " << p2_copy_on_stack.value(2) << endl;
    cout << "p4(3) = " << p4.value(3) << endl;
    cout << "\n";

    // Afisare (p1 + p2)(1), (p1 - p2)(1) si (p1 * p2)(1)
    Polinom res1 = (*p1) + (*p2);
    cout << "(p1 + p2)(1) = " << res1.value(1) << endl;

    Polinom res2 = (*p1) - (*p2);
    cout << "(p1 - p2)(1) = " << res2.value(1) << endl;

    Polinom res3 = (*p1) * (*p2);
    cout << "(p1 * p2)(1) = " << res3.value(1) << endl;

    // Citirea si afisarea a n polinoame
    int n;
    cout << "Enter number of polynomials: ";
    cin >> n;
    readPolynomials(n);

    // Eliberarea memoriei alocata dinamic
    delete p1;
    delete p2;
    delete p1_copy_on_heap;
    delete p3;

    return 0;
}
