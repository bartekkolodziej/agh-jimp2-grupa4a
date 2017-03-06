//
// Created by kcik1_000 on 2017-03-05.
//

#include "Array2D.h"

using namespace std;

int **Array2D(int n_rows, int n_columns){
    if(n_rows <= 0 || n_columns <= 0) return 0;
    int **tab = new int *[n_rows];
    for(int i=0; i<n_rows; i++) {
        tab[i] = new int[n_columns];
    }
    FillArray2D(n_rows, n_columns,tab);
    return tab;
}

void DeleteArray2D(int **array, int n_rows, int n_columns) {
    for( int i = 0; i < n_rows; i++ ) {
            delete [] array[i];
        }
    delete [] array;
}

void FillArray2D(int n_rows, int n_columns,int **array){
    int a = 1;
    for(int i=0; i<n_rows; i++){
        for(int j=0; j<n_columns; j++) array[i][j] = a++;
    }
}

void Print(int **array, int n_rows, int n_columns){
    for(int i=0; i<n_rows; i++){
        for(int j=0; j<n_columns; j++) {
            cout.width(3);
            cout << array[i][j];
        }
        cout << "\n";
    }
}
