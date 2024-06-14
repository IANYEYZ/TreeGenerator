#include <iostream>
#include <algorithm>
#include <vector>
#include "../Tree.hpp"
#define SIZE 10
using namespace std;

int main()
{
	randomTree c(10);
	c.construct();
	for (auto i:c.getEdges()) {
		cout << i.first << " " << i.second << "\n";
	}
}