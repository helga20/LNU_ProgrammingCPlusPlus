//#pragma once
//
//template <typename T> class Beta
//{
//	// ������ ��� ��������, �쳺 �� ���������, ���������� ����������
//private:
//	// �������� ���������� ������� �����
//	template <typename V> class Hold;
//	// ������������ ����� �������
//	Hold<T> q;
//	Hold<int> n;
//public:
//	Beta(T t, int i) :q(t), n(i) {}
//	void Show() const
//	{
//		q.show(); n.show();
//		template<typename U>
//		U calc(U u, T t);
//	}7
//		// �������� �����, ��� ���������� �������� �� ���� ������� ���������
//		template <typename U> U calc(U u, T t);
//};
//// ���������� ���������� ����������� ������� �����
//template <typename T> template <typename V>
//class Beta<T>::Hold
//{
//private:
//	V val;
//public:
//	Hold(V v = V()) :val(v) {}
//	void show() const { std::cout << val << '\t'; }
//	V value() const { return val; }
//};
//// ���������� ������� ������
//template <typename T> template <typename U>
//U Beta<T>::calc(U u, T t)
//{
//	return (n.value() * u + q.value()) * t;
//}
//
////// ������ ����� � ������������ ������� ���������
////template <class T> class HasFriend
////{
////	friend void counts(); // ������ �� �Ѳ� ������������
////	// �������� ������� � ��������� ����������
////	// � ������� ������� ��������� �� ���� ���� ������� ��� ����� � ������������
////	// ������� HasFriend<���>, �������� ������� �������������� �������, ����� � ����
////	// ������ �� ���� ������������
////	friend void report(HasFriend<T>&);
////	...
////};
////// ������ ����� � ���������� ������� ��������� �������
////// 1. �������� ���������� ������� �������
////template <typename T> void counts();
////template <typename T> void report(T&); 
////// 2. ���������� ������� ����� � ������� ���������
////template <typename TT>
////class HasFriendT
////{
////	// ������������ ������� count ����� ������� HasFriendT
////	friend void counts<TT>();
////	// ������������ ������� report, ��� ������� HasFriendT ���������� �����������
////	friend void report<>(HasFriend<TT>&);
////	...
////};
////// 3. ���������� ������� �������
////template <typename T> void counts()
////{
////	...
////}
////// ������ ����� � ������ ������ �������, �� ��������� �����
////template <typename TT>
////class ManyFriend
////{
////	// ����� ������������ ������� ������ �� ����� ������������ �����
////	template <typename C, typename D> friend void show2(C&, D&);
////	...
////};
//
//
//#include <iostream>
//
//template<typename T>
//class TRational {
//	T n;
//public:
//	explicit TRational(int n_) : n(n_) {}
//
//	template<typename U>
//	friend bool operator == (const TRational<U>& lObj, const TRational<U>& rObj);
//};
//
//template<typename U>
//bool operator == (const TRational<U>& lObj, const TRational<U>& rObj)
//{
//	return lObj.n == rObj.n;
//}
//
//int main()
//{
//	TRational<int> a(1);
//	TRational<int> b(1);
//	TRational<int> c(2);
//
//	std::cout << (a == b) << ", " << (a == c);
//
//	return 0;
//}