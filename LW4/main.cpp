#include <iostream>
#include <cstdlib>
#include <ctime>
#include "class.h"

using namespace std;

int main() {
	int size;
	cout << "Enter Vec1 size: ";
	cin >> size;

	BoolVector vec1(size);
	srand(time(NULL));

	for (size_t i = 0; i < size; i++) {
		vec1.append(rand() % 2);
	}

	cout << "Vec1: ";
	vec1.printVector();

	cout << endl << "Enter elements of Vec2. If you want to stop enter -1: " << endl;
	int element;

	BoolVector vec2;

	while (true) {
		cin >> element;
		if (element == -1) break;
		if (element < 0 || element > 1) {
			cout << "Invalid input. Please enter either 0 or 1." << endl;
			continue;
		}
		vec2.append((bool)element);
	}

	cout << endl << "Vec2: ";
	vec2.printVector();

	BoolVector complement_vec1 = ~vec1;
	cout << "~Vec1: ";
	complement_vec1.printVector();

	BoolVector vec3 = complement_vec1 & vec2;
	cout << endl << "Vec3 == ~Vec1 & Vec2: ";
	vec3.printVector();

	cout << "Weight of Vec3: " << vec3.weight() << endl;

	return 0;
}