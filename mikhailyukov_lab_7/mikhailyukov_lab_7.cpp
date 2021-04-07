#include <iostream>
#include <cmath>
using namespace std;

long long int Factorial(int number);
double GetNumber();

class CalculatingSeries {
    public:
        void Setx(double number) {
            x = number;
        }

        double CalculateSeries() {
            double Sum = 0;
            for (int i = 0; i <= ElementsCount; i++) {
                double Summand = (pow(-1, i) * pow(x, 2 * i)) / (Factorial(2 * i + 1));
                Sum += Summand;
            }
            return Sum;
        }

    private:
        static int ElementsCount;
        double x = 0;
};

int CalculatingSeries::ElementsCount = 9;

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Введите x для вычисления ряда: ";
    double x = GetNumber();
    CalculatingSeries Obj1;
    Obj1.Setx(x);
    cout << "При x = " << x << " ряд равен : " << Obj1.CalculateSeries() << "\n";

    cout << "И давайте ещё раз.\n";
    cout << "Введите x для вычисления ряда: ";
    x = GetNumber();
    CalculatingSeries Obj2;
    Obj2.Setx(x);
    cout << "При x = " << x << " ряд равен : " << Obj2.CalculateSeries() << "\n";

    return 0;
}

long long int Factorial(int number) {
    long long int res = 1;
    for (int i = 1; i <= number; i++) {
        res *= i;
    }
    return res;
}

double GetNumber()
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
