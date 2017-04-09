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
#include <set>



namespace datastructures {


    class Counts {
    public:
        Counts();
        Counts(int number);

        ~Counts();

        int count;
    };


    class Word {
    public:
        Word();
        Word(std::string word);

        ~Word();

        std::string word;
        Counts count_;
    };

    class WordCounter {
    public:
        WordCounter();
        WordCounter(std::initializer_list<Word> words);
        // its probably necessary WordCounter(std::string file);
        int TotalWords();
        int DistinctWords();
        std::set<Word> Words();

        ~WordCounter();
        int & operator[](std::string word);


        std::list<std::pair<Word, Counts>> words_list;
        int total_words;
        int distinct_words;

    };

}
#endif //JIMP_EXERCISES_WORDCOUNTER_H
