//
// Created by bartek on 31.05.17.
//

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H

#include <string>
#include <unordered_map>
#include <chrono>
#include <ctime>

namespace profiling{

    template<typename T>
    std::pair<T, double> TimeRecorder(T object){
        std::chrono::time_point<std::chrono::system_clock> start, end;
        start = std::chrono::system_clock::now();
        T wynik = object();
        end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        std::pair<T, double> to_return{wynik, elapsed_seconds.count()};

        return to_return;
    };
}

#endif //JIMP_EXERCISES_TIMERECORDER_H
