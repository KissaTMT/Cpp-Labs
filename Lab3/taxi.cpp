#include "taxi.h"

taxi::taxi(int number, string carbrand_name, string taxidriver_name)
{
	this->number = number;
	this->carbrand_name = carbrand_name;
	this->taxidriver_name = taxidriver_name;
	this->is_busy = false;
}
int taxi::get_number() {
	return number;
}
string taxi::get_carbrand() {
	return carbrand_name;
}
string taxi::get_taxidriver() {
	return taxidriver_name;
}
bool taxi::get_state() {
	return is_busy;
}
void taxi::set_state(bool condition) {
	is_busy = condition;
}
bool taxi::operator==(taxi& taxi)
{
	return number == taxi.get_number();
}
bool taxi::operator==(int number)
{
	return this->number == number;
}
taxi :: operator string() {
	string condition = is_busy == true ? "такси на вызове" : "такси свободное";
	return to_string(number) + " " + carbrand_name + " " + taxidriver_name + " " + condition;
}
