#include <iomanip>
#include <ctime>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Task.h"
#include "TaskManager.h"

using namespace std;

void add_task(char* description, char* priority){
    Task *new_task = new Task();

    // set description to given arg
    new_task->description = description;

    // get the current time for time stamp
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%d-%m-%Y %H-%M-%S");
    new_task->created_date = oss.str();

    // status defaults to not started
    Task::Status task_status;

    // priority defaults to medium
    Task::Priority task_priority;

    switch(task_status){
        case Task::NOT_STARTED:
            break;
        case Task::DONE:
            break;
        case Task::IN_PROGRESS:
            break;
        default:
            task_status = new_task->NOT_STARTED;
    }

    switch(task_priority){
        case Task::LOW:
            break;
        case Task::MEDIUM:
            break;
        case Task::HIGH:
            break;
        default:
            task_priority = new_task->MEDIUM;
    }

    // append this new task to the tasks txt file
    string task_fname = "tasks.txt";
    ofstream task_file;
    task_file.open(task_fname, std::ios_base::app | std::ios_base::out);
    if (task_file.is_open()) {
        task_file << "ID: " << new_task->ID << " | ";
        task_file << new_task->description << " | ";
        task_file << get_task_stat(task_status) << " | ";
        task_file << get_task_prio(task_priority) << " | ";
        task_file << new_task->created_date << "\n";
        task_file.close();
    } else {
        std::cout << "Cannot find task file to open it" << std::endl;
    }
}

std::string get_task_prio(Task::Priority task_priority){
    std::string task_prio;

    switch (task_priority){
    case Task::HIGH:
        task_prio = "HIGH";
    case Task::MEDIUM:
        task_prio = "MEDIUM";
    case Task::LOW:
        task_prio = "LOW";
    }

    return task_prio;
}

std::string get_task_stat(Task::Status task_status){
    std::string task_stat;

    switch(task_status){
    case Task::DONE:
        task_stat = "DONE";
    case Task::IN_PROGRESS:
        task_stat = "IN PROGRESS";
    case Task::NOT_STARTED:
        task_stat = "NOT STARTED";
    }

    return task_stat;
}

/*int get_id(Task, std::ofstream task_file){
    // go through lines of task_file
    // search for task description == Task->Description
    eturn id;
}*/