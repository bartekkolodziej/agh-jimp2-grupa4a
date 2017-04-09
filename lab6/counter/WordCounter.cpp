//
// Created by bartek on 09.04.17.
//

#include "WordCounter.h"


Word::Word(std::string word_){
    this->word = word_;
}

Word::~Word(){};

Counts::Counts(){
    this->count = 0;
}
Counts::~Counts(){};

WordCounter::WordCounter(std::string file_name){
    std::fstream file;
    std::string tmp = "";
    std::pair<Word, Counts> single_word;
    char ch = '';

    file.open(file_name, std::ios::in);

    if(file.good() == true){
        while(!file.eof()){
            while(ch != ' ' or ch != ',' or ch != '!' or ch != '.') {
                file.get(ch);
                tmp += ch;
            }
            for(auto x: this->words_list){
                if(x.first.word == tmp){
                   x.second.count += 1;
                    goto here;
                }
            }
            Word tmp_word{tmp};
            Counts tmp_count{};
            single_word.first = tmp_word;
            single_word.second = tmp_count;
            this->words_list.push_back(single_word);
            here:
            continue;

        }
    }
    else{
        std::cout<< "File doesn't exists";
    }
}
