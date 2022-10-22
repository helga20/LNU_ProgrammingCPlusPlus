#ifndef _Array_Procs_
#define _Array_Procs_

// ���������� ���� ������� ��� ����, ��� ������� ������ ���� ���� �����
using num_type = double;

const size_t N = 10;
using Array = num_type[N];

// ������� ��� ������ � �������� ���� array (� ���������� ��������)
void ReadArray(Array a);
num_type ScalarProduct(Array a, Array b);

// ��������� ���������� ������ �������� ������
num_type* CreateArray(size_t n, num_type x = 0);
// ����������� �������� ������ � ������
void ReadArray(num_type* a, size_t n);
// ��������� ������ �� �������
void WriteArray(const num_type* a, size_t n);
// ���������� ���������� ������� �������
num_type ScalarProduct(const num_type* a, const num_type* b, size_t n);
// ���������� ����� �������
num_type Norm(const num_type* a, size_t n);

// г�� ������� ��������� ���������� �������� ������
double maxVal(const double* a, size_t n);
double maxVal(const double* start, const double* end);
double* max(double* start, double* end);

#endif