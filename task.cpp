#include "task.h"

void Task::markCompleted()
{
    m_completed = true;
}

void Task::editTask(const std::string newTitle, const std::string newDescription, const std::string newDeadline, const std::string newCategory, const PRIO newPriority,const int id, const int tid, const bool com, const Status st)
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
    //std::cout<<"Title "<<m_title<<"\nDescription "<<m_description<<"\nDeadline "<<m_deadline<<"\nCategory "<<m_category<<"\nPriority "<<m_priority<<"\nCompleted "<<m_completed<<"\nStatus "<<m_status<<"\nTask ID "<<m_task_id<<"\nID "<<m_id<<std::endl; 
    std::cout<<(*this);
}

void Task::set_status(Status st)
{
    m_status = st;
}

void Task::set_prio(PRIO pr)
{
    m_priority = pr;
}

const std::string& Task::get_title()const
{
    return m_title;
}

int Task::get_tid()const
{
    return m_task_id;
}

Task::Task(Task&& other) noexcept
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
        //
        other.m_task_id = 0;
        other.m_id = 0;
        other.m_status = LOW;
        other.m_priority = NOT_STARTED;
        other.m_completed = false;
    };

Task& Task::operator=(const Task& other)
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
        return *this;
    }

    bool Task::operator==(const Task& rhs)
    {
        //if(m_task_id == rhs.m_task_id && m_id == rhs.m_id && m_title == rhs.m_title && m_description)
        if(m_task_id == rhs.m_task_id)
        {
            return true;
        }
        return false;
    }

    bool Task::operator!=(const Task& rhs)
    {
        if(m_task_id != rhs.m_task_id)
        {
            return true;
        }
        return false;
    }

    bool Task::operator>(const Task& rhs)
    {
        if(m_priority > rhs.m_priority)
        {
            return true;
        }
        return false;
    }

    bool Task::operator<(const Task& rhs)
    {
        if(m_priority < rhs.m_priority)
        {
            return true;
        }
        return false;
    }

    Task& Task::operator++()
    {
        if(int a = static_cast<int>(m_priority) <= 1)
        {
            m_priority = static_cast<PRIO>(m_priority + 1);
        }
        else
        {
            static_cast<PRIO>(m_priority);
            std::cout<<"Priority is at the highest level!"<<std::endl;
        }
        return *this;
    }

    Task Task::operator--(int)
    {
        Task tmp = *this;
        if(static_cast<int>(m_priority) >= 1)
        {
            m_priority = static_cast<PRIO>(m_priority - 1);
        }
        else
        {
            static_cast<PRIO>(m_priority);
            std::cout<<"Priority is at the lowest level!"<<std::endl;
        }
        return tmp;
    }

void Task::set_id(int id)
{
    m_id = id;
}