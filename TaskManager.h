#pragma once

#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#endif // TASKMANAGER_H

#include <vector>
#include "Task.h"

void add_task(char* description, char* priority);
void remove_task();
std::vector<Task> list_tasks();