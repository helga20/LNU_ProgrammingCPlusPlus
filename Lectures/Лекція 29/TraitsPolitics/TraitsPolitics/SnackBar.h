#ifndef _SnackBar_H_
#define _SnackBar_H_

#include "guests.h"

template <class Guest, class Action, 
		class Traits = GuestTraits<Guest> >
class SnackBar
{
// різновид закладу харчування, що уточнює СПОСІБ обслуговування гостей
// вважається, що цей спосіб задано статичним методом класу Action
	typedef typename Traits::beverage_type beverage_type;
	typedef typename Traits::snack_type snack_type;
	Guest theGuest;
	beverage_type bev;
	snack_type snack;
public:
	SnackBar(const Guest& g): theGuest(g) {}
	void entertain()
	{
		std::cout << "*SnackBar*   " << Action::doAction() << ' ' 
			<< theGuest << " serving " << bev << " and " << snack << '\n';
	}
};

#endif