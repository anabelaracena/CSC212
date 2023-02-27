#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Gradebook.h"

//constructor accepts 5 vectors of names, lab grades, assignment grades, project grades, 
//and exam grade, and pushes any values into their respective categories
//adds -1 to the grade vector if it is incomplete
Gradebook::Gradebook(std::vector<std::string> &names, std::vector<std::vector<int> > &labs, std::vector<std::vector<int> > &assignments, std::vector<std::vector<int> > &projects, std::vector<std::vector<int> > exams) {
    this->students = names;
    this->labs = labs;
    this->assignments = assignments;
    this->projects = projects;
    this->exams = exams;

    while(this->labs.size() < this->students.size()) {
        std::vector<int> l;
        l.push_back(-1);
        this->labs.push_back(l);
    }
    while(this->assignments.size() < this->students.size()) {
        std::vector<int> a;
        a.push_back(-1);
        this->assignments.push_back(a);
    }
    while(this->projects.size() < this->students.size()) {
        std::vector<int> p;
        p.push_back(-1);
        this->projects.push_back(p);
    }
    while(this->exams.size() < this->students.size()) {
        std::vector<int> e;
        e.push_back(-1);
        this->exams.push_back(e);
    }

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

// loops through all the students in the gradebook and displays them for the user
void Gradebook::display_students() {
    std::cout << "These are the students in the class:\n";
    for (int i = 0; i < this->students.size(); i++) {
        std::cout << this->students[i] << std::endl;
    }
}

// prompts the user for a student's name from the class, and returns the index of that student
int Gradebook::get_student() {
    std::string first_name;
    std::string last_name;
    std::string name;
    int idx = -1;
    while (idx == -1) {
        display_students();
        std::cout << "Please pick a first name from the list above: ";
        std::cin >> first_name;
        std::cout << "Please pick a last name from the list above: ";
        std::cin >> last_name;
        name = first_name + " " + last_name;
        for (int i = 0; i < this->students.size(); i++) {
            if (this->students[i] == name) {
                idx = i;
                return idx;
            }
        }
        std::cout << "Error: Invalid name entered. Please try again.\n";
        first_name.clear();
        last_name.clear();
        name.clear();
    }
}

// sums the grades from every category and prints the student's point total
void Gradebook::get_overall() {
    int idx = get_student();
    int total = 0;
    // adds lab grades to total, ignoring any -1
    for (int i = 0 ; i < this->labs[idx].size() ; i++) {
        if (this->labs[idx][i] < 0) {
            continue;
        }
        total += this->labs[idx][i];
    }
    // adds assignment grades to total, ignoring any -1
    for (int i = 0; i < this->assignments[idx].size() ; i++){
        if (this->assignments[idx][i] < 0) {
            continue;
        }
        total += this->assignments[idx][i];
    }
    // adds project grades to total, ignoring any -1
    for (int i = 0; i < this->projects[idx].size() ; i++){
        if (this->projects[idx][i] < 0) {
            continue;
        }
        total += this->projects[idx][i];
    }
    // adds exam grade to total, ignoring -1
    for (int i = 0; i < this->exams[idx].size() ; i++){
        if (this->exams[idx][i] < 0) {
            continue;
        }
        total += this->exams[idx][i];
    }
    
    // output results
    std::cout << this->students[idx] << "'s course overall is " << total << " points out of 1000.\n";
}

//final_grade looks at the current student and cumulates the total number of points 
//they got across every category, then outputs the letter grade
void Gradebook::final_grade() {
    int idx = get_student();
    int course_total = 0;
    // adds lab grades to total, ignoring any -1
    for (int i = 0 ; i < this->labs[idx].size() ; i++) {
        if (this->labs[idx][i] < 0) {
            continue;
        }
        course_total += this->labs[idx][i];
    }
    // adds assignment grades to total, ignoring any -1
    for (int i = 0; i < this->assignments[idx].size() ; i++){
        if (this->assignments[idx][i] < 0) {
            continue;
        }
        course_total += this->assignments[idx][i];
    }
    // adds project grades to total, ignoring any -1
    for (int i = 0; i < this->projects[idx].size() ; i++){
        if (this->projects[idx][i] < 0) {
            continue;
        }
        course_total += this->projects[idx][i];
    }
    // adds exam grade to total, ignoring -1
    for (int i = 0; i < this->exams[idx].size() ; i++){
        if (this->exams[idx][i] < 0) {
            continue;
        }
        course_total += this->exams[idx][i];
    }
    // prep output
    std::cout << this->students[idx] << "'s final letter grade is ";

    // give a different output depending on point total
    if (course_total >= 940) {
        std::cout << "A";
    }
    else if (course_total >= 900) {
        std::cout << "A-";
    }
    else if (course_total >= 870) {
        std::cout << "B+";
    }
    else if (course_total >= 830) {
        std::cout << "B";
    }
    else if (course_total >= 800) {
        std::cout << "B-";
    }
    else if (course_total >= 770) {
        std::cout << "C+";
    }
    else if (course_total >= 730) {
        std::cout << "C";
    }
    else if (course_total >= 700) {
        std::cout << "C-";
    }
    else if (course_total >= 670) {
        std::cout << "D+";
    }
    else if (course_total >= 630) {
        std::cout << "D";
    }
    else if (course_total >= 600) {
        std::cout << "D-";
    }
    else {
        std::cout << "F";
    }
    std::cout << "\n";

}

//all_grades lists out every individual grade from every category of the student, 
//then outputs the student’s total course grade out of 1000.
void Gradebook::all_grades() {

    int idx = get_student();
    int course_total = 0;

    // diplay every lab grade and add to course total, ignoring -1
    std::cout << this->students[idx] << "'s lab grades are: \n";
    for (int i = 0 ; i < this->labs[idx].size() ; i++ ) {
        if (this->labs[idx][i] < 0) {
            continue;
        }
        std::cout << this->labs[idx][i] << " ";
        course_total += this->labs[idx][i];
    }
    std::cout << "\n";

    // diplay every assignment grade and add to course total, ignoring -1
    std::cout << this->students[idx] << "'s assignment grades are: \n";
    for (int i = 0 ; i < this->assignments[idx].size() ; i++ ) {
        if (this->assignments[idx][i] < 0) {
            continue;
        }
        std::cout << this->assignments[idx][i] << " ";
        course_total += this->assignments[idx][i];
    }
    std::cout << "\n";

    // diplay every project grade and add to course total, ignoring -1
    std::cout << this->students[idx] << "'s project grades are: \n";
    for (int i = 0 ; i < this->projects[idx].size() ; i++ ) {
        if (this->projects[idx][i] < 0) {
            continue;
        }
        std::cout << this->projects[idx][i] << " ";
        course_total += this->projects[idx][i];
    }
    std::cout << "\n";

    // diplay exam grade and add to course total, ignoring -1
    std::cout << this->students[idx] << "'s exam grade is: \n";
    for (int i = 0 ; i < this->exams[idx].size() ; i++ ) {
        if (this->exams[idx][i] < 0) {
            std::cout << "N/A (not yet taken)";
        }
        else {
        std::cout << this->exams[idx][i] << " ";
        course_total += this->exams[idx][i];
        }
    }
    std::cout << "\n";

    // outpu total
    std::cout << this->students[idx] << "'s course total is " << course_total << "/1000";
}

//category_grades requests a category to be input by the user and 
//displays the grades and total for that category
void Gradebook::category_grades() {
    int idx = get_student();
    std::string category;
    
    // get a category from user input, correcting for invalid input
    while ((category != "Labs") && (category != "Assignments") && (category != "Projects") && (category != "Exam")) {
        std::cout << "Enter one of the 4 categories below to get all of " << this->students[idx] << "'s grades for that category.\n"
                << "Labs\tAssignments\tProjects\tExam\n" << "Enter category: ";
        std::cin >> category;
        if ((category == "Labs") || (category == "Assignments") || (category == "Projects") || (category == "Exam")) {
            continue;
        }
        else {
            std::cout << "Error, invalid category name. Please try again. " << std::endl;
        }
    }

    int cat_total = 0;
    
    // sums all lab grades, ignoring any -1
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
    // sums all assignment grades, ignoring any -1
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
    // sums all project grades, ignoring any -1
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
    // displays exam grade, or nothing if the student hasn't taken it yet
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

//get_categories lists out every individual category and each of the grades 
//within that category, as well as the overall course grade
void Gradebook::get_categories() {

    int idx = get_student();
    int cat_total = 0;
    int course_total = 0;

    // sums and displays lab total, ignoring -1
    for (int i = 0 ; i < this->labs[idx].size() ; i++ ) {
        if (this->labs[idx][i] < 0) {
            continue;
        }
        cat_total += this->labs[idx][i];
        course_total += this->labs[idx][i];
    }
    std::cout << this->students[idx] << "'s lab total is " << cat_total << "/200\n";
    cat_total = 0;

    // sums and displays assignment total, ignoring -1
    for (int i = 0 ; i < this->assignments[idx].size() ; i++ ) {
        if (this->assignments[idx][i] < 0) {
            continue;
        }
        cat_total += this->assignments[idx][i];
        course_total += this->assignments[idx][i];
    }
    std::cout << this->students[idx] << "'s assignment total is " << cat_total << "/200\n";
    cat_total = 0;

    // sums and displays project total, ignoring -1
    for (int i = 0 ; i < this->projects[idx].size() ; i++ ) {
        if (this->projects[idx][i] < 0) {
            continue;
        }
        cat_total += this->projects[idx][i];
        course_total += this->projects[idx][i];
    }
    std::cout << this->students[idx] << "'s project total is " << cat_total << "/500\n";
    cat_total = 0;

    // sums and displays exam grade, correcting for a missing exam grade
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

//is_exempt judges all of the grades before the exam and 
//determines if the student would have 90% or higher by the exam.
void Gradebook::is_exempt() {

    int idx = get_student();
    int course_total = 0;

    // sums lab grades, ignoring -1
    for (int i = 0; i < this->labs[idx].size(); i++) {
        if (this->labs[idx][i] < 0) {
            continue;
        }
        course_total += this->labs[idx][i];
    }
    // sums assignment grades, ignoring -1
    for (int i = 0; i < this->assignments[idx].size(); i++) {
        if (this->assignments[idx][i] < 0) {
            continue;
        }
        course_total += this->assignments[idx][i];
    }
    // sums project grades, ignoring -1
    for (int i = 0; i < this->projects[idx].size(); i++) {
        if (this->projects[idx][i] < 0) {
            continue;
        }
        course_total += this->projects[idx][i];
    }

    // displays the result of exempt or not depending on if the point threshold has been crossed
    if (course_total >= 810) {
        std::cout << this->students[idx] << " is exempt from taking the final! :)";
    } else {
        std::cout << this->students[idx] << " is not exempt from taking the final";
    }
}


//change_grade requests a category to be input by the user and then asks which 
//of the list to be changed, then requests a new grade to be input
void Gradebook::change_grade() {
    
    int idx = get_student();
    std::string category;
    
    // get a category form user input, correcting for invalid inputs
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

    // get the maximum allowing deliverable # and grade value, depending on which category is chosen
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
        max_deliverable = 1;
    }
    else {
        max_deliverable = 2;
    }

    // get a deliverable number from the user, correecting for invalid input
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

    // change max_grade depending on which project grade is being updated
    if (deliverable_num == 1 && category == "Projects") {
        max_grade = 150;
    }
    else if (deliverable_num == 2 && category == "Projects") {
        max_grade = 350;
    }

    // get a new grade from user input, correcting for invalid input
    int new_grade = -1;
    while(true) {
        std::cout << "Please enter the new grade for deliverable " << deliverable_num << " from the " << category << " category: ";
        std::cin >> new_grade;
        if (new_grade >= 0 && new_grade <= max_grade) {
            break;
        }
        else {
            std::cout << "Error, invalid grade value for that deliverable. Please try again. \n"
            << "\tLabs: 0-20pts\n\tAssignments: 0-50pts\n\tProject 1: 0-150pts\n\tProject 2: 0-350pts\n\tExam: 0-100pts" << std::endl;
        }
    }

    // update the chosen deliverable with the new input grade
    if (category == "Labs") {
        this->labs[idx][deliverable_num - 1] = new_grade;
    }
    else if (category == "Assignments") {
        this->assignments[idx][deliverable_num - 1] = new_grade;
    }
    else if (category == "Projects") {
        this->projects[idx][deliverable_num - 1] = new_grade;
    }
    else {
        this->exams[idx][0] = new_grade;
    }
    
}

//update_gradebook takes all of the current data and replaces the 
//existing input file with the updated data.
void Gradebook::update_gradebook(std::string file_name) {
    
    // open the output file using the same name as the input file (overwriting it)
    std::ofstream out_file(file_name);
    for (int i = 0 ; i < this->students.size() ; i++) {
        if (i == this->students.size() - 1) {
            out_file << this->students[i] << "\n";
            continue;
        }
        out_file << this->students[i] << " ";
    }

    // loop through every student
    for (int i = 0 ; i < this->students.size() ; i++) {
        // write the student's lab grades, ignoring -1
        for (int j = 0 ; j < this->labs[i].size() ; j++) {
            if (this->labs[i][j] < 0) {
            continue;
            }
            out_file << "l" << this->labs[i][j] << " ";
        }
        // write the student's assignment grades, ignoring -1
        for (int k = 0 ; k < this->assignments[i].size() ; k++) {
            if (this->assignments[i][k] < 0) {
            continue;
            }
            out_file << "a" << this->assignments[i][k] << " ";
        }
        // write the student's project grades, ignoring -1
        for (int l = 0 ; l < this->projects[i].size() ; l++) {
            if (this->projects[i][l] < 0) {
            continue;
            }
            out_file << "p" << this->projects[i][l] << " ";
        }
        for (int m = 0 ; m < this->exams[i].size() ; m++) {
            if (this->exams[i][m] < 0) {
                continue;
            }
            out_file << "e" << this->exams[i][m];
        }
        if (i == this->students.size() - 1) {
            continue;
        }
        else {
            out_file << "\n";
        }
    }
}
