#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;

class BASE {
public:
    virtual void solve() = 0;
};


class LinearEquation : public BASE {
private:
    double a, b;

public:
    LinearEquation(double valueA, double valueB) : a(valueA), b(valueB) {}

    void solve() override {
        if (a == 0) {
            if (b == 0) {
                cout << "Рівняння має безліч розв'язків." << endl;
            }
            else {
                cout << "Рівняння не має розв'язків." << endl;
            }
        }
        else {
            double x = -b / a;
            cout << "Корінь рівняння: x = " << x << endl;
        }
    }
};



class QuadraticEquation : public BASE {
private:
    double a, b, c;

public:
    QuadraticEquation(double valueA, double valueB, double valueC)
        : a(valueA), b(valueB), c(valueC) {}

    void solve() override {
        if (a == 0) {
            LinearEquation linearEquation(b, c);
            linearEquation.solve();
        }
        else {
            double discriminant = b * b - 4 * a * c;

            if (discriminant > 0) {
                double x1 = (-b + sqrt(discriminant)) / (2 * a);
                double x2 = (-b - sqrt(discriminant)) / (2 * a);
                cout << "Корені рівняння: x1 = " << x1 << ", x2 = " << x2 << endl;
            }
            else if (discriminant == 0) {
                double x = -b / (2 * a);
                cout << "Рівняння має один корінь: x = " << x << endl;
            }
            else {
                cout << "Рівняння не має дійсних коренів." << endl;
            }
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double a, b, c;

    cout << "Enter the values:" << endl;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;

    cout << "Лінійне:" << endl;
    LinearEquation linearEquation(a, b);
    linearEquation.solve();

    cout << endl;
    cout << "Квадратичне:" << endl;
    QuadraticEquation quadraticEquation(a, b, c);
    quadraticEquation.solve();

    return 0;
}
