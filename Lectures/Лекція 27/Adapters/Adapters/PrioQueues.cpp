#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <queue>
#include <functional>
using namespace std;

template <typename T>
class PQI : public priority_queue<T>
{
public:
	vector<T>& impl() { return c; }
};
template <typename T>
void writeQueue(T& pq)
{
	while (!pq.empty())
	{
		cout << pq.top() << '\t';
		pq.pop();
	}
	cout << '\n';
}
class Compare
{
public:
	bool operator()(int a, int b)
	{
		return a > b;
	}
};
int main()
{
	srand(time(0));
	priority_queue<int> pq1;
	priority_queue<int, vector<int>, greater<int> > pq2;
	priority_queue<int, vector<int>, Compare > pqC;
	PQI<int> pq3;
	for (int i=0; i<100; ++i)
	{
		int x=rand()%25;
		pq1.push(x); pq2.push(x), pq3.push(x); pqC.push(x);
	}
	cout << "Greater priority queue\n";
	writeQueue(pq2);
	cout << "\n\nUsual (less) priority queue\n";
	writeQueue(pq1);
	cout << "\n\nContainer of child priority queue\n";
	copy(pq3.impl().begin(),pq3.impl().end(),ostream_iterator<int>(cout,"\t"));
	cout << "\n\nChild (less) priority queue\n";
	writeQueue(pq3);
	writeQueue(pqC);
	cout<<endl;
	return 0;
}
/*
Greater priority queue
0       0       0       0       0       0       1       1       1       1
1       1       1       2       2       2       2       3       3       3
3       4       4       4       4       5       5       5       6       6
6       6       6       7       7       8       8       9       9       9
9       9       10      10      10      11      11      12      12      12
12      12      12      13      13      13      13      13      13      13
14      14      14      14      14      14      14      14      14      15
15      15      16      16      16      17      17      17      17      18
18      19      19      19      19      19      19      20      20      20
21      21      21      21      21      22      22      22      24      24



Usual (less) priority queue
24      24      22      22      22      21      21      21      21      21
20      20      20      19      19      19      19      19      19      18
18      17      17      17      17      16      16      16      15      15
15      14      14      14      14      14      14      14      14      14
13      13      13      13      13      13      13      12      12      12
12      12      12      11      11      10      10      10      9       9
9       9       9       8       8       7       7       6       6       6
6       6       5       5       5       4       4       4       4       3
3       3       3       2       2       2       2       1       1       1
1       1       1       1       0       0       0       0       0       0



Container of child priority queue
24      24      22      22      21      21      21      18      22      21
20      19      17      19      14      14      16      20      21      16
20      17      19      18      14      13      15      6       17      13
12      13      12      14      14      12      17      13      19      11
10      16      19      8       12      11      19      14      15      10
9       4       3       2       14      1       0       1       15      0
5       9       10      4       13      3       9       7       13      6
12      2       5       6       14      6       13      4       1       0
9       0       5       3       12      2       8       0       4       1
1       1       6       0       14      1       9       3       7       2


Child (less) priority queue
24      24      22      22      22      21      21      21      21      21
20      20      20      19      19      19      19      19      19      18
18      17      17      17      17      16      16      16      15      15
15      14      14      14      14      14      14      14      14      14
13      13      13      13      13      13      13      12      12      12
12      12      12      11      11      10      10      10      9       9
9       9       9       8       8       7       7       6       6       6
6       6       5       5       5       4       4       4       4       3
3       3       3       2       2       2       2       1       1       1
1       1       1       1       0       0       0       0       0       0
*/