#ifndef TASK_MANAGER
#define TASK_MANAGER
#include "header.h"
#include "user.h"
#include "task.h"

class TaskManager
{
    std::vector<User*> users;
    std::vector<Task*> all_tasks;

    public:
    TaskManager():users(0),all_tasks(0) {};

    TaskManager(const TaskManager& other)
    {
        users = other.users;
        all_tasks = other.all_tasks;
    }

    TaskManager(TaskManager&& other) noexcept
    {
        users = std::move(other.users);
        all_tasks = std::move(other.all_tasks);
    }

    ~TaskManager()
    {
        for(int i=0; i < users.size(); ++i)
        {
            delete users[i];
        }
        for(int i = 0; i < all_tasks.size(); ++i)
        {
            delete all_tasks[i];
        }
    }
   

    void registerUser(const std::string& username, const std::string& password, const int& id);
    void login(const std::string& username, const std::string& password);
    void logout(const int& id);
    void addTaskForUser(Task* task, const int& id);
    void deleteTaskForUser(const std::string& title, const int& id);
    void editTaskForUser(const std::string& title, const Task& updatedTask, const int& id);
    void displayTasksForUser() const;
    void add_task();
};

#endif