#include <iostream>
#include <algorithm>
#include <vector>
#include "../Tree.hpp"
#define SIZE 10
using namespace std;

int main()
{
	chain c(SIZE);
	c.construct();
	for (auto i:c.getEdges()) {
		cout << i.first << " " << i.second << "\n";
	}
}