//
// Created by bartek on 02.03.17.
//

#include "MultiplicationTable.h"

using namespace std;

void MultiplicationTable(int tab[][10]){
    for(int i=0; i<10 ; i++){
        for(int j=0; j<10; j++){
            tab[i][j] = (i+1)*(j+1);
            cout.width( 4 );
        }
    }
}

void printTable(int tab[][10]){
    for(int i=0; i<10 ; i++){
        for(int j=0; j<10; j++){
            cout.width( 4 );
            cout << tab[i][j];
        }
        cout << "\n";
    }
}
