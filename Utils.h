#pragma once
#include <string>
#include <functional>

// чтение символа конца строки из консоли
void get_eoln();

// проверка на пустую строку
bool check(std::string str);

// ввод числа с последующей проверкой его на принадлежность отрезку [min, max]
template<typename T>
T get_num(std::string str, std::string err, T min, T max);

// ввод строки из консоли
std::string get_string(const std::function<bool(const std::string&)>& check, std::string text, std::string error_text);

// получение подстроки из строки
std::string take_field(std::string str);

// преобразование строки 
template<typename T>
T str_to_val(std::string str);