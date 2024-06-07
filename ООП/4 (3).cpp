#include <iostream>
#include <fstream>
#include <string>
using std::ios;

class student {
public:
	std::string name;
	unsigned int age;
	unsigned int year;
	char gender;
	double academicPerfromance;

	student() {}
	student(std::string x) {
		name = x;
	}
	student(student& s) {
		name = s.name;
	}
	student(student&& s) {
		name = s.name;
		s.name = nullptr;
	}
	~student() {}

	int countOfExcStudents(int sizeOfBase, student* student, std::fstream& out) {
		int n;
		std::cout << "Enter the year of study: ";
		std::cin >> n;

		int count = 0;
		for (int i = 0; i < sizeOfBase; ++i)
			if (student[i].year == n && student[i].academicPerfromance >= 9 && student[i].academicPerfromance <= 10) {
				count++;
			}
			else if (student[i].academicPerfromance < 0 || student[i].academicPerfromance > 10) { std::cout << "Invalid grade!"; return -1; }
		std::cout << "Count of excellent students on " << n << " year is: " << count << '\n' << '\n';
		out << "Count of excellent students on " << n << " year is: " << count << '\n';
		return count;
	}


	void fillClass(int sizeOfBase, student* student, std::fstream& out) {
		for (size_t i = 0; i < sizeOfBase; ++i) {
			std::cout << "Enter name: "; std::cin >> student[i].name;
			std::cout << "Enter age: "; std::cin >> student[i].age;
			std::cout << "Enter year of study: "; std::cin >> student[i].year;
			std::cout << "Enter gender: "; std::cin >> student[i].gender;
			std::cout << "Enter academic Performance: "; std::cin >> student[i].academicPerfromance;
			std::cout << std::endl;
		}
	}

	void printToConsole(int sizeOfBase, student* student) {
		std::cout << "============STUDENTS================" << '\n';
		for (size_t i = 0; i < sizeOfBase; ++i) {
			std::cout << "Name: " << student[i].name << '\n';
			std::cout << "Age: " << student[i].age << '\n';
			std::cout << "Year of study: " << student[i].year << '\n';
			std::cout << "Gender: " << student[i].gender << '\n';
			std::cout << "Academic Performance: " << student[i].academicPerfromance << '\n' << '\n';
		}
	}

	int printToFile(int sizeOfBase, student* student, std::fstream& out) {
		if (out.is_open()) {
			out.write(reinterpret_cast<char*>(&student), sizeof(student));
			/*for (size_t i = 0; i < sizeOfBase; ++i) {
				out << "Name: " << student[i].name << '\n';
				out << "Age: " << student[i].age << '\n';
				out << "Year of study: " << student[i].year << '\n';
				out << "Gender: " << student[i].gender << '\n';
				out << "Academic Performance: " << student[i].academicPerfromance << '\n' << '\n';
			}*/
		}
		else { std::cout << "File couldn't be opened for writing!"; return -1; }
	}

	int readFromFile(std::ifstream& in) {
		std::string line;
		if (in.is_open()) {
			while (std::getline(in, line))
			{
				std::cout << line << std::endl;
			}
		}
		else { std::cout << "File couldn't be opened for writing!"; return -1; }
	}

	int research(int sizeOfBase, student* student) {
		std::string name;
		std::cout << "Please enter the name of the student: ";
		std::cin >> name;

		if (student->name == name) {
			std::cout << std::endl << "Student found!" << std::endl;
			std::cout << "Name: " << student->name << '\n';
			std::cout << "Age: " << student->age << '\n';
			std::cout << "Year of study: " << student->year << '\n';
			std::cout << "Gender: " << student->gender << '\n';
			std::cout << "Academic Performance: " << student->academicPerfromance << '\n' << '\n';
		}
		else { std::cout << "Student not found!"; return -1; }
	}
};


int main() {
	std::string path = "students.bin";
	std::fstream outf(path, ios::out | ios::binary);
	std::ifstream inf(path, ios::in | ios::binary);

	int sizeOfBase;
	std::cout << "Enter the size of your base: ";
	std::cin >> sizeOfBase; std::cout << std::endl;
	if (sizeOfBase <= 0) { std::cout << "Invalid size!"; return -1; }

	student* Student = new student[sizeOfBase];


	Student->fillClass(sizeOfBase, Student, outf);
	Student->printToFile(sizeOfBase, Student, outf);

	Student->countOfExcStudents(sizeOfBase, Student, outf);
	Student->research(sizeOfBase, Student);

	inf.close();
	outf.close();
	delete[] Student;
	return 0;
}