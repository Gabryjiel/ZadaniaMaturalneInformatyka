#include <iostream>
#include <cmath>

using namespace std;

int main() {
	
	double surface = 0;
	double C = 10;
	
	int counter = 0;
	
	for(double i = 0; i <= C+0.01; i += 0.01) {
		double x = 0.01;
		double y = 1 + (((i+0.01)*(i+0.01)) / (100 - i + 0.01) / 200);
		
		surface += x*y;
		counter++;
	}
	
/*	for(double i = 0; i <= C+ 0.01; i+= 0.01) {
		double x = 0.01;
		double y = abs(-((i+0.01)*(i+0.01)/50));
		counter++;
		surface += x*y;
	}
*/	
	cout << surface << " " << counter << endl;
	surface *= 100;
	surface = round(surface);
	surface /= 100;
	cout << surface;
	
	
	
	return 1;
}
