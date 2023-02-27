#pragma once
#include <vector>
#include <string>

class Gradebook {
    
    private:
        std::vector<std::string> students; //names of students
        std::vector<std::vector<int> > labs; //values of labs
        std::vector<std::vector<int> > assignments; //values of assignments
        std::vector<std::vector<int> > projects; //values of projects
        std::vector<std::vector<int> > exams; //values of exams

    public:
        Gradebook(std::vector<std::string> &names, std::vector<std::vector<int> > &labs, std::vector<std::vector<int> > &assignments, std::vector<std::vector<int> > &projects, std::vector<std::vector<int> > exams);
        int get_student(); //requests name of student for inquiry
        void display_students(); //displays names of all students
        void category_grades(); //calculates and displays grades in one category
        void change_grade(); //requests a grade to be changed in the vector
        void final_grade(); //calculates and displays letter grade of student
        void all_grades(); //calculates and displays every grade from every category + overall
        void get_categories(); //calculates and displays total grade in categories + overall
        void get_overall(); //calculates and displays the total overall grade
        void is_exempt(); //tells user whether a student is exempt from exam
        void update_gradebook(std::string file_name); //overwrites input file

};
