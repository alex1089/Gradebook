// Gradebook definition
// AD3 Assignment
// Aleksey Leshchuk

#include "Gradebook.h"
#include <cctype>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

// enum for grade input count for readability
enum Grades{A=0,B,C,D,F,ERROR};

// class constructor
GradeBook::GradeBook(std::string const& cName)
    {
    initializeData();
    std::cout<<"The Grade Book constructor is called\n";
    setCourseName(cName); // initialize data member class name
    displayMessage();	// display welcome message
    displayGradeReport(); // display current gradebook
    std::cout<<"*****The end of Grade Book Constructor.*****\n\n\n";
}

// sets up to 30 characters of a string as the courseName
void GradeBook::setCourseName(std::string const& cName){
    if (cName.size()>30){   // if >30 characters in course name input
	std::cout<<"\tName: \""<<cName<<"\"\n\t exceeds maximum length (30).\n\n";
	std::cout<<"\tLimiting course name to 30 characters.\n\n";
	courseName=cName.substr(0,29);
    } else {
	courseName=cName;
    }
}

// returns private member string courseName
std::string GradeBook::getCourseName() const{
    return courseName;
}

// initializes private data members
void GradeBook::initializeData(){
    for (char*& i:studentName)
	i=nullptr;
    for (int& i:countGrades)
	i=0;
    for (char& i:letterGrades)
	i=0;
}

// displays a welcome message 
void GradeBook::displayMessage() const{
    std::cout<<"\tWelcome to the grade book for\n\t"<<courseName<<"!\n\n";
}
// **
bool GradeBook::inputGrades(int const& element, char const& lGrade){
    bool status=true;     // variable to the validity of the input
    switch (lGrade){	    // increment gradeCount, and write grade in upper to letterGrades array
	case 'A':
	case 'a':
	    letterGrades[element]=toupper(lGrade);
	    countGrades[A]++;
	    break;
	case 'B':
	case 'b':
	    letterGrades[element]=toupper(lGrade);
	    countGrades[B]++;
	    break;
	case 'C':
	case 'c':
	    letterGrades[element]=toupper(lGrade);
	    countGrades[C]++;
	    break;
	case 'D':
	case 'd':
	    letterGrades[element]=toupper(lGrade);
	    countGrades[D]++;
	    break;
	case 'F':
	case 'f':
	    letterGrades[element]=toupper(lGrade);
	    countGrades[F]++;
	    break;
	default:
	    countGrades[ERROR]++;
	    std::cout<<"\tXXXXIncorrect letter grade entered.XXXX\n"<<
		"\t\""<<lGrade<<"\""<<"is not a valid grade.\n\n";
	    status=false;
	    letterGrades[element]=lGrade;
    }
    return status;
}
    
// displays grade report
void GradeBook::displayGradeReport() const{
    int total=0;    // stores total number of data input
    std::cout<<"The total number sets of data input is ";
    for (int i:countGrades)
	total+=i;   // add all data up
    std::cout<<total<<std::endl;    // output
    std::cout<<"The total number of error input is "<<countGrades[ERROR]<<std::endl;
    std::cout<<"The total number of students receive grades is "<<total-countGrades[ERROR]<<std::endl;
    std::cout<<"The total number of students who received each letter grade:\n";
    std::cout<<"A: "<<countGrades[A]<<std::endl
	<<"B: "<<countGrades[B]<<std::endl
	<<"C: "<<countGrades[C]<<std::endl
	<<"D: "<<countGrades[D]<<std::endl
	<<"F: "<<countGrades[F]<<std::endl;
std::cout<<std::fixed<<std::setprecision(2);
std::cout<<"The class average is: "<<calculateGrade()<<std::endl;
}
// diplays 4 columns of all grades entered
//void GradeBook::displayInputs() const

// calculates and returns double GPA
double GradeBook::calculateGrade() const{
    int total=0, total_points=0;    // total valid grades, and total points
    double GPA; 

    for (int i=0;letterGrades[i]!=0;i++)	// loop through entered grades until a 0 is found
    {
	switch (letterGrades[i]){
	    case 'A':
		total++;
		total_points+=4;
		break;
	    case 'B':
		total++;
		total_points+=3;
		break;
	    case 'C':
		total++;
		total_points+=2;
		break;
	    case 'D':
		total++;
		total_points+=1;
		break;
	    case 'F':
		total++;
		break;
	    default:
		break;
	}

    }
    if (total)
	GPA=static_cast<double>(total_points)/total;
    else
	GPA=0.0;
    return GPA;
}

