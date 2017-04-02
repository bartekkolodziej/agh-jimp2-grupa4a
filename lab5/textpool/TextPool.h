//
// Created by bartek on 31.03.17.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H

#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>
#include <vector>
#include <algorithm>


namespace pool{

    class TextPool{
    public:

        TextPool();
        TextPool(TextPool &&text_pool);
        TextPool &operator=(TextPool &&text_pool);
        TextPool(const std::initializer_list<std::string> &elements);
        ~TextPool();
        size_t StoredStringCount() const;
        std::experimental::string_view Intern(const std::string &str);
        friend void swap(TextPool& lhs, TextPool& rhs);


        std::vector<std::experimental::string_view> elements_;
        size_t count_;

    };

}

#endif //JIMP_EXERCISES_TEXTPOOL_H
