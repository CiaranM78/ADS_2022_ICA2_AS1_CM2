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
    TNode* pLeft, * pRight;


public:
    TNode* getLeft()
    {
        return pLeft;
    }

    TNode* getRight()
    {
        return pRight;
    }
    K getKey()
    {
        return key;
    }
    TNode(K key, E value)
    {
        this->key = key;
        this->data = value;
    }

    bool insert(K key, E data)
    {
        if (key.hash() == this->key.hash())
        {
            return false;
        }
        if (key.hash() < this->key.hash())
        {
            if (this->pLeft == nullptr)
            {
                this->pLeft = new TNode(key, data);
                return true;
            }
            else
            {
               return this->pLeft->insert(key, data);
            }
            
        }
        else if (key.hash() > this->key.hash())
        {
            if (this->pRight == nullptr)
            {
                this->pRight = new TNode(key, data);
                return true;
            }
            else
            {
                return this->pRight->insert(key, data);
            }
            
        }
        return false;
    }

    void setData(E data) { this->data = data; }
    E getData() const { return this->data; }
};