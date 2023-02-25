#include <vector>
#include <string>

class Gradebook {
    Private:
        std::vector<std::string> students;
        std::vector<std::vector<int> > labs;
        std::vector<std::vector<int> > assignments;
        std::vector<std::vector<int> > projects;
        std::vector<std::vector<int> > exams;

    Public:
        Gradebook::Gradebook(std::vector<std::string> names, std::vector<std::vector<int> > labs, std::vector<std::vector<int> > assignments, std::vector<std::vector<int> > projects, std::vector<std::vector<int> > exams);
        Gradebook::get_student();
        Gradebook::display_students()
        Gradebook::category_grades();
        Gradebook::change_grade();
        Gradebook::final_grade();
        Gradebook::all_grades();
        Gradebook::get_categories();
        Gradebook::get_overall();
        Gradebook::is_exempt();
        Gradebook::update_gradebook(std::string file_name);

};
