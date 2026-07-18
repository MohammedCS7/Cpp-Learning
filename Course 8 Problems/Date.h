#pragma once

#include <iostream>
#include <cmath>


using namespace std;

namespace DateAndTime
{
    struct Date
    {
        int day;
        int month;
        int year;
    };

    int ReadPositiveNumber(string message)
    {
        int num;
        do
        {
            cout << message;
            cin >> num;
            while (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << message;
                cin >> num;
            }
        } while (num < 0);
        return num;
    }

    int ReadNumberInRange(string message, int from, int to)
    {
        int num;
        do
        {
            cout << message;
            cin >> num;
        } while (num < from || num > to);
        return num;
    }

    bool IsLeapYear(int year)
    {
        return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
    }

    int GetMonthDays(int year, int month)
    {
        int monthsDays[13] = { 0,31,0,31,30,31,30,31,31,30,31,30,31 };
        return month == 2 ? IsLeapYear(year) ? 29 : 28 : monthsDays[month];
    }

    int GetYearDays(int year)
    {
        return IsLeapYear(year) ? 366 : 365;
    }

    int ReadYear()
    {
        return ReadPositiveNumber("Please enter a year : ");
    }

    int ReadMonth()
    {
        return ReadNumberInRange("Please enter a month : ", 1, 12);
    }

    int ReadDay(int year, int month)
    {
        return ReadNumberInRange("Please enter a day : ", 1, GetMonthDays(year, month));
    }

    int GetTotalDays(Date date)
    {
        int total = 0;
        for (int i = 1; i < date.month; i++)
        {
            total += GetMonthDays(date.year, i);
        }
        return total += date.day;
    }

    Date ReadDate()
    {
        Date date;
        date.year = ReadYear();
        date.month = ReadMonth();
        date.day = ReadDay(date.year, date.month);
        cout << "\n\n";
        return date;
    }

    bool IsDateLower(Date date1, Date date2)
    {
        return (date1.year != date2.year) ? date1.year < date2.year : GetTotalDays(date1) < GetTotalDays(date2);
    }

    bool IsDateEqual(Date date1, Date date2)
    {
        return (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day);
    }


    bool IsLastDay(Date date)
    {
        return (date.day == GetMonthDays(date.year, date.month));
    }

    bool IsLastMonth(Date date)
    {
        return date.month == 12;
    }

    int GetDayOrder(int year, int month, int day)
    {
        int a = (14 - month) / 12;
        int y = year - a;
        int m = month + 12 * a - 2;

        int d = (day + y + y / 4 - y / 100 + y / 400 + (31 * m / 12)) % 7;

        return d;
    }

    Date IncrementDateByOne(Date date)
    {
        if (IsLastDay(date) && IsLastMonth(date))
        {
            date.day = 1;
            date.month = 1;
            date.year++;
        }
        else if (IsLastDay(date))
        {
            date.month++;
            date.day = 1;
        }
        else
            date.day++;

        return date;
    }

    void IncrementDateByOneDay(Date& date)
    {
        if (IsLastDay(date) && IsLastMonth(date))
        {
            date.day = 1;
            date.month = 1;
            date.year++;
        }
        else if (IsLastDay(date))
        {
            date.month++;
            date.day = 1;
        }
        else
            date.day++;
    }

    int GetDiffBetweenDates(Date date1, Date date2, bool isEndDayIncluded = false)
    {
        int date1Days = GetTotalDays(date1);
        int date2Days = GetTotalDays(date2);
        short diffValue = IsDateLower(date1, date2) ? 1 : -1;
        if (date1.year == date2.year)
        {
            return isEndDayIncluded ? (date2Days - date1Days + diffValue) : (date2Days - date1Days);
        }
        if (diffValue == 1)
        {
            for (int i = date1.year; i < date2.year; i++)
            {
                date2Days += GetYearDays(i);
            }
        }
        else
        {
            for (int i = date2.year; i < date1.year; i++)
            {
                date1Days += GetYearDays(i);
            }
        }
        return isEndDayIncluded ? (date2Days - date1Days + diffValue) : (date2Days - date1Days);
    }

