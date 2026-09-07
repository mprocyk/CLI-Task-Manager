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
    Task::Status task_status = new_task->NOT_STARTED;

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
    task_file.open(task_fname);
    if (task_file.is_open()) {
        task_file << new_task->ID << " ";
        task_file << new_task->description << " ";
        task_file << task_status << " ";
        task_file << task_priority << " ";
        task_file << new_task->created_date << "\n";
        task_file.close();
    } else {
        std::cout << "Cannot find task file to open it" << std::endl;
    }
}