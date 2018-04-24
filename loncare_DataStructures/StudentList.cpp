#include "stdafx.h"
#include "StudentList.h"
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <chrono>

using namespace std;

// constrcutor
StudentList::StudentList(string file_name)
{
	// vairables
	vector<string> names;
	vector<int> ids;
	// open file
	fstream file(file_name, ios::in);
	// check if not successful
	if (!file.is_open()) {
		cout << "File not found";
	}
	else {
		// read input
		string line;
		while (getline(file, line, ',')) {
			names.push_back(line);
		}
		// generate ids and store data into lists and vectors
		GenerateRandomIDs(ids, names.size());
		for (int i = 0; i < names.size(); i++) {
			vectors.push_back(Student(ids.at(i), names.at(i)));
			lists.push_back(Student(ids.at(i), names.at(i)));
		}
		file.close();
	}
}

// sorts the vector and returns how long it took
double StudentList::sort_vector()
{
	auto t1 = chrono::high_resolution_clock::now();
	sort(vectors.begin(), vectors.end());
	auto t2 = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> time = t2 - t1;
	return time.count();
}

// sorts the list and returns how long it took
double StudentList::sort_list() {
	auto t1 = chrono::high_resolution_clock::now();
	lists.sort();
	auto t2 = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> time = t2 - t1;
	return time.count();
}

// searchs the vector and returns how long it took
double StudentList::search_vector_by_id(int search) {
	auto t1 = chrono::high_resolution_clock::now();
	find_if(vectors.begin(), vectors.end(), [&](Student& s) { return s.get_id() == search; });
	auto t2 = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> time = t2 - t1;
	return time.count();
}

// searches the list and returns how long it took
double StudentList::search_list_by_id(int search) {

	auto t1 = chrono::high_resolution_clock::now();
	find_if(lists.begin(), lists.end(), [search](Student& s) { return s.get_id() == search; });
	auto t2 = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> time = t2 - t1;
	return time.count();
}

//outputs the id and name in the vector when operator << is called
ostream& operator<<(ostream& out, const StudentList& value) {

	for (int i = 0; i < value.vectors.size(); i++) {

		out << left << fixed << setw(10) << value.vectors.at(i).get_id();
		out << fixed << setw(10) << value.vectors.at(i).get_name() << endl;

	}
	return out;
}
