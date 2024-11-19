#include "Student.h"
#include <iostream>
Student::Student(){
    m_id = 0;
    m_name = "null";
    m_level = "null";
    m_major = "null";
    m_gpa = 0.0;
    m_advisor = -1;
}

Student::Student(int Id){
    m_id = Id;
    m_name = "null";
    m_level = "null";
    m_major = "null";
    m_gpa = 0.0;
    m_advisor = -1;
}

Student::Student(int Id, std::string name, std::string level, std::string major, double Gpa, int Advisor){
    m_id = Id;
    m_name = name;
    m_level = level;
    m_major = major;
    m_gpa = Gpa;
    m_advisor = Advisor;
}

Student::~Student(){}
    
int Student::getId() const{
    return m_id;
}

std::string Student::getName(){
    return m_name;
}

std::string Student::getLevel(){
    return m_level;
}

std::string Student::getMajor(){
    return m_major;
}
        
double Student::getGpa(){
    return m_gpa;
}

int Student::getAdvisor(){
    return m_advisor;
}

void Student::setAdvisor(int newID){
    m_advisor = newID;
}

bool Student::operator>(Student& other){
    return getId() > other.getId();
}

bool Student::operator<(Student& other){
    return getId() < other.getId();
}

bool Student::operator==(Student& other){
    return getId() == other.getId();
}

std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << student.getId();
    return os;
}

bool Student::operator==(const Student& other) const {
    return m_id == other.m_id;
}

bool Student::operator>(const Student& other) const {
    return m_id > other.m_id;
}

bool Student::operator<(const Student& other) const {
    return m_id < other.m_id;
}

bool Student::operator!=(const Student& other) const {
    return m_id != other.m_id;
}

bool Student::operator!=(Student& other){
    return getId() != other.getId();
}