#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
struct Student
{
	Student() {
	}
	char name[10];
	int num;
	double grade;
};
int main(int argc, char* argv[]) {
	int count = atoi(argv[1]);
	ofstream fout(argv[0], std::ios::binary);
	Student stud;
	while (count--) {
		std::cout << "Enter name, num & grade\n";
		std::cin >> stud.name >> stud.num >> stud.grade;
		fout.write((char*)&stud, sizeof(stud));
	}
	system("pause");
	return 0;
}