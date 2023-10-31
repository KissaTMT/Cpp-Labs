#pragma once
#include <vector>
#include <queue>
#include "taxi.h"
using namespace std;
class taxi_controller
{
public:
	taxi_controller();
	taxi_controller(queue<taxi> items);
	vector<taxi> get_taxis();
	void push_front(string brand_name, string taxidriver_name);
	void insert(string brand_name, string taxidriver_name, int beforeitem);
	void pop(int number);
	void exit(int number);
	void release(int number);
	vector<taxi> get_free_taxis();
	vector<taxi> get_busy_taxis();
private:
	vector<taxi> taxis;
	int number;
	taxi* get_taxi(int number);
};

