//
// Created by bartek on 02.03.17.
//

#include "Palindrome.h"

using namespace std;

int main() {
    int a;
    string str;
    cout << "1 - sprawdz palindrom \n2 - wyjscie" << endl;
    cin >> a;
    if(a==1)
    {
        cout << "Podaj slowo: " << endl;
        cin >> str;
        cout << is_palindrome(str) << endl;
    }
    return 0;
}
