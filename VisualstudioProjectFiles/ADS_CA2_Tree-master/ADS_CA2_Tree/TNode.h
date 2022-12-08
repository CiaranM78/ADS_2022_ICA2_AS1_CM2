#pragma once
#include "StudentKey.h"
#include "Student.h"



template <typename K, typename E>
class TNode {

    /// <summary>
    /// A subset of the main data used to generate a unique number for the node
    /// </summary>
    /// 
    /// 
    /// 
    /// 
    TNode<K, E>* parent;
    TNode<K, E>* pLeft;
    TNode<K, E>* pRight;
    K key;
    /// <summary>
    /// The actual data that the node stores e.g. Person, Record, Student
    /// </summary>
    E data;

    /// <summary>
    /// Pointers to the two kids. Go left if new data key < key for this node, else go right
    /// </summary>
    //TNode* pLeft, * pRight;


public:
    TNode();
    TNode<K, E>* root;
    TNode(K key, E data);
    TNode<K, E>* getLeft();
    TNode<K, E>* getRight();
    TNode<K,E>* getParent();
    int count();
    int count2();
    //TNode<K, E>* getRight();
    void setLeft(TNode<K, E>* l);
    void setRight(TNode<K, E>* r);
    ~TNode();
    void setData(E data);
    void setKey(K key);
    E getData();
    K getKey();
    bool insert(K key, E data);
    bool remove(K key);
    void add(K key, E data);
    
};

/*
template <class K, class E>
TNode<K, E>::TNode()
{
    root = nullptr;
}
*/


template <typename K, typename E>
TNode<typename K, typename E>::~TNode()
{
    delete pLeft;
    delete pRight;
}

    template <typename K, typename E>
    TNode<K, E>* TNode<K, E>::getLeft()
    {
        return this->pLeft;
    }
    template <typename K, typename E>
    void TNode<K, E>::setLeft(TNode<K, E>* l)
    {
        this->pLeft = l;
    }
    
    template <typename K, typename E>
    TNode<K, E>* TNode<K, E>::getRight()
    {
        return this->pRight;
    }
    template <typename K, typename E>
    void TNode<K, E>::setRight(TNode<K, E>* r)
    {
        this->pRight = r;
    }

    template <typename K, typename E>
    TNode<K, E>* TNode<K, E>::getParent()
    {
        return this->parent;
    }
    
    template <typename K, typename E>
    void TNode<K, E>::setData(E data)
    {
        this->data = data;
    }

    template <typename K, typename E>
    E TNode<K,E>::getData()
    {
        return this->data;
    }

    template <typename K, typename E>
    TNode<K,E>::TNode(K key, E data)
    {
        this->key = key;
        this->data = data;
        root = nullptr;
        
    }

    template <typename K, typename E>
    void TNode<K, E>::setKey(K item)
    {
        this->key = item;
    }

    template <typename K, typename E>
    K TNode<K, E>::getKey()
    {
        return this->key;
    }

   
    template <class K, class E>
    int TNode<K, E>::count()
    {
         if (root == nullptr)
            return 0;
        return root->count2();
    }
    
    template <class K, class E>
    int TNode<K, E>::count2()
    {
       
        int c = 1;
        if (pLeft != nullptr)
            c += pLeft->count2();
        if (pRight != nullptr)
            c += pRight->count2();
        return c;
    }
    

    
    template <typename K, typename E>
    TNode<K,E>::TNode()
    {
        parent = pLeft = pRight = nullptr;
    }
    




    /*
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
    */
   
    template <class K, class E>
    void TNode<K, E>::add(K key, E data)
    {
        if (root == nullptr)
        {
            root = new TNode<K, E>(key, data);
        }
        else
        {
            root->insert(key, data);
        }
    }

    

    template <typename K, typename E>
    bool TNode<K,E>::insert(K key, E data)
    {
        if (key.hash() == this->key.hash())
        {
            return false;
        }
        if (key.hash() < this->key.hash())
        {
            if (this->pLeft == nullptr)
            {
                this->pLeft = new TNode<K,E>(key, data);
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
                this->pRight = new TNode<K,E>(key, data);
                return true;
            }
            else
            {
                return this->pRight->insert(key, data);
            }

        }
        return false;
    }

    template <class K, class E>
    bool TNode<K, E>::remove(K key)
    {
        TNode<K, E>* toBeRemoved = root;
        TNode<K,E>* parent = nullptr;
        bool found = false;

        while (!found && toBeRemoved != nullptr)
        {
            if (toBeRemoved->getKey().hash() == key.hash())
            {
                found = true;
            }
            else
            {
                parent = toBeRemoved;
                if (key.hash() < toBeRemoved->getKey().hash())
                    toBeRemoved = toBeRemoved->getLeft();
                else
                    toBeRemoved = toBeRemoved->getRight();
            }

        }
        if (!found)
            return false;

        if (toBeRemoved->getLeft() == nullptr || toBeRemoved->getRight() == nullptr)
        {
            TNode<K,E>* newChild;
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
            TNode<K,E>* smallestParent = toBeRemoved;
            TNode<K,E>* smallest = toBeRemoved->getRight();
            while (smallest->getLeft() != nullptr)
            {
                smallestParent = smallest;
                smallest = smallest->getLeft();
            }
            toBeRemoved->setData(smallest->getData());
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

    
    
