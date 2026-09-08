#pragma once

#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#endif // TASKMANAGER_H

#include <vector>
#include <fstream>
#include "Task.h"

void add_task(char* description, char* priority);
std::string get_task_prio(Task::Priority task_priority);
std::string get_task_stat(Task::Status task_status);
int get_id(Task, std::ofstream task_file);
void remove_task();
std::vector<Task> list_tasks();