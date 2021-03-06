#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
struct student {
	char name[10];
	int num;
	double grade;
};

int main(int argc, char* argv[])
{
	ofstream fout(argv[1]);
	ifstream fin(argv[0], std::ios::binary);
	fout << "Name of source binary file: " << argv[0] << '\n'
		<< "List student with average mark more than: " << argv[2] << ":\n";
	double num = atof(argv[2]);
	student stud;
	while (fin.read((char*)&stud, sizeof(stud))) {
		if (stud.grade > num) {
			fout << stud.name << ' ' << stud.num << ' ' << stud.grade << '\n';
		}
	}
	return 0;
}