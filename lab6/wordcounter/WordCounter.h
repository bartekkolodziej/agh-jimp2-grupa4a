//
// Created by bartosz on 09.04.17.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <string>
#include <fstream>
#include <iostream>

class Word{
    public:
        Word();
        Word(std::string new_word);
        ~Word();
        std::string word;
};


class Counts{
    public:
        Counts();
        ~Counts();
        void operator ++ ();
        int counts;
};
class WordCounter{
    public:
        WordCounter();
        WordCounter(std::string path);
        int FindWord(std::string word);
        int operator[](std::string word);
        list<std::pair<Word,Counts>> word_list;
};

#endif //JIMP_EXERCISES_WORDCOUNTER_H
