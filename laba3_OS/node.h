#pragma once

class Node {

public:
	Node() = default;
	~Node() = default;
	explicit Node(const Node &other);
	explicit Node(const char _letter, const size_t _digit);
	
	void setLetter(const char _letter);
	void setDigit(const size_t _digit);
	void setLeft(Node *_left);
	void setRight(Node *_right);
	void setHeight(size_t _height);

	char getLetter() const;
	size_t getDigit() const;
	Node *getLeft() const;
	Node *getRight() const;
	size_t getHeight() const;

	size_t heightByNode(Node *branch);
	int bFactor(Node *branch);
	void fixHeight(Node *branch);
	Node *rotateRight(Node *branch);
	Node *rotateLeft(Node *branch);

	void printNode() const;

private:
	char letter = ' '; // upper letters
	size_t digit = 0; // 10 - 99

	Node *left = nullptr;
	Node *right = nullptr;

	size_t height = 1;
};
