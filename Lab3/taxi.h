#pragma once
#include "string"
using namespace std;
class taxi
{
public:
	taxi(int number, string carbrand_name, string taxidriver_name);
	int get_number();
	string get_carbrand();
	string get_taxidriver();
	bool get_state();
	void set_state(bool condition);
	bool operator==(taxi& taxi);
	bool operator==(int number);
	operator string();
private:
	int number;
	string carbrand_name;
	string taxidriver_name;
	bool is_busy;
};