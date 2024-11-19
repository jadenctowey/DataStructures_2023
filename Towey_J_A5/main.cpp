#include "LazyBST.h"
#include "Student.h"
#include "Teacher.h"
#include <fstream>

int main() {
    bool keepRunning = true;
    LazyBST<Student> *students = new LazyBST<Student>();
    LazyBST<Teacher*> *teachers = new LazyBST<Teacher*>();


    while(keepRunning == true){
        string input;
        //Gives all the options for user
        cout << "1.	Print all students and their information (sorted by ascending id #)\n2.	Print all faculty and their information (sorted by ascending id #)\n3.	Find and display student information given the student id\n4.	Find and display faculty information given the faculty id\n5.	Add a new student\n6.	Delete a student given the id\n7.	Add a new faculty member\n8.	Delete a faculty member given the id.\n9.	Change a student’s advisor given the student id and the new faculty id.\n10.	Remove an advisee from a faculty member given the ids\n11.	Exit" << endl;
        cin >> input;
        
        if(input == "1"){
            students->printTreeInOrder();
        //OPTION 2 DOES NOT PRINT PROPERLY, SEE README
        }else if(input == "2"){
            teachers->printTreeInOrder();
        }else if(input == "3"){
            cout << "Enter ID:" << endl;
            string findID;
            int desiredID;
            cin >> findID;
            desiredID = stoi(findID);
            cout << "Name:" << students->findElement(Student(desiredID)).getName() << "\nLevel:" << students->findElement(Student(desiredID)).getLevel() << "\nMajor:" << students->findElement(Student(desiredID)).getMajor() << "\nGPA:" << students->findElement(Student(desiredID)).getGpa() << "\nAdvisor: " << students->findElement(Student(desiredID)).getAdvisor() << endl;
        
        //This may not work always becuase Teacher operators are not working, see README
        }else if(input == "4"){
            cout << "Enter ID:" << endl;
            string findID;
            int desiredID;
            cin >> findID;
            desiredID = stoi(findID);
            Teacher *findT = new Teacher(desiredID);
            Teacher* foundTeacher = teachers->findElementTeach(new Teacher(desiredID));

            if (foundTeacher != nullptr) {
                cout << "Name:" << foundTeacher->getName();
                cout << "\nLevel:" << foundTeacher->getLevel();
                cout << "\nDepartment:" << foundTeacher->getDepartment() << endl;
            } else {
                cout << "Teacher not found." << endl;
            }
            
            delete findT;
        }else if(input == "5"){ //add student
            cout << "DO NOT USE SPACES, USE UNDERSCORES" << endl;
            cout << "Enter ID:" << endl;
            string tempID;
            int intID;
            cin >> tempID;
            intID = stoi(tempID);
            cout << "Enter Name:" << endl;
            string tempName;
            cin >> tempName;
            cout << "Enter Level:" << endl;
            string tempLevel;
            cin >> tempLevel;
            cout << "Enter Major:" << endl;
            string tempMajor;
            cin >> tempMajor;
            cout << "Enter GPA:" << endl;
            string tempGPA;
            cin >> tempGPA;
            double dblGPA = stod(tempGPA);
            cout << "Enter Advisor:" << endl;
            string tempAdvisor;
            cin >> tempAdvisor;
            int intAdvisor = stoi(tempAdvisor);
            
            if(teachers->findElementTeach(new Teacher(intAdvisor)) != nullptr){
                students->insert(Student(intID, tempName, tempLevel, tempMajor, dblGPA, intAdvisor));
                teachers->findElementTeach(new Teacher(intAdvisor))->addAdvisee(intID);
            }else{
                cout<< "Advisor does not exist." << endl;
            }
        
        }else if(input == "6"){
            cout << "Enter ID:" << endl;
            string tempID;
            int intID;
            cin >> tempID;
            intID = stoi(tempID);
            if(students->contains(Student(intID))){ //Checks if student exists and removes from Students and advisees
                int checkID = students->findElement(Student(intID)).getAdvisor();
                students->remove(students->findElement(Student(intID)));
                teachers->findElementTeach(new Teacher(checkID))->removeAdvisee(intID);

            }
        }else if(input == "7"){
            cout << "DO NOT USE SPACES, USE UNDERSCORES" << endl;
            cout << "Enter ID:" << endl;
            string tempID;
            int intID;
            cin >> tempID;
            intID = stoi(tempID);
            cout << "Enter Name:" << endl;
            string tempName;
            cin >> tempName;
            cout << "Enter Level:" << endl;
            string tempLevel;
            cin >> tempLevel;
            cout << "Enter Department:" << endl;
            string tempDepartment;
            cin >> tempDepartment;

            teachers->insert(new Teacher(intID, tempName, tempLevel, tempDepartment));

        }else if(input == "8"){
            
            cout << "Enter ID:" << endl;
            string tempID;
            int intID;
            cin >> tempID;
            intID = stoi(tempID);
            if(teachers->findElementTeach(new Teacher(intID))->getAdvisorSize() == 0){
                teachers->remove(teachers->findElementTeach(new Teacher(intID)));
            }else{ // Cannot remove if teacher has advisees
                cout << "Cannot remove, will cause referential error" << endl;
            }
        }else if(input == "9"){
            cout << "Enter Student ID:" << endl;
            string tempID;
            int intID;
            cin >> tempID;
            intID = stoi(tempID);

            cout << "Enter Teacher ID:" << endl;
            string tempTID;
            int intTID;
            cin >> tempTID;
            intTID = stoi(tempTID);
            if(students->contains(Student(intID)) && teachers->findElementTeach(new Teacher(intTID)) != nullptr){
                Student tempS = Student(students->findElement(intID).getId(), students->findElement(intID).getName(), students->findElement(intID).getLevel(), students->findElement(intID).getMajor(), students->findElement(intID).getGpa(), intTID);
                students->remove(Student(intID));
                students->insert(tempS);
            }else{
                cout << "Student or Teacher does not exist" << endl;
            }


        }else if(input == "10"){
            cout << "Enter Student ID:" << endl;
            string tempID;
            int intID;
            cin >> tempID;
            intID = stoi(tempID);

            cout << "Enter Teacher ID:" << endl;
            string tempTID;
            int intTID;
            cin >> tempTID;
            intTID = stoi(tempTID);

            if(students->contains(Student(intID)) && teachers->findElementTeach(new Teacher(intTID)) != nullptr){
                teachers->findElementTeach(new Teacher(intTID))->removeAdvisee(intID);
                Student tempS = Student(students->findElement(intID).getId(), students->findElement(intID).getName(), students->findElement(intID).getLevel(), students->findElement(intID).getMajor(), students->findElement(intID).getGpa(), 0);
                students->remove(Student(intID));
                students->insert(tempS);
            }else{
                cout << "Student or Teacher unvalid." << endl;
            }
        }else if(input == "11"){
            ofstream runLogFile("runLog.txt");
            if (runLogFile.is_open()) {
                // Print students 
                runLogFile << "Students Information:\n";
                students->printTreeInOrderFile(runLogFile);

                // Print teachers 
                runLogFile << "\nTeachers Information:\n";
                teachers->printTreeInOrderFile(runLogFile);

                runLogFile.close();
            } else {
                cout << "Error" << endl;
            }

            keepRunning = false;
        }

        }
        delete students;
        delete teachers;
    }
