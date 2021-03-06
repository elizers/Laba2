#include "Utils.h"
#include "MainMenu.h"
#include "Accounts.h"
#include "AccountStructure.h"
#include <Windows.h>
#include <cstdio>
#include <list>
#include <iostream>
#include <sstream>

// ������ ������� ����� ������ �� �������
void get_eoln()
{
	do
	{

	} while (getchar() != '\n');
}

bool check(std::string str)
{
	return (str == "");
}

// ���� ����� � ����������� ��������� ��� �� �������������� ������� [min, max]
template<typename T>
T get_num(std::string str, std::string err, T min, T max)
{
	T num;
	std::string tmp;
	bool check = false;
	do {
		std::cout << str;
		std::cin >> num;
		if (std::cin.fail())
			std::cin.clear();
		else
			check = (num >= min) && (num <= max);
		getline(std::cin, tmp);
		if (!check)
			std::cout << err << std::endl;
	} while (!check);
	return num;
}

template int ::get_num<int>(std::string str, std::string err, int min, int max);
template float ::get_num<float>(std::string str, std::string err, float min, float max);

// ���� ������ �� �������
std::string get_string(const std::function<bool(const std::string&)>& check, std::string text, std::string error_text)
{
	std::cout << text;
	std::string result_string;
	getline(std::cin, result_string);
	bool ok = check(result_string);
	while (ok)
	{
		std::cout << error_text;
		getline(std::cin, result_string);
		ok = check(result_string);
	}
	return result_string;
}

// ��������� ��������� �� ������
std::string take_field(std::string str)
{
	std::string tmp_substr = "";
	int pos = str.find(':');
	if (pos != -1)
		tmp_substr = str.substr(pos + 2);
	return tmp_substr;
}

// �������������� ������
template<typename T>
T str_to_val(std::string str)
{
	std::stringstream sstr;
	T val;
	if (str.empty())
		return 0;
	sstr << str;
	sstr >> val;
	return val;
}

template int str_to_val<int>(std::string str);
template float str_to_val<float>(std::string str);