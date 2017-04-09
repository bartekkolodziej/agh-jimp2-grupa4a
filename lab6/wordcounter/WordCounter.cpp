//
// Created by bartek on 09.04.17.
//

#include "WordCounter.h"

namespace datastructures {

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

    Word::Word(){
        this->word = "";
    }

    Word::Word(std::string word) {
        this->word = word;
        this->count = 1;
    }

    Word::~Word() {};

    Counts::Counts() {
        this->count = 1;
    }

    Counts::Counts(int number){
        this->count = number;
    }

    Counts::~Counts() {};

    WordCounter::WordCounter() {
        this->total_words = 0;
        this->distinct_words = 0;
    }

    int WordCounter::TotalWords() {
        return this->total_words;
    }
    //g

    int WordCounter::DistinctWords() {
        return this->distinct_words;
    }

    std::set<Word> WordCounter::Words(){
        std::set<Word> words;
        for(auto x: this->words_list) words.emplace(x.first);
        return words;
    }

    WordCounter::~WordCounter(){};

    WordCounter::WordCounter(std::initializer_list<Word> words){
        this->total_words = 0;
        this->distinct_words = 0;
        bool word_doesnt_exists;
        for(auto x: words){
            word_doesnt_exists = true;
            this->total_words++;
            for(auto y: this->words_list){
                if(x.word == y.first.word){
                    y.second.count += 1;
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



    /* probalby there's no need to use constructor that reads from file, in tests, only constructor with initializer list
     * is required, anywar its not completed
     WordCounter::WordCounter(std::string file_name) {
          std::fstream file;
          std::pair<Word, Counts> single_word;
          std::string tmp = "";
          char ch;
          bool if_exists;

          file.open(file_name, std::ios::in);

          if (file.good() == true) {
              while (!file.eof()) {
                  while (ch != ' ' or ch != ',' or ch != '!' or ch != '.') {
                      file.get(ch);
                      tmp += ch;
                  }
                  for (auto x: this->words_list) {
                      if (x.first.word == tmp) {
                          x.second.count += 1;
                          if_exists = true;
                          break;
                      }
                  }
                  if(if_exists == false) {
                      Word tmp_word(tmp);
                      Counts tmp_count{};
                      single_word.first = tmp_word;
                      single_word.second = tmp_count;
                      this->words_list.push_back(single_word);
                  }

              }
          } else {
              std::cout << "File doesn't exists";
          }
      }

      */

}