#include <iostream>
#include <iomanip>
using namespace std;

const int BILLION = 1000000000;
const int MILLION = 1000000;
const int THOUSAND = 1000;
const int HUNDRED = 100;
const int TEN = 10;
const int ZERO = 0;


long ReadLong(string message)
{
    long num;
    cout << message;
    cin >> num;
    return num;
}

string GetOneSlotNumText(int num)
{
    if (num - 1 < 0)
        return "";
    string nums[9] = { "One","Two","Three","Four","Five","Six","Seven","Eight","Nine" };
    return nums[num - 1];
}

string GetTenSlotNumText(int num)
{
    string nums[10] = { "Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
    return nums[num % 10];
}


string GetUpTenSlotNumText(int num)
{
    string nums[9] = { "Ten","Twenty","Thirty","Fourty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    return nums[num / 10 - 1] + " " + GetOneSlotNumText(num % 10);
}

string GetTensSlotNumText(int num)
{
    if (num < ZERO)
        return "";
    if (num > 19)
    {
        return GetUpTenSlotNumText(num);
    }
    else if (num >= TEN)
    {
        return GetTenSlotNumText(num);
    }
    else
    {
        return GetOneSlotNumText(num);
    }
}

string GetHundredsSlotNumText(int num)
{
    if (num < HUNDRED && num >= TEN)
        return GetTensSlotNumText(num);
    else if (num > ZERO && num < TEN)
        return GetOneSlotNumText(num);
    else if(num <= ZERO)
        return "";
    else
    {
        string hundred = (num / HUNDRED > 1) ? "Hundreds" : "Hundred";
        return GetOneSlotNumText(num / HUNDRED) + " " + hundred + " " + GetTensSlotNumText(num % HUNDRED);
    }
}

string GetText(long num)
{
    if (num >= BILLION)
        return (num / BILLION > 1) ? "Billions" : "Billion";
    else if (num >= MILLION)
        return (num / MILLION > 1) ? "Millions" : "Million";
    else if (num >= THOUSAND)
        return (num / THOUSAND > 1) ? "Thousands" : "Thousand";
    else if (num >= HUNDRED)
        return (num / HUNDRED > 1) ? "Hundreds" : "Hundred";
}

string GetNumText(long num)
{
    if (num >= BILLION)
        return GetHundredsSlotNumText(num / BILLION) + " " + GetText(num) + " " + GetNumText(num % BILLION);
    else if (num >= MILLION)
        return GetHundredsSlotNumText(num / MILLION) + " " + GetText(num) + " " + GetNumText(num % MILLION);
    else if (num >= THOUSAND)
        return GetHundredsSlotNumText(num / THOUSAND) + " " + GetText(num) + " " + GetNumText(num % THOUSAND);
    else if (num >= HUNDRED)
        return GetHundredsSlotNumText(num);
    else if (num > 19)
        return GetUpTenSlotNumText(num);
    else if (num >= 10 && num <= 19)
        return GetTenSlotNumText(num);
    else
        return GetOneSlotNumText(num);
}

void PrintNumText(string text)
{
    cout << "\n\n_________________________________________________________________________________________\n" << endl;
    cout << text << endl;
    cout << "_________________________________________________________________________________________" << endl;
}

int main() {


    PrintNumText(GetNumText(ReadLong("Enter a Number : ")));

    return 0;
}