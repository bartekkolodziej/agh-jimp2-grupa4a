//
// Created by bartek on 31.03.17.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H

#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>

namespace pool{

    class TextPool{
    public:

        TextPool();
        //1. konstruktor kopiujący
        //TextPool(const TextPool &text);
        //2. konstruktor przenoszący
        TextPool(TextPool &&text_pool);
        //3. operator przypisania kopiujący
        //TextPool &operator=(const TextPool &text);
        //4. operator przypisania przenoszący
        TextPool &operator=(TextPool &&text_pool);
        //5. konstruktor z lista inicjalizacyjna
        TextPool(const std::initializer_list<std::string> &elements);
        //5. Destruktor
        ~TextPool();
        size_t StoredStringCount() const;
        std::experimental::string_view Intern(const std::string &str);

        std::string text_;
        std::vector<std::string> elements_;
        size_t count_;

    };





}

#endif //JIMP_EXERCISES_TEXTPOOL_H
