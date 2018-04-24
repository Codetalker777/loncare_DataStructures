#pragma once
#include <string>
using namespace std;
class Student
{
private:
	// variables
	int id;
	string name;
public:
	// functions
	Student(int, string);
	// method for determining which student object is less than
	bool operator <(const Student& input) {
		return name < input.name;
	}
	int get_id() const;
	string get_name() const;
};

