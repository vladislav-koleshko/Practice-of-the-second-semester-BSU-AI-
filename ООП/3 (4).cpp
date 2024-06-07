#include <iostream>
#include <fstream>
#include <string>
using std::ios;

struct student {
	std::string name;
	unsigned int age;
	unsigned int year;
	char gender;
	double academicPerfromance;
};


int countOfExcStudents(int sizeOfBase, int n, student* student, std::ofstream& out);
int fillStruct(int sizeOfBase, student* student, std::ofstream& out);
int printStruct(int sizeOfBase, student* student, std::ofstream& out);


int main() {
	std::string path = "students.txt";
	std::ofstream outf(path);

	int sizeOfBase;
	std::cout << "Enter the size of your base: ";
	std::cin >> sizeOfBase; std::cout << std::endl;
	if (sizeOfBase <= 0) { std::cout << "Invalid size!"; return -1; }

	student* stu = new student[sizeOfBase];

	fillStruct(sizeOfBase, stu, outf);
	printStruct(sizeOfBase, stu, outf);

	int n;
	std::cout << "Enter the year of study: ";
	std::cin >> n;
	countOfExcStudents(sizeOfBase, n, stu, outf);

	outf.close();
	return 0;
}

int countOfExcStudents(int sizeOfBase, int n, student* student, std::ofstream& out) {
	int count = 0;
	for (int i = 0; i < sizeOfBase; ++i)
		if (student[i].year == n && student[i].academicPerfromance >= 9 && student[i].academicPerfromance <= 10) {
			count++;
		}
		else if (student[i].academicPerfromance < 0 || student[i].academicPerfromance > 10) { std::cout << "Invalid grade!"; return -1; }
	out << "Count of excellent students on " << n << " year is: " << count << '\n';
	return count;
}


int fillStruct(int sizeOfBase, student* student, std::ofstream& out) {
	if (out.is_open()) {
		for (size_t i = 0; i < sizeOfBase; ++i) {
			std::cout << "Enter name: "; std::cin >> student[i].name;
			std::cout << "Enter age: "; std::cin >> student[i].age;
			std::cout << "Enter year of study: "; std::cin >> student[i].year;
			std::cout << "Enter gender: "; std::cin >> student[i].gender;
			std::cout << "Enter academic Performance: "; std::cin >> student[i].academicPerfromance;
			std::cout << std::endl;
		}
	}
	else std::cout << "File couldn't be opened!"; return -1;
}

int printStruct(int sizeOfBase, student* student, std::ofstream& out) {
	if (out.is_open()) {
		for (size_t i = 0; i < sizeOfBase; ++i) {
			out << "Name: " << student[i].name << '\n';
			out << "Age: " << student[i].age << '\n';
			out << "Year of study: " << student[i].year << '\n';
			out << "Gender: " << student[i].gender << '\n';
			out << "Academic Performance: " << student[i].academicPerfromance << '\n' << '\n';
		}
	}
	else std::cout << "File couldn't be opened for writing!"; return -1;
}
