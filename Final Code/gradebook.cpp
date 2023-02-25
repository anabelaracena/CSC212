#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Gradebook.h"

Gradebook::category_grades() {
    int idx = get_student();
    std::string category;
    while ((category != "Labs") && (category != "Assignments") && (category != "Projects") && (category != "Exam")) {
        std::cout << "Enter one of the 4 categories below to get all of " << this->students[idx] << "'s grades for that category.\n" ;
                << "Labs\tAssignments\tProjects\tExam\n" << "Enter category";
        std::cin >> category;
        if ((category == "Labs") || (category == "Assignments") || (category == "Projects") || (category == "Exam")) {
            continue;
        }
        else {
            std::cout << Error, invalid category name. Please try again. " << std::endl;
        }
    }

    int cat_total = 0;
    if (category == "Labs") {
        std::cout << this->students[idx] << "'s Lab grades are ";
        for (int i == 0 ; i < this->labs.size() ; i++) {
            std::cout << this->labs[i] << " ";
            cat_total += this_labs[i];
        }
        std::cout << ", and their Lab total is " << cat_total << "/200";
    }
    else if (category == "Assignments") {
        std::cout << this->students[idx] << "'s Assignment grades are ";
        for (int i == 0 ; i < this->assignments.size() ; i++) {
            std::cout << this->assignments[i] << " ";
            cat_total += this_assignments[i];
        }
        std::cout << ", and their Assignment total is " << cat_total << "/200";
    }
    else if (category == "Projects") {
        std::cout << this->students[idx] << "'s Project grades are ";
        for (int i == 0 ; i < this->projetcs.size() ; i++) {
            std::cout << this->projects[i] << " ";
            cat_total += this_projects[i];
        }
        std::cout << ", and their Project total is " << cat_total << "/500";
    }
    else {
        std::cout << this->students[idx] << "'s Exam grade is a " << this->exams[idx] << "/100";
    }
    std::cout << std::endl;
}

Gradebook::change_grade() {
    int idx = get_student();
    std::string category;
    while ((category != "Labs") && (category != "Assignments") && (category != "Projects") && (category != "Exam")) {
        std::cout << "Which of the 4 categories below would you like to change " << this->students[idx] << "'s grade for?\n"; 
                << "Labs\tAssignments\tProjects\tExam\n" << "Enter category: ";
        std::cin >> category;
        if ((category == "Labs") || (category == "Assignments") || (category == "Projects") || (category == "Exam")) {
            continue;
        }
        else {
            std::cout << Error, invalid category name. Please try again. " << std::endl;
        }
    }

    int max_grade = 0;
    int max_deliverable = 0;
    if (category == "Labs") {
        max_grade = 20;
        max_deliverable = 10;
    }
    else if (category == "Assignments") {
        max_grade = 50;
        max_deliverable = 4;
    }
    else if (category == "Exam") {
        max_grade = 100;
        max_deliverable == 1;
    }
    else {
        max_deliverable = 2;
    }

    int deliverable_num = 0;
    while (deliverable_num < 1 || deliverable_num > max_deliverable) {
        std::cout << "Which " << category << " grade (1 through " << max_deliverable << ") would you like to change? ";
        std::cin >> deliverable_num;
        if (deliverable_num >= 1 && deliverable_num <= max_deliverable) {
            continue;
        }
        else {
            std::cout << "Error, invalid deliverable for the " << category << " category. Please try again. " << std::endl;        
        }
    }

    if (category == "Projects" && deliverable_num = 1) {
        max_grade == 150;
    }
    else if (category == "Projects" && deliverable_num == 2) {
        max_grade = 350;
    }

    int new_grade = -1;
    while(true) {
        std::cout << "Please enter the new grade for deliverable " << deliverable_num << " from the " << category << " category:";
        std::cin >> new_grade;
        if (new_grade >= 0 && new_grade <= max_grade) {
            break;
        }
        else {
            std::cout << "Error, invalid grade value for that deliverable. Please try again. \n"
            << "\tLabs: 0-20pts\n\tAssignments: 0-50pts\n\tProject 1: 0-150pts\n\tProject 2: 0-350pts" << std::endl;
        }
    }

    if (category == "Labs") {
        this->labs[idx][deliverable_num - 1] == new_grade;
    }
    else if (category == "Assignments") {
        this->assignments[idx][deliverable_num - 1] == new_grade;
    }
    else if (category == "Projects") {
        this->projects[idx][deliverable_num - 1] == new_grade;
    }
    else {
        this->exams[idx] == new_grade;
    }
    
}
