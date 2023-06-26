#include<iostream>
#include "class.h"

using namespace std;

int main() {
	int size;
	cout << "Enter vec1 size: ";
	cin >> size;

	BoolVector vec1(size);
	srand(time(NULL));

	for (size_t i = 0; i < size; i++) {
		vec1.append(rand() % 2);
	}

	cout << "Vec1: " << vec1 << endl;

	cout << "Enter elements of vec2. If you want to stop enter -1: " << endl;
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

	cout << "Vec1: " << vec1 << endl;
	cout << "Vec2: " << vec2 << endl;

	BoolVector vec3 = ~vec1;
	cout << "~Vec1: " << vec3 << endl;

	vec3 &= vec2;
	cout << "Vec3 == ~Vec1 & Vec2: " << vec3 << endl;
	cout << "Weight of Vec3: " << vec3.weight() << endl;

	return 0;
}