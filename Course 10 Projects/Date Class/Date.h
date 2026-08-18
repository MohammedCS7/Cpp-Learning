#pragma once
#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
using namespace std;
class Date
{
private:
	int _Year;
	int _Month;
	int _Day;
	enum DateState {After = 1,Equal = 0,Before = -1};

public:
	void setYear(int Year)
	{
		_Year = Year;
	}
	void setMonth(int Month)
	{
		_Month = Month;
	}
	void setDay(int Day)
	{
		_Day = Day;
	}
	int getYear()
	{
		return _Year;
	}
	int getMonth()
	{
		return _Month;
	}
	int getDay()
	{
		return _Day;
	}

	Date()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		_Year = now->tm_year + 1900;
		_Month = now->tm_mon + 1;
		_Day = now->tm_mday;
	}

	Date(int Day, int Month, int Year)
	{
		_Year = Year;
		_Month = Month;
		_Day = Day;
	}

	static bool IsLeapYear(const Date& date)
	{
		return ((date._Year % 4 == 0 && date._Year % 100 != 0) || (date._Year % 400 == 0));
	}

	bool IsLeapYear()
	{
		return IsLeapYear(*this);
	}

private:
	static int GetYearDays(const Date& date)
	{
		return IsLeapYear(date) ? 366 : 365;
	}

	static int GetMonthDays(const Date& date)
	{
		if (date._Month < 1 || date._Month > 12)
			return 0;
		if (date._Month == 2)
			return IsLeapYear(date) ? 29 : 28;
		int bigMonths[7] = { 1,3,5,7,8,10,12 };
		for (int i = 0; i < 7; i++)
		{
			if (bigMonths[i] == date._Month)
				return 31;
		}
		return 30;
	}

	static int GetDayOrder(const Date& date)
	{
		int a = (14 - date._Month) / 12;
		int y = date._Year - a;
		int m = date._Month + 12 * a - 2;

		int d = (date._Day + y + y / 4 - y / 100 + y / 400 + (31 * m / 12)) % 7;

		return d;
	}

	static int GetTotalDays(const Date& date)
	{
		int total = 0;
		for (int i = 1; i < date._Month; i++)
		{
			total += GetMonthDays(Date(1, i, date._Year));
		}
		return total += date._Day;
	}

	static Date GetDateFromTotalDays(int year, int total)
	{
		Date date;
		date._Year = year;
		int month = 1;
		int days;
		while (true)
		{
			days = GetMonthDays(Date(1, month, year));
			if (total > days)
			{
				total -= days;
				month++;
			}
			else
				break;
		}
		date._Month = month;
		date._Day = total;
		return date;
	}

	static Date GetDateAfterAdding(const Date& date, int addedDays)
	{
		Date newDate = date;
		int remDays = GetTotalDays(date) + addedDays;
		while (true)
		{
			int yearDays = GetYearDays(newDate);
			if (remDays >= yearDays)
			{
				remDays -= yearDays;
				newDate._Year++;
			}
			else
				break;
		}
		return GetDateFromTotalDays(newDate._Year, remDays);
	}

	static bool IsLastDay(const Date& date)
	{
		return (date._Day == GetMonthDays(date));
	}

	static bool IsLastMonth(const Date& date)
	{
		return date._Month == 12;
	}

	static Date IncrementDate(const Date& date)
	{
		Date newDate = date;
		if (IsLastMonth(date) && IsLastDay(date))
		{
			newDate._Year++;
			newDate._Month++;
			newDate._Day = 1;
		}
		else if (IsLastDay(date))
		{
			newDate._Month++;
			newDate._Day = 1;
		}
		else
			newDate._Day++;
		if (newDate._Day > GetMonthDays(newDate))
			newDate._Day = GetMonthDays(newDate);
		return newDate;
	}

	static Date IncrementDateByMonth(const Date& date)
	{
		Date newDate = date;
		if (IsLastMonth(date))
		{
			newDate._Year++;
			newDate._Month++;
			newDate._Day = 1;
		}
		else
		{
			newDate._Month++;
		}
		if (newDate._Day > GetMonthDays(newDate))
			newDate._Day = GetMonthDays(newDate);
		return newDate;
	}

	static Date IncrementDateByXMonths(const Date& date, int months)
	{
		Date newDate = date;
		for (int i = 0; i < months; i++)
		{
			newDate = IncrementDateByMonth(newDate);
		}
		return newDate;
	}

	static Date IncrementDateByYear(const Date& date)
	{
		Date newDate = date;
		newDate._Year++;

		int maxDays = GetMonthDays(newDate);
		if (newDate._Day > maxDays)
		{
			newDate._Day = maxDays;
		}
	}

	static Date IncrementDateByXYears(const Date& date, int years)
	{
		Date newDate = date;
		for (int i = 0; i < years; i++)
		{
			newDate = IncrementDateByYear(newDate);
		}
		return newDate;
	}

	static Date IncrementDateByXYearsFaster(const Date& date, int years)
	{
		Date newDate = date;
		newDate._Year += years;
		int maxDays = GetMonthDays(newDate);
		if (newDate._Day > maxDays)
		{
			newDate._Day = maxDays;
		}
		return newDate;
	}

	Date IncrementDate()
	{
		return IncrementDate(*this);
	}

	static Date DecrementDate(const Date& date)
	{
		Date newDate = date;
		if (newDate._Day == 1 && newDate._Month == 1)
		{
			newDate._Year--;
			newDate._Month = 12;
			newDate.Day = GetMonthDays(newDate);;
		}
		else if (newDate._Day = 1)
		{
			newDate._Month--;
			newDate._Day = GetMonthDays(newDate);
		}
		else
			newDate._Day--;
		return newDate;
	}

	static Date DecrementDateByMonth(const Date& date)
	{
		Date newDate = date;
		if (newDate._Month == 1)
		{
			newDate._Month = 12;
			newDate._Year--;
		}
		else
			newDate._Month--;

		int maxDays = GetMonthDays(newDate);
		if (newDate._Day > maxDays)
		{
			newDate._Day = maxDays;
		}
		return newDate;
	}

	static Date DecrementDateByYear(const Date& date)
	{
		Date newDate = date;
		newDate._Year--;

		int maxDays = GetMonthDays(newDate);
		if (newDate._Day > maxDays)
		{
			newDate._Day = maxDays;
		}

		return newDate;
	}

	Date DecrementDate()
	{
		return DecrementDate(*this);
	}

