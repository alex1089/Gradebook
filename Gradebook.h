// Gradebook header
// Assignment AD3
// Alekey Leshchuk

#include <string>
#ifndef GRADEBOOK_H
#define GRADEBOOK_H

class GradeBook {
    public:
    	// class constructor
	GradeBook(std::string const& cName);
	// sets up to 30 characters of a string as the courseName
	void setCourseName(std::string const& cName);
	// returns private member string courseName
	std::string getCourseName() const;
	// initializes private data members
	void initializeData();
	// displays a welcome message 
	void displayMessage() const; 
	// assigns the letter grade entered, and validates
	// data, returns result of validation
	bool inputGrades(int const& element, char const& lGrade);
	// displays grade report
	void displayGradeReport() const;
	// diplays 4 columns of all grades entered
	void displayInputs() const;
	// calculates and returns double GPA
	double calculateGrade() const;
	// data input interface
	void inputData();
	// displays student's names and grades
	void displayAllStudentsandGrades() const;
	// input student name according to the index element entered as argument
	void inputStudentName(int const element);
	// displays student's name at input index
	void displayStudentName(int const element) const;
	// displays grade at input index
	void displayGrade(int const element) const;
	~GradeBook();

    private:
	std::string courseName;
	char letterGrades[100];
	int countGrades[6];
	char* studentName[100];
};

#endif 
