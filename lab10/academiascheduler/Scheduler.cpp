//
// Created by bartosz on 21.05.17.
//

#include "Scheduler.h"
#include <algorithm>


namespace  academia {

    Schedule Schedule::OfTeacher(int teacher_id) const {
        Schedule schedule;
        std::copy_if(this->items.begin(), this->items.end(), std::back_inserter(schedule.items),
                     [](SchedulingItem item) { return item.teacher_id = teacher_id; });
        return schedule;
    }

    Schedule Schedule::OfRoom(int room_id) const {
        Schedule schedule;
        std::copy_if(this->items.begin(), this->items.end(), std::back_inserter(schedule.items),
                     [](SchedulingItem item) { return item.room_id = room_id; });
        return schedule;
    }

    Schedule Schedule::OfYear(int year) const {
        Schedule schedule;
        std::copy_if(this->items.begin(), this->items.end(), std::back_inserter(schedule.items), [](SchedulingItem item) { return item.year = year; });
        return schedule;
    }

    std::vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const {
        std::vector<int> TimeSlots (n_time_slots);
        std::remove_if(TimeSlots.begin(), TimeSlots.end(), [](int x){for(auto v:this->items)return v.time_slot=x;});
        return TimeSlots;
    }
}