    int GetDiffBetweenDatesTeacherWay(Date date1, Date date2,bool isIncluded = false)
    {
        int diff = 0;
        if (IsDateLower(date2, date1))
        {
            while (IsDateLower(date2, date1))
            {
                diff--;
                IncrementDateByOne(date2);
            }
            return isIncluded ? --diff : diff;
        }
        else if (IsDateLower(date1, date2))
        {
            while (IsDateLower(date1, date2))
            {
                diff++;
                IncrementDateByOne(date1);
            }
            return isIncluded ? ++diff : diff;
        }
        else
            return isIncluded ? 1 : 0;
        
    }

    void SwapDates(Date& date1, Date& date2)
    {
        Date temp;

        temp.year = date1.year;
        temp.month = date1.month;
        temp.day = date1.day;

        date1.year = date2.year;
        date1.month = date2.month;
        date1.day = date2.day;

        date2.year = temp.year;
        date2.month = temp.month;
        date2.day = temp.day;
    }

    int GetDiffBetweenDatesTeacherStyle(Date date1, Date date2, bool isIncluded = false)
    {
        int swapValue = 1;
        int diff = 0;
        if (IsDateEqual(date1, date2))
            return isIncluded ? 1 : 0;
        if (!IsDateLower(date1, date2))
        {
            SwapDates(date1, date2);
            swapValue = -1;
        }
        while (IsDateLower(date1, date2))
        {
            IncrementDateByOne(date1);
            diff++;
        }
        return isIncluded ? ++diff * swapValue : diff * swapValue;
    }

    //Problem 20 Level4 :

    Date IncreaseDateByXDays(Date date, int days)
    {
        for (int i = 0; i < days; i++)
        {
            IncrementDateByOne(date);
        }
        return date;
    }

    //Problem 21 Level4 :

    Date IncreaseDateByWeek(Date& date)
    {
        return IncreaseDateByXDays(date, 7);
    }

    //Problem 22 Level4 :

    Date IncreaseDateByXWeeks(Date& date, int weeks)
    {
        for (int i = 0; i < weeks; i++)
        {
            date = IncreaseDateByWeek(date);
        }
        return date;
    }

    //Problem 23 Level4 :

    Date IncreaseDateByMonth(Date date)
    {
        if (IsLastMonth(date))
        {
            date.month = 1;
            date.year++;
        }
        else if (date.day == 31 || (date.month == 1 && (date.day == 29 || date.day == 30)))
        {
            date.month++;
            date.day = GetMonthDays(date.year, date.month);
        }
        else
            date.month++;

        return date;
    }

    Date IncreaseDateByMonthUsingClamping(Date date)
    {
        if (IsLastMonth(date))
        {
            date.month = 1;
            date.year++;
        }
        else
            date.month++;

        int maxDays = GetMonthDays(date.year, date.month);
        if (date.day > maxDays)
        {
            date.day = maxDays;
        }
        return date;
    }

    //Problem 24 Level4 :

    Date IncreaseDateByXMonths(Date date, int months)
    {
        for (int i = 0; i < months; i++)
        {
            date = IncreaseDateByMonth(date);
        }
        return date;
    }

    //Problem 25 Level4 : 

    Date IncreaseDateByYear(Date date)
    {
        date.year++;

        int maxDays = GetMonthDays(date.year, date.month);
        if (date.day > maxDays)
        {
            date.day = maxDays;
        }

        return date;
    }

    //Problem 26 Level4 :

    Date IncreaseDateByXYears(Date date, int years)
    {
        for (int i = 0; i < years; i++)
        {
            date = IncreaseDateByYear(date);
        }
        return date;
    }

    //Problem 27 Level4 :

