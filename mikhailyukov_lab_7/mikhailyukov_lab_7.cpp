#include <iostream>
#include <cmath>
using namespace std;

double GetDoubleNumber();
int GetIntegerNumber();
int GetNaturalNumberLessThanEleven();

class CalculatingSeries {
    public:
        void Setx(double number) {
            x = number;
        }

        static void SetElementsCount(int number) {
            ElementsCount = number;
        }

        double CalculateSeries() {
            double Sum = 0;
            for (int i = 0; i < ElementsCount; i++) {
                double Summand = (pow(-1, i) * pow(x, 2 * i)) / (Factorial(2 * i + 1));
                Sum += Summand;
            }
            return Sum;
        }

        static int GetElementsCount() {
            return ElementsCount;
        }

    private:
        static int ElementsCount;
        double x = 0;

        long long int Factorial(int number) {
            long long int res = 1;
            for (int i = 1; i <= number; i++) {
                res *= i;
            }
            return res;
        }
};

int CalculatingSeries::ElementsCount = 10;

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Введите x для вычисления ряда: ";
    double x = GetDoubleNumber();
    CalculatingSeries Obj1;
    Obj1.Setx(x);
    cout << "При x = " << x << ", для " << Obj1.GetElementsCount() << " слагаемых ряд равен : " << Obj1.CalculateSeries() << "\n";

    cout << "И давайте ещё раз.\n";
    cout << "Введите x для вычисления ряда: ";
    x = GetDoubleNumber();
    CalculatingSeries Obj2;
    Obj2.Setx(x);
    cout << "Введите количество слагаемых в ряде (не больше десяти): ";
    int ElementsCount = GetNaturalNumberLessThanEleven();
    CalculatingSeries::SetElementsCount(ElementsCount);
    cout << "При x = " << x << ", для " << ElementsCount << " слагаемых ряд равен : " << Obj2.CalculateSeries() << "\n";

    return 0;
}



double GetDoubleNumber()
{
    while (true)
    {
        double number;
        cin >> number;
        if (cin.fail())
        {
            cout << "Ошибка: вы ввели не число\n";
            cout << "Введите данные снова: ";
            cin.clear();
            cin.ignore(32767, '\n');
        }
        else {
            cin.ignore(32767, '\n');
            return number;
        }
    }
}

int GetIntegerNumber()
{
    while (true)
    {
        int number;
        cin >> number;
        if (cin.fail())
        {
            cout << "Ошибка: вы ввели не число\n";
            cout << "Введите данные снова: ";
            cin.clear();
            cin.ignore(32767, '\n');
        }
        else {
            cin.ignore(32767, '\n');
            return number;
        }
    }
}

int GetNaturalNumberLessThanEleven() {
    int number = 0;
    do {
        number = GetIntegerNumber();
        if (number == 0) {
            cout << "Ошибка: количество элементов не должно быть равно нулю\n";
            cout << "Введите данные снова: ";
        }
        
        if (number < 0) {
            cout << "Ошибка: количество элементов не может быть отрицательным\n";
            cout << "Введите данные снова: ";
        }

        if (number > 10) {
            cout << "Ошибка: количество элементов не должно быть больше 10\n";
            cout << "Введите данные снова: ";
        }

    } while ((number < 1) || (number > 10));
    return number;
}