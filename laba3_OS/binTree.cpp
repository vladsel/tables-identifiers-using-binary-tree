#include "binTree.h"

#include <iostream>
#include <iomanip>
#include <vector>

void BinTree::removeTree(Node *branch) {
	if (branch == nullptr)
		return;
	removeTree(branch->getLeft());
	removeTree(branch->getRight());
	if (branch)
		delete branch;
	else
		throw std::exception("\nImpossible to delete branch\n");
	root = nullptr;
	return;
}

Node *BinTree::addNode_private(Node *branch, const char &letter, const size_t &digit) {
	try {
		if (branch == nullptr) {
			branch = new Node(letter, digit);
			return balance(branch);
		}
		if (letter > branch->getLetter()) {
			branch->setRight(addNode_private(branch->getRight(), letter, digit));
		} 
		else if (letter < branch->getLetter()) {
			branch->setLeft(addNode_private(branch->getLeft(), letter, digit));
		} 
		else {
			if (letter == branch->getLetter() && digit > branch->getDigit()) {
				branch->setRight(addNode_private(branch->getRight(), letter, digit));
			} 
			else if (letter == branch->getLetter() && digit < branch->getDigit()) {
				branch->setLeft(addNode_private(branch->getLeft(), letter, digit));
			}
			else
				std::cout << "Identifier with the same name already exists" << std::endl << std::endl;
		}
	}
	catch (const std::exception &ex) {
		std::cout << ex.what() << std::endl;
		std::cout << "\nIdentifier is not added\n";
	}
	return balance(branch);
}

Node *BinTree::deleteNode_private(const char &letter, const size_t &digit, Node *branch, bool &flag) {
	try {
		if (branch == nullptr)
			return balance(branch);
		if (branch->getLetter() == letter && branch->getDigit() == digit) {
			flag = 1;
			Node *nextBranch;
			if (branch->getRight() != nullptr) {
				Node *temp = branch->getRight();
				if (temp->getLeft() != nullptr) {
					Node *tempMin = temp->getLeft();
					while (tempMin->getLeft() != nullptr) {
						temp = tempMin;
						tempMin = temp->getLeft();
					}
					temp->setLeft(tempMin->getRight());
					tempMin->setLeft(branch->getLeft());
					tempMin->setRight(branch->getRight());
					nextBranch = tempMin;
					return balance(nextBranch);
				}
				else {
					temp->setLeft(branch->getLeft());
					nextBranch = temp;
				}
			}
			else
				nextBranch = branch->getLeft();
			delete branch;
			return nextBranch;
		}
		else if (branch->getLetter() > letter)
			branch->setLeft(deleteNode_private(letter, digit, branch->getLeft(), flag));
		else if (branch->getLetter() < letter)
			branch->setRight(deleteNode_private(letter, digit, branch->getRight(), flag));
		else {
			if (branch->getLetter() == letter && branch->getDigit() > digit)
				branch->setLeft(deleteNode_private(letter, digit, branch->getLeft(), flag));
			else if (branch->getLetter() == letter && branch->getDigit() < digit)
				branch->setRight(deleteNode_private(letter, digit, branch->getRight(), flag));
		}
	}
	catch (const std::exception &ex) {
		std::cout << ex.what() << std::endl;
		std::cout << "\nIdentifier is not deleted\n";
	}
	return branch;
}

void BinTree::printBinTree_private(Node const *branch, std::string const &prefix, bool rt, bool last) const {
	std::cout << prefix << (rt ? "" : (last ? "\\-" : "|-"));
	if (branch)
		branch->printNode();
	else
		std::cout << "";
	std::cout << std::endl;
	if (!branch || (!branch->getLeft() && !branch->getRight()))
		return;
	std::vector<Node *> v { branch->getLeft(), branch->getRight() };
	for (size_t i = 0; i < v.size(); i++)
		printBinTree_private(v[i], prefix + (rt ? "" : (last ? "  " : "| ")), false, i + 1 >= v.size());
}

