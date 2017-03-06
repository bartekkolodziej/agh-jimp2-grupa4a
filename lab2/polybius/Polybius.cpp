//
// Created by bartek on 07.03.17.
//

#include "Polybius.h"

using namespace std;

string PolybiusCrypt(string message){
    string crypt;
    transform(message.begin(), message.end(), message.begin(), ::tolower);
    char alfabet[5][5] = {{'a','b','c','d','e'},
                          {'f','g','h','i','k'},
                          {'l','m','n','o','p'},
                          {'q','r','s','t','u'},
                          {'v','w','x','y','z'}};

    for(int i=0; i<message.length(); i++){
        tutaj:
        for(int j=0; j<5; j++){
            for(int k=0; k<5; k++){
                if(message.at(i) == alfabet[j][k]) {
                    crypt += to_string(j+1) + to_string(k+1);
                    break;
                }
                if(message.at(i) == 'j') {
                    crypt += to_string(2) + to_string(4);
                    i++;
                    goto tutaj;
                }
            }
        }
    }
    return crypt;
}
string PolybiusDecrypt(string crypted){
    string decrypt;
    int index1,index2;
    char alfabet[5][5] = {{'a','b','c','d','e'},
                          {'f','g','h','i','k'},
                          {'l','m','n','o','p'},
                          {'q','r','s','t','u'},
                          {'v','w','x','y','z'}};

    for(int i=0; i<crypted.length(); i += 2){
        index1 = (int)crypted.at(i) - 49;
        index2 = (int)crypted.at(i+1) - 49;
        decrypt += alfabet[index1][index2];
    }
    return decrypt;
}