    Date IncreaseDateByXYearsFaster(Date date, int years)
    {
        date.year += years;
        int maxDays = GetMonthDays(date.year, date.month);
        if (date.day > maxDays)
        {
            date.day = maxDays;
        }
        return date;
    }

    //Problem 28 Level4 :

    Date IncreaseDateByDecade(Date date)
    {
       return IncreaseDateByXYears(date, 10);
    }


    //Problem 29 Level4 :

    Date IncreaseDateByXDecades(Date date, int decades)
    {
        for (int i = 0; i < decades; i++)
        {
           date = IncreaseDateByDecade(date);
        }
        return date;
    }

    //Problem 30 Level4 :

    Date IncreaseDateByXDecadesFaster(Date& date, int decades)
    {
        int years = decades * 10;
        date.year += years;
        int maxDays = GetMonthDays(date.year, date.month);
        if (date.day > maxDays)
        {
            date.day = maxDays;
        }
        return date;
    }

    //Problem 31 Level4 :

    Date IncreaseDateByCentury(Date date)
    {
       return IncreaseDateByXDecades(date, 10);
    }

    //Problem 32 Level4 :

    Date IncreaseDateByMillenium(Date& date)
    {
        date.year += 1000;
        int maxDays = GetMonthDays(date.year, date.month);
        if (date.day > maxDays)
        {
            date.day = maxDays;
        }
        return date;
    }

    //Problem 33 Level4 :

    Date DecrementDateByOne(Date date)
    {
        if (date.day == 1 && date.month == 1)
        {
            date.month = 12;
            date.year--;
            date.day = GetMonthDays(date.year, date.month);
        }
        else if (date.day == 1)
        {
            date.month--;
        }
        else
        {
            date.day--;
        }
        int maxDays = GetMonthDays(date.year, date.month);
        if (date.day > maxDays)
        {
            date.day = maxDays;
        }
        return date;
    }

    //Problem 34 Level4 :

    Date DecreaseDateByXDays(Date date, int days)
    {
        for (int i = 0; i < days; i++)
        {
            DecrementDateByOne(date);
        }
        return date;
    }

    //Problem 35 Level4 : 

    Date DecreaseDateByWeek(Date& date)
    {
        return DecreaseDateByXDays(date, 7);
    }

    //Problem 36 Level4 :

    Date DecreaseDateByXWeeks(Date& date, int weeks)
    {
        for (int i = 0; i < weeks; i++)
        {
            date = DecreaseDateByWeek(date);
        }
        return date;
    }

    //Problem 37 Level4 : 

    Date DecreaseDateByMonth(Date date)
    {
        if (date.month == 1)
        {
            date.month = 12;
            date.year--;
        }
        else
            date.month--;

        int maxDays = GetMonthDays(date.year, date.month);
        if (date.day > maxDays)
        {
            date.day = maxDays;
        }
        return date;
    }

    //Problem 38 Level4 :

    Date DecreaseDateByXMonths(Date date, int months)
    {
        for (int i = 0; i < months; i++)
        {
            date = DecreaseDateByMonth(date);
        }
        return date;
    }

    //Problem 39 Level4 : 

    Date DecreaseDateByYear(Date date)
    {
        date.year--;

        int maxDays = GetMonthDays(date.year, date.month);
        if (date.day > maxDays)
        {
            date.day = maxDays;
        }

        return date;
    }

    //Problem 40 Level4 :

    Date DecreaseDateByXYears(Date date, int years)
    {
        for (int i = 0; i < years; i++)
        {
            date = DecreaseDateByYear(date);
        }
        return date;
    }

    //Problem 41 Level4 :

    Date DecreaseDateByXYearsFaster(Date date, int years)
    {
        date.year -= years;
        int maxDays = GetMonthDays(date.year, date.month);
        if (date.day > maxDays)
        {
            date.day = maxDays;
        }
        return date;
    }

    //Problem 42 Level4 :

    Date DecreaseDateByDecade(Date date)
    {
        return DecreaseDateByXYears(date, 10);
    }


