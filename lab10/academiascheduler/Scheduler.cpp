//
// Created by bartosz on 21.05.17.
//

#include "Scheduler.h"
#include <algorithm>


namespace  academia {



    Schedule Schedule::OfTeacher(int teacher_id) const {
        Schedule schedule;
        std::copy_if(this->items.begin(), this->items.end(), std::back_inserter(schedule.items),
                     [teacher_id](SchedulingItem item) {return item.teacher_id == teacher_id;});
        return schedule;
    }

    Schedule Schedule::OfRoom(int room_id) const {
        Schedule schedule;
        std::copy_if(this->items.begin(), this->items.end(), std::back_inserter(schedule.items),
                     [room_id](SchedulingItem item) {return item.room_id == room_id; });
        return schedule;
    }

    Schedule Schedule::OfYear(int year) const {
        Schedule schedule;
        std::copy_if(this->items.begin(), this->items.end(), std::back_inserter(schedule.items), [year](SchedulingItem item) {return item.year == year;});
        return schedule;
    }

    std::vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const {
        std::vector<int> TimeSlots;
        for(int i=0; i<n_time_slots; i++) TimeSlots.push_back(i+1);
        
        for(auto x: this->items) {
            TimeSlots.erase(std::remove(TimeSlots.begin(), TimeSlots.end(), x.time_slot),
                            TimeSlots.end());
        }
        
        return TimeSlots;
    }

    void Schedule::operator=(const Schedule schedule){
        this->items = schedule.items;
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

