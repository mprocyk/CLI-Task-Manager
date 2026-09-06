#pragma once

#ifndef TASK_H
#define TASK_H

#endif // TASK_H

#include <string>

class Task{
    public:
        int ID;
        std::string description;
        std::string created_date;

        enum Status {
            NOT_STARTED,
            IN_PROGRESS,
            DONE
        };

        enum Priority{
            LOW,
            MEDIUM,
            HIGH
        };
};