//
// Created by kcik1_000 on 2017-03-05.
//
#include "Array2D.h"

using namespace std;

int main() {
    int rows, columns;
    cout << "Ile wierszy? \n";
    cin >> rows;
    cout << "Ile kolumn? \n";
    cin >> columns;
    int **tab = Array2D(rows,columns);


    FillArray2D(rows, columns,tab);
    Print(tab,rows,columns);
    DeleteArray2D(tab, rows, columns);

return 0;
}