#include "node.h"

#include <iostream>
#include <exception>

Node::Node(const Node &other) {
	letter = other.letter;
	digit = other.digit;
}

Node::Node(const char _letter, const size_t _digit) {
	if ((_letter >= 'a' && _letter <= 'z') && (_digit >= 10 && _digit <= 99)) {
		letter = _letter - 32; // upper letters
		digit = _digit;
	}
	else if ((_letter >= 'A' && _letter <= 'Z') && (_digit >= 10 && _digit <= 99)) {
		letter = _letter; // upper letters
		digit = _digit;
	}
	else
		throw std::exception("\nIncorrect letter or digit at Node Identifier\n");
}

void Node::setLetter(const char _letter) {
	if (_letter >= 'a' && _letter <= 'z')
		letter = _letter - 32; // upper letters
	else if (_letter >= 'A' && _letter <= 'Z')
		letter = _letter;
	else
		throw std::exception("\nIncorrect letter at Node Identifier\n");
}

void Node::setDigit(const size_t _digit) {
	if (_digit >= 10 && _digit <= 99)
		digit = _digit;
	else 
		throw std::exception("\nIncorrect digit at Node Identifier\n");
}

void Node::setLeft(Node *_left) {
	left = _left;
}

void Node::setRight(Node *_right) {
	right = _right;
}

void Node::setHeight(size_t _height) {
	height = _height;
}

char Node::getLetter() const {
	return letter;
}

size_t Node::getDigit() const {
	return digit;
}

Node *Node::getLeft() const {
	return left;
}

Node *Node::getRight() const {
	return right;
}

size_t Node::getHeight() const {
	return height;
}

size_t Node::heightByNode(Node *branch) {
	return branch ? branch->height : 0;
}

int Node::bFactor(Node *branch) {
	if (branch != nullptr)
		return heightByNode(branch->right) - heightByNode(branch->left);
	else
		return 0;
}

void Node::fixHeight(Node *branch) {
	if (branch != nullptr) {
		size_t hl = heightByNode(branch->left);
		size_t hr = heightByNode(branch->right);
		branch->height = (hl > hr ? hl : hr) + 1;
	}
}

Node *Node::rotateRight(Node *branch) {
	if (branch != nullptr) {
		Node *temp = branch->left;
		branch->left = temp->right;
		temp->right = branch;
		fixHeight(branch);
		fixHeight(temp);
		return temp;
	}
}

Node *Node::rotateLeft(Node *branch) {
	if (branch != nullptr) {
		Node *temp = branch->right;
		branch->right = temp->left;
		temp->left = branch;
		fixHeight(branch);
		fixHeight(temp);
		return temp;
	}
}

void Node::printNode() const {
	if ((letter >= 'A' && letter <= 'Z') && (digit >= 10 && digit <= 99))
		std::cout << "[" << letter << digit << "] ";
	else
		throw std::exception("\nIncorrect Identifier\n");
}
