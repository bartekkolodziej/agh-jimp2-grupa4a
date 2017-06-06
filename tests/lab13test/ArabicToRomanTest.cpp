//
// Created by mwypych on 01.06.17.
//

#include <string>
#include <unordered_map>
#include <gtest/gtest.h>
#include <MemLeakTest.h>
#include "ArabicRoman.h"
#include <stdexcept>


using ::to_roman;
using ::std::literals::string_literals::operator""s;


class ArabicToRomanTest : public ::testing::Test {
public:
};

TEST_F(ArabicToRomanTest, CanConvertPositiveNumber) {
    EXPECT_EQ("XLIV"s, to_roman(44));
}

TEST_F(ArabicToRomanTest, NegativeNumberThrowException) {
    EXPECT_THROW(to_roman(-12),NegativeNumber);
}

TEST_F(ArabicToRomanTest, OutOfNumberThrowException) {
    EXPECT_THROW(to_roman(4000),OutOfRange);
}