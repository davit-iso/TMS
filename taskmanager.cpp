#include "taskmanager.h"

void TaskManager::registerUser(const std::string& username, const std::string& password, const int& id)
{
    User* user = new User(username,password,id);
    users.push_back(user);
    std::cout<<"\nUser "<<username<<" is created"<<std::endl;
}
void TaskManager::login(const std::string& username, const std::string& password)
{
    for(int i=0; i < users.size(); ++i)
    {
        if(users[i] -> get_username() == username)
        {
            if(users[i] -> get_password() == password)
            {
                users[i] -> set_is_log(true);
                std::cout<<"\nUser "<<users[i] -> get_username()<<" is loged in\n"<<std::endl;
            }
        }
    }
}
void TaskManager::logout(const int& id)
{
    for(int i = 0; i<users.size(); ++i)
    {
        if(users[i] -> get_id() == id)
        {
            users[i] -> set_is_log(false);
            std::cout<<"\nUser "<<users[i]->get_username()<<" is loged out\n"<<std::endl;
        }
    }
}
void TaskManager::addTaskForUser(Task* task, const int& id)
{
    for(int i=0; i < users.size(); ++i)
    {
        if(users[i] -> get_id() == id)
        {
            users[i] -> addTask(task);
            all_tasks.push_back(task);
            std::cout<<"The task - "<<task->get_title()<<" is added for user - "<<users[i]->get_username()<<std::endl;
            return;
        }
    }
    std::cout<<"User not found!"<<std::endl;
}
void TaskManager::deleteTaskForUser(const std::string& title, const int& id)
{
    for(int i = 0; i < users.size(); ++i)
    {
        if(users[i] -> get_id() == id)
        {
            Task* task = users[i] -> searchTask(title);
            if (task != nullptr)
            {
                users[i] -> deleteTask(task->get_tid());
                std::cout<<"The task - "<<title<<" deleted for user - "<<users[i]->get_username()<<std::endl;
            }
            else
            {
                std::cout<<"Task not found!"<<std::endl;
            }
        }
    }
    for(int i = 0; i < all_tasks.size(); ++i)
    {
        if(all_tasks[i] -> get_title() == title)
        {
            all_tasks.erase(all_tasks.begin()+i);
        }
    }
}

void TaskManager::editTaskForUser(const std::string& title, const Task& updatedTask, const int& id)
{
    for(int i = 0; i < users.size(); ++i)
    {
        if(users[i] -> get_id() == id)
        {
            users[i]->editTask(users[i]->searchTask(title),updatedTask);
        }
    }
}
void TaskManager::displayTasksForUser() const
{
    for(int i = 0; i < users.size(); ++i)
    {
        std::cout<<users[i] -> get_username()<<std::endl;
        users[i] -> listTasks();
    }
}
