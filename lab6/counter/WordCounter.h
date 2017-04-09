//
// Created by bartek on 09.04.17.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <iostream>
#include <string>
#include <list>
#include <utility>
#include <fstream>

class Word{
public:
    Word(std::string word_);
    ~Word();

    std::string word;
};

class Counts{
public:
    Counts();
    ~Counts();

    int count;
};

class WordCounter{
public:
    WordCounter(std::string file);
    ~WordCounter();

private:
    std::list<std::pair<Word, Counts>> words_list;
};

#endif //JIMP_EXERCISES_WORDCOUNTER_H
