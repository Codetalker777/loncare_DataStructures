// loncare_DataStructures.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "StudentList.h"
#include "Student.h"

using namespace std;

int main() {

	StudentList student_list("names.csv");
	
	cout << student_list << endl;
	
	double duration_of_vector_sort = student_list.sort_vector();
	double duration_of_list_sort = student_list.sort_list();

	cout << student_list << endl;
	cout << "The vector sort took " << duration_of_vector_sort << " seconds.\n";
	cout << "The list sort took " << duration_of_list_sort << " seconds.\n";

	cout << "Press any key to continue ... ";
	char c;
	cin.get(c);
	
	double duration_of_vector_search = student_list.search_vector_by_id(750);
	double duration_of_list_search = student_list.search_list_by_id(750);

	cout << "The vector search took " << duration_of_vector_search << " seconds.\n";
	cout << "The list search took " << duration_of_list_search << " seconds.\n";

	cout << "Press any key to exit ... ";
	cin.get(c);
	return 0;
}
/*The vector data structure operates faster than the list for the following reason;
in a vector you can have random access to any variable from 0 to size while in a list
it is bi-directional meaning you only have access to the next or previous element but not all of them
due to this, more effiecent sorts can be done on vectors versues lists*/

