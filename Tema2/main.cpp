#include "Matrice_patratica.h"
#include "Matrice_oarecare.h"

using namespace std;

int main()
{
    Matrice_patratica mp1;
    cin >> mp1;
    cout << mp1.at(0, 0) << endl;

    Matrice_patratica mp2(mp1);

    Matrice_oarecare mo1;
    cin >> mo1;
    cout << mo1.at(0, 1) << endl;

    Matrice_oarecare mo2(mo1);

    return 0;
}
