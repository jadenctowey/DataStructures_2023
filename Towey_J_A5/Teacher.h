#ifndef TEACHER_H
#define TEACHER_H

#include "DblList.h"
#include <string>
class Teacher{
    public:
        Teacher();
        Teacher(int id);
        Teacher(int Id, std::string name, std::string level, std::string department);
        ~Teacher();
        int getId();
        std::string getName();
        std::string getLevel();
        std::string getDepartment();
        void addAdvisee(int id);
        void removeAdvisee(int id);
        int getAdvisorSize();

        //These operators dont work.  Not sure why could not find any information that helped.
        bool operator>(Teacher& other);
        bool operator<(Teacher& other);
        bool operator==(Teacher& other);
        bool operator==(const Teacher& other) const;
        bool operator>(const Teacher& other) const;
        bool operator<(const Teacher& other) const;
        bool operator!=(Teacher& other);
        bool operator!=(const Teacher& other) const;
        bool operator==(Teacher *teacher);
        bool operator>(Teacher *other);
        bool operator<(Teacher *other);
        bool operator!=(Teacher *other);

        //This function works
        bool equals(Teacher *teacher);
        bool operator==(const Teacher* other) const;
        friend std::ostream& operator<<(std::ostream& os, Teacher *teacher);
        DblList<int>* advisees;

    private:
        int m_id;
        std::string m_name;
        std::string m_level;
        std::string m_department;        
};

#endif