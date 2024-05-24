#pragma once

#include "node.h"

#include <string>

class BinTree {

public:
	BinTree() = default;
	~BinTree() { removeTree(root); }

	void addNode(const char &letter, const size_t &digit);
	void deleteNode(const char &letter, const size_t &digit);
	void printBinTree() const;
	void print() const;
	void findNodeByIdentifier(const char &letter, const size_t &digit) const;

	Node *balance(Node *branch);
	
private:
	void removeTree(Node *branch);
	Node *addNode_private(Node *branch, const char &letter, const size_t &digit);
	Node *deleteNode_private(const char &letter, const size_t &digit, Node *branch, bool &flag);
	void printBinTree_private(Node const *branch, std::string const &prefix = "", bool root = true, bool last = true) const;
	void print_private(const Node *branch) const;
	void findNodeByIdentifier_private(const char &letter, const size_t &digit, Node *branch, bool &flag) const;

	Node *root = nullptr;
};
