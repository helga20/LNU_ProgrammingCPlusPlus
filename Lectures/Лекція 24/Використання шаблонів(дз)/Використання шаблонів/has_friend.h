//#pragma once
//
//template <typename T> class Beta
//{
//	// містить два значення, вміє їх друкувати, виконувати обчислення
//private:
//	// попереднє оголошення шаблона класу
//	template <typename V> class Hold;
//	// використання цього шаблона
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
//		// шаблоний метод, тип результату залежить від типу першого параметра
//		template <typename U> U calc(U u, T t);
//};
//// визначення попередньо оголошеного шаблона класу
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
//// визначення шаблона методу
//template <typename T> template <typename U>
//U Beta<T>::calc(U u, T t)
//{
//	return (n.value() * u + q.value()) * t;
//}
//
////// Шаблон класу з нешаблонними дружніми функціями
////template <class T> class HasFriend
////{
////	friend void counts(); // дружня до ВСІХ спеціалізацій
////	// звичайна функція з шаблонним параметром
////	// у програмі потрібно оголосити по одній такій функції для кожної зі спеціалізацій
////	// шаблона HasFriend<тип>, отримаємо декілька перевантажених функцій, кожна з яких
////	// дружня до «своєї» спеціалізації
////	friend void report(HasFriend<T>&);
////	...
////};
////// Шаблон класу з пов’язаними дружніми шаблонами функцій
////// 1. Попереднє оголошення шаблонів функцій
////template <typename T> void counts();
////template <typename T> void report(T&); 
////// 2. Визначення шаблона класу з дружніми функціями
////template <typename TT>
////class HasFriendT
////{
////	// спеціалізація шаблона count типом шаблона HasFriendT
////	friend void counts<TT>();
////	// спеціалізація шаблона report, тип шаблона HasFriendT виводиться компілятором
////	friend void report<>(HasFriend<TT>&);
////	...
////};
////// 3. Визначення шаблонів функцій
////template <typename T> void counts()
////{
////	...
////}
////// Шаблон класу і дружній шаблон функції, не пов’язаний типом
////template <typename TT>
////class ManyFriend
////{
////	// кожна спеціалізація функції дружня до кожної спеціалізації класу
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