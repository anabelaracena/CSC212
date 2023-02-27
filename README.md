# CSC212 - Review/Gradebook Project

## Summary

The gradebook project looks for an input file containing the first and last names of students on the first line, and their grades on the respective next lines. First and last name 1 will go with line 2’s data, first and last name 2 will go with line 3’s data, etc. Each grade in the file will have a letter value before (‘l’, ‘a’, ‘p’, or ‘e’) to determine what category it falls in, ex: l10, for a lab with a grade of 10. Grading is based on the syllabus that lists out every grading category by points, totalling in 1000. The user will be asked to enter an input to see different stats based on the data, including letter grade of a student, every grade from a student, editing grades of a student, and more.

## Planning

#### Tentative Plan
    1. Write pseudocode for main, as well as gradebook .cpp & .h, upload as their own files in /pseudocode
    2. Pick which functions you want to implement via the "Functions" file in /pseudocode
    3. Implement functions individually, updating the real files in /final_files
    4. Functions can be tested along the way with the input1.txt file in /pseudocode
    5. Each member writes a full mock data set (n students), following the guidelines in the input_format.txt and input1.txt files
        - Datasets don't HAVE to be in alphabetical order, but if we're hard coding our datasets we might as well
        - We'll sort by first name for the time being
    6. Complete summary section, as well as the compilation/runtime instruction sections in README
    7. Provide ample comments in all files
    8. Make project walkthrough video
    9. Upload to Gradescope by Monday Feb. 27th

#### Pseudocode
All pseudocode used to map out the project is kept within the "pseudocode" folder. Pseudocode was written, and then it turned into real, usable code within the project files. Also within the pseudocode folder is the .md file "Functions", where all the needed functions for the program are listed out, and each teammate responsible for implementing a certain function lists their name above it


## Instructions

#### Compilation

To compile the program, simply enter "g++ main.cpp gradebook.cpp -o main" in the terminal while in the same folder as the .cpp files.

#### Runtime

To run the program, the only command line arguments are "./main", and the name of the .txt file the user wishes to input. While reading the input, any incomplete gradebook entries will be replaced by a -1 in memory, and gradebook entries exceeding the minimum/maximum permissable grade (ex: a lab grade of -20pts or 200pts) will be rewritten as a 0 or the maximum grade for that deliverable type, respectively. The gradebook class implementation will ignore this -1 value anytime it appears, as no deliverable may have a negative grade value. During runtime, the program will prompt the user with several choices they can make regarding what kind of results they want from the gradebook. The choices include, but are not limited to: getting a student's current letter grade, getting a student's grades from a certain deliverable category, seeing whether or not a student is exempt from the final exam, and so on. In the program, invalid input will be handled with an error message, and the user will be re-prompted to give a correct, valid input. When the user is finished with the program, they simply have to enter "-1" at the main menu, and the program will quit with a good-bye message, as well as updating the input file with any changes the user may have made to the grades. 

## Sample I/O

### Regular Data Set, Minor Gradebook Changes

##### Input
![Screen Shot 2023-02-27 at 5 01 11 PM](https://user-images.githubusercontent.com/90429535/221695788-ff9b7300-fee8-4028-b24b-535167d00aa4.png)

##### Output
![Screen Shot 2023-02-27 at 5 06 42 PM](https://user-images.githubusercontent.com/90429535/221696678-c925af6a-1781-4c51-b542-971bbc18c2b6.png)

Grade for Exam 1 (Connor) changed from 100 to 99, grade for Lab 5 (Mark McMark) changed from 0 to 20, grade for exam 1 (Joe Schmoe) changed from 89 to 100.

### Irregular Data Set, Out Of Bounds Grades Cases

##### Input
![Screen Shot 2023-02-27 at 5 08 32 PM](https://user-images.githubusercontent.com/90429535/221697001-252b5c5c-e493-420b-8786-5aa1cf454e4a.png)

##### Output
![Screen Shot 2023-02-27 at 5 09 09 PM](https://user-images.githubusercontent.com/90429535/221697091-8c43e8e3-d2ea-4ee8-abcb-2c53789b67d6.png)

No explicit changes made, function automatically recognizes invalid grades and corrects them to either 0 or the maximum possible point value.
