#include "ShapesArray.h"

// виділення більшої пам'яті для масиву, що зростає
void ShArray::checkMem()
{
	if (used == size)
	{
		size *= 2;
		VolShape** newMem = new VolShape*[size];
		for (int i=0; i<used; ++i) newMem[i] = mem[i];
		delete [] mem;
		mem = newMem;
	}
}

// конструктор копіювання виконує "суперглибоке" копіювання

//ShArray::ShArray(const ShArray & A): used(A.used), size(A.used), mem(new VolShape*[A.used])
//{
//	for (int i=0; i<used; ++i) mem[i] = VolShape::CopyInstance(A.mem[i]);
//}

// ТЕ САМЕ ІЗ ЗАСТОСУВАННЯМ ШАБЛОНУ *ПРОТОТИП*
ShArray::ShArray(const ShArray & A): used(A.used), size(A.used), mem(new VolShape*[A.used])
{
	for (int i=0; i<used; ++i) mem[i] = A.mem[i]->clone();
}


// контейнер - власник своїх динамічних елементів, тому знищує і їх
ShArray::~ShArray()
{
	for (int i=0; i<used; ++i) delete mem[i];
	delete [] mem;
}

ShArray& ShArray::put(VolShape* s)
{
	this->checkMem();
	mem[used++] = s;
	return *this;
}

// метод вставляння нової фігури всередину контейнера
// по неправильну позицію вставляння сигналізуватиме виняток
ShArray& ShArray::insert(VolShape* s, int i)
{
	this->chekIndex(i);
	this->checkMem();
	for (int j=used; j>i; --j) mem[j] = mem[j-1];
	mem[i] = s;
	++used;
	return *this;
}

// метод вилучення довільного елемента контейнера за його номером
// про неправильний номер сигналізуватиме виняток
ShArray& ShArray::remove(int i)
{
	this->chekIndex(i);
	delete mem[i];
	for (int j=i+1; j<used; ++j) mem[j-1] = mem[j];
	--used;
	return *this;
}

ShArray& ShArray::clear()
{
	for (int i=0; i<used; ++i) delete mem[i];
	used = 0;
	return *this;
}

// оператор присвоєння порівнює адреси отримувача та аргумента
// це захист від самоприсвоєння
ShArray& ShArray::operator=(const ShArray& A)
{
	if (this != &A)
	{
		this->clear();
		delete [] mem;
		used = A.used;
		size = A.used;
		mem = new VolShape*[used];
		for (int i=0; i<used; ++i) mem[i] = A.mem[i]->clone();
	}
	return *this;
}

// оператор надає доступ для "читання-запису" до наявних елементів контейнера
VolShape*& ShArray::operator[](int i)
{
	this->chekIndex(i);
	return this->mem[i];
}
// оператор для читання елементів константного контейнера
const VolShape* ShArray::operator[](int i) const
{
	this->chekIndex(i);
	return this->mem[i];
}
// метод завантажує з файла інформацію про об'ємні фігури
// формат даних має бути правильним
void ShArray::loadFrom(std::ifstream& fin)
{
	this->clear();
	int k, i; fin >> k;
	// якщо ім'я класу у файлі задано неправильно, станеться виняток
	try
	{
		for (i = 0; i < k; ++i) this->put(VolShape::MakeInstance(fin));
	}
	// можемо частково опрацювати цей виняток: правильно задати розмір контейнера
	// далі - повторний запуск, щоб користувач вирішував, що робити ще
	catch (VolShape::BadClassname&)
	{
		used = i;
		throw;
	}
}

void ShArray::printOn(ostream& os) const
{
	if (used==0) os << "Empty Array of VolumeShapes\n";
	else
	{
		os << "Array of " << used << " VolumeShapes:\n";
		for (int i=0; i<used; ++i) os << *mem[i] << '\n';
		os << "---\n";
	}
}

void ShArray::storeOn(ofstream& fout) const
{
	fout << used << '\n';
	for (int i=0; i<used; ++i)
	{
		mem[i]->storeOn(fout);
		fout << '\n';
	}
}

// загальні методи перебору елементів контейнера
void ShArray::doEach(Action f) const
{
	for (int i=0; i<used; ++i) f(mem[i]); 
}

int ShArray::detectFirst(Predicate condition) const
{
	int i = 0;
	for ( ; i<used; ++i)
		if (condition(mem[i])) break;
	return i;
}