public:

	Date(int totalDays, int year)
	{
		Date date = GetDateFromTotalDays(year, totalDays);
		_Year = year;
		_Month = date._Month;
		_Day = date._Day;
	}

	Date(string date)
	{
		short pos = date.find('/');
		_Day = stoi(date.substr(0, pos));
		date.erase(0, pos+1);
		pos = date.find('/');
		_Month = stoi(date.substr(0, pos));
		date.erase(0, pos+1);
		_Year = stoi(date);
	}

	static string ToString(const Date& date)
	{
		return to_string(date._Day) + "/" + to_string(date._Month) + "/" + to_string(date._Year);
	}

	string ToString()
	{
		return ToString(*this);
	}

	void Print()
	{
		cout << _Day << "/" << _Month << "/" << _Year << endl;
	}

	static string GetWeekDayName(const Date& date)
	{
		const string days[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
		return days[GetDayOrder(date)];
	}

	static string GetWeekDayName(int dayOrder)
	{
		const string days[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
		return days[dayOrder];
	}

	static string GetMonthName(const Date& date)
	{
		const string months[13] = { "","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
		return months[date._Month];
	}

	static void PrintMonthCalendar(const Date& date)
	{
		int days = GetMonthDays(date);
		int dayOrder = GetDayOrder(Date(1, date._Month, date._Year));
		cout << "\n_________________";
		cout << GetMonthName(date);
		cout << "_________________\n";
		cout << endl;
		int i = 0;
		for (int a = 0; a < 7; a++)
		{
			cout << setw(5) << GetWeekDayName(a);
		}
		cout << endl;
		for (; i < 7;)
		{
			if (i != dayOrder)
			{
				cout << setw(5) << " ";
				i++;
			}
			else
				break;
		}
		int dayCount = 1;
		while (dayCount <= days)
		{
			if (i++ < 7)
			{
				cout << setw(5) << dayCount++;
			}
			else
			{
				cout << endl;
				i = 0;
			}
		}
		cout << "\n_____________________________________" << endl;
	}

	void PrintMonthCalendar()
	{
		return PrintMonthCalendar(*this);
	}

	static bool IsDateBefore(const Date& date1, const Date& date2)
	{
		return (date1._Year != date2._Year) ? (date1._Year < date2._Year) : (date1._Month != date2._Month) ? (date1._Month < date2._Month) : (date1._Day < date2._Day);
	}

	static bool IsDateEqual(const Date& date1, const Date& date2)
	{
		return (date1._Year == date2._Year && date1._Month == date2._Month && date1._Day == date2._Day);
	}

	static bool IsDateAfter(const Date& date1, const Date& date2)
	{
		return !(IsDateBefore(date1, date2) || IsDateEqual(date1, date2));
	}

	bool IsDateBefore(const Date& date2)
	{
		return IsDateBefore(*this, date2);
	}

	bool IsDateEqual(const Date& date2)
	{
		return IsDateEqual(*this, date2);
	}

	bool IsDateAfter(const Date& date2)
	{
		return IsDateAfter(*this, date2);
	}

	static bool IsEndOfWeek(int dayOrder)
	{
		return (dayOrder == 6);
	}

	static bool IsWeekEnd(int dayOrder)
	{
		return (dayOrder == 5 || dayOrder == 6);
	}

	static bool IsBusinnessDay(int dayOrder)
	{
		return (!IsWeekEnd(dayOrder));
	}

	static bool IsValid(const Date& date)
	{
		return (date._Year > 0 && date._Month > 0 && date._Month < 13 && date._Day > 0 && date._Day <= GetMonthDays(date));
	}

	bool IsValid()
	{
		return IsValid(*this);
	}

	bool IsEndOfWeek()
	{
		return IsEndOfWeek(GetDayOrder(*this));
	}

	bool IsWeekEnd()
	{
		return IsWeekEnd(GetDayOrder(*this));
	}

	bool IsBusinnessDay()
	{
		return IsBusinnessDay(GetDayOrder(*this));
	}

	static int GetDiffBetweenDates(const Date& date1, const Date& date2, bool IncludeCurrentDay = true)
	{
		int diff = 0;
		Date newDate = date1;
		if (!IsDateBefore(date1, date2)) return -1;
		while (IsDateBefore(newDate, date2))
		{
			newDate = IncrementDate(newDate);
			diff++;
		}
		return IncludeCurrentDay ? diff + 1 : diff;
	}

	int GetDiffBetweenDates(const Date& date2, bool IncludeCurrentDay = true)
	{
		return GetDiffBetweenDates(*this, date2, IncludeCurrentDay);
	}

	static int DaysUntillEndOfWeek(const Date& date, bool IncludeCurrentDay = true)
	{
		int diff = 0;
		int order = GetDayOrder(date);
		while (!IsEndOfWeek(order++))
		{
			diff++;
		}
		return IncludeCurrentDay ? diff + 1 : diff;
	}

	int DaysUntillEndOfWeek(bool IncludeCurrentDay = true)
	{
		return DaysUntillEndOfWeek(*this, IncludeCurrentDay);
	}

	static int DaysUntillEndOfMonth(const Date& date, bool IncludeCurrentDay = true)
	{
		int rem = GetMonthDays(date) - date._Day;
		return IncludeCurrentDay ? rem+1 : rem;
	}

	int DaysUntillEndOfMonth(bool IncludeEndDay)
	{
		return DaysUntillEndOfMonth(*this, IncludeEndDay);
	}

	static int DaysUntillEndOfYear(const Date& date, bool IncludeCurrentDay = true)
	{
		int rem = GetYearDays(date) - GetTotalDays(date);
		return IncludeCurrentDay ? rem + 1 : rem;
	}

	int DaysUntillEndOfYear(bool IncludeCurrentDay = true)
	{
		return DaysUntillEndOfYear(*this, IncludeCurrentDay);
	}

	static int DaysUntillVacationEnds(const Date& vacStart, const Date& vacEnd)
	{
		int days = GetDiffBetweenDates(vacStart,vacEnd);
		int order = GetDayOrder(vacStart);
		int i = 1;
		int vacDays = days;
		while (i <= days)
		{
			if (IsWeekEnd(order++))
				vacDays--;
			i++;
			order %= 7;
		}
		return vacDays;
	}

	static Date GetVacationEndFromDays(const Date& vacStart, int vacDays)
	{
		Date newDate = vacStart;
		int order = GetDayOrder(newDate);
		while (vacDays > 0)
		{
			if (IsBusinnessDay(order++))
			vacDays--;
			order %= 7;
			newDate = IncrementDate(newDate);
		}
		return newDate;
	}

	static int GetAgeDays(const Date& birthDay)
	{
		Date today;
		return GetDiffBetweenDates(birthDay, today, true);
	}

	static int GetDiffBetweenDate(const Date& date1, const Date& date2)
	{
		if (IsDateAfter(date1, date2))
		{
			return -GetDiffBetweenDates(date2, date1);
		}
		else if (IsDateBefore(date1, date2))
		{
			return GetDiffBetweenDates(date1, date2);
		}
		else
			return 0;
	}

	int GetDiffBetweenDate(const Date& date2)
	{
		return GetDiffBetweenDate(*this, date2);
	}

	static DateState Compare(const Date& date1, const Date& date2)
	{
		return IsDateAfter(date1, date2) ? DateState::After : IsDateBefore(date1, date2) ? DateState::Before : DateState::Equal;
	}

	DateState Compare(const Date& date2)
	{
		return Compare(*this, date2);
	}

	static int GetAbsoluteDays(const Date& date)
	{
		int days = 0;
		for (int i = 1; i < date._Year; i++)
		{
			days += GetYearDays(Date(1,1,i));
		}
		return days + GetTotalDays(date);
	}

	static string Format(const Date& date, string format = "dd/mm/yyyy")
	{
		string newFormat = "";
		format.append("    ");
		int length = format.length() - 4;
		int i = 0;
		while (i < length)
		{
			if (format.compare(i, 2, "dd") == 0)
			{
				newFormat += to_string(date._Day);
				i += 2;
			}
			else if (format.compare(i, 2, "mm") == 0)
			{
				newFormat += to_string(date._Month);
				i += 2;
			}
			else if (format.compare(i, 4, "yyyy") == 0)
			{
				newFormat += to_string(date._Year);
				i += 4;
			}
			else
			{
				newFormat += format[i];
				i++;
			}
		}
		return newFormat;
	}

	string Format(string format = "dd/mm/yyyy")
	{
		return Format(*this, format);
	}

	__declspec(property(get = getYear, put = setYear)) int Year;
	__declspec(property(get = getMonth, put = setMonth)) int Month;
	__declspec(property(get = getDay, put = setDay)) int Day;
};

