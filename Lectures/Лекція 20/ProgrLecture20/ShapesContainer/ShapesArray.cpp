#include "ShapesArray.h"

// �������� ����� ���'�� ��� ������, �� ������
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

// ����������� ��������� ������ "������������" ���������

//ShArray::ShArray(const ShArray & A): used(A.used), size(A.used), mem(new VolShape*[A.used])
//{
//	for (int i=0; i<used; ++i) mem[i] = VolShape::CopyInstance(A.mem[i]);
//}

// �� ���� �� ������������� ������� *��������*
ShArray::ShArray(const ShArray & A): used(A.used), size(A.used), mem(new VolShape*[A.used])
{
	for (int i=0; i<used; ++i) mem[i] = A.mem[i]->clone();
}


// ��������� - ������� ���� ��������� ��������, ���� ����� � ��
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

// ����� ���������� ���� ������ ��������� ����������
// �� ����������� ������� ���������� �������������� �������
ShArray& ShArray::insert(VolShape* s, int i)
{
	this->chekIndex(i);
	this->checkMem();
	for (int j=used; j>i; --j) mem[j] = mem[j-1];
	mem[i] = s;
	++used;
	return *this;
}

// ����� ��������� ��������� �������� ���������� �� ���� �������
// ��� ������������ ����� �������������� �������
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

// �������� ��������� ������� ������ ���������� �� ���������
// �� ������ �� �������������
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

// �������� ���� ������ ��� "�������-������" �� ������� �������� ����������
VolShape*& ShArray::operator[](int i)
{
	this->chekIndex(i);
	return this->mem[i];
}
// �������� ��� ������� �������� ������������ ����������
const VolShape* ShArray::operator[](int i) const
{
	this->chekIndex(i);
	return this->mem[i];
}
// ����� ��������� � ����� ���������� ��� ��'��� ������
// ������ ����� �� ���� ����������
void ShArray::loadFrom(std::ifstream& fin)
{
	this->clear();
	int k, i; fin >> k;
	// ���� ��'� ����� � ���� ������ �����������, ��������� �������
	try
	{
		for (i = 0; i < k; ++i) this->put(VolShape::MakeInstance(fin));
	}
	// ������ �������� ���������� ��� �������: ��������� ������ ����� ����������
	// ��� - ��������� ������, ��� ���������� ��������, �� ������ ��
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

// ������� ������ �������� �������� ����������
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