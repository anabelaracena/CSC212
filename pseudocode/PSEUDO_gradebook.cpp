/*

Need to include: vector, string, fstream, iostream, Gradebook.h

Constructor {
    assign each input vector to this->corresponding vector
}

Listed towards the end of the .h pseudocode, but these functions are so important they're going at the top

show_students() {
    cout a message along the lines of "these are the students in the class"
    loop through this->students
        cout each student by calling students[i] (no need to worry about the 2nd index), make sure to endl
}

get_student() {
    make a string to hold a name
    while true
        call display_students
        prompt the user to pick a name from the students listed about (cout message, followed by cin >> name string)
        loop through this->students
            if students[i] == name string
                return i
        loop ended nothing returned
        cout an error message
        repeat while loop until a valid name is entered, breaking the loop
}

final_grade() {
    call get_student, assign the returned value to an int idx
    int point total = 0
    loop through this->labs[idx] (subvector containing the lab grades of student @ idx)
        point total += this->labs[idx][i]
    loop through this->assignments[idx] (subvector containing the assigment grades of student @ idx)
        point total += this->labs[idx][i]
    loop through this->projects[idx] (subvector containing the project grades of student @ idx)
        point total += this->labs[idx][i]
    Add the student's exam grade to point total (exams are 1D, just access via this->exams[idx])

    cout the students name, and a leading sentence to present their grade in main
    Ex: student[@idx]'s final course grade is a (dont end line)

    Luckily, the course point total is out of 1000 and the cutoffs are given in the syllabus
    if total >= 940, cout "A"
    else if 940 > total >= 900, cout "A-"
    else if 900 > total >= 870, cout "B+"
    else if 870 > total >= 830, cout "B"
    else if 830 > total >= 800, cout "B-"
    else if 800 > total >= 770, cout "C+"
    else if 770 > total >= 730, cout "C"
    else if 730 > total >= 700, cout "C-"
    else if 700 > total >= 670, cout "D+"
    else if 670 > total >= 630, cout "D"
    else if 630 > total >= 600, cout "D-"
    else, cout "F"

}

category_grades() {
    call get_student, assign the returned value to an int idx
    make a string to hold a category
    while string != any of the 4 possible categories ("Lab", "Assignment", "Project", "Exam")
        cout the 4 possible categories 
        prompt the user to enter a catergory (store in the string)
        if string = any of the 4 category names ("Lab", "Assignment", "Project", "Exam")
            continue (while breaks)
        else, user entered a bad category
            cout an error statement, loop runs again


    make a total variable to hold the category total (=0)
    cout "student[@idx]'s (string) grades are"
    depending on which of the 4 categories string is (4 if / else if statements)
        loop through that category
            category total += category[idx][i]
            cout each grade, separated by a whitespace

    cout "and their (category) total is (total)"
    May have to alter the cout statements case by case depending on the nature of category itself
        ^^^ This is extremely nit-picky, but printing "So-and-so's Exam grades are" when there's only 1 exam grade looks lazy
}

all_grades() {
    call get_student, assign the returned value to an int idx
    make an int to track the overall total
    loop through every category vector
        cout the value of category[@idx][i]
        sum the points for the overall total

    *** Make sure to print some kind of leading statement before the loops that print the grades ***
                i.e. print student[@idx]'s lab grades are: x y z endl
                            vs
                print x y z (user has no idea what this data means)

    cout the overall total
}

get_categories() {
    call get student, assign the returned value to an int idx
    loop through every category vector, summing the totals for student[@idx]
    make a separate sum int to hold the course overall points
    cout each category total and the overall

    this can be done either with one category sum tracker that resets between each loop, or with a sum tracker for each category
    only different is the couts for one tracker will have to be between every loop
    for multiple sum variables, will have to write one cout statement for each
    dont forget to cout the overall total!
}

get_overall() {
    call get student, assign the returned value to an int idx
    make an overall point total counter
    loop through every single category vector
        total += category[idx][i]

    cout student[idx]'s course overall is (total) points
}

is_exempt() {
    call get student, assign the returned value to an int idx
    make an overall point total counter
    loop through every single category vector EXCLUDING EXAM
        total += category[idx][i]
    
    if total >= 810
        cout "student[idx] is exempt from the final"
    else, cout "student[idx] is not exempt from the final

    810 is because pre exam, the max points you can achieve is 900
    To be exempt from the final, you need at least 90% of 900, aka 810
}

change_grade() {
    call get student, assign the returned value to an int idx
    make a string to hold a category
    while string != any of the 4 possible categories ("Lab", "Assignment", "Project", "Exam")
        cout the 4 possible categories 
        prompt the user to enter a catergory (store in the string)
        if string = any of the 4 category names ("Lab", "Assignment", "Project", "Exam")
            continue (while breaks)
        else, user entered a bad category
            cout an error statement, loop runs again
    
    make an int for which grade the user would like to change (start at =0)
    while 1 > deliverable_number or category.size < deliverable_number
    *** For the while condition, include an && check for what category ==, this spares you from having to paste the code below 4 times ***
        Ask the user which (category) grade they would like to change (1-n), where n is the size of the (category) vector
        cin >> deliverable number
        if the deliverable number is valid for that category (ex assignment #3 exists, assignment #9 does not)
        *** in this if statement, include nearly the logic in the while loop condition, but to make sure the deliverable number IS within bounds ***
        ex category == Lab && (deliverable number is within the appropriate bounds of said category)
            continue (loop should break and not run again)
        else
            print an error statement
            continue (loop runs again)
    make an int for the new grade being updated
    while (true)
        cin >> new grade
        if new grade is within the boundaries of possible points for that deliverable
        (i.e labs 0-20pts, assignments 0-50pts, exam 0-100pts, project1 0-150pts, and 0-350pts)
            break the while loop
        else, print an error statement and loop again
        *** NOTE: since project 1 and project 2 have different point values, will need to include each project deliverable # in the if statement
    

    All possible error checking is resolved
    category[idx][deliverable number - 1] = new_grade
}

update_gradebook(file_name) {
    open an output stream with the file name
    write to the first line the entire name vector, separated by whitespace
        make sure the last entry has no whitespace to prevent discrepencies between in/out files
    endl

    loop through the size of the names vector
        loop through the size of labs[i]
            write all lab grades (with whitespace)
        loop through the size of assignments[i]
            write all assignment grades (with whitespace)
        loop through the size of projects[i]
            write all project grades (with whitespace)
        write the exam grade @ index i (no whitespace, but an endl)
}

*/
