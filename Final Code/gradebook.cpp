#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Gradebook.h"

Gradebook::Gradebook(std::vector<std::string> &names, std::vector<std::vector<int> > &labs, std::vector<std::vector<int> > &assignments, std::vector<std::vector<int> > &projects, std::vector<std::vector<int> > exams) {
    this->students = names;
    this->labs = labs;
    this->assignments = assignments;
    this->projects = projects;
    this->exams = exams;

    for (int i = 0 ; i < this->students.size() ; i++) {
        while(this->labs[i].size() < 10) {
            this->labs[i].push_back(-1);
        }
        while(this->assignments[i].size() < 4) {
            this->assignments[i].push_back(-1);
        }
        while(this->projects[i].size() < 2) {
            this->projects[i].push_back(-1);
        }
        while(this->exams[i].size() < 1) {
            this->exams[i].push_back(-1);
        }
    }
}

void Gradebook::final_grade() {
    int idx = get_student();
    int course_total = 0;
    for (int i = 0 ; i < this->labs[idx].size() ; i++) {
        if (this->labs[idx][i] < 0) {
            continue;
        }
        course_total += this->labs[idx][i];
    }
    for (int i = 0; i < this->assignments[idx].size() ; i++){
        if (this->assignments[idx][i] < 0) {
            continue;
        }
        course_total += this->assignments[idx][i];
    }
    for (int i = 0; i < this->projects[idx].size() ; i++){
        if (this->projects[idx][i] < 0) {
            continue;
        }
        course_total += this->projects[idx][i];
    }
    for (int i = 0; i < this->exams[idx].size() ; i++){
        if (this->exams[idx][i] < 0) {
            continue;
        }
        course_total += this->exams[idx][i];
    }

    std::cout << this->students[idx] << "'s final letter grade is ";

    if (course_total >= 940)
        std::cout << "A";
    else if (course_total >= 900)
        std::cout << "A-";
    else if (course_total >= 870)
        std::cout << "B+";
    else if (course_total >= 830)
        std::cout << "B";
    else if (course_total >= 800)
        std::cout << "B-";
    else if (course_total >= 770)
        std::cout << "C+";
    else if (course_total >= 730)
        std::cout << "C";
    else if (course_total >= 700)
        std::cout << "C-";
    else if (course_total >= 670)
        std::cout << "D+";
    else if (course_total >= 630)
        std::cout << "D";
    else if (course_total >= 600)
        std::cout << "D-";
    else
        std::cout << "F";
}

void Gradebook::all_grades() {

    int idx = get_student();
    int course_total = 0;

    std::cout << this->students[idx] << "'s lab grades are: \n";
    for (int i = 0 ; i < this->labs[idx].size() ; i++ ) {
        if (this->labs[idx][i] < 0) {
            continue;
        }
        std::cout << this->labs[idx][i] << " ";
        course_total += this->labs[idx][i];
    }
    std::cout << "\n";

    std::cout << this->students[idx] << "'s assignment grades are: \n";
    for (int i = 0 ; i < this->assignments[idx].size() ; i++ ) {
        if (this->assignments[idx][i] < 0) {
            continue;
        }
        std::cout << this->assignments[idx][i] << " ";
        course_total += this->assignments[idx][i];
    }
    std::cout << "\n";

    std::cout << this->students[idx] << "'s project grades are: \n";
    for (int i = 0 ; i < this->projects[idx].size() ; i++ ) {
        if (this->projects[idx][i] < 0) {
            continue;
        }
        std::cout << this->projects[idx][i] << " ";
        course_total += this->projects[idx][i];
    }
    std::cout << "\n";

    std::cout << this->students[idx] << "'s exam grade is: \n";
    for (int i = 0 ; i < this->exams[idx].size() ; i++ ) {
        if (this->exams[idx][i] < 0) {
            continue;
        }
        std::cout << this->exams[idx][i] << " ";
        course_total += this->exams[idx][i];
    }
    std::cout << "\n";

    std::cout << this->students[idx] << "'s course total is " << course_total << "/1000";
}

void Gradebook::category_grades() {
    int idx = get_student();
    std::string category;
    while ((category != "Labs") && (category != "Assignments") && (category != "Projects") && (category != "Exam")) {
        std::cout << "Enter one of the 4 categories below to get all of " << this->students[idx] << "'s grades for that category.\n"
                << "Labs\tAssignments\tProjects\tExam\n" << "Enter category";
        std::cin >> category;
        if ((category == "Labs") || (category == "Assignments") || (category == "Projects") || (category == "Exam")) {
            continue;
        }
        else {
            std::cout << "Error, invalid category name. Please try again. " << std::endl;
        }
    }

    int cat_total = 0;
    if (category == "Labs") {
        std::cout << this->students[idx] << "'s Lab grades are ";
        for (int i = 0 ; i < this->labs[idx].size() ; i++) {
            if (this->labs[idx][i] < 0) {
            continue;
            }
            std::cout << this->labs[idx][i] << " ";
            cat_total += this->labs[idx][i];
        }
        std::cout << ", and their Lab total is " << cat_total << "/200";
    }
    else if (category == "Assignments") {
        std::cout << this->students[idx] << "'s Assignment grades are ";
        for (int i = 0 ; i < this->assignments[idx].size() ; i++) {
            if (this->assignments[idx][i] < 0) {
            continue;
            }
            std::cout << this->assignments[idx][i] << " ";
            cat_total += this->assignments[idx][i];
        }
        std::cout << ", and their Assignment total is " << cat_total << "/200";
    }
    else if (category == "Projects") {
        std::cout << this->students[idx] << "'s Project grades are ";
        for (int i = 0 ; i < this->projects[idx].size() ; i++) {
            if (this->projects[idx][i] < 0) {
            continue;
            }
            std::cout << this->projects[idx][i] << " ";
            cat_total += this->projects[idx][i];
        }
        std::cout << ", and their Project total is " << cat_total << "/500";
    }
    else {
        if (this->exams[idx][0] < 0) {
            std::cout << this->students[idx][0] << " has not taken the exam yet.";
        }
        else {
            std::cout << this->students[idx] << "'s Exam grade is a " << this->exams[idx][0] << "/100";
        }
    }
    std::cout << std::endl;
}

