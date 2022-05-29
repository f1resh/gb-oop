#pragma once
#include <cassert>
#include <iostream>
#include <string>
#include "mySort.h" //My Advanced QSort implementation from Algorhithms ans Data structures course.


class ArrayInt
{
private:
	int m_length;
	int* m_data;

public:

	ArrayInt() : m_length(0), m_data(nullptr) {};
	ArrayInt(int length) : m_length(length) {
		assert(length >= 0);
		if (length > 0)
			m_data = new int[length];
		else
			m_data = nullptr;
	};
	~ArrayInt() {
		delete[] m_data;
		m_data = nullptr;
	}

	int* begin() {
		return &m_data[0];
	}
	int* end() {
		return &m_data[m_length];
	}
	void fill(int value) {
		for (size_t i = 0; i < m_length; i++)
		{
			m_data[i] = value;
		}
	}

	void erase() {
		if (m_data == nullptr) return;
		delete[] m_data;
		m_data = nullptr;
		m_length = 0;
	}

	int size() {
		return m_length;
	}

	int& operator[](int index) {
		assert(index>=0 && index < m_length);
		return m_data[index];
	}

	void resize(int newSize) {
		if (newSize == m_length) return;
		if (newSize < 1) {
			erase();
			return;
		}
		int* newData = new int[newSize]{0};

		if (m_length > 0) 
		{
			int N_copy = (newSize >= m_length) ? m_length : newSize;
			for (size_t i = 0; i < N_copy; i++)
			{
				newData[i] = m_data[i];
			}
		}
		delete[] m_data;
		m_data = newData;
		m_length = newSize;
	}

	void insert(int value, int index) {
		assert(index >= 0 && index <= m_length);
		int* newData = new int[m_length+1] {0};
		for (size_t i = 0; i < index; i++)
		{
			newData[i] = m_data[i];
		};

		newData[index] = value;

		for (size_t i = index; i < m_length; i++)
		{
			newData[i+1] = m_data[i];
		};

		delete[] m_data;
		m_data = newData;
		m_length++;
	}

	void push_back(int value)
	{
		insert(value, m_length); 
	}
	void push_front(int value)
	{
		insert(value, 0);
	}

	// Homework methods

	int pop(int index) {
		assert(index >= 0 && index < m_length);
		int* newData = new int[m_length - 1]{ 0 };
		for (size_t i = 0; i < index; i++)
		{
			newData[i] = m_data[i];
		};

		int value = m_data[index];

		for (size_t i = index; i < m_length; i++)
		{
			newData[i] = m_data[i+1];
		};

		delete[] m_data;
		m_data = newData;
		m_length--;
		return value;
	}

	int pop_back() {
		return pop(m_length-1);
	}

	int pop_front() {
		return pop(0);
	}

	void sort() {
		mySort::advancedQSort(m_data, 0, m_length - 1);
	}

	void print(std::string name = "") {
		std::cout << "Vector" << name << ": ";
		for (size_t i = 0; i < m_length; i++)
		{
			std::cout << m_data[i] << " ";
		}
		std::cout << std::endl;
	}

};



