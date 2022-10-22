#include "BearCorner.h"
#include "SnackBar.h"
#include "politics.h"

class MixedUpTraits
{
public:
	typedef Cage place_type;
	typedef Milk beverage_type;
	typedef Honey snack_type;
};
class HelthTraits
{
public:
	typedef Carpet place_type;
	typedef Water beverage_type;
	typedef Bread snack_type;
};

int main()
{
	// різноманітні гості закусочних
	Boy boy("Mathew");
	Boy yogi;
	Bear A(3);
	Bear B;
	Predator D;
	// швидке створення закусочних відповідно до типу гостя
	BearCorner<Boy> C1(boy);
	BearCorner<Bear> C2(A);
	BearCorner<Boy, HelthTraits> C3(yogi);
	BearCorner<Bear, MixedUpTraits> C4(B);
	BearCorner<Predator> C5(D);
	// випробування закусочних в дії
	C1.entertain();
	C2.entertain();
	C3.entertain();
	C4.entertain();
	C5.entertain();
	std::cout << '\n';
	// ще один різновид закусочних з налаштуванням поведінки
	SnackBar<Boy,Feed> R1(boy);
	SnackBar<Bear,Stuff> R2(B);
	R1.entertain();
	R2.entertain();
	system("pause");
	return 0;
}