//
// Created by bartek on 14.03.17.
//

#include "MinimalTimeDifference.h"

using namespace std;

int Difference(int a, int b){
    if(abs(a-b) <= 720) return abs(a - b);
    if(abs(a-b) > 720) return a - b + 1440;
}

int FindMinDifference(vector<int> differences){
    int min = differences[0];
    for(auto i: differences){
        if(i < min) min = i;
    }
    return min;
}

unsigned int ToMinutes(string time_HH_MM){
    int minutes = 0;
    minutes += (time_HH_MM[0]-48) * 600 + (time_HH_MM[1]-48) * 60 + (time_HH_MM[3]-48) * 10 + int(time_HH_MM[4]-48);
    return minutes;
}

unsigned int MinimalTimeDifference(vector<string> times){
    vector<int> differences;
    for(int i=0; i<times.size(); i++){
        for(int j=0; j<times.size(); j++ ){
            if(i != j) differences.push_back(Difference(i,j));
        }
    }
    return FindMinDifference(differences);
}
