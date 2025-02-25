#ifndef TASK
#define TASK
#include "header.h"

enum Status{LOW,MID,HIGH,URG=99};
enum PRIO{NOT_STARTED,IN_PROGRESS,COMPLETED};

class Task
{
    int m_task_id;
    int m_id;
    std::string m_title;
    std::string m_description;
    std::string m_deadline;
    std::string m_category;
    Status m_status;
    PRIO m_priority;
    bool m_completed;

    public:
    Task()
    :m_title(""),m_task_id(0),m_id(0),m_description(""),m_deadline(""),m_category(""),m_status(LOW),m_priority(NOT_STARTED),m_completed(false)
    { std::cout<<"Task def ctor"<<std::endl;};
    
    Task(const std::string& title, const std::string& description, const std::string& deadline, const std::string& category,const int& tid, const int id,Status st,PRIO pr)
    :m_title(title),m_description(description),m_deadline(deadline),m_category(category),m_priority(pr),m_status(st),m_task_id(tid),m_id(id)
    { std::cout<<"Task param"<<std::endl; };
    
    Task(const Task& other)
    :m_task_id(other.m_task_id),m_id(other.m_id),m_title(other.m_title),m_description(other.m_description),m_deadline(other.m_deadline),m_category(other.m_category),m_status(other.m_status),m_priority(other.m_priority),m_completed(other.m_completed)
    { std::cout<<"Task copy"<<std::endl; };
    
    Task(Task&& other) noexcept
    {
        m_task_id = other.m_task_id;
        m_id = other.m_id;
        m_title = std::move(other.m_title);
        m_description = std::move(other.m_description);
        m_deadline = std::move(other.m_deadline);
        m_category = std::move(other.m_category);
        m_status = other.m_status;
        m_priority = other.m_priority;
        m_completed = other.m_completed;
        std::cout<<"Task move ctor"<<std::endl;
    };

    Task& operator=(const Task& other)
    {
        m_task_id = other.m_task_id;
        m_id = other.m_id;
        m_title = other.m_title;
        m_description = other.m_description;
        m_deadline = other.m_deadline;
        m_category = other.m_category;
        m_status = other.m_status;
        m_priority = other.m_priority;
        m_completed = other.m_completed;
        std::cout<<"Task copy assignment"<<std::endl;
        return *this;
    }

    ~Task(){ std::cout<<"Task dtor"<<std::endl; };

    void markCompleted();
    void editTask(const std::string& newTitle, const std::string& newDescription, const std::string& newDeadline, const std::string& newCategory, const PRIO& newPriority,const int& id, const int& tid, const bool& com, const Status& st);
    void displayTask() const;
    void set_status(Status st);
    void set_prio(PRIO pr);
    std::string get_title()const;
    int get_tid()const;
};

#endif