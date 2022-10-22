#ifndef _LOOPS_PROCEDURES_GUARD_
#define _LOOPS_PROCEDURES_GUARD_

#include <iostream>
using std::cout;
using std::cin;

void unitaryMatrix();
void symmetricBuildMatrix();
void triangleMatrix();
void matrixFromSequence();
void sequenceToMatrix();
void regionsSumming();
void economySumming();
void moveMax();
void saddleElement();

int** createMatrix(int n);
void printMatrix(int** a, int n);
void eraseMatrix(int ** a);

#endif