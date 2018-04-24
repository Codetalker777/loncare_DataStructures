#pragma once
#include <string>
#include "Student.h"
#include <vector>
#include <list>
#include <iostream>
#include <time.h>
#include <algorithm>

using namespace std;

class StudentList
{
private:
	// variables
	vector<Student> vectors;
	list<Student> lists;
public:
	// function declarations
	StudentList(string);
	double sort_vector();
	double sort_list();
	double search_vector_by_id(int);
	double search_list_by_id(int);
	friend ostream& operator <<(ostream&, const StudentList&);
	// method used to generate random numbers
	static void GenerateRandomIDs(vector<int>& num, const int size) {
		srand(time(NULL));
		int i = 0;
		vector<int>::iterator it;

		int number = rand() % size;
		num.push_back(number);
		int count = 0;
		count++;
		for (i = 0; i < size; i++) {

			// terminate if max amount of numbers generated
			if (count == size){
				break;
			}
			it = find(num.begin(), num.end(), number);

			// keep running until number not in vector generated
			while (it != num.end()) {

				number = rand() % size;
				it = find(num.begin(), num.end(), number);
			}
			num.push_back(number);
			count++;
		}
		return;
	}
};

