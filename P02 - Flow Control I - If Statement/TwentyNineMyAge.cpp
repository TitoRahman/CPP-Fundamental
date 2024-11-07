#include <iostream>
#include <string>

using namespace std;

int main()
{
    string days[] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
    string day;
    int n;
    cin >> n;
    cin >> day;
    int daynum = 0;

    if (day == "senin" ){
        daynum = 1;
    } else if (day == "selasa" ){
        daynum = 2;
    } else if (day == "rabu" ){
        daynum = 3;
    } else if (day == "kamis" ){
        daynum = 4;
    } else if (day == "jumat" ){
        daynum = 5;
    } else if (day == "sabtu" ){
        daynum = 6;
    } else if (day == "minggu" ){
        daynum = 7;
    }
    daynum = daynum - 1;
    int newdaynum = (daynum + n) %7;
    cout << n << " " << day << " " << days[newdaynum] << endl;
}