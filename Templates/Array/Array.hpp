#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
	private:
		T *array;
		unsigned int len;

	public:
		Array() : array(NULL), len(0) {}
		Array(unsigned int n) : array(new T[n]), len(n) {}
		Array(const Array &obj) : array(new T[obj.len]), len(obj.len) {
			for (size_t i = 0; i < len; i++)
				array[i] = obj.array[i];
		}
		Array& operator=(const Array &obj){
			if (this == &obj)
				return *this;
			delete[] array;
			array = new T[obj.len];
			len = obj.len;
			for (size_t i = 0; i < len; i++)
				array[i] = obj.array[i];
			return *this;
		}
		~Array(){ delete[] array;};
		unsigned int getSize() const { return len; }
		T& operator[](unsigned int i){
			if (i < 0 || i >= len)
				throw std::out_of_range("Index out of range");
			return array[i];
		}
};

#endif // ARRAY_HPP