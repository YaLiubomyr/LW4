#include<iostream>

using namespace std;

class BoolVector {
private:
	int _size = 0;
	int _capacity = 1;
	bool* memory;

	void resize();

public:
	BoolVector(int size) : _size(0), _capacity(size * 2), memory(new bool[size]) {}
	BoolVector() : _size(0), _capacity(1), memory(new bool[_capacity]) {}
	BoolVector(const BoolVector& vec);

	~BoolVector() { delete[] memory; }

	friend std::ostream& operator<<(std::ostream& out, const BoolVector& vec);

	int getSize() const { return _size; }
	int getCapacity() const { return _capacity;}

	void append(bool value);
	int weight() const;

	BoolVector& operator~();
	BoolVector& operator&=(const BoolVector& vec);
};
