// *******************************************************************************
// *******************************************************************************
// * ASSIGNMENT #2 *
// * Name: Lucas Campbell   *
// * Class: COP3330 *
// * Description: This project is designed to meet the assignment's requirements,*
// * where the user is asked for a date in which the output is modeled after *
// * different types of formats. Functions used include const, int, bool, void, *
// * char, if/else, return, switch, case, break, and include equations designed *
// * to calculate leap years and convert date formats. This function also *
// * ensures that certain paremeters are met in the input. *
// * Date: February 2nd, 2024 *
// *******************************************************************************
// *******************************************************************************


#include "date.h"
#include <iostream>
#include <iomanip>

using namespace std;

const int Date::DEFAULT_DAY;                                                                                        // Declaration of constants
const int Date::DEFAULT_MONTH;
const int Date::DEFAULT_YEAR;

Date::Date() {                                                                                                      // Constructor
    Set(DEFAULT_MONTH, DEFAULT_DAY, DEFAULT_YEAR);
    format = 'D'; 
}

Date::Date(int m, int d, int y) {                                                                                   // declarations
    Set(m, d, y);
    format = 'D';
}

bool Date::isLeapYear(int year) const {                                                                             // Created a leap year function for correct display
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));                                                 // equation for leap year
}

void Date::Input() {                                                                                                // Input function where the user is asked for the date
    int m, d, y;
    char slash;
    
    cout << "Enter a date (M/D/YYYY): ";                                                                            // Output asking user for the date
    cin >> m >> slash >> d >> slash >> y;                                                                           // Input of the date

    if (Set(m, d, y)) {                                                                                             // Correct date given
        cout << "Date set successfully." << endl;
    } else {
        cout << "Invalid date. Set to default date." << endl;                                                       // Date out of parameters
    }   
}

void Date::Show() const {                                                                                           // Show function where the date format is determined and displayed
    switch (format) {
        case 'D':
            cout << GetMonth() << "/" << GetDay() << "/" << GetYear();                                              // Default date format: M/D/Y
            break;
        case 'T':                                                                                                   // Two digit format: mm/dd/yy
            cout << setfill('0') << setw(2) << GetMonth() << "/"
                 << setw(2) << GetDay() << "/" << setw(2) << GetYear() % 100;
            break;
        case 'L':                                                                                                   // Long format: "Month abbreviation" D, Y 
            cout << MONTHS[GetMonth() - 1] << " " << GetDay() << ", " << GetYear();
            break;
        case 'J':                                                                                                   // Julian format: DDD/Y
            cout << Julian() << "-" << GetYear();
            break;
        default:
            cout << "Invalid format code.";                                                                         // If incorrect format code is set
    }
    cout << endl;
}

bool Date::Set(int m, int d, int y) {                                                                               // Set function where it is determined if the given date is within the parameters
    if (m >= 1 && m <= 12 && d >= 1 && d <= Days_in_Month[m] + (m == 2 && isLeapYear(y)) && y > 1582) {             // Ensures that the month is between 1 and 12, the day is between 1 and the amount of days in a certain month, and a year after 1582
        month = m;
        day = d;
        year = y;
        return true;
    } else {                                                                                                        // Set to default date if invalid
        month = DEFAULT_MONTH;
        day = DEFAULT_DAY;
        year = DEFAULT_YEAR;
        return false;
    }
}

int Date::GetMonth() const {                                                                                        // Accessor function working with date.h
    return month;
}

int Date::GetDay() const {                                                                                          // Accessor functions working with date.h
    return day;
}

int Date::GetYear() const {                                                                                         // Accessor functions working with date.h
    return year;
}

bool Date::SetFormat(char f) {                                                                                      // SetFormat function where format is determined
    switch (f) {
        case 'D':
        case 'T':
        case 'L':
        case 'J':
            format = f;
            return true;                                                                                            // D,T,L, or J are stated
        default:
            cout << "Invalid format code.";                                                                         // Incorrect format is stated
            return false;
    }
}


void Date::Increment(int numDays) {                                                                                 // Increment function
    for (int i = 0; i < numDays; ++i) {
        ++day;
        
        if (day > Days_in_Month[month] + (month ==2 && isLeapYear(year)))   {
            day =1;
            ++month;
            
            if (month > 12) {
                month = 1;
                ++year;
            }
        }
        
    }
}

int Date::Compare(const Date& d) const {
    if (year < d.GetYear() || (year == d.GetYear() && (month < d.GetMonth() || (month == d.GetMonth() && day < d.GetDay())))) {                                     // Compare function
        return -1;                                                                                                  // Current object comes first chronologically
    } 
    else if (year == d.GetYear() && month == d.GetMonth() && day == d.GetDay()) {
        return 0;                                                                                                   // Objects represent the same date
    } 
    else {
        return 1;                                                                                                   // Parameter object comes first chronologically
    }
}

int Date::Julian() const {                                                                                          // Julian function
    
    int Julian = day;
    for (int i = 1; i < month; ++i) {
      Julian += Days_in_Month[i];
    }
    return Julian;
}