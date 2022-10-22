#include <ctime>
#include <iostream>
using namespace std;

// �������� ���� ��� ��������� �������� �� ������� �������� ����
template </*�������� �������*/class, size_t, /*�������*/class, class> class VectorSum;

// ����-������. ������� ����� �������� ���� �������
template <class T, size_t N> class Vector
{
	T data[N];
public:
	Vector<T,N>& operator=(const Vector<T,N>& V)
	{
		for (size_t i=0; i<N; ++i) data[i] = V.data[i];
		return *this;
	}
	template <class L, class R> Vector<T,N>& operator=(const VectorSum<T,N,L,R>& S);
	const T& operator[](size_t i) const { return data[i]; }
	T& operator[](size_t i) { return data[i]; }
};

// �������� ���� ��� ��������� �������� �� ������� �������� ����
// ���� ���� ��������� ����� ���� ��������� �� �������� �����
template <class T, size_t N, class L, class R> class VectorSum {
	const L& left;
	const R& right;
public:
	VectorSum(const L& lh, const R& rh): left(lh), right(rh) {}
	T operator[](size_t i) const { return left[i]+right[i]; }
};

// ����� ����� ����������� �������� ��������� ����� Vector
template <class T, size_t N> template <class L, class R>
Vector<T,N>& Vector<T,N>::operator =(const VectorSum<T,N,L,R> &S)
{
	for (size_t i=0; i<N; ++i) data[i] = S[i];
	return *this;
}

// ��������� ��������� ��������� �� ������� ������� �������
// ��� �������� - ������������� ��'���� � ����������� �� �������
template <class T, size_t N> inline VectorSum<T, N, Vector<T,N>, Vector<T,N> > 
operator+(const Vector<T,N>& lh, const Vector<T,N>& rh)
{
	return VectorSum<T, N, Vector<T,N>, Vector<T,N> >(lh,rh);
}
template <class T, size_t N, class L, class R> inline VectorSum<T, N, VectorSum<T,N,L,R>, Vector<T,N> > 
operator+(const VectorSum<T,N,L,R>& S, const Vector<T,N>& V)
{
	return VectorSum<T, N, VectorSum<T,N,L,R>, Vector<T,N> >(S,V);
}

// ������� ������� ��� ��������� �� ��������� �������
template <class T, size_t N> void init(Vector<T,N>& V)
{
	for (size_t i=0; i<N; ++i) V[i] = rand() % 100;
}
template <class T, size_t N> void print(const Vector<T,N>& V)
{
	for (size_t i=0; i<N; ++i) cout << ' ' << V[i];
	cout << endl;
}

int main()
{
	srand(time(0));
	Vector<int,5> A; init(A); cout << "\nA = "; print(A);
	Vector<int,5> B; init(B); cout << "\nB = "; print(B);
	Vector<int,5> C; C = A+B; cout << "\nA+B = "; print(C);
	Vector<int,5> D; D=A+B+C; cout << "\nA+B+C = "; print(D);
	Vector<int,5> E; E = A + B + C + D; cout << "\nA+B+C+D = "; print(E);
	return 0;
}