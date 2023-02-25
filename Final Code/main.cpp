/*

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "Gradebook.h"

int main(int argc, char*argv[]) {

    std::string file_name(argv[1]);
    std::ifstream in_file(file_name);

    std::string current_line;
    std::getline(in_file, current_line);
    std::stringstream ss(current_line);

    std::string temp;
    std::string full_name;
    int counter = 0;

    std::vector<std::string> names;
    std::vector<std::vector<int> > labs;
    std::vector<std::vector<int> > assignments;
    std::vector<std::vector<int> > projects;
    std::vector<int> exams;

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

    counter = 0;
    std::vector<int> temp_lab;
    std::vector<int> temp_assignment;
    std::vector<int> temp_project;

    while(std::getline(in_file, current_line)) {
        std::stringstream ss(current_line);
        while(ss >> temp) {
            if (counter >= 0 && counter <= 9) {
                temp_lab.push_back(std::stoi(temp));
            }
            else if (counter >= 10 && counter <= 13) {
                temp_assignment.push_back(std::stoi(temp));
            }
            else if (counter == 14 || counter == 15) {
                temp_lab.push_back(std::stoi(temp));
            }
            else {
                exams.push_back(std::stoi(temp));
            }
            counter += 1;
        }
        counter = 0;
        labs.push_back(temp_lab);
        assignments.push_back(temp_assignment);
        projects.push_back(temp_project)

        temp_lab.clear();
        temp_assignment.clear();
        temp_project.clear();
    }

    Gradebook gb(labs, assignments, projects, exams);

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

    std::cout << "Thank you for using the Gradebook, goodbye." << std::endl;
    gb.update_gradebook(file_name);

}

*/
