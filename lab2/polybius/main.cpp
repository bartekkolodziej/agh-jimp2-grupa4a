//
// Created by bartek on 07.03.17.
//

#include "Polybius.h"

int main(int argc,  char* argv){
    char word[64];
    string crypted;

    ifstream myfile(argv[1]);
    ofstream myfile2 (argv[2], ios_base::in | ios_base::app);

    if(!myfile1 || !myfile2)
        cout << "Nie można otworzyć pliku!" << endl;

    if(argv[3] == 1){
        while(myfile1 >> word) myfile << PolybiusCrypt(word);
    }

    if(argv[3] == 0 ){
        while(myfile1 >> word) myfile << PolybiusDecrypt(word);
    }

    myfile1.close();
    myfile2.close();
    return 0;
}