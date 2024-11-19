#ifndef STUDENT_H
#define STUDENT_H

#include <string>
class Student{
    public:
        Student();
        Student(int Id, std::string name, std::string level, std::string major, double Gpa, int Advisor);
        Student(int Id);
        ~Student();
        int getId() const;
        std::string getName();
        std::string getLevel();
        std::string getMajor();
        double getGpa();
        int getAdvisor();

        //Overloaded Operators
        bool operator>(Student& other);
        bool operator<(Student& other);
        bool operator==(Student& other);
        bool operator==(const Student& other) const;
        bool operator>(const Student& other) const;
        bool operator<(const Student& other) const;
        bool operator!=(Student& other);
        bool operator!=(const Student& other) const;
        friend std::ostream& operator<<(std::ostream& os, const Student& student);


        void setAdvisor(int newID);
        

    private:
        int m_id;
        std::string m_name;
        std::string m_level;
        std::string m_major;
        double m_gpa;
        int m_advisor;



};

#endif