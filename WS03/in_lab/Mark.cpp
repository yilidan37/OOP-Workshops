/***********************************************************************
// OOP244 Workshop 3: Member functions and privacy
// File Mark.cpp
// Version 1.0
// Date	2019/09/22
// Author	Song Zeng
// Name Song Zeng    Date 2019/09/22    Reason OOP244_NBB_workshop2_DIY_submition
// Student NO: 125824185    Email: szeng9@myseneca.ca
// Description
// Function and struct declaration
//
// Revision History
// -----------------------------------------------------------
//
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Mark.h"
using namespace std;
namespace sdds {
	void Mark::flushKeyboard()const {
		while (cin.get() != '\n');
	}

	void Mark::set(int diaplayMode) {
		m_displayMode = diaplayMode;
	}

	void Mark::set(double mark, int outOf ) {
		m_mark = mark;
		m_outOf = outOf;
	}

	void Mark::setEmpty() {
		m_displayMode = DSP_UNDEFINED;
		m_mark = -1;
		m_outOf = 100;
	}

	bool Mark::isEmpty() const {
		if (m_mark == -1 && m_outOf == 100)
			return true;
		else
			return false;
	}

	int Mark::percent()const {
		int i;
		i = m_mark / m_outOf * 100 + 0.5;
		return i;
	}

	double Mark::rawValue()const {
		return m_mark / m_outOf;
	}

	bool Mark::read(const char* prompt) {
		char ch;
		cout << prompt;
		cin >> m_mark >> ch >> m_outOf;
		if (cin.fail()) {
			cin.clear();
			flushKeyboard();
			setEmpty();
			return false;
		}
		else
			return true;
	}

	std::ostream& Mark::display() const {
		if (isEmpty()) {
			cout << "Empty Mark object";
		}
		else if (m_displayMode == DSP_RAW)
			cout << rawValue();
		else if (m_displayMode == DSP_PERCENT)
			cout << "%" << percent();
		else if (m_displayMode == DSP_ASIS)
			cout << m_mark << "/" << m_outOf;
		else if (m_displayMode == DSP_UNDEFINED)
			cout << "Display mode not set!";
		else
			cout << "Invalid Mark Display setting!";
		return cout;
	}
	int Mark::out() {
		return m_outOf;
	}
}