void BinTree::print_private(const Node *branch) const {
	if (branch == nullptr)
		return;
	print_private(branch->getLeft());
	branch->printNode();
	print_private(branch->getRight());
	return;
}

void BinTree::findNodeByIdentifier_private(const char &letter, const size_t &digit, Node *branch, bool &flag) const {
	if (branch == nullptr)
		return;
	branch->printNode();
	std::cout << " --> ";
	if (letter > branch->getLetter())
		findNodeByIdentifier_private(letter, digit, branch->getRight(), flag);
	else if (letter < branch->getLetter())
		findNodeByIdentifier_private(letter, digit, branch->getLeft(), flag);
	else {
		if (letter == branch->getLetter() && digit > branch->getDigit())
			findNodeByIdentifier_private(letter, digit, branch->getRight(), flag);
		else if (letter == branch->getLetter() && digit < branch->getDigit())
			findNodeByIdentifier_private(letter, digit, branch->getLeft(), flag);
		else if (letter == branch->getLetter() && digit == branch->getDigit()) {
			std::cout << "found: ";
			branch->printNode();
			flag = true;
			return;
		}
	}
	return;
}

void BinTree::addNode(const char &letter, const size_t &digit) {
	if ((letter >= 'a' && letter <= 'z') && (digit >= 10 && digit <= 99))
		root = addNode_private(root, letter - 32, digit);
	else if ((letter >= 'A' && letter <= 'Z') && (digit >= 10 && digit <= 99))
		root = addNode_private(root, letter, digit);
	else
		throw std::exception("\nIncorrect letter or digit for Node Identifier\n");
}

void BinTree::deleteNode(const char &letter, const size_t &digit) {
	char let = ' ';
	if ((letter >= 'a' && letter <= 'z') && (digit >= 10 && digit <= 99))
		let = letter - 32;
	else if ((letter >= 'A' && letter <= 'Z') && (digit >= 10 && digit <= 99))
		let = letter;
	else
		throw std::exception("\nIncorrect letter or digit for Node Identifier\n");

	if (root != nullptr) {
		if (root->getLetter() == let && root->getDigit() == digit)
			removeTree(root);
		else {
			bool flag = 0;
			deleteNode_private(let, digit, root, flag);
			if (flag == 0)
				std::cout << "unknown Identifier: [" << let << digit << "]" << std::endl << std::endl;
		}
	}
}

void BinTree::printBinTree() const {
	printBinTree_private(root);
}

void BinTree::print() const {
	if (root == nullptr)
		std::cout << "\nBinTree is empty" << std::endl;
	print_private(root);
}

void BinTree::findNodeByIdentifier(const char &letter, const size_t &digit) const {
	bool flag = false;
	char let = ' ';
	if ((letter >= 'a' && letter <= 'z') && (digit >= 10 && digit <= 99)) {
		let = letter - 32;
		findNodeByIdentifier_private(let, digit, root, flag);
	}
	else if ((letter >= 'A' && letter <= 'Z') && (digit >= 10 && digit <= 99)) {
		let = letter;
		findNodeByIdentifier_private(let, digit, root, flag);
	}
	else
		throw std::exception("\nIncorrect letter or digit for Node Identifier\n");
	if (flag == false)
		std::cout << "NULL\n\nIdentifier: [" << let << digit << "] is not exist" << std::endl;
}

Node *BinTree::balance(Node *branch) {
	branch->fixHeight(branch);
	if (branch->bFactor(branch) == 2) {
		if (branch->bFactor(branch->getRight()) < 0)
			branch->setRight(branch->rotateRight(branch->getRight()));
		return branch->rotateLeft(branch);
	}
	if (branch->bFactor(branch) == -2) {
		if (branch->bFactor(branch->getLeft()) > 0)
			branch->setLeft(branch->rotateLeft(branch->getLeft()));
		return branch->rotateRight(branch);
	}
	return branch;
}
