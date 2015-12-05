#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct coordinate {
	int x;
	int y;
	int present;
};

int main() {
	ifstream grid;
	grid.open("grid.txt");
	char c;
	int index(0), count(0);
	int sIndex(0), rIndex(0);

	coordinate current;
	vector<coordinate> santa;
	vector<coordinate> robot;

	current.x = 0;
	current.y = 0;
	current.present = 1;

	santa.push_back(current);
	robot.push_back(current);
	index++; //index of vector increased with initial element
	sIndex = index;
	rIndex = index;

		while (grid.get(c)) {
			if (index % 2 != 0) {
				if (c == '^') {
					current.x = santa[sIndex - 1].x;
					current.y = santa[sIndex - 1].y + 1;
				}
				else if (c == 'v') {
					current.x = santa[sIndex - 1].x;
					current.y = santa[sIndex - 1].y - 1;
				}
				else if (c == '<') {
					current.x = santa[sIndex - 1].x - 1;
					current.y = santa[sIndex - 1].y;
				}
				else if (c == '>') {
					current.x = santa[sIndex - 1].x + 1;
					current.y = santa[sIndex - 1].y;
				}
			}
			if (index % 2 == 0) {
				if (c == '^') {
					current.x = robot[rIndex - 1].x;
					current.y = robot[rIndex - 1].y + 1;
				}
				else if (c == 'v') {
					current.x = robot[rIndex - 1].x;
					current.y = robot[rIndex - 1].y - 1;
				}
				else if (c == '<') {
					current.x = robot[rIndex - 1].x - 1;
					current.y = robot[rIndex - 1].y;
				}
				else if (c == '>') {
					current.x = robot[rIndex - 1].x + 1;
					current.y = robot[rIndex - 1].y;
				}
			}

			current.present = 1;

		for (int i = 0; i < santa.size(); i++) {
			if (current.x == santa[i].x && current.y == santa[i].y){
				santa[i].present++;
			}
			else if (current.x == robot[i].x && current.y == robot[i].y) {
				robot[i].present++;
			}
		}
		if (index % 2 != 0) {
			santa.push_back(current);
			sIndex++;
		}
		else {
			robot.push_back(current);
			rIndex++;
		}
		index++;

	}
	for (int i = 0; i < index; i++) {
		if (santa[i].present == 1) {
			count++;
		}
		if (robot[i].present == 1) {
			count++;
		}
	}
	count--; // exclude starting hosue

	cout << "Number of houses that recieved one present: " << count << endl;

	return 0;
}