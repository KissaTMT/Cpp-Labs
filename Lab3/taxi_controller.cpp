#include "taxi_controller.h"

taxi_controller::taxi_controller()
{
	number = 100;
}
taxi_controller::taxi_controller(queue<taxi> items)
{
	number = 100;
	while(!items.empty()) {
		taxis.emplace(taxis.begin(), items.front());
		items.pop();
		number++;
	}
}
vector<taxi> taxi_controller::get_taxis() {
	vector<taxi> result;
	auto iterator = taxis.begin();
	for (auto i = taxis.begin(); i != taxis.end(); i++) {
		result.push_back(*i);
	}
	return result;
}
void taxi_controller::push_front(string brand_name, string taxidriver_name)
{
	taxis.emplace(taxis.begin(),taxi(number, brand_name, taxidriver_name));
	number++;
}
void taxi_controller::insert(string brand_name, string taxidriver_name, int beforeitem)
{
	taxi item(number, brand_name, taxidriver_name);
	vector<taxi> ::iterator iterator;
	for (auto i = taxis.begin(); i != taxis.end(); i++) {
		if (*i == beforeitem) {
			taxis.insert(i, item);
			break;
		}
	}
}
void taxi_controller::remove(int number)
{
	taxi *item = get_taxi(number);
	if (item == nullptr) return;
	vector<taxi> :: iterator iterator;
	for (auto i = taxis.begin(); i != taxis.end(); i++) {
		if (*i == *item) {
			iterator = i;
			break;
		}
	}
	taxis.erase(iterator);
}
void taxi_controller::exit(int number)
{
	taxi *taxi = get_taxi(number);
	if(taxi != nullptr) taxi -> set_state(true);
}
void taxi_controller::release(int number)
{
	taxi* taxi = get_taxi(number);
	if (taxi != nullptr) taxi->set_state(false);
}
vector<taxi> taxi_controller::get_free_taxis()
{
	vector<taxi> result;
	for (int i = 0; i < taxis.size(); i++) {
		taxi taxi = taxis[i];
		if (taxi.get_state() == false) result.push_back(taxi);
	}
	return result;
}
vector<taxi> taxi_controller::get_busy_taxis()
{
	vector<taxi> result;
	for (int i = 0; i < taxis.size(); i++) {
		taxi taxi = taxis[i];
		if (taxi.get_state() == true) result.push_back(taxi);
	}
	return result;
}
taxi* taxi_controller::get_taxi(int number)
{
	for (int i = 0; i < taxis.size(); i++) {
		if (taxis[i].get_number() == number) {
			return &taxis[i];
		}
	}
	return nullptr;
}