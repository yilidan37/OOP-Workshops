/***********************************************************************
// OOP244 Workshop 3: Member functions and privacy
// File Mark.h
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
#ifndef SDDS_MARK_H__
#define SDDS_MARK_H__
#include <iostream>
namespace sdds {
#define DSP_RAW 1
#define DSP_PERCENT 2
#define DSP_ASIS 3
#define DSP_UNDEFINED -1
	class Mark {
		int m_displayMode;
		double m_mark;
		int m_outOf;
		void flushKeyboard()const;
	public:
		void set(int diaplayMode);
		void set(double mark, int outOf = 1);
		void setEmpty();
		bool isEmpty()const;
		int percent()const;
		double rawValue()const;
		bool read(const char* prompt);
		std::ostream& display() const;
		int out();
	};
}
#endif
