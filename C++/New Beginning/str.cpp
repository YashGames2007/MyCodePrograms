#include <iostream>
#include <ctime>
using namespace std;

string get_Clock(void)
{
    string current_Clock;

    time_t t = time(0); // get time now
    tm *now = localtime(&t);

    const string session[] = {"AM", "PM"};
    const string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    const string days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    // current_Clock.append(now->tm_hour);
    int hour;
    int current_Session;

    if (now->tm_hour > 12)
    {
        hour = now->tm_hour - 12;
        current_Session = 1;
    }
    else if (now->tm_hour == 0)
    {
        hour = 12;
        current_Session = 0;
    }
    else
    {
        hour = now->tm_hour;
        current_Session = 0;
    }

    current_Clock.append(to_string(hour));
    current_Clock.append(":");
    current_Clock.append(to_string(now->tm_min));
    current_Clock.append(":");
    current_Clock.append(to_string(now->tm_sec));
    current_Clock.append(" ");
    current_Clock.append(session[(current_Session)]);
    current_Clock.append(" ");
    current_Clock.append(days[(now->tm_wday - 1)]);
    current_Clock.append(", ");
    current_Clock.append(to_string(now->tm_mday));
    current_Clock.append(" ");
    current_Clock.append(months[(now->tm_mon)]);
    current_Clock.append(" ");
    current_Clock.append(to_string(now->tm_year + 1900));

    cout << "" << endl;
    cout << current_Clock << endl;

    return current_Clock;
}

int main()
{
    time_t t = time(0); // get time now
    tm *now = localtime(&t);
    cout << (now->tm_year + 1900) << '-'
         << (now->tm_mon + 1) << '-'
         << now->tm_mday << '-'
         << now->tm_hour << '-'
         << now->tm_min << '-'
         << now->tm_sec << '-'
         << "\n"
         << time(0) << endl
         << endl
         << now->tm_wday;

    get_Clock();

    return 0;
}