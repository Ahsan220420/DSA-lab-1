#include <iostream>
#include "BST.h"

int main() {
	BST<int> tree;

	int insertValues[] = { 50, 30, 70, 20, 40, 60, 80 };
	int n = sizeof(insertValues) / sizeof(insertValues[0]);

	for (int i = 0; i < n; i++) {
		tree.insert(insertValues[i]);
	}

	std::cout << "After Insertion: ";
	tree.displayInorder();

	tree.remove(70);

	std::cout << "After Deletion:  ";
	tree.displayInorder();

	return 0;
}