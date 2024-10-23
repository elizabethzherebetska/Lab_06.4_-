#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void COUT(double mas[], int size, int i = 0) {  
    if (i == size) {
        cout << endl;
        return;
    }
    cout << setw(6) << mas[i] << " ";
    COUT(mas, size, i + 1);  
}

double Max(double mas[], int size, int i = 0, double max = -1) {
    if (i == size) {
        return max;
    }
    if (mas[i] > max) {
        max = mas[i];
    }
    return Max(mas, size, i + 1, max);  
}

int Last(double mas[], int size, int i = 0, int last = -1) {
    if (i == size) {
        return last;
    }
    if (mas[i] > 0) {
        last = i;
    }
    return Last(mas, size, i + 1, last);
}

double Sum(double mas[], int last, int i = 0, double sum = 0) {
    if (i == last) {
        return sum;
    }
    sum += mas[i];
    return Sum(mas, last, i + 1, sum);  
}

void NULLS(double mas[], int size, double a, double b, int i = 0) {
    if (i == size) {
        return;
    }
    if (abs(mas[i]) >= a && abs(mas[i]) <= b) {
        mas[i] = 0;
    }
    NULLS(mas, size, a, b, i + 1);  
}

int main() {
    setlocale(LC_CTYPE, "ukr");

    int n;
    double a, b;

    cout << "����i�� �i���i��� �������i� ������ n: ";
    cin >> n;

    cout << "I������� ��� ���������: ";
    cin >> a >> b;

    double* mas = new double[n];

    cout << "����i�� �������� ������: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }

    cout << "���������� �����: " << endl;
    COUT(mas, n);

    double max = Max(mas, n);
    cout << "������������ ������� ������: " << max << endl;

    int last = Last(mas, n);

    double sum = Sum(mas, last);
    cout << "���� �������i� (��i� ���������): " << sum << endl;

    NULLS(mas, n, a, b);

    cout << "��������� �����: " << endl;
    COUT(mas, n);

    delete[] mas;

    return 0;
}