    //Problem 43 Level4 :

    Date DecreaseDateByXDecades(Date date, int decades)
    {
        for (int i = 0; i < decades; i++)
        {
            date = DecreaseDateByDecade(date);
        }
        return date;
    }

    //Problem 44 Level4 :

    Date DecreaseDateByXDecadesFaster(Date& date, int decades)
    {
        int years = decades * 10;
        date.year -= years;
        int maxDays = GetMonthDays(date.year, date.month);
        if (date.day > maxDays)
        {
            date.day = maxDays;
        }
        return date;
    }

    //Problem 45 Level4 :

    Date DecreaseDateByCentury(Date date)
    {
        return DecreaseDateByXDecades(date, 10);
    }

    //Problem 46 Level4 :

    Date DecreaseDateByMillenium(Date& date)
    {
        date.year -= 1000;
        int maxDays = GetMonthDays(date.year, date.month);
        if (date.day > maxDays)
        {
            date.day = maxDays;
        }
        return date;
    }


    //Problem 47 Level4:

    int GetDayOrder(Date date)
    {
        int a = (14 - date.month) / 12;
        int y = date.year - a;
        int m = date.month + 12 * a - 2;

        int d = (date.day + y + y / 4 - y / 100 + y / 400 + (31 * m / 12)) % 7;

        return d;
    }

    //Problem 48 Level4 :

    bool IsEndOfWeek(int dayOrder)
    {
        return (dayOrder == 6);
    }

    //Problem 49 Level4 :

    bool IsWeekEnd(int dayOrder)
    {
        return (dayOrder == 5 || dayOrder == 6);
    }

    //Problem 50 Level4 :

    bool IsBusinnessDay(int dayOrder)
    {
        return (!IsWeekEnd(dayOrder));
    }

    //Problem 51 Level4 :

    int DaysUntilTheEndOfWeek(Date date)
    {
        return 6 - GetDayOrder(date);
    }

    //Problem 52 Level4 :

    int DaysUntilTheEndOfMonth(Date date)
    {
        int diff = 1;
        while (date.day != GetMonthDays(date.year, date.month))
        {
            diff++;
            date.day++;
        }
        return diff;
    }

    int DaysUntilTheEndOfMonthAnotherSolve(Date date)
    {
        Date monthEnd;
        monthEnd.year = date.year;
        monthEnd.month = date.month;
        monthEnd.day = GetMonthDays(date.year, date.month);

        return GetDiffBetweenDates(date, monthEnd, 1);
    }

    //Problem 53 Level4 :

    int DaysUntilTheEndOfYear(Date date)
    {
        return GetYearDays(date.year) - GetTotalDays(date);
    }

    //Problem 54 Level4 :

    int DaysUntilEndOfVacation(Date vacStart, Date vacEnd)
    {
        int vacDays = 0;
        int dayOrder;
        while (IsDateLower(vacStart, vacEnd))
        {
            dayOrder = GetDayOrder(vacStart);
            if (!IsWeekEnd(dayOrder))
            {
                vacDays++;
            }
            IncrementDateByOneDay(vacStart);
        }
        return vacDays;
    }

    int DaysUntilEndOfVacationAnotherSolve(Date vacStart, Date vacEnd)
    {
        int weekends = 0;
        int dayOrder = GetDayOrder(vacStart);
        int vacDays = GetDiffBetweenDates(vacStart, vacEnd);

        for (int i = 0; i < vacDays; i++)
        {
            if (IsWeekEnd(dayOrder++))
                weekends++;
            dayOrder %= 7;
        }

        return vacDays - weekends;
    }

    //Problem 56 Level4 :
    bool IsDateAfter(Date date1, Date date2)
    {
        return !(IsDateLower(date1, date2) || IsDateEqual(date1, date2));
    }


    void PrintDate(Date date)
    {
        printf("%d/%d/%d\n", date.day, date.month, date.year);
    }
}
