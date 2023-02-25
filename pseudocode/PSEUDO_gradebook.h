/*

Need to include: vector, string

Class Gradebook {
    Private:
        2D vector for student names (holds strings)
        2D vector for lab grades (holds ints)
        2D vector for assignment grades (holds ints)
        2D vector for project grades (holds ints)
        1D vector for exam grades (holds ints) ---> is 1D becuase the course only has 1 exam
    Public:

        *** Nearly every one of these functions will call get_student() ***

        REQUIRED by the project guidelines:
        Constructor (input parameters are the names, labs, assignments, projects, and exams)
            - Gradebook::Gradebook( std::vector<std::string> > names, std::vector<std::vector <int> > labs, std::vector<std::vector <int> > assignments, std::vector<std::vector <int> > projects, std::vector<int> exams )
        
        (void) function to get a student's final grade
            - Gradebook::final_grade()
            - Will have to get the point total, and then convert to a letter grade using the scale in the syllabus

        (void) function to print all the grades from a certain category for a student, as well as the total of said category
            - Gradebook::category_grades()

        (void) function to print all  grades, within their respective categories, and the final grade
            - Gradebook::all_grades()
            - Multiple cout statements

        (void) function to print the category totals, and return the overall final grade
            - Gradebook::get_categories()

        (void) function to print only the overall course grade
            - Gradebook::get_overall()



        NOT REQUIRED by the project guidelines, but these won't hurt to have and probably aren't diificult to implement:
        (int) function to get the index in the name list where a certain student's name is
            - Gradebook::get_student()
            - Not required by the guidelines, but for our purposes it basically is

        (void) function to get a students final grade (PRE-EXAM) to determine if the student is exempt from the final
            - Gradebook::is_exempt()
        
        (void) function to update a certain student's grade (input parameter is the student's name as a string)
            - Gradebook::change_grade()

        (void) function to display the names of every student so the user can choose one for a function
            - Gradebook::show_students()
        
        (void) function write to the input file all the changes that were made
            - Gradebook::update_gradebook( std::string file name )

};

*/
