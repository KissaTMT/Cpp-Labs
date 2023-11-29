#include <iostream>

using namespace std;
struct Date {
    int day;
    int month;
    int year;
};
Date try_input_date() {
    int day;
    int month;
    int year;
    while (true) {
        cin >> day;
        if (cin.get() != '/')
        {
            cout << "expected /\n";
        }
        cin >> month;
        if (cin.get() != '/')
        {
            cout << "expected /\n";
        }
        cin >> year;
        if (day >= 1 && day <= 31) {
            if (month >= 1 && month <= 12) {
                if (year >= 2023 && year <= 2025) {
                    Date date;
                    date.day = day;
                    date.month = month;
                    date.year = year;
                    return date;
                }
            }
        }
        else cout << "Incorrect format date. Try again";
    }
}
int main()
{
    Date date = try_input_date();
    cout << date.day<<endl;
    cout << date.month<<endl;
    cout << date.year<<endl;
}
