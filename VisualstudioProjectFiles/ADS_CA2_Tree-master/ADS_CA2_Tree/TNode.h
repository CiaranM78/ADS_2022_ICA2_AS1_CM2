#pragma once

template <typename K, typename E>
class TNode {
private:

	




	/// <summary>
	/// A subset of the main data used to generate a unique number for the node
	/// </summary>
	K key;
	/// <summary>
	/// The actual data that the node stores e.g. Person, Record, Student
	/// </summary>
	E data;

	/// <summary>
	/// Pointers to the two kids. Go left if new data key < key for this node, else go right
	/// </summary>
	TNode* pLeft, * pRight, *parent;


public:

	TNode();

	bool insert(K key, E data) {
		return false;
	}

	void setData(E data) { this->data = data; }
	E getData() const { return this->data; }


	template <typename K, typename E>
	TNode<K,E>::TNode()
	{
		parent = nullptr;
		left = nullptr;
		right = nullptr;
	}

	template <typename K, typename E >
	
	bool insertdata(typename K, typename E)
	{
		if (typename K == nullptr)
		{
			return 0;
		}

		else if (this->K >= K)

		{
			this-> K new TNode(typename K, typename E)
		}

		else
		{
			insert(typename K, typename E);
		}


	} 






};
