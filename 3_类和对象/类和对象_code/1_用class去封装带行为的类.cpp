#include <iostream>

using namespace std;

class Date
{
public:
	void init(Date &d);
	void show(Date& d);
	bool isLeapYear(Date& d);

private:
	int year;
	int month;
	int day;
};

void Date::init(Date& d)
{
	cout << "year, month, day :" << endl;
	cin >> d.year >> d.month >> d.day;
}
void Date::show(Date& d)
{
	cout << "year:" << d.year << " month:" << d.month << " day:" << d.day << endl;
}
bool Date::isLeapYear(Date& d)
{
	if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0)
		return true;
	else
		return false;
}
int main()
{
	Date d;
	d.init(d);
	d.show(d);
	if (d.isLeapYear(d))
		cout << "leap year" << endl;
	else 
		cout << "not leap year" << endl;
	return 0;
}