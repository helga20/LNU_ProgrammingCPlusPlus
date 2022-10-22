//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	// складові частини майбутнього привітання
	char a[] = "Hello";
	cout << a << endl;
	char b[] = "World";
	cout << b << endl;
	// резервуємо місце під цілу фразу
	char c[20] = {'\0'};
#ifdef _CRT_SECURE_NO_WARNINGS
	// копіюємо перше слово
	strcpy(c, a);
	// дописуємо продовження
	strcat(c, ", ");
	strcat(c, b);
	// потенційно небезпечна заміна останнього елемента рядка
	size_t n = strlen(c);
	c[n] = '!';
#else
	// копіюємо перше слово
	strcpy_s(c, a);
	// дописуємо продовження
	strcat_s(c, ", ");
	strcat_s(c, b);
	// потенційно небезпечна заміна останнього елемента рядка
	size_t n = strlen(c);
	c[n] = '!';
	c[n + 1] = '\0';
#endif
	cout << c << endl;
	system("pause");
	// останній штрих - зробити друге слово великими літерами
	char * pos = strchr(c, 'W');
	// перший спосіб - вручну, політерно
	/*while (*pos != '!')
	{
		*pos = toupper(*pos);
		++pos;
	}*/
	// другий спосіб - за допомогою стандартної функції
#ifdef _CRT_SECURE_NO_WARNINGS
	_strupr(pos);
#else
	_strupr_s(pos, 10);
#endif
	cout << c << endl;
	system("pause");
	return 0;
}