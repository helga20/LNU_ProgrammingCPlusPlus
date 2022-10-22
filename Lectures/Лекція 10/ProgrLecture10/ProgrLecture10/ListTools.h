#pragma once
namespace ListTools
{
	struct Node;
	typedef Node* List_t;
	struct Node
	{
		int value;
		List_t link;
		Node(int x, List_t p = nullptr) :value(x), link(p) {}
	};

	// завантажує з консолі послідовність цілих в звичайному порядку
	List_t readList();
	// завантажує з консолі послідовність цілих в оберненому порядку
	List_t reverseReadList();
	// рекурсивна, завантажує з консолі послідовність цілих в оберненому порядку
	void recursiveReadList(List_t& L);
	// завантажує і впорядковує послідовність цілих чисел
	List_t readSortedList();
	List_t readSortedLst();
	// виводить елементи списку на консоль
	void writeList(List_t L);
	// вилучає з непорожнього списку першу ланку
	int delFirst(List_t& L);
	// вилучає весь список
	void removeList(List_t& List);
	// вставляє число у впорядкований список
	void insert(int x, List_t& L);
	// об'єднує два впорядковані списки (копіює елементи в новий)
	List_t merge(List_t a, List_t b);
}
