#pragma once
#include <iostream>
namespace std
{
	template<typename F, typename S>
	ostream& operator<<(ostream& os, const pair<F, S>& p)
	{
		return os << p.first << " : " << p.second;
	}
}
//template<typename F, typename S>
//std::ostream& operator<<(std::ostream& os, const std::pair<F, S>& p)
//{
//	return os << p.first << " : " << p.second;
//}

char replaceNotAlpha(char c);

void MapWordCount();
void MultisetWordCount();
