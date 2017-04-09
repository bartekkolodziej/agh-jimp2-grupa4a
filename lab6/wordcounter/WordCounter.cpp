//
// Created by bartosz on 09.04.17.
//

#include "WordCounter.h"


Word::Word(){
    this->word="";
}

Word::Word(std::string new_word){
    this->word=new_word;
}

Counts::Counts(){
    this->counts=1;
}

void Counts::operator ++ (){
    this->counts+=1;
}

WordCounter::WordCounter(std::string path){
    std::ifstream myfile(path);
    if(!myfile){
        cout << "Can't open the file." << endl;
    }
    std::string text;
    myfile>> text;
    regex pattern( "\\w*" );
    smatch match;
    if( regex_search( text, match, pattern ) ){
        pair<bool,int> result = FindWord(match[0]);
        if(result.first){
            this->word_list[result.second].second++;
        }
        else{
            Word word(match[0]);
            Counts count;
            pair<Word,Counts> pair(word,count);
            this->word_list.emplace_back(pair);
        }

    }

}

pair<bool,int> WordCounter::FindWord(std::string word) {
    int i=0;
    pair<bool,int> result(false,0);
    for (auto v : this->word_list){
        if (v.first==word) {
            result.first=true;
            result.second=i;
            return result;
        };
        i++;
    }
    return result;
}
int WordCounter::operator[](std::string word){
    pair<bool,int> result = FindWord(word);
    if(result.first) return this->word_list[result.second].second.count;
    else return 0;
}