#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main() {
	int length(0), width(0), height(0), counter(0), smallest(0), total(0), bow(0), ribbon(0), totalRibbon(0), b(0);
	int surfaceArea(0);
	string s, substr;

	ifstream dimensions;
	dimensions.open("dimensions.txt");

	while (getline(dimensions, s)) {
		stringstream ss(s);
		while (getline(ss, substr, 'x')) { //use stringstream to convert from string to int delimiting on x
			stringstream ss1(substr);
			if (counter == 0) {
				ss1 >> length;
			}
			else if (counter == 1) {
				ss1 >> width;
			}
			else if (counter == 2) {
				ss1 >> height;
			}
			counter++;
		}
		counter = 0; //reset couter for next set of dimensions

		//compute surfaceArea
		surfaceArea = 2 * length*width + 2 * width*height + 2 * height*length;

		//compute area of smallest side
		cout << "length: " << length << endl;
		cout << "width: " << width << endl;
		cout << "height" << height << endl;
		smallest = length*width;
		bow = 1;
		if (smallest > width*height) {
			smallest = width*height;
			bow = 2;
		}
		if (smallest > height*length) {
			cout << "before case 3 smallest is: " << smallest << endl;
			smallest = height*length;
			cout << "after case 3 smallest is: " << smallest << endl;
			bow = 3;
		}
		//compute total
		total += surfaceArea + smallest;

		//compute ribbon wrap & bow
		if (bow == 1) {
			ribbon = length + length + width + width;
		}
		else if (bow == 2) {
			ribbon = width + width + height + height;
		}
		else if (bow == 3) {
			ribbon = height + height + length + length;
		}
		b = length*width*height;
		totalRibbon += ribbon + b;
		cout << "smallest bow: " << bow << endl;
		cout << "ribbon: " << ribbon << endl;
		cout << "bow: " << b << endl;
		cout << "total ribbon: " << totalRibbon << endl;
		cout << endl;
	}
	cout << "Total wrapping paper required: " << total << endl;
	cout << "Total ribbon required: " << totalRibbon << endl;
	dimensions.close();

	return 0;
}