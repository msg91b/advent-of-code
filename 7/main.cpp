#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

struct values {
	string v1;
	string v2;
	string command;
	string output;
};

void parse(string s, map<string, uint16_t>& matches, vector<values>& myValues, int& index) {
	string  temp;
	istringstream ss(s);
	values operation;

	getline(ss, temp, ' ');
	if (temp == "NOT") {
		operation.command = temp;
		getline(ss, temp, ' ');
		operation.v1 = temp;
		getline(ss, temp, ' ');// -> throwaway
		getline(ss, temp);
		operation.output = temp;

		myValues.push_back(operation);
	}

	else {
		operation.v1 = temp;
		getline(ss, temp, ' ');

		if (temp == "->") {
			getline(ss, temp);
			operation.output = temp;
			if (operation.output == "b") { // comment out for Part 1
				operation.v1 = "956";
			}
			myValues.push_back(operation);

			if (myValues.at(index).v1 != "lx")
				matches[myValues.at(index).output] = stoi(myValues.at(index).v1);
		}

		else {
			operation.command = temp;
			getline(ss, temp, ' ');
			operation.v2 = temp;
			getline(ss, temp, ' '); // -> throwaway
			getline(ss, temp);
			operation.output = temp;
			myValues.push_back(operation);
		}
	}
	index++;
}

void shift(map<string, uint16_t>& matches, vector<values>& myValues) {
	for (auto const& x : matches) {
		for (auto &i : myValues) {
			if (x.first == i.v1) {
				if (i.command == "RSHIFT") {
					matches[i.output] = x.second >> stoi(i.v2);
				}
				else if (i.command == "LSHIFT") {
					matches[i.output] = x.second << stoi(i.v2);
				}
			}
		}
	}
}

void ao(map<string, uint16_t>& matches, vector<values>& myValues) {
	for (auto const& x : matches) {
		for (auto const& y : matches) {
			for (auto &i : myValues) {
				if ((i.v1 == x.first && i.v2 == y.first) || (i.v2 == x.first && i.v1 == y.first)) {
					if (i.command == "AND")
						matches[i.output] = x.second & y.second;
					if (i.command == "OR")
						matches[i.output] = x.second | y.second;
				}
			}
		}
	}
}

void not(map<string, uint16_t>& matches, vector<values>& myValues) {
	for (auto const& x : matches) {
		for (auto &i : myValues) {
			if (x.first == i.v1) {
				if (i.command == "NOT") {
					matches[i.output] = ~x.second;
				}
			}
		}
	}
}

void as(map<string, uint16_t>& matches, vector<values>& myValues) {
	for (auto &i : myValues) {
		for (auto const& x : matches) {
			if (i.command == "" && i.v2 == "" && i.v1 == x.first) {
				matches[i.output] = x.second;
			}
		}
	}
}

int main() {
	string s;
	int index(0);
	ifstream input("input.txt");

	map<string, uint16_t> matches;
	vector<values> myValues;

	while (getline(input, s)) {
		parse(s, matches, myValues, index);
	}
	while (matches["a"] == 0) {
		shift(matches, myValues);
		ao(matches, myValues);
		not(matches, myValues);
		as(matches, myValues);
	}

	cout << matches["a"] << endl;

	system("pause");
	return 0;
}