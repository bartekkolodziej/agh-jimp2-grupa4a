//
// Created by bartek on 09.04.17.
//

#include "WordCounter.h"

namespace datastructures {

    //operators

    int  WordCounter::operator[](std::string word){
        for(auto x: this->words_list){
            if(x.first.word == word) return x.second.count;
        }
        return 0;
    }

    bool operator<(const Word &word1, const Word &word2){
        return word1.count.count < word2.count.count;
    }

    bool operator==(const Counts &count1, int number){
        return count1.count == number;
    }

    bool operator==(const Word &word1, const Word &word2){
        return word1.count.count == word2.count.count;
    }


    //Word

    Word::Word(){
        this->word = "";
        this->count.count = 0;
    }

    Word::Word(std::string word) {
        this->word = word;
        this->count.count = 1;
    }

    Word::~Word() {};


    //Counts

    Counts::Counts() {
        this->count = 1;
    }

    Counts::Counts(int number){
        this->count = number;
    }

    Counts::~Counts() {};


    //WordCounter

    WordCounter::WordCounter() {
        this->total_words = 0;
        this->distinct_words = 0;
    }

    WordCounter::WordCounter(std::initializer_list<Word> words){
        this->total_words = 0;
        this->distinct_words = 0;
        bool word_doesnt_exists;
        for(auto x: words){
            word_doesnt_exists = true;
            this->total_words++;

            // for(auto y: this->words_list) { do smth } doesnt work, it loses data out of loop
            for (std::list<std::pair<Word, Counts>>::iterator i = this->words_list.begin(), end = this->words_list.end(); i != end; i++){
                if(x.word == i->first.word){
                    i->second.count++;
                    word_doesnt_exists = false;
                    break;
                }
            }
            if(word_doesnt_exists){
                this->words_list.push_back({x,x.count});
                this->distinct_words++;
            }
        }

    }

    WordCounter::~WordCounter(){};

    int WordCounter::TotalWords() {
        return this->total_words;
    }

    int WordCounter::DistinctWords() {
        return this->distinct_words;
    }

    std::set<Word> WordCounter::Words(){
        std::set<Word> words;
        for(auto x: this->words_list) words.emplace(x.first);
        return words;
    }
}