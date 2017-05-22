//
// Created by bartosz on 21.05.17.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include <vector>
#include <map>
#include <stdexcept>
#include <set>

namespace academia{
    class SchedulingItem{
    public:

        SchedulingItem(){};
        SchedulingItem(int course_id, int teacher_id, int room_id, int time_slot, int year): course_id{course_id}, teacher_id{teacher_id}, room_id{room_id}, time_slot{time_slot}, year{year}{}
        int course_id;
        int teacher_id;
        int room_id;
        int time_slot;
        int year;

        ~SchedulingItem(){};

    };

    class Schedule{
    public:

        Schedule(){};

        Schedule OfTeacher(int teacher_id) const ;
        Schedule OfRoom(int room_id) const;
        Schedule OfYear(int year) const;

        std::vector<int> AvailableTimeSlots(int n_time_slots) const;

        void InsertScheduleItem(const SchedulingItem &item){this->items.push_back(item);};

        size_t Size() const{return this->items.size();};

        std::vector<SchedulingItem> items;

        ~Schedule(){};
    };

    class Scheduler{
    public:
        Scheduler(){};
        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) = 0;
        virtual ~Scheduler() = 0;
    };


    class GreedyScheduler: public Scheduler{
    public:
        GreedyScheduler(){};
        Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year, int n_time_slots);
        int FindTeacher( const std::map<int, std::vector<int>> &teacher_courses_assignment,int course_id);
        bool IsScheduled(Schedule *schedule, int year, const std::vector<int> &rooms, int teacher, int course, int n_time_slots);
        ~GreedyScheduler(){};
    };

    class NoViableSolutionFound : public std::runtime_error{
    public:
        NoViableSolutionFound(std::string error_message) : std::runtime_error(error_message){};

        virtual ~NoViableSolutionFound(){};
    };

}

#endif //JIMP_EXERCISES_SCHEDULER_H


