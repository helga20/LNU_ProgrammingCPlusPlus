#ifndef _ASSOFILLGENN
#define _ASSOFILLGENN

template<class Assoc, class Count, class T>
void as_fill_n(Assoc& a, Count n, const T& val)
{
	while (n-- > 0) a.insert(val);
}

template<class Assoc, class Count, class Gen>
void as_generate_n(Assoc& a, Count n, Gen g)
{
	while (n-- > 0) a.insert(g());
}

#endif