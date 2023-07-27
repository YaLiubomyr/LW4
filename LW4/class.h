#include <iostream>

class BoolVector {
	int size;
	bool* memory;

	void resize();

public:
	BoolVector(const int size);
	BoolVector() : size(0), memory(nullptr) {};
	BoolVector(const BoolVector& vec);

	~BoolVector() { delete[] memory; };

	void printVector() const;

	int getSize() const { return size; };

	void append(const bool value);
	int weight() const;

	BoolVector operator~();
	BoolVector operator&(const BoolVector& vec);
};