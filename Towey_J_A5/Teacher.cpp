#include "Teacher.h"
#include <iostream>

Teacher::Teacher(){
    m_id = 0;
    m_name = "null";
    m_level = "null";
    m_department = "null";
}

Teacher::Teacher(int id){ //Used only for comparisons
    m_id = id;
    m_name = "null";
    m_level = "null";
    m_department = "null";
}

Teacher::Teacher(int Id, std::string name, std::string level, std::string department){
    m_id = Id;
    m_name = name;
    m_level = level;
    m_department = department;
    advisees = new DblList<int>();
}

Teacher::~Teacher(){
    delete advisees;
}
    
int Teacher::getId(){
    return m_id;
}

std::string Teacher::getName(){
    return m_name;
}

std::string Teacher::getLevel(){
    return m_level;
}

std::string Teacher::getDepartment(){
    return m_department;
}
        
//OVERLOADED OPERATORS NOT FUNCTIONING
bool Teacher::operator>(Teacher& other){
    return getId() > other.getId();
}

bool Teacher::operator<(Teacher& other){
    return getId() < other.getId();
}

 bool Teacher::operator==(Teacher& other){
     return getId() == other.getId();
}

std::ostream& operator<<(std::ostream& os, Teacher *teacher) {
    os << teacher->getId();
    return os;
}

void Teacher::addAdvisee(int id){
    advisees->addBack(id);
}

void Teacher::removeAdvisee(int id){//Iterates through advisees to see if the id is contained
    for(int i = 0; i< advisees->getSize(); i++){
        if(advisees->get(i) == id){
            advisees->remove(i);
        }
    }
    
}

int Teacher::getAdvisorSize(){
    return advisees->getSize();
}

//THESE ALSO DONT WORK
bool Teacher::operator==(const Teacher& other) const {
    return m_id == other.m_id;
}

bool Teacher::operator>(const Teacher& other) const {
    return m_id > other.m_id;
}

bool Teacher::operator<(const Teacher& other) const {
    return m_id < other.m_id;
}

bool Teacher::operator!=(const Teacher& other) const {
    return m_id != other.m_id;
}

bool Teacher::operator!=(Teacher& other){
    return getId() != other.getId();
}

bool Teacher::operator==(Teacher *teacher){
    return getId() == teacher->getId();
}

bool Teacher::operator==(const Teacher* other) const {
    if (other == nullptr) {
        return false;
    }
    return m_id == other->m_id;
}


bool Teacher::operator>(Teacher *other) {
    return m_id > other->m_id;
}

bool Teacher::operator<(Teacher *other) {
    return m_id < other->m_id;
}


bool Teacher::operator!=(Teacher *other){
    return getId() != other->getId();
}

//This function works and it has the same implementation that doesnt work.  VERY confused
bool Teacher::equals(Teacher *teacher){
    return getId() == teacher->getId();
}