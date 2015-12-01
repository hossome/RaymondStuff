//***********************************************************************
// Use the following data class:
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class RomanNumeral
{
private:
	int value;
	string romString;
	static const int ARRAY_SIZE = 13;
	static const RomanNumeral romanArray[ARRAY_SIZE];

public:
	RomanNumeral() { value = 0; }
	RomanNumeral(int val);
	RomanNumeral(string str);
	bool setValue(int val);
	bool setString(string str);
	int getValue() const { return value; }
	const string &getRomString() const { return romString; }

private:
	void convertIntToStr();
	void convertStrToInt();
};

const RomanNumeral RomanNumeral::romanArray[ARRAY_SIZE] = {
	RomanNumeral("M"),
	RomanNumeral("CM"),
	RomanNumeral("D"),
	RomanNumeral("CD"),
	RomanNumeral("C"),
	RomanNumeral("XC"),
	RomanNumeral("L"),
	RomanNumeral("XL"),
	RomanNumeral("X"),
	RomanNumeral("IX"),
	RomanNumeral("V"),
	RomanNumeral("IV"),
	RomanNumeral("I")
};

RomanNumeral::RomanNumeral(int val)
{
	setValue(val);
}

RomanNumeral::RomanNumeral(string str)
{
	setString(str);
}

bool RomanNumeral::setValue(int val)
{
	if (val > 0)
	{
		value = val;
		convertIntToStr();
		return true;
	}
	return false;
}

bool RomanNumeral::setString(string str)
{
	if (str.length() > 0)
	{
		romString = str;
		convertStrToInt();
		return true;
	}
	return false;
}



//private functions:
void RomanNumeral::convertIntToStr()
{
	string tempStr;
	int i = 0;

	int val = value;
	for (i = 0; i < ARRAY_SIZE; ++i) {
		while ((val - romanArray[i].value) >= 0) {
			tempStr.append(romanArray[i].romString);
			val -= romanArray[i].value;
		}	// end while
	}// end for
	romString = tempStr;
}

void RomanNumeral::convertStrToInt()
{
	static int romanValues[] = { 1000, 500, 100, 50, 10, 5, 1 };
	static string validRomDigits("MDCLXVI");
	int strSize = romString.length();

	if (strSize == 0)
		return;
	int* digitValues = new int[strSize];
	int i;

	// get int values of each roman numeral digit
	for (i = 0; i < strSize; ++i) {
		int index = validRomDigits.find(romString.at(i));
		if (index != string::npos) {
			digitValues[i] = romanValues[index];
		}
		else {
			romString.clear();
			value = 0;
			delete digitValues;
			return;
		}
	} // end for

	  // convert to int value
	value = 0;
	for (i = 0; i < strSize - 1; ++i) {
		if (digitValues[i] >= digitValues[i + 1]) {
			value += digitValues[i];
		}
		else
			value -= digitValues[i];
	}// end for
	if (strSize > 0)
		value += digitValues[i];
	delete digitValues;
}
