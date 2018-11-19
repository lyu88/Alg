#include <iostream>
#include <ctime>
#include <string>

int days_month(int month, bool is_leap_year)
{
    int ret = 0;
    switch (month)
    {
        case 1: ret = 31;
            break;
        case 2: ret = is_leap_year ? 29:28;
            break;
        case 3: ret = 31;
            break;
        case 4: ret = 30;
            break;
        case 5: ret = 31;
            break;
        case 6: ret = 30;
            break;
        case 7: ret = 31;
            break;
        case 8: ret = 31;
            break;
        case 9: ret = 30;
            break;
        case 10: ret = 31;
            break;
        case 11: ret = 30;
            break;
        case 12: ret = 31;
            break;
        default: ret = 0;
            break;
    }
}

bool is_leap_year(int year)
{
    if (year%4 == 0)
    {
        if (year%100 == 0)
        {
            if (year%400 == 0)
                return true;
            else return false;
        }
        else return true;
    }
    else return false;
}

int day_date(int day, int month, int year)
{
    bool islpyear = is_leap_year(year);
    int sum = 0;
    for (int i = 1; i < month; i++)
    {
        sum += days_month(i, islpyear);
    }
    sum += day;
    return sum;
}

int main() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    std::string date;
  	std::cout << "Please, enter your DOB(format yyyyMMdd. Eg. 19910805): ";
  	std::getline(std::cin,date);
  	int year = std::stoi(date.substr(0,4));
  	int month = std::stoi(date.substr(4,2));
  	int day = std::stoi(date.substr(6,2));
  	int now_year = 1900 + ltm->tm_year;
  	int now_month = ltm->tm_mon+1;
  	int now_day = ltm->tm_mday;
  	int sum = is_leap_year(year) ? 366 : 365;
  	sum = sum - day_date(day, month, year) + 1;
  	for (int i = year +1; i < now_year; i++)
  	{
  		sum += is_leap_year(i) ? 366: 365;
  	}
  	sum += day_date(now_day, now_month, now_year);
    std::cout << "You have lived " << sum << " days!" << std::endl;
    return 0;
}





