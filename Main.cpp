#include "LinkedList.h"
#include <iostream>
int main()
{
	LinkedList<int> List;

	for (int i = 0; i < 100000; i++)
		List.Add(i);

	int test = List[0];

	for (int i = 0; i < 10000; i++)
	std::cout << List[i];	

	std::cin.get();
	return 0;
}