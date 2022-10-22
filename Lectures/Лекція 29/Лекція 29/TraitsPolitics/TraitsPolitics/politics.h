#ifndef _POLITICS_H_
#define _POLITICS_H_

// класи ПОЛІТИК інкапсулюють функціональність
class Feed
{
public:
	static const char * doAction() { return "Feeding"; }
};
class Stuff
{
public:
	static const char * doAction() { return "Stuffing"; }
};

#endif