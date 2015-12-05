#include <iostream>
#include <fstream>
#include <string>
#include "md5.h" //Taken from http://www.zedwood.com/article/cpp-md5-function

using namespace std;

int main() {
	string input = "ckczppom";
	string hash, ret, firstFive, firstSix;
	bool checkFive(true), checkSix(true);

	for (int i = 0; checkSix; i++) {
		hash = input + to_string(i);
		ret = md5(hash);
		firstFive = ret.substr(0, 5);
		firstSix = ret.substr(0, 6);

		//Part One output
		if (firstFive == "00000" && checkFive) {
			checkFive = false;
			cout << "Part One:  " << i << endl;
		}

		//part Two output
		else if (firstSix == "000000") {
			checkSix = false;
			cout << "Part Two: " << i << endl;
		}
	}
	return 0;
}