// data input interface
void GradeBook::inputData() {
    static int inpCount=0;
    char inp=0;	// hold input
    bool valid; // input loop validity flag
    while (true){	// get input until EOF is entered
	std::cout<<"\tEnter the letter grades.\n";
	std::cout<<"\tOr enter the EOF character to end input.\n";
	std::cout<<"\t(Use Ctl + D, or Ctl + Z)\n";
    
	do{
	    valid=true;
	    inp=std::cin.get();
	    if (!std::cin.good() && !std::cin.eof() || inp=='\n'){	
		// if error or space is input, clear flags and try again.
		std::cin.clear();
		std::cin.ignore(1000,'\n');
		valid=false;
		std::cout<<"\nError in input, try again.\n";
	    }
	    std::cin.ignore(1000,'\n');
	} while (!valid);   // loop dowhile until valid input is entered

	if (std::cin.eof())			// exit if EOF char is entered
	    break;
	if (inputGrades(inpCount,inp))	// if input is a valid grade, get name
	    inputStudentName(inpCount);
	inpCount++;			// increment input counter
    }
    if (!inpCount)
	std::cout<<std::setw(70)<<std::right<<"There is no data entered.\n";
}

// displays student's names and grades
void GradeBook::displayAllStudentsandGrades() const{
    int index=0;    // array index
    int rows=0;	    // store total rows necessary for output of grades entered
    int total=0;    // store total grades entered
    int iOffset=0, nOffset=0, gOffset=0;  //variables for offset calculations to center name
    for (int i:countGrades)
	total+=i;
    rows=total/2;	// number of rows to be printed, 2 entries per row
    rows=rows+total%2;	
    
    std::cout<<std::endl;
    std::cout<<"The data entered is listed at the following:\n";

    std::cout<<std::left;
    for (int i=0;i<2;i++)
	std::cout<<std::setw(10)<<"Index"<<std::setw(18)<<"Student Name"<<std::setw(8)<<"Grade";   

    std::cout<<std::endl;
    for (int i=0;i<rows;i++){
	for (int ii=0;ii<2;ii++){	    // 2 columns per row
	    if (ii%2)		    // if second column is printed, offset index by 8, else by 3
		iOffset=8;
	    else
		iOffset=3;
	    std::cout<<std::right;
	    if (studentName[index]){	// if studentName[index] is allocated, calculate offset
		nOffset=14+(strlen(studentName[index])/2); // nameoffset = 14 + sizeofname/2
		gOffset=14-strlen(studentName[index])/2;
	    }else{			// else use static offsets 
		nOffset=22;
		gOffset=2;
	    }

	    if (index<total)	// print second column only if element exists
		std::cout<<std::setw(iOffset)<<index;
	    if (studentName[index]) // if studentName exists, print it, else print blank
		std::cout<<std::setw(nOffset)<<studentName[index];
	    else
		std::cout<<std::setw(26)<<" ";
	    std::cout<<std::setw(gOffset)<<letterGrades[index];	    // print grade
	    index++;	// increment index
	}
	std::cout<<std::endl;
    }
    std::cout<<std::endl<<std::endl;
}
    
// input student name according to the index element entered as argument

void GradeBook::inputStudentName(int const element){
    bool valid;	    // validity flag for input
    studentName[element]= new char[19];     // allocate 19 char array to hold student name
    std::cout<<"\tEnter a student's name.\n";
    do {
	valid=true;
	std::cin.get(studentName[element],18,'\n'); // if error occurs in input, clear flag
	if (!std::cin.good() || *studentName[element]=='\n'){
	    std::cin.clear();
	    std::cin.ignore(1000,'\n');
	    std::cout<<"Error in input, try again.\n";
	    valid=false;
	}
    } while (!valid);
	
    std::cin.ignore(100,'\n');	// clear stream before returning
}

// displays student's name at input index
void GradeBook::displayStudentName(int const element) const{
    std::cout<<"\tThe student's name at index "<<element<<" is "<<studentName[element]<<std::endl;
}

// displays grade at input index
void GradeBook::displayGrade(int const element) const{
    std::cout<<"\tThe grade at index "<<element<<" is "<<letterGrades[element]<<std::endl;
}

// destructor
GradeBook::~GradeBook(){
    int total=0; 
    
    std::cout<<"Destructor is called\n";

    for (int i:countGrades)
	total+=i;

    total-=countGrades[ERROR]; // count total allocated arrays of names
    for (int i=0, found=0;found<total;i++){
	if (studentName[i]!=nullptr){	    // Loop until all allocated pointers are deallocated
	    found++;
	    delete[] studentName[i];
	}
    }

}
