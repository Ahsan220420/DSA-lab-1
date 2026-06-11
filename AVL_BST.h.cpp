#ifndef BST_H
#define BST_H

#include <iostream>

template <typename T>
struct Node {
	T data;
	Node* left;
	Node* right;

	Node(T val) {
		data = val;
		left = nullptr;
		right = nullptr;
	}
};

template <typename T>
class BST {
private:
	Node<T>* root;

	Node<T>* insert(Node<T>* node, T val) {
		if (node == nullptr) {
			return new Node<T>(val);
		}
		if (val < node->data) {
			node->left = insert(node->left, val);
		}
		else if (val > node->data) {
			node->right = insert(node->right, val);
		}
		return node;
	}

	Node<T>* findMin(Node<T>* node) {
		Node<T>* current = node;
		while (current && current->left != nullptr) {
			current = current->left;
		}
		return current;
	}

	Node<T>* deleteNode(Node<T>* node, T val) {
		if (node == nullptr) {
			return node;
		}

		if (val < node->data) {
			node->left = deleteNode(node->left, val);
		}
		else if (val > node->data) {
			node->right = deleteNode(node->right, val);
		}
		else {
			if (node->left == nullptr) {
				Node<T>* temp = node->right;
				delete node;
				return temp;
			}
			else if (node->right == nullptr) {
				Node<T>* temp = node->left;
				delete node;
				return temp;
			}

			Node<T>* temp = findMin(node->right);
			node->data = temp->data;
			node->right = deleteNode(node->right, temp->data);
		}
		return node;
	}

	void inorder(Node<T>* node) {
		if (node == nullptr) {
			return;
		}
		inorder(node->left);
		std::cout << node->data << " ";
		inorder(node->right);
	}

public:
	BST() {
		root = nullptr;
	}

	void insert(T val) {
		root = insert(root, val);
	}

	void remove(T val) {
		root = deleteNode(root, val);
	}

	void displayInorder() {
		inorder(root);
		std::cout << std::endl;
	}
};

#endif