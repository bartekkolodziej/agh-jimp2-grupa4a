//
// Created by bartek on 06.03.17.
//

#include "GreatestProduct.h"

using namespace std;


void sort(int *tab, int k){
    for(int j=0; j<k; j++){
        for(int i=0; i<k; i++){
            if (tab[i]>tab[j]){
                swap(tab[i],tab[j]);
            }
        }
    }
}

int GreatestProduct(const vector<int> &numbers, int k) {
    int iloczyn = 1;
    int *tab = new int[k]();

    for (int i : numbers) {
        if (i > tab[0]) {
            tab[0] = i;
            sort(tab, k);
        }
    }

    for (int j = 0; j < k; j++){
        iloczyn *= tab[j];

    }

    delete[] tab;
    return iloczyn;
}

