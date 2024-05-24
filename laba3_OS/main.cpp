#include "binTree.h"

#include <iostream>

int main() {
	try {
		std::cout << "\nTEST 1" << std::endl;

		BinTree tree;

		tree.addNode('k', 50);
		tree.addNode('K', 58);
		tree.addNode('k', 42);
		tree.addNode('P', 23);
		tree.addNode('n', 11);
		tree.addNode('h', 34);
		tree.addNode('K', 45);
		tree.addNode('N', 87);
		tree.addNode('k', 99);
		tree.addNode('h', 67);
		tree.addNode('G', 25);
		tree.addNode('p', 29);
		tree.addNode('P', 60);
		tree.addNode('P', 24);
		tree.addNode('p', 70);
		tree.addNode('P', 80);
		tree.addNode('p', 90);
		tree.addNode('k', 12);
		tree.addNode('e', 34);
		tree.addNode('R', 67);

		std::cout << "\nInitial tree:\n" << std::endl;
		tree.printBinTree();
		std::cout << "\n";
		tree.print();

		std::cout << "\n\n\nDeleting an identifier [N11]\n" << std::endl;
		tree.deleteNode('n', 11);
		tree.printBinTree();
		std::cout << "\n";
		tree.print();

		std::cout << "\n\n\nDeleting an identifier [P29]\n" << std::endl;
		tree.deleteNode('p', 29);
		tree.printBinTree();
		std::cout << "\n";
		tree.print();

		std::cout << "\n\n\nDeleting an identifier [K42]\n" << std::endl;
		tree.deleteNode('k', 42);
		tree.printBinTree();
		std::cout << "\n";
		tree.print();

		std::cout << "\n\n\nAdding an identifier [U19]\n" << std::endl;
		tree.addNode('U', 19);
		tree.printBinTree();
		std::cout << "\n";
		tree.print();

		std::cout << "\n\n\nAdding an identifier [K33]\n" << std::endl;
		tree.addNode('k', 33);
		tree.printBinTree();
		std::cout << "\n";
		tree.print();

		std::cout << "\n\n\nSearching an identifier [P23]\n" << std::endl;
		tree.findNodeByIdentifier('p', 23);
		std::cout <<"\n\n";
		tree.printBinTree();
		std::cout << "\n";
		tree.print();

		std::cout << "\n\n\nSearching an identifier [U19]\n" << std::endl;
		tree.findNodeByIdentifier('u', 19);
		std::cout << "\n\n";
		tree.printBinTree();
		std::cout << "\n";
		tree.print();

//-----------------------------------------------------------------------------------------------
		std::cout << "\n\n\n\nTEST 2" << std::endl;

		tree.~BinTree();

		tree.addNode('a', 10);
		tree.addNode('b', 15);
		tree.addNode('c', 20);
		tree.addNode('d', 25);
		tree.addNode('e', 30);
		tree.addNode('f', 35);
		tree.addNode('g', 40);
		tree.addNode('h', 45);
		tree.addNode('i', 50);
		tree.addNode('j', 55);
		tree.addNode('a', 12);
		tree.addNode('b', 14);
		tree.addNode('c', 16);
		tree.addNode('d', 18);
		tree.addNode('e', 22);
		tree.addNode('f', 24);
		tree.addNode('g', 26);
		tree.addNode('h', 28);
		tree.addNode('i', 17);
		tree.addNode('j', 13);

		std::cout << "\nInitial tree:\n" << std::endl;
		tree.printBinTree();
		std::cout << "\n";
		tree.print();

		std::cout << "\n\n\nAdding an identifier [A12]\n" << std::endl;
		tree.addNode('a', 12);
		tree.printBinTree();
		std::cout << "\n";
		tree.print();

		std::cout << "\n\n\nDeleting an identifier [A99]\n" << std::endl;
		tree.deleteNode('a', 99);
		tree.printBinTree();
		std::cout << "\n";
		tree.print();

		std::cout << "\n\n\nAdding an identifier [f53]\n" << std::endl;
		tree.addNode('f', 53);
		tree.printBinTree();
		std::cout << "\n";
		tree.print();

		std::cout << "\n\n\nDeleting an identifier [C20]\n" << std::endl;
		tree.deleteNode('c', 20);
		tree.printBinTree();
		std::cout << "\n";
		tree.print();

		std::cout << "\n\n\nSearching an identifier [U19]\n" << std::endl;
		tree.findNodeByIdentifier('u', 19);
		std::cout << "\n";
		tree.printBinTree();
		std::cout << "\n";
		tree.print();

		std::cout << "\n\n\nSearching an identifier [B14]\n" << std::endl;
		tree.findNodeByIdentifier('b', 14);
		std::cout << "\n\n";
		tree.printBinTree();
		std::cout << "\n";
		tree.print();

		std::cout << "\n\n\n";
		return 0;
	}
	catch (const std::exception &ex) {
		std::cout << ex.what();
		std::terminate;
	}
}
