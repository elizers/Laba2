#include "AccountStructure.h"

AccountStructure::AccountStructure() : _name_of_firm(""), _type_of_work(""), _unit(""), _cost_per_unit(0), _date_of_execution(Date()), _scope_of_work(0.0f){}


AccountStructure::AccountStructure(std::string name_of_firm, std::string type_of_work, std::string unit, int cost_per_unit, Date date, float scope_o_work) :
	_name_of_firm(name_of_firm), _type_of_work(type_of_work), _unit(unit), _cost_per_unit(cost_per_unit), _date_of_execution(date), _scope_of_work(scope_o_work)
{
	this->_date_of_execution = Date(date);
}


std::string AccountStructure::get_name_of_firm() const 
{ 
	return _name_of_firm; 

}

std::string AccountStructure::get_type_of_work() const 
{ 
	return _type_of_work; 
}

std::string AccountStructure::get_unit() const 
{ 
	return _unit;
}

int AccountStructure::get_cost_per_unit() const 
{ 
	return _cost_per_unit; 
}

Date AccountStructure::get_date_of_execution() const 
{ 
	return _date_of_execution; 
}

float AccountStructure::get_scope_of_work() const 
{ 
	return _scope_of_work;
}


void AccountStructure::set_name_of_firm(const std::string& name)
{
	this->_name_of_firm = name;
}

void AccountStructure::set_type_of_work(const std::string& type)
{
	this->_type_of_work = type;
}

void AccountStructure::set_unit(const std::string& unit)
{
	this->_unit = unit;
}

void AccountStructure::set_cost_per_unit(const int cost)
{
	this->_cost_per_unit = cost;
}

void AccountStructure::set_date_of_execution(const Date& date)
{
	this->_date_of_execution = Date(date);
}

void AccountStructure::set_scope_of_work(const float scope)
{
	this->_scope_of_work = scope;
}


bool compare(const AccountStructure& r1, const AccountStructure& r2)
{
	if (r1._name_of_firm < r2._name_of_firm)
		return true;
	if (r1._name_of_firm > r2._name_of_firm)
		return false;
	if (r1._type_of_work < r2._type_of_work)
		return true;
	if (r1._type_of_work > r2._type_of_work)
		return false;
	return (r1._date_of_execution < r2._date_of_execution);
}

std::ostream& operator<<(std::ostream& out, const AccountStructure& record)
{
	out << "Название фирмы: " << record._name_of_firm << std::endl
		<< "Вид работы: " << record._type_of_work << std::endl
		<< "Единица измерения: " << record._unit << std::endl
		<< "Стоимость единицы выполненной работы (в рублях): " << record._cost_per_unit << std::endl
		<< "Дата исполнения: " << record._date_of_execution
		<< "Объём работы: " << record._scope_of_work << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, AccountStructure& record)
{
	std::string str;
	getline(in, str);
	record._name_of_firm = take_field(str);

	getline(in, str);
	record._type_of_work = take_field(str);

	getline(in, str);
	record._unit = take_field(str);

	getline(in, str);
	record._cost_per_unit = str_to_val<int>(take_field(str));

	in >> record._date_of_execution;

	getline(in, str);
	record._scope_of_work = str_to_val<float>(take_field(str));

	getline(in, str);
	
	return in;
}

AccountStructure add(AccountStructure& record)
{
	record.set_name_of_firm(get_string(check, "Название фирмы: ", "Встречена пустая строка! Введите название фирмы: "));
	record.set_type_of_work(get_string(check, "Вид работы: ", "Встречена пустая строка! Введите вид работы: "));
	record.set_unit(get_string(check, "Единица измерения: ", "Встречена пустая строка! Введите единицу измерения: "));
	record.set_cost_per_unit(get_num("Стоимость единицы измерения (в рублях): ", "Ошибка! Повторите ввод: ", 0, 10000));
	std::cout << "Дата исполнения (ДД.ММ.ГГГГ) : ";
	input_date(record._date_of_execution);
	record.set_scope_of_work(get_num("Объём работ : ", "Ошибка! Повторите ввод: ", 0.f, 10000.0f));
	return record;
}

bool operator== (const AccountStructure& rec1, const AccountStructure& rec2)
{
	return ((rec1._name_of_firm == rec2._name_of_firm) &&
		(rec1._type_of_work == rec2._type_of_work) &&
		(rec1._unit == rec2._unit) &&
		(rec1._cost_per_unit == rec2._cost_per_unit) &&
		(rec1._date_of_execution == rec2._date_of_execution) &&
		(rec1._scope_of_work == rec2._scope_of_work));
}

bool operator!= (const AccountStructure& rec1, const AccountStructure& rec2)
{
	return !(rec1 == rec2);
}