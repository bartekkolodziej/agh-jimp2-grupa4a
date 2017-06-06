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
    EXPECT_EQ(44, to_arabic("XLIV"));
}

TEST_F(ArabicToRomanTest, NotARomanNumberThrowException) {
    EXPECT_THROW(to_arabic("asdasd"),InvalidInput);
}