#include "ShapesList.h"

// ��������� ����� - ��������� �������� �� ������� �����
void ShDblList::moveCurr(int i) const
{
	while (i > index)
	{
		curr = curr->next;
		++index;
	}
	while (i < index)
	{
		curr = curr->prev;
		--index;
	}
}
// ����������� ��������� ������ "������������" ��������� �� ������������� ������� *��������*
ShDblList::ShDblList(const ShDblList & A) : len(0), index(-1), mem(new Node())
{
	curr = bottom = mem;
	Node* toCopy = A.mem->next;
	while (toCopy != nullptr)
	{
		this->put(toCopy->shape->clone());
		toCopy = toCopy->next;
	}
}


// ��������� - ������� ���� ��������� ��������, ���� ����� � ��:
// ������ ����� �����, ���������� ����� ����� ������
ShDblList::~ShDblList()
{
	Node* victim;
	while (mem != nullptr)
	{
		victim = mem;
		mem = mem->next;
		delete victim;
	}
}

// ��������� ������ � ���� ������
ShDblList& ShDblList::put(VolShape* s)
{
	this->bottom->next = new Node(s, this->bottom);
	this->bottom = this->bottom->next;
	++len;
	return *this;
}

// ����� ���������� ���� ������ ��������� ����������
// �� ����������� ������� ���������� �������������� �������
ShDblList& ShDblList::insert(VolShape* s, int i)
{
	this->chekIndex(i);
	this->moveCurr(i);
	Node* newNode = new Node(s, curr->prev, curr);
	curr->prev->next = newNode;
	curr->prev = newNode;
	curr = newNode;
	++len;
	return *this;
}

// ����� ��������� ��������� �������� ���������� �� ���� �������
// ��� ������������ ����� �������������� �������
ShDblList& ShDblList::remove(int i)
{
	this->chekIndex(i);
	this->moveCurr(i);
	if (bottom == curr) bottom = bottom->prev;
	Node* victim = curr;
	curr = victim->prev;
	--index;
	curr->next = victim->next;
	curr->next->prev = victim->prev;
	delete victim;
	--len;
	return *this;
}

// ������� ������ �� ����������� (����������) �����
ShDblList& ShDblList::clear()
{
	Node* victim;
	while (mem->next != nullptr)
	{
		victim = mem->next;
		mem->next = victim->next;
		delete victim;
	}
	len = 0;
	index = -1;
	curr = bottom = mem;
	return *this;
}

// �������� ��������� ������� ������ ���������� �� ���������
// �� ������ �� �������������
ShDblList& ShDblList::operator=(const ShDblList& A)
{
	if (this != &A)
	{
		this->clear();
		Node* toCopy = A.mem->next;
		while (toCopy != nullptr)
		{
			this->put(toCopy->shape->clone());
			toCopy = toCopy->next;
		}
		this->moveCurr(A.index);
	}
	return *this;
}

// �������� ���� ������ ��� "�������-������" �� ������� �������� ����������
VolShape*& ShDblList::operator[](int i)
{
	this->chekIndex(i);
	this->moveCurr(i);
	return curr->shape;
}

// �������� ��� ������� �������� ������������ ����������
const VolShape* ShDblList::operator[](int i) const
{
	this->chekIndex(i);
	this->moveCurr(i);
	return curr->shape;
}

// ����� ��������� � ����� ���������� ��� ��'��� ������
// ������ ����� �� ���� ����������
void ShDblList::loadFrom(std::ifstream& fin)
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
		len = i;
		throw;
	}
}

void ShDblList::printOn(ostream& os) const
{
	if (len==0) os << "Empty List of VolumeShapes\n";
	else
	{
		os << "List of " << len << " VolumeShapes:\n";
		Node* toPrint = mem->next;
		while (toPrint != nullptr)
		{
			os << *(toPrint->shape) << '\n';
			toPrint = toPrint->next;
		}
		os << "---\n";
	}
}

void ShDblList::storeOn(ofstream& fout) const
{
	fout << len << '\n';
	Node* toStore = mem->next;
	while (toStore != nullptr)
	{
		toStore->shape->storeOn(fout);
		fout << '\n';
		toStore = toStore->next;
	}
}

// ������� ������ �������� �������� ����������
void ShDblList::doEach(Action f) const
{
	Node* toAct = mem->next;
	while (toAct != nullptr)
	{
		f(toAct->shape);
		toAct = toAct->next;
	}
}

int ShDblList::detectFirst(Predicate condition) const
{
	int i = 0;
	Node* toDetect = mem->next;
	while (toDetect != nullptr)
	{
		if(condition(toDetect->shape)) break;
		toDetect = toDetect->next;
		++i;
	}
	return i;
}