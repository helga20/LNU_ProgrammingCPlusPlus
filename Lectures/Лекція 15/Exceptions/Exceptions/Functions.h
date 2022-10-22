#pragma once

//����� ����������� ��� ���������� �������
class DivByZero {};
class ZeroArg {};

// ���������� ���������� �������������
double arithmetic(double, double);

// ���������� ���������� �������������
// ������ ������� � ������� ��'����� ���������
double geometric(double, double) throw(const char*);

// ������� ��� ���������� ���������� �����������, ��� ������� ����������� �������
// - ������� ��������
double harmonic_1(double, double);
// - ������� ������ �����
  bool harmonic_2(double, double, double*);
// - ������� �������
double harmonic_3(double, double) throw(const char*);
// - ������� ����� �������� �������
double harmonic_4(double, double) throw(DivByZero, ZeroArg);
// - ������� ������� ������������ �����
double harmonic_5(double, double);