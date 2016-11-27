#include <iostream>
using namespace std;

class String
{
private:
	int size;
	char* str;

public:
	String(const char* string);
	void stringChange(const char* string);
	char* LenStr();
	int strSize();
	void AddStr(const char* addStr);
	void tString();
	void InsertSymb(int index, char symbol);
	void AsciiStr();
	void UpperR();
	void LowerR();
	~String();
};

String::String(const char* string)
{
	size = strlen(string) + 1;
	str = new char[size];
	strcpy_s(str, size, string);
}

void String::stringChange(const char* string)
{
	size = strlen(string) + 1;
	str = new char[size];
	strcpy_s(str, size, string);
}

inline char* String::LenStr()
{
	return str;
}

inline int String::strSize()
{
	return strlen(str);
}

void String::tString()
{
	char* tString = new char[size];
	strcpy_s(tString, size, str);
	delete[] str;
	str = new char[size];
	strcpy_s(str, size, tString);
	delete[] tString;
}

void String::AddStr(const char* addStr)
{
	size += strlen(addStr);
	tString();
	strcat_s(str, size, addStr);
}

void String::InsertSymb(int index, char symbol)
{
	if (index < 0 || index >= size) {
		cout << "This position is empty" << endl;
		return;
	}
	char* buffString = str;
	++size;
	str = new char[size];
	str[index] = symbol;
	for (int i = 0; i < size; ++i)
	{
		if (i == index)
			continue;
		if (i > index)
			str[i] = buffString[i - 1];
		else
			str[i] = buffString[i];
	}
	delete[] buffString;
}

void String::AsciiStr()//7
{
	for (int i = 0; i < size - 1; ++i) {
		cout << str[i] << " = " << (int)str[i] << " ";
	}
	cout << endl;
}

void String::UpperR()
{
	for (int i = 0; i < size; ++i) {
		if (str[i] >= 97 && str[i] <= 122) {
			str[i] = str[i] - 32;
		}
	}
}

void String::LowerR()
{
	for (int i = 0; i < size; ++i) {
		if (str[i] >= 65 && str[i] <= 90) {
			str[i] = str[i] + 32;
		}
	}
}

String::~String()
{
	delete[] str;
}

int main()
{
	String str("Example");
	cout << "Inizialitaion of String: " << str.LenStr() << endl;
	cout << "Lenght of string: " << str.strSize() << endl;
	str.AddStr("Hello");
	cout << "Add string to string: " << str.LenStr() << endl;
	cout << "Insert Symbol in position of string: ";
	str.InsertSymb(3, 'C');
	cout << str.LenStr() << endl;
	cout << "Ascii code of string: ";
	str.AsciiStr();
	str.UpperR();
	cout << "Symbols of string in Upper Register: " << str.LenStr() << endl;
	str.LowerR();
	cout << "Symbols of string in Lower Register: " << str.LenStr() << endl;
	return 0;
};



