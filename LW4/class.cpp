#include "class.h"

void BoolVector::resize()
{
	int new_size = size + 1;
	bool* temp = memory;
	memory = new bool[new_size];

	for (int i = 0; i < size; i++) {
		memory[i] = temp[i];
	}

	delete[] temp;
}

BoolVector::BoolVector(const int size) : size(0), memory(new bool[size])
{
	for (int i = 0; i < size; i++)
		memory[i] = false;
}

BoolVector::BoolVector(const BoolVector& vec)
{
	size = vec.size;
	memory = new bool[size];
	for (int i = 0; i < size; i++) {
		memory[i] = vec.memory[i];
	}
}

void BoolVector::printVector() const
{
	for (int i = 0; i < size; i++) {
		std::cout << memory[i] << " ";
	}
	std::cout << std::endl;
}

void BoolVector::append(const bool value)
{
	resize();
	memory[size++] = value;
}

int BoolVector::weight() const
{
	int w = 0;
	for (int i = 0; i < size; i++) {
		if (memory[i]) w++;
	}
	return w;
}

BoolVector BoolVector::operator~()
{
	BoolVector complement(*this);
	for (int i = 0; i < size; i++) {
		complement.memory[i] = !complement.memory[i];
	}
	return complement;
}

BoolVector BoolVector::operator&(const BoolVector& vec)
{
	int max = (size > vec.size) ? size : vec.size;

	BoolVector conjunction(max);
	int i = 0;

	for (i; i < size && i < vec.size; i++) {
		conjunction.memory[i] = memory[i] && vec.memory[i];
	}

	for (i; i < max; i++) {
		conjunction.memory[i] = false;
	}

	/*while (i < size && i < vec.size) {
		conjunction.memory[i] = memory[i] && vec.memory[i];
		i++;
	}*/

	/*while (i < max) {
		conjunction.memory[i] = false;
		i++;
	}*/

	conjunction.size = i;

	return conjunction;
}