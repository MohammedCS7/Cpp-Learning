#include <iostream>
using namespace std;
enum Operations {Add='+',Substract='-',Multiply='*',Divide='/' };
struct Calculator
{
    float number1, number2;
    Operations operation;
};
Calculator ReadCalcData()
{
    Calculator calc;
    char operation;
    cout << "Enter Number 1 : " << endl;
    cin >> calc.number1;

    cout << "Enter Number 2 : " << endl;
    cin >> calc.number2;

    cout << "Enter Operation : " << endl;
    cin >> operation;
    calc.operation = (Operations)operation;
    
    return calc;
}
bool CheckDivisionByZero(Calculator calc)
{
    return (calc.operation == Operations::Divide && calc.number2 == 0);
    
}
float GetResult(Calculator calc)
{
    switch (calc.operation)
    {
    case Operations::Add :
        return calc.number1 + calc.number2;
        break;
    case Operations::Substract :
        return calc.number1 - calc.number2;
        break;
    case  Operations::Multiply :
        return calc.number1 * calc.number2;
        break;
    case Operations::Divide :
        return calc.number1 / calc.number2;
        break;
    default :
        return 0;
    }
}
void PrintResult(bool unDivideByZero,float result)
{
    if (unDivideByZero)
        cout << "Error, Unable to Divide by Zero!" << endl;
    else
        cout << "Result = " << result << endl;
}
int main() {
    Calculator myCalc = ReadCalcData();
    PrintResult(CheckDivisionByZero(myCalc), GetResult(myCalc));

    return 0;
}