#include <iostream>
#include "TaskManager.h"

using std::cout;
using std::endl;
using std::string;

int main(int argc, char* argv[])
{
    cout << "Starting Task Manager" << endl;

    if (argc > 1 && argc <= 3){
        string comd = argv[1];
        if (comd == "add"){
            add_task(argv[2], argv[3]);
        } else if (comd == "list"){
            list_tasks();
        } else if (comd == "complete"){
            // mark task as compelte
        } else if (comd == "remove") {
            // remove a task by ID
        } else if (comd == "update") {
            // update the task based on ID to set the priority
        }

    // error cases
    } else if (argc == 1) {
        cout << "ERR: Need to input arguments to run Task Manager" << endl;
        return 1;
    } else {
        cout << "ERR: Entered too many input arguments" << endl;
        return 1;
    }
    return 0;
}