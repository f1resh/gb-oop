#pragma once
#include <iostream>
#include <cstdint>
#include <iomanip>
#include <string>
using namespace std;

class RGBA {
private:
	uint8_t m_red;
	uint8_t m_green;
	uint8_t m_blue;
	uint8_t m_alpha;
public:
	RGBA(uint8_t _m_red = 0 , uint8_t _m_green = 0, uint8_t _m_blue = 0, uint8_t _m_alpha = 255) : m_red(_m_red), m_green(_m_green), m_blue(_m_blue), m_alpha(_m_alpha) {
	};
	void print(){
		cout << "m_red = " 		<< int(m_red) 	<< endl;
		cout << "m_green = " 	<< int(m_green) << endl;
		cout << "m_blue = " 	<< int(m_blue)	<< endl;
		cout << "m_alpha = " 	<< int(m_alpha) << endl;
		printHex();
	}
	void printHex(){
		cout << "HEX:" << hex << setfill('0') <<
		setw(2) << int(m_red) 	<< 
		setw(2) << int(m_green) <<
		setw(2) << int(m_blue) 	<< 
		setw(2) << int(m_alpha) << dec << endl;
	}
};

