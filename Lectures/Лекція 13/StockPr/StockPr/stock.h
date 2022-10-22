#pragma once

class Stock
{
private:
	enum { Len = 30 };
	char company[Len];          // назва компанії
	int shares;                 // кількість акцій в пакеті
	double share_val;           // ціна однієї акції
	double total_val;           // загальна ціна пакета
	static Stock default_stock; // готовий об'єкт - пакет акцій деякої фіксованої компанії
	static int Counter;         // лічильник створених об'єктів
	void set_tot() { total_val = shares * share_val; } // метод обчислення ціни пакету
public:
	Stock();      // конструктор за замовчуванням використовує значення default_stock
	Stock(const char* co, int n, double pr); // конструктор з параметрами
	~Stock();     // деструктор
	Stock& buy(int num, double price);  // метод купівлі num акцій за ціною price
	Stock& sell(int num, double price); // метод продажу num акцій за ціною price
	void update(double price);          // метод зміни ціни однієї акції
	void show() const;                  // метод виведення об'єкта на консоль
	const Stock& topval(const Stock& s) const;  // порівняння двох пакетів: метод повертає більшого
	static void set_default(const char*,int,double); // задання фіксованого пакету акцій
	static int getCounter()  { return Counter; }     // отримання інформації про кількість створених
};