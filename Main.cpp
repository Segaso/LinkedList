#include "LinkedList.h"

int main()
{
	LinkedList<int> List;

	List.Add(1);
	List.Add(3);
	List.Add(10);
	List.Add(5);

	int test = List[0];
	List.Remove(1);

	return 0;
}