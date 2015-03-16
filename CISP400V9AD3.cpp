// CISP400V9AD3.cpp
// Create GradeBook object, input grades and display grade report.

// include definition of class GradeBook from GradeBook.h
#include "GradeBook.h"

int main()
{
   // create GradeBook object myGradeBook and 
   // pass course name to constructor
   GradeBook myGradeBook( "CISP400 Object Oriented Programming with C++" );

   myGradeBook.displayMessage(); // display welcome message
   myGradeBook.inputData(); // read names and grades from user
   myGradeBook. displayAllStudentsandGrades();//display student's name and grade
   myGradeBook.displayGradeReport(); // display report based on grades
   myGradeBook.~GradeBook(); // call destructor
   myGradeBook.displayMessage(); //try to display the destroyed object information
   system("PAUSE");
  return 0; // indicate successful termination
} // end main

