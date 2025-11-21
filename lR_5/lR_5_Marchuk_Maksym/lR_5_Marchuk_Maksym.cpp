#include "pch.h"
#include <iomanip>
#include <iostream>

using namespace System;

#pragma region Helpers
void PrintHeader(String^ title) {
    Console::WriteLine();
    Console::WriteLine("=================================================================");
    Console::WriteLine("  {0}", title);
    Console::WriteLine("=================================================================");
}

String^ Fixed(double v, int width = 12, int prec = 6) {
    return String::Format("{0," + width + ":F" + prec + "}", v);
}
#pragma endregion

#pragma region Task1
void Task1_EIllumination() {
    PrintHeader("Task 1 — Освітленість поверхні (E = 100 * cos α)");

    array<double>^ anglesDeg = gcnew array<double> {30, 35, 37, 40, 45, 58, 60, 64, 70, 80};
    Console::WriteLine("{0,6} | {1,12}", "α (°)", "E (лк)");
    Console::WriteLine("-------+-------------");
    for each (double aDeg in anglesDeg) {
        double aRad = aDeg * Math::PI / 180.0;
        double E = 100.0 * Math::Cos(aRad);
        Console::WriteLine("{0,6:F0} | {1}", aDeg, Fixed(E, 12, 4));
    }
}
#pragma endregion

#pragma region Task2
void Task2_FlowRates() {
    PrintHeader("Task 2 — Об'ємні витрати води (Poiseuille)");

    array<double>^ radii = gcnew array<double> {0.005, 0.010, 0.015, 0.020, 0.025, 0.030, 0.035, 0.040, 0.045, 0.050};
    double eta = 0.0018;    // Па·с
    double deltaP = 0.02;   // Па
    double l = 2.0;         // м

    Console::WriteLine("{0,8} | {1,18}", "R (m)", "V (m^3/s)");
    Console::WriteLine("---------+----------------------");
    for each (double R in radii) {
        double V = Math::PI * Math::Pow(R, 4) * deltaP / (8.0 * eta * l);
        Console::WriteLine("{0,8:F3} | {1}", R, Fixed(V, 18, 8));
    }
}
#pragma endregion

#pragma region Task3
void Task3_FailureFrequency() {
    PrintHeader("Task 3 — Частота відмов ω = m / (n * T)");

    int n = 50;
    array<int>^ failures = gcnew array<int> {2, 1, 0, 3, 2, 4, 1, 0, 2, 3, 1, 2, 0, 1, 2};
    int years = failures->Length;

    Console::WriteLine("n (ex.units) = {0}", n);
    Console::WriteLine("{0,6} | {1,10} | {2,12}", "Year", "m (fails)", "ω (1/yr)");
    Console::WriteLine("-------+------------+------------");
    for (int i = 0; i < failures->Length; ++i) {
        double m = failures[i];
        double omega = m / ((double)n * 1.0);
        Console::WriteLine("{0,6} | {1,10} | {2,12}", i + 1, failures[i], Fixed(omega, 12, 6));
    }

    double totalM = 0;
    for each (int mm in failures) totalM += mm;
    double omegaTotalPerYear = totalM / (n * years);
    Console::WriteLine();
    Console::WriteLine("Середня частота відмов за {0} років: ω_avg = {1}", years, Fixed(omegaTotalPerYear, 12, 8));
}
#pragma endregion

#pragma region Task4
void Task4_ShortCircuitCurrent() {
    PrintHeader("Task 4 — Струм короткого замикання I_kz = S / (sqrt(3)*U*B)");

    double S = 100000.0; // VA
    double B = 0.1;

    array<int>^ voltages = gcnew array<int> {220, 380, 6000, 10000, 35000, 110000};

    Console::WriteLine("Прикладні S = {0} VA, B = {1}", S, B);
    Console::WriteLine("{0,10} | {1,18}", "U (V)", "I_kz (A)");
    Console::WriteLine("-----------+----------------------");
    for each (int U in voltages) {
        double I_kz = S / (Math::Sqrt(3.0) * (double)U * B);
        Console::WriteLine("{0,10} | {1}", U, Fixed(I_kz, 18, 4));
    }
}
#pragma endregion

#pragma region Task5
void Task5_ShaftDiameter() {
    PrintHeader("Task 5 — Діаметр вала d = sqrt( T / (0.2 * τ) )");

    double T = 1800.0; // кгс
    array<double>^ tau = gcnew array<double> {100, 120, 150, 170, 200, 250};

    Console::WriteLine("{0,12} | {1,12}", "τ (кгс/см^2)", "d (од.)");
    Console::WriteLine("-------------+-------------");
    for each (double t in tau) {
        double d = Math::Sqrt(T / (0.2 * t));
        Console::WriteLine("{0,12:F2} | {1}", t, Fixed(d, 12, 4));
    }
}
#pragma endregion

