#include "stdafx.h"
#include "Student.h"
#include <string>

using namespace std;
// constrcutor
Student::Student(int id, string name)
{
	this->id = id;
	this->name = name;
}

//return id
int Student::get_id() const {
	return id;
}

// return name
string Student::get_name() const {
	return name;
}
