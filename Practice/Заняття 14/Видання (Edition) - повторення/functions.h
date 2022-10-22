#pragma once
#include "edition.h"

void printEditions(const Edition* arr, int n);
void printEditionsByAuthor(const Edition *arr, int n, const std::string& authorName);
void printEditionsByPagePrice(const Edition* arr, int n, double pagePrice);

double totalPrice(const Edition* arr, int n);
const Edition &findMostExpensiveEdition(const Edition* arr, int n);
int findCheapestEditionByPagePrice(const Edition* arr, int n);

void sortByPrice(Edition* arr, int n);
void sortByAuthor(Edition* arr, int n);