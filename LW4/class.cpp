#include "class.h"

void BoolVector::resize()
{
	bool* temp = memory;
	int size = _capacity;
	_capacity *= 2;
	memory = new bool[_capacity];

	for (size_t i = 0; i < size; i++) {
		memory[i] = temp[i];
	}

	delete[] temp;
}

BoolVector::BoolVector(const BoolVector& vec)
{
	_size = vec._size;
	_capacity = vec._capacity;

	memory = new bool[_capacity];
	for (size_t i = 0; i < _size; i++) {
		memory[i] = vec.memory[i];
	}
}

void BoolVector::append(bool value)
{
	if (_size >= _capacity)
		resize();
	memory[_size++] = value;
}

int BoolVector::weight() const
{
	int w = 0;
	for (size_t i = 0; i < _size; i++) {
		if (memory[i]) w++;
	}
	return w;
}

BoolVector& BoolVector::operator~()
{
	for (size_t i = 0; i < _size; i++) {
		memory[i] = !memory[i];
	}
	return *this;
}

BoolVector& BoolVector::operator&=(const BoolVector& vec)
{
	size_t i = 0;
	while (i < _size && i < vec._size) {
		memory[i] = memory[i] && vec.memory[i];
		i++;
	}

	while (i < _size) {
		memory[i] = false;
		i++;
	}
	_size = i;

	return *this;
}

std::ostream& operator<<(std::ostream& out, const BoolVector& vec)
{
	for (size_t i = 0; i < vec._size; i++) {
		out << vec.memory[i] << " ";
	}

	return out;
}

/*BoolVector(initializer_list<bool> list) {
	int _index = 0;
	_size = list.size();
	_capacity = _size * 2;
	memory = new bool[_capacity];
	for (auto i : list) {
		memory[_index++] = i;
	}
}*/