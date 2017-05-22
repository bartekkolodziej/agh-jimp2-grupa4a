//
// Created by bartosz on 21.05.17.
//

#include "Scheduler.h"
#include <algorithm>


namespace  academia {



    Schedule Schedule::OfTeacher(int teacher_id) const {
        Schedule schedule;
        std::copy_if(this->items.begin(), this->items.end(), std::back_inserter(schedule.items),
                     [teacher_id](SchedulingItem item) {
                         item.teacher_id = teacher_id;
                         return item.teacher_id;
                     });
        return schedule;
    }

    Schedule Schedule::OfRoom(int room_id) const {
        Schedule schedule;
        std::copy_if(this->items.begin(), this->items.end(), std::back_inserter(schedule.items),
                     [room_id](SchedulingItem item) {
                         item.room_id = room_id;
                         return item.room_id;
                     });
        return schedule;
    }

    Schedule Schedule::OfYear(int year) const {
        Schedule schedule;
        std::copy_if(this->items.begin(), this->items.end(), std::back_inserter(schedule.items), [year](SchedulingItem item) {
            item.year = year;
            return item.year;
        });
        return schedule;
    }

    std::vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const {
        std::vector<int> TimeSlots;
        std::remove_if(TimeSlots.begin(), TimeSlots.end(), [this](int x){for(auto v: this->items)return v.time_slot=x;});
        return TimeSlots;
    }

    Schedule GreedyScheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                                 const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                                 const std::map<int, std::set<int>> &courses_of_year,
                                                 int n_time_slots) {

        Schedule schedule;
        for (auto year : courses_of_year){
            for (auto course: year.second){
                int teacher = FindTeacher(teacher_courses_assignment,course);
                if(!IsScheduled(&schedule,year.first,rooms,teacher,course,n_time_slots)) throw NoViableSolutionFound("No viable solution found.");
            }
        }
        return schedule;

    }

    int GreedyScheduler::FindTeacher(const std::map<int, std::vector<int>> &teacher_courses_assignment, int course_id) {
        for(auto teacher:teacher_courses_assignment){
            for(auto course:teacher.second) if(course==course_id) return teacher.first;
        }
        return int();
    }

    bool GreedyScheduler::IsScheduled(Schedule *schedule, int year, const std::vector<int> &rooms, int teacher, int course, int n_time_slots) {
        for (auto room:rooms){
            for(auto room_slot: schedule->OfRoom(room).AvailableTimeSlots(n_time_slots)){
                for(auto year_slot: schedule->OfYear(year).AvailableTimeSlots(n_time_slots)){
                    for(auto teacher_slot: schedule->OfTeacher(teacher).AvailableTimeSlots(n_time_slots)){
                        if(year_slot == teacher_slot && year_slot == room_slot && room_slot == teacher_slot)
                        {
                            schedule->InsertScheduleItem(SchedulingItem {course, teacher, room, year_slot, year});
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
}

