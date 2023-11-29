#include <iostream>
#include <string>
#include "taxi_controller.h"
using namespace std;
void try_input(int* n) {
    float k;
    cin >> k;

    while (true) {
        *n = k;
        if (*n == k && k > -1) {
            break;
        }
        else {
            cout << "input number of taxi: ";
            cin >> k;
            cout << endl;
        }
    }
}
int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    queue<taxi> queue;
    queue.push(taxi(100,"BMV","Kisa"));
    queue.push(taxi(101,"Shevrolet","Olga"));
    queue.push(taxi(102,"Nisan","Vladislave"));
    queue.push(taxi(103,"Ferrary","Pavel"));
    queue.push(taxi(104,"TelegaEpta","Markdown"));
    queue.push(taxi(105,"Peshkom","Hazar"));
    taxi_controller controller(queue);
    while (true) {
        cout << "getall | push | insert | remove | exit | release | getfree | getbusy | close" << endl;;
        string key;
        cin >> key;
        if (key == "getall") {
            vector<taxi> all_taxi = controller.get_taxis();
            if (!all_taxi.empty()) {
                for (int i = 0; i < all_taxi.size(); i++) {
                    cout << string(all_taxi[i]) << endl;
                }
                cout << endl;
            }
        }
        if (key == "push") {
            string carbrand_name;
            cin >> carbrand_name;
            string taxidriver_name;
            cin >> taxidriver_name;
            controller.push_front(carbrand_name, taxidriver_name);
        }
        if (key == "insert") {
            string carbrand_name;
            cin >> carbrand_name;
            string taxidriver_name;
            cin >> taxidriver_name;
            int afterNumber;
            try_input(&afterNumber);
            controller.insert(carbrand_name, taxidriver_name, afterNumber);
        }
        if (key == "remove") {
            int number;
            try_input(&number);
            controller.remove(number);
        }
        if (key == "exit") {
            int number;
            try_input(&number);
            controller.exit(number);
        }
        if (key == "release") {
            int number;
            try_input(&number);
            controller.release(number);
        }
        if (key == "getfree") {
            vector<taxi> all_taxi = controller.get_free_taxis();
            if (!all_taxi.empty()) {
                for (int i = 0; i < all_taxi.size(); i++) {
                    cout << string(all_taxi[i]) << endl;
                }
                cout << endl;
            }
        }
        if (key == "getbusy") {
            vector<taxi> all_taxi = controller.get_busy_taxis();
            if (!all_taxi.empty()) {
                for (int i = 0; i < all_taxi.size(); i++) {
                    cout << string(all_taxi[i]) << endl;
                }
                cout << endl;
            }
        }
        if (key == "close") break;
    }
}