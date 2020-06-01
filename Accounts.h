#pragma once
#include <iterator>
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <functional>
#include <list>

// заполнение файла элементами подмножества
template<typename T>
void fill_file(const std::list<T>& list, std::string filename);		

// печать элементов подмножества в консоль
template<typename T>
void print(const std::list<T>& list);	


// шаблонный класс 
template<typename T>
class Accounts
{
private:	
	// выбранный тип контейнера для хранения данных - список
	std::list<T> _list;	
public:
	// добавление элемента
	void add_elem(); 

	// изменение элемента с помощью переданной функции 
	bool change_elem(std::function<void(T&)> change);

	// удаление элемента
	bool delete_elem(); 

	// очистка контейнера
	void clear(); 

	// проверка контейнера на пустоту
	bool empty(); 

	// ввод элементов из файла
	void fill_container(std::string filename); 

	// заполнение файла элементами контейнера
	void fill_file_from_container(std::string filename); 

	// печать элементов контейнера в консоль	
	void print_container(); 

	// линейный поиск элементов по заданным критериям 
	std::list<T> linear_search_elements(std::function<bool(const T&)> check);

	// двоичный поиск элементов по заданным критерим
	std::list<T> binary_search_elements(const T& value, std::function<bool(const T&, const T&)> compare);
};

template<typename T>
void Accounts<T>::add_elem()
{
	std::cout << std::endl << "Введите элемент, который необходимо добавить:" << std::endl;
	T tmp;
	add(tmp);
	_list.push_back(tmp);
	std::cout << std::endl << "Заданный элемент успешно добавлен." << std::endl;
}

template<typename T>
bool Accounts<T>::change_elem(std::function<void(T&)> change)
{
	std::cout << std::endl << "Введите элемент, который необходимо изменить:" << std::endl;
	T tmp;
	add(tmp);
	auto iter = find(_list.begin(), _list.end(), tmp);
	if (iter != _list.end())
	{
		std::cout << std::endl << "Заданный элемент найден." << std::endl;
		change(*iter);
		std::cout << std::endl << "Заданный элемент успешно изменён." << std::endl;
		return true;
	}
	else
	{
		std::cout << std::endl << "Заданный элемент отсутствует." << std::endl;
		return false;
	}
}

template<typename T>
bool Accounts<T>::delete_elem()
{
	std::cout << std::endl << "Введите элемент, который необходимо удалить:" << std::endl;
	T tmp;
	add(tmp);
	auto iter = find(_list.begin(), _list.end(), tmp);
	if (iter != _list.end())
	{
		_list.erase(iter);
		std::cout << std::endl << "Заданный элемент успешно удалён." << std::endl;
		return true;
	}
	else
	{
		std::cout << std::endl << "Заданный элемент отсутствует." << std::endl;
		return false;
	}
}

template<typename T>
void Accounts<T>::clear()
{
	_list.clear();
}

template<typename T>
bool Accounts<T>::empty()
{
	return _list.empty();
}

template<typename T>
void Accounts<T>::fill_container(std::string filename)
{
	std::ifstream fin(filename);
	if (!fin.is_open())
		std::cout << std::endl << "Не удаётся открыть указанный файл!" << std::endl;
	else
	{
		if (fin.peek() == EOF)
		{
			std::cout << std::endl << "Указанный файл - пустой!" << std::endl;
		}
		else
		{
			copy(std::istream_iterator<T>(fin), std::istream_iterator<T>(), std::back_inserter(_list));
			std::cout << std::endl << "Контейнер заполнен элементами из указанного файла." << std::endl;
		}
		fin.close();
	}
}

template<typename T>
void Accounts<T>::fill_file_from_container(std::string filename)
{	
	fill_file(_list, filename);
}

template<typename T>
void Accounts<T>::print_container()
{
	print(_list);
}

template<typename T>
std::list<T> Accounts<T>::linear_search_elements(std::function<bool(const T&)> check)
{
	std::list<T> result_list;
	for (T elem : _list)
	{
		if (check(elem))
		{
			result_list.push_back(elem);
		}
	}
	return result_list;
}

template<typename T>
std::list<T> Accounts<T>::binary_search_elements(const T& value, std::function<bool(const T&, const T&)> compare)
{
	_list.sort(compare);
	std::list<T> result;
	result.insert(result.begin(), std::lower_bound(_list.begin(), _list.end(), value, compare), std::upper_bound(_list.begin(), _list.end(), value, compare));
	return result;
}

template<typename T>
void fill_file(const std::list<T>& list, std::string filename)
{
	std::ofstream fout(filename);
	if (!fout.is_open())
	{
		std::cout << std::endl << "Файл с таким именем не удалось открыть!" << std::endl;
	}
	else
	{
		std::ostream_iterator<T> ositer(fout, "\n");
		copy(list.begin(), list.end(), ositer);
		std::cout << std::endl << "Файл успешно создан и заполнен." << std::endl;
		fout.close();
	}
}

template<typename T>
void print(const std::list<T>& list)
{
	if (list.empty())
	{
		std::cout << std::endl << "Данный контейнер пуст!" << std::endl;
	}
	else
	{
		std::ostream_iterator<T> ositer(std::cout, "\n");
		std::cout << std::endl << "Данный контейнер содержит следующие элементы:" << std::endl;
		copy(list.begin(), list.end(), ositer);
	}
}