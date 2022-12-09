#pragma once
#include <vector>
#include "TNode.h"

template <class K, class V>
class BinaryTree
{
//	void addItemToArray(BSTNode<T>* node, int& pos, int* arr);
public:
	TNode<K,V>* root;
	BinaryTree();
	//void add(K key, V data);
	//bool remove(K item);
	//void clear();
	int count();
	V search(K toFind);
	//V* toArray();
	//void printInOrder();
	//void printInOrder(TNode<K, V>* node);
	//void printPreOrder();
	//void printPreOrder(TNode<K, V>* node);
	//void printPostOrder();
	//void printPostOrder(TNode<K, V>* node);
	
	~BinaryTree() {};
};

template <class K, class V>
BinaryTree<K, V>::BinaryTree()
{
	root = nullptr;
}


template <class K, class V>
V BinaryTree<K, V>::search(K toFind)
{
	TNode<K, V>* node = root;
	while (node != nullptr)
	{
		if (node->getKey().hash() == toFind.hash())
		{
			break;
		}
		else if (toFind.hash() < node->getKey().hash())
		{
			node = node->getLeft();
		}
		else
		{
			node = node->getRight();
		}
	}
	if (node != nullptr)
	{
		return node->getData();
	}
	else
		return nullptr;
}


template <class K, class V>
int BinaryTree<K,V>::count()
{
	if (root == nullptr)
		return 0;
	return root->count();
}

/*
template <class K, class V>
void BinaryTree<K, V>::add(K key, V data)
{
	if (root == nullptr)
	{
		root = new TNode<K,V>(key, data);
	}
	else
	{
		root->insert(key, data);
	}
}


*/





/*
template <class K, class V>
bool BinaryTree<K, V>::remove(K item)
{
	BSTNode<T>* toBeRemoved = root;
	BSTNode<T>* parent = nullptr;
	bool found = false;
	while (!found && toBeRemoved != nullptr)
	{
		if (toBeRemoved->getItem() == item)
		{
			found = true;
		}
		else
		{
			parent = toBeRemoved;
			if (item < toBeRemoved->getItem())
				toBeRemoved = toBeRemoved->getLeft();
			else
				toBeRemoved = toBeRemoved->getRight();
		}

	}
	if (!found)
		return false;

	if (toBeRemoved->getLeft() == nullptr || toBeRemoved->getRight() == nullptr)
	{
		BSTNode<T>* newChild;
		if (toBeRemoved->getLeft() == nullptr)
		{
			newChild = toBeRemoved->getRight();
		}
		else
		{
			newChild = toBeRemoved->getLeft();
		}

		if (parent == nullptr)
		{
			root = newChild;
		}
		else if (parent->getLeft() == toBeRemoved)
		{
			parent->setLeft(newChild);
		}
		else
		{
			parent->setRight(newChild);
		}
		return true;
	}
	else
	{
		BSTNode<T>* smallestParent = toBeRemoved;
		BSTNode<T>* smallest = toBeRemoved->getRight();
		while (smallest->getLeft() != nullptr)
		{
			smallestParent = smallest;
			smallest = smallest->getLeft();
		}
		toBeRemoved->setItem(smallest->getItem());
		if (smallestParent == toBeRemoved)
		{
			smallestParent->setRight(smallest->getRight());
		}
		else
		{
			smallestParent->setLeft(smallest->getRight());
		}

	}

	return false;
}

*/
/**
	Helper Function to put the binary tree into a sorted array;

*/



/**
	This function is used to convert this binary tree into a sorted array.

*/
/*
template <class K, class V>
T* BinaryTree<K, V>::toArray()
{
	T* arr = new T[root->count()];
	int pos = 0;
	addItemToArray(root, pos, arr);
	return arr;
}
*/
/*
template <class K, class V>
void BinaryTree<K, V>::clear()
{
	delete root;
	root = nullptr;
}
template <class K, class V>
BinaryTree<K, V>::~BinaryTree()
{
	delete root;
}
*/


/*
Print the entire tree using in order traversal
*/
/*
template <class K, class V>
void BinaryTree<K, V>::printInOrder()
{
	this->printInOrder(root);
	cout << endl;
}*/
/*
Print a subtree using in order traversal
*/
//template <class K, class V>
//void BinaryTree<K, V>::printInOrder(BSTNode<T>* node)
//{
//
//
//}
/*
Print the entire tree using pre order traversal
*/
//template <class K, class V>
//void BinaryTree<K, V>::printPreOrder()
//{
//	this->printPreOrder(root);
//	cout << endl;
//}
//
///*
//Print a subtree using post order traversal
//*/
//template <class K, class V>
//void BinaryTree<K, V>::printPreOrder(BSTNode<T>* node)
//{
//
//
//}
//
///*
//	Print the entire tree using post order traversal
//*/
//template <class K, class V>
//void BinaryTree<K, V>::printPostOrder()
//{
//	this->printPostOrder(root);
//	cout << endl;
//}
///*
//		Print a subtree using post order traversal
//*/
//template <class K, class V>
//void BinaryTree<K, V>::printPostOrder(BSTNode<T>* node)
//{
//
//
//}