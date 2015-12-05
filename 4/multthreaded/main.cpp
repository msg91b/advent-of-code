#include <iostream>
#include <string>
#include <thread>
#include "md5.h" //Taken from http://www.zedwood.com/article/cpp-md5-function

using namespace std;

string input = "ckczppom";
bool checkFive(true), checkSix(true);
bool check(true);

void work(int i);
void results(string firstFive, string firstSix, int i);

void startAt0() {
	for (int i = 0; check; i += 4) {
		work(i);
	}
}

void startAt1() {
	for (int i = 1; check; i += 4) {
		work(i);
	}
}

void startAt2() {
	for (int i = 2; check; i += 4) {
		work(i);
	}
}
void startAt3() {
	for (int i = 3; check; i += 4) {
		work(i);
	}
}

void work(int i) {
	string ret, firstFive, firstSix;
	string hash = input + to_string(i);
	ret = md5(hash);
	firstSix = md5(hash).substr(0, 6);
	firstFive = firstSix.substr(0, 5);
	results(firstFive, firstSix, i);
}


void results(string firstFive, string firstSix, int i) {
	//Part One output
	if (firstFive == "00000" && checkFive) {
		checkFive = false;
		cout << "Part One:  " << i << endl;
	}

	//part Two output
	else if (firstSix == "000000") {
		checkSix = false;
		cout << "Part Two: " << i << endl;
		check = false;
	}
}

int main() {
	thread t1(startAt0);
	thread t2(startAt1);
	thread t3(startAt2);
	thread t4(startAt3);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	system("pause");
	return 0;
}