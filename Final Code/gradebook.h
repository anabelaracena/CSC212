#pragma once
#include <vector>
#include <string>

class Gradebook {
    
    private:
        std::vector<std::string> students;
        std::vector<std::vector<int> > labs;
        std::vector<std::vector<int> > assignments;
        std::vector<std::vector<int> > projects;
        std::vector<std::vector<int> > exams;

    public:
        Gradebook(std::vector<std::string> &names, std::vector<std::vector<int> > &labs, std::vector<std::vector<int> > &assignments, std::vector<std::vector<int> > &projects, std::vector<std::vector<int> > exams);
        void get_student();
        void display_students();
        void category_grades();
        void change_grade();
        void final_grade();
        void all_grades();
        void get_categories();
        void get_overall();
        void is_exempt();
        void update_gradebook(std::string file_name);

};
