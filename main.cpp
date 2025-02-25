#include "header.h"
#include "task.h"
#include "taskmanager.h"
#include "user.h"

int main()
{
    TaskManager Manager;
    Manager.registerUser("John","Passw",100);
    Manager.login("John","Passw");
    Task* t = new Task;
    Manager.addTaskForUser(t,100);
    Manager.displayTasksForUser();
    return 0;
}