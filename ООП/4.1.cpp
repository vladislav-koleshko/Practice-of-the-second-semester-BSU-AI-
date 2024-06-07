#include <iostream>
#include <string>

class word {
	std::string str;
public:
	void fill() {
		std::cin >> str;
	}
	void print() {
		std::cout << str << std::endl;
	}


	word() {
		std::cout << "First constr: " << std::endl;
	}
	word(std::string p_str) {
		str = p_str;
		std::cout << "Second constr: ";
	}
	word(char symb, int n) {
		std::string str1(n, symb);
		str = str1;
		std::cout << "Third constr: ";
	}
	word(std::string p_str, int n) {
		std::cout << "Fourth constr: " << std::endl << "{" << std::endl;
		std::string first_n = p_str.substr(0, n);
		str = first_n;
		std::cout << "First n symbols: " + str << std::endl;

		std::string last_n = p_str.substr(p_str.size() - n);
		str = last_n;
		std::cout << "Last n symbols: " + str << std::endl << "}" << std::endl;
	}
	word(const word& p) {
		str = p.str;
		std::cout << "Constr of copy: ";
	}
	word(const word&& moved) noexcept {
		str = moved.str;
		std::cout << "Constr of movement: ";
	}
	/*~word() {
		delete str;
	}*/

	int countASCI() {
		int sum = 0;
		for (const auto& i : str) {
			sum += i;
		}
		std::cout << "Sum of ASCI: " << sum << '\n';
		return sum;
	}
};


int main() {
	word slovo1;

	word slovo2("privet");

	slovo2.print();
	word slovo3('a', 5);

	slovo3.print();

	word slovo4("abcdefg", 4);
	word slovo5{ slovo2 };

	slovo5.print();

	word slovo6{ slovo3 };

	slovo6.print();

	word slovo7;
	slovo7.fill();
	slovo7.countASCI();

	return 0;
}
