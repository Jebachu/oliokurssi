#include <iostream>
#include <ctime>

using namespace std;


int game(int maxnum);

int main()
{
    int arvausten_lkm = 0;
    int maxnum = 40;
    arvausten_lkm = game(maxnum);
    cout << "arvauksia: "
         << arvausten_lkm
         << endl;


return 0;
}

int game(int maxnum) {
    int arvausten_lkm = 0;

    cout << "maxnum="
         << maxnum
         << endl;

    srand(time(NULL));
    int satluku = rand() % maxnum;
    int arvaus = 0;

    while (arvaus != satluku) {
        cout << "anna luku?"
             << endl;
        cin >> arvaus;
        arvausten_lkm++;


        if (arvaus==satluku) {
            cout << "oikein"
                 << endl;

        }

        if (arvaus < satluku) {
            cout << "luku on suurempi"
                 << endl;
        }

        if (arvaus > satluku) {
            cout << "luku on pienempi"
                 << endl;
        }
    }

    return arvausten_lkm;
}
