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

    public:
    User():m_id(0),username(""),password(""),tasks{0},is_log(false){};

    User(const std::string& username, const std::string& password,int id)
    :username(username),password(password),m_id(id),is_log(false),tasks(0){};
    
    User(User&& other) noexcept
    {
        m_id = other.m_id;
        password = std::move(other.password);
        username = std::move(other.username);
        is_log = other.is_log;
        other.is_log = false;
        other.m_id = 0;
        tasks = std::move(other.tasks);
    }

    ~User(){};

    void login();
    void logout();
    void addTask(Task* task);
    void deleteTask(const int& id);
    void editTask(Task* task, const Task& updatedTask);
    void listTasks() const;
    Task* searchTask(const std::string& title);
    int get_id()const;
    std::string get_username()const;
    std::string get_password()const;
    void set_is_log(bool);

    explicit operator bool()
    {
        if(is_log == true)
        {
            return true;
        }
        return false;
    }

    friend std::ostream& operator<<(std::ostream& os, const User& us)
    {
        os<<us.m_id<<std::endl;
        os<<us.username<<std::endl;
        os<<us.password<<std::endl;
        os<<us.is_log<<std::endl;
        for(int i = 0; i < us.tasks.size(); ++i)
        {
            os<<"Task - "<<i<<std::endl<<(*(us.tasks[i]));
        }
        std::cout<<std::endl;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, User& us)
    {
        is>>us.m_id;
        is>>us.username;
        is>>us.password;
        is>>us.is_log;
        for(int i = 0; i < us.tasks.size(); ++i)
        {
            is>>(*(us.tasks[i]));
        }
        return is;
    }

};

#endif