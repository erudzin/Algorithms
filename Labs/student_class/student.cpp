/*******************************************************************************
 * Name    : student.cpp
 * Author  : Eric Rudzin
 * Version : 1.0
 * Date    : September 10, 2020
 * Description : Creates a student class
 * Pledge : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>

#include <iomanip>

#include <vector>

using namespace std;

class Student {

private:
	string first_;
	string last_;
	float gpa_;
	int id_;

	public:
	// Constructor that uses an initializer list.
	Student(string first, string last, float gpa, int id) : first_{first}, last_{last}, gpa_{gpa}, id_{id} { }
	// Methods that do not modify member variables should be declared const.
	string full_name() const{
		return first_ + " "  + last_;
	}
	int id() const{
		return id_;
	}
	float gpa() const{
		return gpa_;
	}

	void print_info() const{
		cout << setprecision(2) << fixed << full_name() << ", GPA: " << gpa() << ", ID: " << id() << endl;
	}
};

/**
* Takes a vector of Student objects, and returns a new vector
* with all Students whose GPA is < 1.0.
*/
vector<Student> find_failing_students(const vector<Student> &students) {
	vector<Student> failing_students;
	for(auto student: students){
		if(student.gpa() < 1.0){
			failing_students.push_back(student);
		}
	}
	return failing_students;
}

/**
* Takes a vector of Student objects and prints them to the screen.
*/
void print_students(const vector<Student> &students) {
	for(auto student: students){
		student.print_info();
	}
}


/**
* Allows the user to enter information for multiple students, then
* find those students whose GPA is below 1.0 and prints them to the
* screen.
*/
int main() {
	string first_name, last_name;
	float gpa;
	int id;
	char repeat;
	vector<Student> students;
	do {
			cout << "Enter student's first name: ";
			cin >> first_name;
			cout << "Enter student's last name: ";
			cin >> last_name;
			gpa = -1;
			while (gpa < 0 || gpa > 4) {
				cout << "Enter student's GPA (0.0-4.0): ";
				cin >> gpa;
			}
			cout << "Enter student's ID: ";
			cin >> id;
			students.push_back(Student(first_name, last_name, gpa, id));
			cout << "Add another student to database (Y/N)? ";
			cin >> repeat;
	} while (repeat == 'Y' || repeat == 'y');
	cout << endl << "All students:" << endl;
	print_students(students);
	cout << endl << "Failing students:";
	vector<Student> failing_students = find_failing_students(students);
	if (failing_students.empty()){
		cout << " None" << endl;
	}
	else{
		cout << endl;
		print_students(failing_students);
	}

return 0;
}

