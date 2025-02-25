#ifndef USER
#define USER
#include "header.h"
#include "task.h"


class User
{
    int m_id;
    std::string username;
    std::string password;
    std::vector<Task*> tasks;
    bool is_log;
    //TaskManager* man;

    public:
    User():m_id(0),username(""),password(""),tasks{0},is_log(false)
    { std::cout<<"Ctor for User"<<std::endl; };
    User(const std::string& username, const std::string& password,int id)
    :username(username),password(password),m_id(id),is_log(false),tasks(0)
    { std::cout<<"Param ctor for User"<<std::endl; };
    
    // User(const User& other)
    // :username(other.username),password(other.password)
    // {
    //     std::vector<Task*> tasks(other.tasks.size());
    //     for(int i=0; i < (other.tasks).size(); ++i)
    //     {
    //         tasks[i] = (other.tasks)[i];
    //     }
    // }
    
    User(User&& other) noexcept
    {
        m_id = other.m_id;
        password = std::move(other.password);
        username = std::move(other.username);
        is_log = other.is_log;
        other.is_log = false;
        other.m_id = 0;
        tasks = std::move(other.tasks);
        std::cout<<"Move ctor for User"<<std::endl;
    }

    ~User()
    { 
        for(int i = 0; i<tasks.size(); ++i)
        {
            delete tasks[i];
        }
        std::cout<<"Dtor for User"<<std::endl; 
    }

    void login();
    void logout();
    void addTask(Task* task);
    void deleteTask(const int& id);
    void editTask(Task* task, const Task& updatedTask);
    void listTasks() const;
    Task* searchTask(const std::string& title);
    //
    int get_id()const;
    std::string get_username()const;
    std::string get_password()const;
    void set_is_log(bool);
};

#endif