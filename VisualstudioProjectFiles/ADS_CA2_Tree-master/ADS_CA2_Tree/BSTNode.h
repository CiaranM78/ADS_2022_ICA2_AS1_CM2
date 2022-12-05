#pragma once

template <class T, class V>
class BSTNode
{

	BSTNode<T>* parent;
	BSTNode<T>* left;
	BSTNode<T>* right;
	T key;
	V data;

public:
	BSTNode();
	BSTNode(T data);
	void setItem(T item);
	int count();
	void add(T item, V data);
	BSTNode<T, V>* getParent();
	BSTNode<T, V>* getLeft();
	BSTNode<T, V>* getRight();
	void setLeft(BSTNode<T, V>* l);
	void setRight(BSTNode<T, V>* r);
	T getItem();
	~BSTNode();
	

};

template <class T, class V>
BSTNode<T, V>::~BSTNode()
{
	delete left;
	delete right;
}
template <class T, class V>
T BSTNode<T, V>::getItem()
{
	return this->data;
}
template <class T, class V>
BSTNode<T, V>* BSTNode<T, V>::getLeft()
{
	return this->left;
}
template <class T, class V>
BSTNode<T, V>* BSTNode<T, V>::getRight()
{
	return this->right;
}
template <class T, class V>
BSTNode<T, V>* BSTNode<T, V>::getParent()
{
	return this->parent;
}
template <class T, class V>
void BSTNode<T, V>::setLeft(BSTNode<T, V>* l)
{
	this->left = l;
}
template <class T, class V>
void BSTNode<T, V>::setRight(BSTNode<T, V>* r)
{
	this->right = r;
}

template <class T, class V>
void BSTNode<T, V>::setItem(T item)
{
	this->data = item;
}


template <class T, class V>
BSTNode<T, V>::BSTNode()
{
	parent = left = right = nullptr;
}


template <class T, class V>
BSTNode<T, V>::BSTNode(T data)
{
	this->data = data;
	parent = left = right = nullptr;
}
template <class T, class V>
int BSTNode<T, V>::count()
{
	int c = 1;
	if (left != nullptr)
		c += left->count();
	if (right != nullptr)
		c += right->count();
	return c;
}

template <class T, class V>
void BSTNode<T, V>::add(T key, V data)
{
	if (key == this->key)
	{
		return;
	}
	if (key < this->key)
	{
		if (left == nullptr)
		{
			left = new BSTNode<T>(key, data);
			left->parent = this;
		}
		else
		{
			left->add(key, data);
		}
	}
	else
	{
		if (right == nullptr)
		{
			right = new BSTNode<T>(key, data);
			right->parent = this;
		}
		else
		{
			right->add(key, data);
		}
	}
}

