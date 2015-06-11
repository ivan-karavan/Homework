#pragma once
#include <iostream>
#include <cmath>
#include <stack>

/* выполняемые действия: добавление новых узлов.
удаление узлов не предусматривается*/
template<class T, class Compare>
class AVLTree
{
public:
	struct Node
	{
		T key;
		int height;
		Node* left;
		Node* right;

		Node(T key)
		{
			this->key = key;
			height = 1;
			left = NULL;
			right = NULL;
		}
	};

	class Iterator {
	public:
		Iterator(Node *node) {
			Node *current = node;
			while (current != NULL) {
				mStack.push(current);
				current = current->left;
			}
		}
		Node* next() {
			if (mStack.empty()) {
				return NULL;
			}
			Node *top = mStack.top();
			mStack.pop();
			if (top->right != NULL) {
				Node *current = top->right;
				while (current != NULL) {
					mStack.push(current);
					current = current->left;
				}
			}
			return top;
		}
	private:
		std::stack<Node*> mStack;
	};

	Iterator* iterator()
	{
		return new Iterator(root);
	}

	AVLTree() {}

	~AVLTree()
	{
		deleteTree(root);
	}

	void insert(T k)
	{
		if (root == NULL)
			root = new Node(k);
		if (comparator(k, root->key))
			root->left = insert(root->left, k);
		else if (comparator(root->key, k))
			root->right = insert(root->right, k);
		root = balance(root);
	}

	// insert key in the tree starts with this node
	Node* insert(Node* p, T k) // вставка ключа k в дерево с корнем p
	{
		if (p == NULL) 
			return new Node(k);
		if (comparator(k, p->key))
			p->left = insert(p->left, k);
		else if (comparator(p->key,k))
			p->right = insert(p->right, k);
		return balance(p);
	}

	// checks the difference between height of right and left children
	bool isAVLTree()
	{
		if (root == NULL)
		{
			return true;
		}
		if (abs(balanceFactor(root)) > 1)
		{
			return false;
		}
		return isAVLTree(root->left) && isAVLTree(root->right);
	}

	// return true if element is already added to the tree
	bool exists(T k)
	{
		if (root == NULL)
		{
			return false;
		}
		if (comparator(k, root->key))
		{
			return exists(k, root->left);
		}
		if (comparator(root->key, k))
		{
			return exists(k, root->right);
		}
		return true;
	}

private:

	Node* root;

	Compare comparator;

	void deleteTree(Node* node)
	{
		if (node != NULL)
		{
			deleteTree(node->left);
			deleteTree(node->right);
			delete node;
		}
	}

	// checks the correctness of AVLTree
	bool isAVLTree(Node* node)
	{
		if (node == NULL)
		{
			return true;
		}
		if (abs(balanceFactor(node)) > 1)
		{
			return false;
		}
		return isAVLTree(node->left) && isAVLTree(node->right);
	}

	// method is neccessary, because null nodes haven't field height
	int height(Node* node)
	{
		if (node != NULL)
		{
			return node->height;
		}
		else
		{
			return 0;
		}
	}

	// difference of height between right and left child
	int balanceFactor(Node* p)
	{
		return height(p->right) - height(p->left);
	}

	//take the highest child and add parent to height
	void updateHeight(Node* node)
	{
		if (height(node->left) > height(node->right))
		{
			node->height = height(node->left) + 1;
		}
		else
		{
			node->height = height(node->right) + 1;
		}
	}

	//right simple rotation around p
	Node* rotateright(Node* p)
	{
		Node* q = p->left;
		p->left = q->right;
		q->right = p;
		updateHeight(p);
		updateHeight(q);
		return q;
	}

	//left simple rotation around 
	Node* rotateleft(Node* q)
	{
		Node* p = q->right;
		q->right = p->left;
		p->left = q;
		updateHeight(q);
		updateHeight(p);
		return p;
	}

	// big rotation around p if neccessary
	Node* balance(Node* p)
	{
		updateHeight(p);
		if (balanceFactor(p) == 2)
		{
			if (balanceFactor(p->right) < 0)
				p->right = rotateright(p->right);
			return rotateleft(p);
		}
		if (balanceFactor(p) == -2)
		{
			if (balanceFactor(p->left) > 0)
				p->left = rotateleft(p->left);
			return rotateright(p);
		}
		return p;
	}

	bool exists(T k, Node* node)
	{
		if (node == NULL)
		{
			return false;
		}
		if (comparator(k, node->key))
		{
			return exists(k, node->left);
		}
		if (comparator(node->key, k))
		{
			return exists(k, node->right);
		}
		return true;
	}
};