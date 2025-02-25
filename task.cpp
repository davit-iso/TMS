#include "task.h"

void Task::markCompleted()
{
    m_completed = true;
}

void Task::editTask(const std::string& newTitle, const std::string& newDescription, const std::string& newDeadline, const std::string& newCategory, const PRIO& newPriority,const int& id, const int& tid, const bool& com, const Status& st)
{
    m_title = newTitle;
    m_description = newDescription;
    m_deadline = newDeadline;
    m_category = newCategory;
    m_priority = newPriority;
    m_task_id = tid;
    m_completed = com;
    m_status = st;
    m_id = id;
}

void Task::displayTask() const
{
    std::cout<<"Title "<<m_title<<"\nDescription "<<m_description<<"\nDeadline "<<m_deadline<<"\nCategory "<<m_category<<"\nPriority "<<m_priority<<"\nCompleted "<<m_completed<<"\nStatus "<<m_status<<"\nTask ID "<<m_task_id<<"\nID "<<m_id<<std::endl; 
}

void Task::set_status(Status st)
{
    m_status = st;
}

void Task::set_prio(PRIO pr)
{
    m_priority = pr;
}

std::string Task::get_title()const
{
    return m_title;
}

int Task::get_tid()const
{
    return m_task_id;
}