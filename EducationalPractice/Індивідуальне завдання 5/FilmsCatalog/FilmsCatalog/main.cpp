#include <iostream>
#include <string>
#include "list.h"
#include "film.h"
#include "filmsCatalog.h"
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    List<string> myList;
    myList.isEmpty();
    myList.getLength();
    cout << "\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n\n";

    myList.push_front("���-11");
    myList.push_front("�����");
    myList.push_front("�������");
    myList.printList();
    myList.getLength();
    cout << "\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n\n";

    cout << "\n����������� ���������\n";
    List<string> list2(myList);
    list2.printList();
    cout << "\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n\n";

    myList.Front();
    myList.pop_front();
    myList.printList();
    myList.isEmpty();
    myList.getLength();
    cout << "\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n\n";

    myList.push_back("���������");
    myList.push_back("����������");
    myList.push_back("�");
    myList.push_back("�����������");
    myList.printList();
    myList.isEmpty();
    myList.getLength();
    cout << "\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n\n";

    myList.Back();
    myList.pop_back();
    myList.Back();
    myList.pop_back();
    myList.printList();
    myList.isEmpty();
    myList.getLength();

    cout << "\n";
    system("pause");
    cout << "\n_________________________________________\n\n\n";

    Film F1;
    Film F2("³�����", "�������", 6.3);
    Film F3("ʳ�����", "��������", 23.2);
    Film F4(F2);
    Film F5;
    //F5.readFilm();

    cout << "\n�� ������:\n";
    F1.printFilmInfo();
    F2.printFilmInfo();
    F3.printFilmInfo();
    F4.printFilmInfo();
    F5.printFilmInfo();

    cout << "\n";
    system("pause");
    cout << "\n_________________________________________\n\n\n";

    Film PC("�������", "����", 15);
    Film CZK("���������_�������", "��������", 19);
    Film KC("ʳ�����", "��������", 23.2);
    PC.printFilmInfo();
    CZK.printFilmInfo();
    KC.printFilmInfo();
    cout << "\n";

    List<Film> myFilms;
    myFilms.push_back(PC);
    myFilms.push_front(CZK);
    myFilms.push_back(KC);
    myFilms.printList();
    cout << "\n\n";

    FilmsCatalog UkrainianFilms("������");
    UkrainianFilms.addFilm(PC);
    UkrainianFilms.addFilm(CZK);
    UkrainianFilms.addFilm(KC);
    UkrainianFilms.printFilmsCatalogInfo();

    UkrainianFilms.readFromFile("catalog.txt");
    UkrainianFilms.printFilmsCatalogInfo();
    UkrainianFilms.totalPrice();
    cout << "\n������� �������: " << UkrainianFilms.averagePrice();
    //UkrainianFilms.getFilmWithMaxPrice();

    cout << "\n";
    system("pause");
    return 0;
}