void Gradebook::get_categories() {

    int idx = get_student();
    int cat_total = 0;
    int course_total = 0;

    for (int i = 0 ; i < this->labs[idx].size() ; i++ ) {
        if (this->labs[idx][i] < 0) {
            continue;
        }
        cat_total += this->labs[idx][i];
        course_total += this->labs[idx][i];
    }
    std::cout << this->students[idx] << "'s lab total is " << cat_total << "/200\n";
    cat_total = 0;

    for (int i = 0 ; i < this->assignments[idx].size() ; i++ ) {
        if (this->assignments[idx][i] < 0) {
            continue;
        }
        cat_total += this->assignments[idx][i];
        course_total += this->assignments[idx][i];
    }
    std::cout << this->students[idx] << "'s assignment total is " << cat_total << "/200\n";
    cat_total = 0;

    for (int i = 0 ; i < this->projects[idx].size() ; i++ ) {
        if (this->projects[idx][i] < 0) {
            continue;
        }
        cat_total += this->projects[idx][i];
        course_total += this->projects[idx][i];
    }
    std::cout << this->students[idx] << "'s project total is " << cat_total << "/500\n";
    cat_total = 0;

    for (int i = 0 ; i < this->exams[idx].size() ; i++ ) {
        if (this->exams[idx][i] < 0) {
            continue;
        }
        cat_total += this->exams[idx][i];
        course_total += this->exams[idx][i];
    }
    if (this->exams[idx][0] < 0) {
            std::cout << this->students[idx] << " has not taken the exam yet.\n";
    }
    else {
        std::cout << this->students[idx] << "'s exam total is " << cat_total << "/100\n";
    }
    std::cout << this->students[idx] << "'s course total is " << course_total << "/1000\n";
}

void Gradebook::is_exempt() {

    int idx = get_student();
    int course_total = 0;

    for (int i = 0; i < this->labs[idx].size(); i++) {
        if (this->labs[idx][i] < 0) {
            continue;
        }
        course_total += this->labs[idx][i];
    }
    for (int i = 0; i < this->assignments[idx].size(); i++) {
        if (this->assignments[idx][i] < 0) {
            continue;
        }
        course_total += this->assignments[idx][i];
    }
    for (int i = 0; i < this->projects[idx].size(); i++) {
        if (this->projects[idx][i] < 0) {
            continue;
        }
        course_total += this->projects[idx][i];
    }

    if (course_total >= 810) {
        std::cout << this->students[idx] << " is exempt from taking the final! :)";
    } else {
        std::cout << this->students[idx] << " is not exempt from taking the final";
    }
}

void Gradebook::change_grade() {
    
    int idx = get_student();
    std::string category;
    while ((category != "Labs") && (category != "Assignments") && (category != "Projects") && (category != "Exam")) {
        std::cout << "Which of the 4 categories below would you like to change " << this->students[idx] << "'s grade for?\n"
                << "Labs\tAssignments\tProjects\tExam\n" << "Enter category: ";
        std::cin >> category;
        if ((category == "Labs") || (category == "Assignments") || (category == "Projects") || (category == "Exam")) {
            continue;
        }
        else {
            std::cout << "Error, invalid category name. Please try again. " << std::endl;
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

    if ((category == "Projects") && (deliverable_num = 1)) {
        max_grade == 150;
    }
    else if ((category == "Projects") && (deliverable_num == 2)) {
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
        this->exams[idx][0] = new_grade;
    }
    
}

void Gradebook::update_gradebook(std::string file_name) {
    
    std::ofstream out_file(file_name);
    for (int i = 0 ; i < this->students.size() ; i++) {
        if (i == this->students.size() - 1) {
            out_file << this->students[i] << "\n";
            continue;
        }
        out_file << this->students[i] << " ";
    }

    for (int i = 0 ; i < this->students.size() ; i++) {
        for (int j = 0 ; j < this->labs.size() ; j++) {
            if (this->labs[i][j] < 0) {
            continue;
            }
            out_file << "l" << this->labs[i][j] << " ";
        }
        for (int k = 0 ; k < this->assignments.size() ; k++) {
            if (this->assignments[i][k] < 0) {
            continue;
            }
            out_file << "a" << this->assignments[i][k] << " ";
        }
        for (int l = 0 ; l < this->projects.size() ; l++) {
            if (this->projects[i][l] < 0) {
            continue;
            }
            out_file << "p" << this->projects[i][l] << " ";
        }
        if (this->exams[i][0] < 0) {
            continue;
        }
        else {
            out_file << "e" << this->exams[i][0] << "\n";
        }
    }

}
