#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Date {
    private:
        int month;
        int day;
        int year;
        char format;
        
        bool isLeapYear(int year) const;
        
        
        const char* MONTHS[13] = {"Jan", "Feb" ,"Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        
        static const int DEFAULT_DAY=1;
        static const int DEFAULT_MONTH=1;
        static const int DEFAULT_YEAR=2000;
        
    public:
        Date();
        Date(int m, int d, int y);
        int Days_in_Month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        
        void Input();
        void Show() const;
        
        bool Set(int m, int d=DEFAULT_DAY, int y=DEFAULT_YEAR);
        int GetMonth() const;
        int GetDay() const;
        int GetYear() const;
        int Julian() const;
        
        bool SetFormat(char f);
        void Increment(int numDays = 1);
        int Compare(const Date& d) const;
};

int main() {
    Date d1;  // initializes to Jan 1, 2000
    Date d2(3, 4, 1992);  // initializes to March 4, 1992
    Date d3(13, 30, 1990);  // invalid month, initializes to Jan 1, 2000 instead.

    d1.Show();  // Output: 1/1/2000
    cout << endl;

    d2.Show();  // Output: 3/4/1992
    cout << endl;

    d3.Show();  // Output: 1/1/2000 (due to invalid input)
    cout << endl;

    d1.Input();  // User input, updating the date
    d1.SetFormat('J');
    d1.Show();   // Show the updated date
    

    return 0;
}