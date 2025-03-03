#include "user.h"

void User::login()
{
    is_log = true;
}
void User::logout()
{
    is_log = false;
}
void User::addTask(Task* task)
{
    tasks.push_back(task);
}
void User::deleteTask(const int& id)
{
    for(int i=0; i<tasks.size(); ++i)
    {
        if((tasks[i]->get_tid()) == id)
        {
            tasks[i]->set_id(0);
            tasks.erase(tasks.begin()+i);
        }
    }
}
void User::editTask( Task* task, const Task& updatedTask)
{
    *task = updatedTask;
}
void User::listTasks() const
{
    for(int i=0; i<tasks.size(); ++i)
    {
        tasks[i] -> displayTask();
    }
}
Task* User::searchTask(const std::string& title)
{
    for(int i=0; i < tasks.size(); ++i)
    {
        if(tasks[i] -> get_title() == title)
        {
            return tasks[i];
        }
    }
    return nullptr;
}
int User::get_id()const
{
    return m_id;
}

std::string User::get_username()const
{
    return username;
}

std::string User::get_password()const
{
    return password;
}

void User::set_is_log(bool con)
{
    is_log = con;
}