#include "stepProcedures.h"

void average()
{
	cout << "\n *Середнє арифметичне послідовності дійсних чисел з термінальним елементом*\n\n"
		<<"Введіть послідовність чисел, що закінчується нулем:\n";
	unsigned k = 0;
	double s = 0.0;
	double a; cin >> a;
	while (a != 0.0)
	{
		s += a;
		++k;
		cin >> a;
	}
	if (k == 0) cout << "Послідовність починається нулем\n";
	else cout << "Середнє арифметичне = " << s / k << '\n';
	return;
}