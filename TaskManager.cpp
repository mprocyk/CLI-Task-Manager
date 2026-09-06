#include <iomanip>
#include <ctime>
#include <sstream>
#include <fstream>
#include "Task.h"
#include "TaskManager.h"

using std::put_time;
using std::ofstream;
using std::string;

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
    Task::Priority task_priority = new_task->MEDIUM;

    // append this new task to the tasks txt file
    string task_fname = "tasks.txt";
    ofstream task_file;
    task_file.open(task_fname);
    task_file << new_task->ID << "\n";
    task_file << new_task->description << "\n";
    task_file << task_status << "\n";
    task_file << task_priority << "\n";
    task_file.close();
}