#pragma region Task6
void Task6_DistancesToSchool() {
    PrintHeader("Task 6 — Відстань від будинків до школи");

    double Ax = 100.0, Ay = 50.0;
    array<double>^ X = gcnew array<double> { 95.0, 120.0, 102.0, 85.0, 150.0 };
    array<double>^ Y = gcnew array<double> { 55.0, 48.0, 70.0, 40.0, 90.0 };

    int n = X->Length;
    Console::WriteLine("Школа: ({0}, {1})", Ax, Ay);
    Console::WriteLine("{0,6} | {1,10} | {2,10} | {3,12}", "№", "X", "Y", "Distance");
    Console::WriteLine("-------+------------+------------+--------------");
    for (int i = 0; i < n; ++i) {
        double dx = X[i] - Ax;
        double dy = Y[i] - Ay;
        double dist = Math::Sqrt(dx * dx + dy * dy);
        Console::WriteLine("{0,6} | {1,10:F2} | {2,10:F2} | {3}", i + 1, X[i], Y[i], Fixed(dist, 12, 4));
    }
}
#pragma endregion

#pragma region Task7
void Task7_PayrollTax() {
    PrintHeader("Task 7 — Виплата заробітної плати з вирахуванням податку");

    double H = 18.0;
    array<int>^ ids = gcnew array<int> {1, 2, 3, 4, 5};
    array<double>^ gross = gcnew array<double> {2500.0, 3000.0, 1800.0, 4000.0, 2200.0};

    Console::WriteLine("Податок H = {0}%\n", H);
    Console::WriteLine("{0,8} | {1,14} | {2,12}", "№", "Gross", "Net");
    Console::WriteLine("--------+----------------------+-----------");
    for (int i = 0; i < ids->Length; ++i) {
        double net = gross[i] * (1.0 - H / 100.0);
        Console::WriteLine("{0,8} | {1,14} | {2,12}", ids[i], Fixed(gross[i], 14, 2), Fixed(net, 12, 2));
    }
}
#pragma endregion

#pragma region Task8
void Task8_Flywheel() {
    PrintHeader("Task 8 — Маховик: ω, v, Wk");

    double D = 1.5;
    double R = D / 2.0;
    double mass_tonnes = 0.5;
    double m = mass_tonnes * 1000.0;

    array<int>^ n_values = gcnew array<int> {50, 150, 200, 350, 550, 900, 1000};

    Console::WriteLine("D = {0} m, m = {1} kg", D, m);
    Console::WriteLine("{0,6} | {1,12} | {2,12} | {3,14}", "n, rpm", "ω (rad/s)", "v (m/s)", "Wk (J)");
    Console::WriteLine("-------+--------------+--------------+----------------");
    for each (int n in n_values) {
        double omega = Math::PI * n / 30.0;
        double v = omega * R;
        double Wk = 0.5 * m * v * v;
        Console::WriteLine("{0,6} | {1,12:F4} | {2,12:F4} | {3,14:F2}", n, omega, v, Wk);
    }
}
#pragma endregion

#pragma region Task9
void Task9_WorkersWage() {
    PrintHeader("Task 9 — Заробітна плата робітників за виготовлену продукцію");

    array<int>^ ids = gcnew array<int> {101, 102, 103, 104, 105};
    array<double>^ pricePerUnit = gcnew array<double> {2.5, 3.0, 1.8, 4.0, 2.2};
    array<int>^ qty = gcnew array<int> {120, 80, 200, 50, 150};

    Console::WriteLine("{0,8} | {1,12} | {2,10} | {3,12}", "№", "Price/unit", "Qty", "Wage");
    Console::WriteLine("--------+---------------+-----------+------------");
    for (int i = 0; i < ids->Length; ++i) {
        double wage = pricePerUnit[i] * qty[i];
        Console::WriteLine("{0,8} | {1,12:F2} | {2,10} | {3,12:F2}", ids[i], pricePerUnit[i], qty[i], wage);
    }
}
#pragma endregion

int main(array<System::String^>^ args)
{
    Console::OutputEncoding = System::Text::Encoding::UTF8;

    Task1_EIllumination();
    Task2_FlowRates();
    Task3_FailureFrequency();
    Task4_ShortCircuitCurrent();
    Task5_ShaftDiameter();
    Task6_DistancesToSchool();
    Task7_PayrollTax();
    Task8_Flywheel();
    Task9_WorkersWage();

    Console::WriteLine();
    Console::ReadKey();
    return 0;
}
