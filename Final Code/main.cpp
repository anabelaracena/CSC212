#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "Gradebook.h"

int main(int argc, char*argv[]) {

    //open the input file using string file_name
    std::string file_name(argv[1]);
    std::ifstream in_file(file_name);

    //create a string current_line to read the file
    std::string current_line;
    std::getline(in_file, current_line);
    std::stringstream ss(current_line);

    //create two additional strings to store the first and last names
    //using a counter to determine if the current name is a first or last name
    std::string temp;
    std::string full_name;
    int counter = 0;

    //create vectors for the names and the 4 grade categories
    std::vector<std::string> names;
    std::vector<std::vector<int> > labs;
    std::vector<std::vector<int> > assignments;
    std::vector<std::vector<int> > projects;
    std::vector<std::vector<int> > exams;

    //fill the names vector with the names on the input file
    while(ss >> temp) {
        if (counter % 2 == 0) {
            full_name += temp;
        }
        else {
            full_name += " " + temp;
            names.push_back(full_name);
            full_name.clear();
        }
        counter += 1;
    }

    //create temporary vectors to fill in main vectors
    counter = 0;
    std::vector<int> temp_lab;
    std::vector<int> temp_assignment;
    std::vector<int> temp_project;
    std::vector<int> temp_exam;

    //set the max possible score of each category
    int max_lab = 20;
    int max_assign = 50;
    int max_proj1 = 150;
    int max_proj2 = 350;
    int max_ex = 100;

    //fill final category vectors with data on the temp categories
    while(std::getline(in_file, current_line)) {
        std::stringstream ss(current_line);
        while(ss >> temp) {
            //push lab grades
            if (temp[0] == 'l') {
                temp.erase(0,1);
                int lab = std::stoi(temp);
                if (lab > max_lab) {
                    lab = max_lab;
                }
                else if (lab < 0) {
                    lab = 0;
                }
                temp_lab.push_back(lab);
            }
            //push assignment grades
            else if (temp[0] == 'a') {
                temp.erase(0,1);
                int assign = std::stoi(temp);
                if (assign > max_assign) {
                    assign = max_assign;
                }
                else if (assign < 0) {
                    assign = 0;
                }
                temp_assignment.push_back(assign);
            }
            //push project grades
            else if (temp[0] == 'p') {
                temp.erase(0,1);
                int proj1;
                int proj2;
                //determine if temp_project is holding first or second project
                if (temp_project.size() == 0) {
                    proj1 = std::stoi(temp);
                }
                else {
                    proj2 = std::stoi(temp);
                }
                if (proj1 > max_proj1) {
                    proj1 = max_proj1;
                    temp_project.push_back(proj1);
                }
                else if (proj1 < 0) {
                    proj1 = 0;
                    temp_project.push_back(proj1);
                }
                else if (proj2 > max_proj2) {
                    proj2 = max_proj2;
                    temp_project.push_back(proj2);
                }
                else if (proj2 < 0) {
                    proj2 = 0;
                    temp_project.push_back(proj2);
                }
            }
            //push exam grades
            else {
                temp.erase(0,1);
                int ex = std::stoi(temp);
                if (ex > max_ex) {
                    ex = max_ex;
                }
                else if (ex < 0) {
                    ex = 0;
                }
                temp_exam.push_back(ex);
            }
        }

        labs.push_back(temp_lab);
        assignments.push_back(temp_assignment);
        projects.push_back(temp_project);
        exams.push_back(temp_exam);

        temp_lab.clear();
        temp_assignment.clear();
        temp_project.clear();
        temp_exam.clear();
    }

    //create Gradebook class
    Gradebook gb(names, labs, assignments, projects, exams);

    //display UI with possible choices and request choice from user
    int choice = 0;
    while(choice != -1) {
        std::cout << "---------- Main Menu ----------" << std::endl;
        std::cout << "Welcome to the Gradebook. Enter a number from one of the options below to get started. " << std::endl;
        std::cout << "1: See the final letter grade of a select student\n"
                << "2: See all the grades within a select category for a student, as well as their course total\n"
                << "3: See all grades for a slect student grouped by category, as well as their course total\n"
                << "4: See all category totals for a select student, as well as their course total\n"
                << "5: See a select student's course total\n"
                << "6: See if a student would've been exempt from Professor Schrader's final\n"
                << "7: Change a student's grade\n"
                << "-1: Quit Gradebook program"
                << "Please enter a choice: ";
        std::cin >> choice;
        if (choice == -1) {
            break;
        }
        else if (choice == 1) {
            gb.final_grade();
        }
        else if (choice == 2) {
            gb.category_grades();
        }
        else if (choice == 3) {
            gb.all_grades();
        }
        else if (choice == 4) {
            gb.get_categories();
        }
        else if (choice == 5) {
            gb.get_overall();
        }
        else if (choice == 6) {
            gb.is_exempt();
        }
        else if (choice == 7) {
            gb.change_grade();
        }
        else {
            std::cout << "Error, invalid choice. Please try again. " << std::endl;
            continue;
        }
    }

    //save any changes made by user
    std::cout << "Thank you for using the Gradebook, goodbye." << std::endl;
    gb.update_gradebook(file_name);

}
