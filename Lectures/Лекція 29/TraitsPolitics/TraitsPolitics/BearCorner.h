#ifndef _BEARCORNER_H_
#define _BEARCORNER_H_

#include "guests.h"

// для гостя кожного типу - відповідний тип закусочної!
// досягаємо за допомогою шаблона класу "закусочна"
template <class Guest, class Traits = GuestTraits<Guest>>
class BearCorner
{ // характеристики гостя можна довідатися з класу Traits
	typedef typename Traits::place_type     place_type;
	typedef typename Traits::beverage_type  beverage_type;
	typedef typename Traits::snack_type     snack_type;
	Guest    theGuest;
	place_type  place;
	beverage_type bev;
	snack_type  snack;
public:
	BearCorner(const Guest& g): theGuest(g) {}
	void entertain()
	{
		std::cout<<"Entertaining " << theGuest << " locating " << place
			<< " serving " << bev << " and " << snack << '\n';
	}
};

#endif