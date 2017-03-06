//
// Created by kcik1_000 on 2017-03-05.
//

#ifndef JIMP_EXERCISES_ARRAY2D_H
#define JIMP_EXERCISES_ARRAY2D_H

#include<iostream>

using namespace std;

int **Array2D(int n_rows, int n_columns);
void DeleteArray2D(int **array, int n_rows, int n_columns);
void FillArray2D(int n_rows, int n_columns,int **array);
void Print(int **array, int n_rows, int n_columns);

#endif //JIMP_EXERCISES_ARRAY2D_H
