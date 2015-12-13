#include <iostream>
#include <string>

int main() {
	std::string currentPW = "hepxcrrq";
	//std::string currentPW = "aaaaxad";
	std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
	std::string doubles = "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyyzz";
	int i = currentPW.size() - 1;
	int beg = 0;
	bool test1 = false;
	bool test2 = false;

	std::cout << i << std::endl;

	while (!(test1 && test2)) {
		if (currentPW[i] == 'z') {
			currentPW[i] = 'a';
			i--;
		}
		else {
			currentPW[i]++;
			i = currentPW.size() - 1;

		}

		for (int j = 0; j < 5; j++) {
			if (alphabet.find(currentPW.substr(j, 3)) == 0) {
				test1 = true;
			}
			if (doubles.find(currentPW.substr(j, 2)) == 0) {
				test2 = true;
			}
		}
	}

	std::cout << currentPW << std::endl;

	system("pause");
	return 0;
}