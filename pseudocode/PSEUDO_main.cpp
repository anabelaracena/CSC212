/*

Need to include: vector, string, iostream, sstream, fstream, gradebook.h

int main(int argc, char* argv[]) {
    Only CLA will be the input/output file name

    Turn the input file name into a string from argv[1]
    Open the input file using said string

    Make a blank string (call this string "current_line", we'll reuse it later)
    Read the first line of the file, store in the blank string
    Turn the first line of the file into a string stream

    Make a temp string to hold each individual first/last name
    Make ANOTHER temp string to hold a student's full name that we'll push into the 2D student name vector
    Make a counter to tell if we're storing a first name or a last name (start it at 0)

    Make vectors for the:
    student names (strings)
    lab grades  (floats)
    assignment grades  (floats)
    exam grades (floats)
    These vectors are all 2D EXCEPT the exam grades

    Loop through the first line (while string stream >> temp string1)
        if the counter is even, we're on a first name
            temp string2 += temp string1 (the first name)
        else, the counter is odd, we're on a last name
            temp string2 += " " + temp string1 (whitespace and the last name)
            push temp string2 into the 2D name vector
            clear temp string2
        increment the counter before looping again

    The name vector is done, follow a similar methodology for the rest of the data
    Reset the counter variable so we can reuse it
    We'll reuse temp string 1
    Need to make temp vectors for: lab grades, assignment grades, project grades

    Loop through the remaining lines (while getline (file, current_line))
        Turn current_line into a string stream (reuse the name of the first string stream so it overwrites)
        
        Loop through the current line (while string stream >> temp string1)

            Because we know the exact number of deliverables in the class, we can add to each vector depending on counter
            If counter is between 0 and 9 (inclusive), we know temp string is a lab grade
                Add the temp string to the lab grade temp vector (convert from string to float - std::stof)
            If the counter is between 10 and 13, we know temp string is an assignment grade
                Add the temp string to the assignment grade temp vector (convert from string to float - std::stof)
            If the counter is 14 or 15, we know temp string is a project grade
                Add the temp string to the exam grades vector (convert from string to float - std::stof)
            Lastly, is the counter is 16, we know we have an exam grade
                Push the temp string into the exam grades vector (convert from string to float - std::stof)

            Remember to increment the counter variable before the inner loop runs again

        Push the temp lab vector into the lab grades
        Push the temp assignment vector into the assignment grades
        Push the temp project vector intp the project grades
        Clear these vectors for the next loop (the next line)
        Reset the counter variable to 0

    Make our gradebook object, passing the vectors by copy in the RIGHT ORDER

    Time for the actual deliverables
    Make an integer (call it choice) which the user can manipulate with std::cin to get different outputs
    This is a concept taken from CSC 110
    Initialize an integer to hold the student_index variable (get_student is about to be called a lot)

    Have a loop run while the choice integer is not equal to some exit value (like -1)
        
        Display to the console the different possibilities of choice (1-7 for different deliverables, -1 to quit)
        If - else if - else chain to run different commands depending on the input
        
        If choice = -1, user has chosen to quit the gradebook
            Break the while loop
        If choice = 1, user wants to see the final letter grade of a student
            call final_grade()
        Else if choice = 2, user wants to see all the grades from a category and the total
            call category_grades()
        Else if choice = 3, user wants to see every grade grouped by category, and the course total
            call all_grades()
        Else if choice = 4, user wants to see the category totals and the course total
            call get_categories()
        Else if choice = 5, user only wants to see the course overall
            call get_overall()
        Else if choice = 6, user wants to know if a student was exempt from the final
            call is_exempt()
        Else if choice = 7, user wants to change a grade
            call change_grade()
        Else, choice was not one of the possible numbers
            Display an error message and loop again

    Outside the while loop, user has quit the program (display a good-bye message?)
    Call update_gradebook(file_name) to update the input file in case any changes were made
                            ^^^^^ Should be the string from when the file was opened

}

*/
