//
// Created by bartek on 14.03.17.
//

#include "MinimalTimeDifference.h"

namespace minimaltimedifference {

    int Difference(int a, int b) {
        if(abs(a-b) <= 720) return abs(a - b);
        if(abs(a-b) > 720) return 1440 - abs(a-b);
        return 0;
    }

    int FindMinDifference(const std::vector<int> &differences) {
        int min = differences[0];
        for (auto i: differences) {
            if (i < min) min = i;
        }
        return min;
    }

    unsigned int ToMinutes(std::string time_HH_MM) {
        int minutes = 0;
        std::regex pattern {R"((\d{1,2}):(\d{2}))"};
        std::smatch matches;
        if (regex_match(time_HH_MM, matches, pattern)) {
            if (matches[1].length() == 2) {
                minutes += (time_HH_MM[0] - 48) * 600 + (time_HH_MM[1] - 48) * 60 + (time_HH_MM[3] - 48) * 10 +
                           (time_HH_MM[4] - 48);
            } else {
                minutes += (time_HH_MM[0] - 48) * 60 + (time_HH_MM[2] - 48) * 10 + (time_HH_MM[3] - 48);
            }
        }
        return minutes;
    }

    unsigned int MinimalTimeDifference(const std::vector<std::string> &times) {
        std::vector<int> times_minutes;
        std::vector<int> differences;
        for (auto x: times) times_minutes.push_back(ToMinutes(x));
        for (int i = 0; i < times_minutes.size(); i++) {
            for (int j = 0; j < times_minutes.size(); j++) {
                if (i != j) differences.push_back(Difference(times_minutes[i], times_minutes[j]));
            }
        }
        return FindMinDifference(differences);
    }
}