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
    t->editTask("title","p","l","pp",IN_PROGRESS,90,89,true,LOW);
    Task* t2 = new Task(*t);
    Manager.addTaskForUser(t,100);
    Manager.displayTasksForUser();
    return 0;
}