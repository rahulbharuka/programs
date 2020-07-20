#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> arr = {1, 2, 3, 4};

	vector<int> *v = &arr; 

	printf("size = %lu\n", arr.size());
	printf("size = %lu\n", v->size());
}
