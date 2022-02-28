#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#pragma once
template<typename T>
class TreeNode;

template<typename T>
class BinaryTree
{
public:

	BinaryTree();
	~BinaryTree();

	/// <summary>
	/// Returns whether or not there are any nodes in the list
	/// </summary>
	bool isEmpty() const;

	/// <summary>
	/// Creates a new node that stores the given value and places it into the tree
	/// </summary>
	/// <param name="value">The new value to add to the tree</param>
	void insert(T value);

	/// <summary>
	/// Finds the node with the given value and removes it from the tree
	/// </summary>
	/// <param name="value">The value of the node to search for in the tree</param>
	void remove(T value);

	/// <summary>
	/// Finds and returns a node with the given value in the tree
	/// </summary>
	/// <param name="value">The value of the node to search for</param>
	TreeNode<T>* find(T value);

	void draw(TreeNode<T>* selected = nullptr);

private:
	/// <summary>
	/// Finds the node that matches the value in the list
	/// </summary>
	/// <param name="searchValue">The value of the node to search for</param>
	/// <param name="nodeFound">A pointer that will store the address of the node that was found</param>
	/// <param name="nodeParent">A pointer that will store the address of the parent of the node that was found</param>
	/// <returns>Whether or not a node matching the value could be found</returns>
	bool findNode(T searchValue, TreeNode<T>*& nodeFound, TreeNode<T>*& nodeParent);

	void draw(TreeNode<T>* currentNode, int x, int y, int horizontalSpacing, TreeNode<T>* selected = nullptr);

	TreeNode<T>* m_root = nullptr;
};

#endif

template<typename T>
inline bool BinaryTree<T>::findNode(T searchValue, TreeNode<T>*& nodeFound, TreeNode<T>*& nodeParent)
{
	if (!isEmpty())
	{
		TreeNode<T>* currNode = m_root;
		nodeParent = nullptr;
		nodeFound = nullptr;

		while (currNode != nullptr)
		{
			if (searchValue == currNode->getData())
			{
				nodeFound = currNode;
				return true;
			}
			else if (searchValue < currNode->getData())
			{
				nodeParent = currNode;
				currNode = currNode->getLeft(); 
			}
			else if (searchValue > currNode->getData())
			{
				nodeParent = currNode;
				currNode = currNode->getRight();
			}
		}
	}

	return false;
}

template<typename T>
inline void BinaryTree<T>::draw(TreeNode<T>* currentNode, int x, int y, int horizontalSpacing, TreeNode<T>* selected)
{
	//Decrease the horizontal spacing as the nodes draw
	horizontalSpacing /= 2;

	//Check if the current node is null
	if (currentNode)
	{
		//Draws the left child if the node has one
		if (currentNode->hasLeft())
		{
			//Draws a line between the left child and the current node
			DrawLine(x, y, x - horizontalSpacing, y + 80, RED);

			//Draws the left child
			draw(currentNode->getLeft(), x - horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		//Draws the right child if the node has one
		if (currentNode->hasRight())
		{
			//Draws a line between the right child and the current node
			DrawLine(x, y, x + horizontalSpacing, y + 80, RED);

			//Draws the right child
			draw(currentNode->getRight(), x + horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		currentNode->draw(x, y, (selected == currentNode));
	}
}

template<typename T>
inline BinaryTree<T>::BinaryTree()
{
	m_root = nullptr;
}

template<typename T>
inline BinaryTree<T>::~BinaryTree()
{
	while (!isEmpty())
	{
		remove(m_root->getData());
	}
}

template<typename T>
inline bool BinaryTree<T>::isEmpty() const
{
	//If the root is not null...
	if (m_root)
	{
		//The list is not empty
		return false;
	}
	//Else
	else
	{
		//List is empty
		return true;
	}
}

template<typename T>
inline void BinaryTree<T>::insert(T value)
{
	//If the tree is empty
	if (isEmpty())
	{
		//Set the root to be this new node
		m_root = new TreeNode<T>(value);
	}
	else
	{
		//Create two treeNode pointers pointing to the currentNode and the new node that is being added
		TreeNode<T>* currNode = m_root;
		TreeNode<T>* NewNode = new TreeNode<T>(value);

		//While the currNode is not nullptr
		while(currNode != nullptr)
		{
			//If the value is less than the current node...
			if (value < currNode->getData())
			{
				//If the current node has a left...
				if (currNode->hasLeft())
				{
					//set the current Node to be the current node's left.
					currNode = currNode->getLeft();
				}
				// Else...
				else
				{
					//Set the currentNode's left to be the newNode.
					currNode->setLeft(NewNode);
					return;
				}
			}
			//If the value is greater than the current node...
			else if (value > currNode->getData())
			{
				//If the current node has a right...
				if (currNode->hasRight())
				{
					// set the current node to equal the current nodes right
					currNode = currNode->getRight();
				}
				// Else...
				else
				{
					//Set the currentNode's right to be the newNode.
					currNode->setRight(NewNode);
					return;
				}
			}
			else if (value == currNode->getData())
			{
				return;
			}
		}
		
	}
}

template<typename T>
inline void BinaryTree<T>::remove(T value)
{
	if (!isEmpty())
	{
		TreeNode<T>* nodeToDelete = nullptr;
		TreeNode<T>* parentNode = nullptr;

		if (findNode(value, nodeToDelete, parentNode))
		{
			if (nodeToDelete->hasLeft() && nodeToDelete->hasRight())
			{
				TreeNode<T>* currNode = nodeToDelete->getRight();
				parentNode = nodeToDelete;

				while (currNode != nullptr)
				{
					if (currNode->hasLeft())
					{
						parentNode = currNode;
						currNode = currNode->getLeft();
					}
					else
					{
						nodeToDelete->setData(currNode->getData());

						if (currNode == nodeToDelete->getRight())
						{
							if (!currNode->hasRight())
							{
								nodeToDelete->setRight(nullptr);
							}
							else
							{
								nodeToDelete->setRight(currNode->getRight());
							}

							delete currNode;
						}
						else
						{
							if (currNode->hasRight())
							{
								parentNode->setLeft(currNode->getRight());
							}
							else
							{
								parentNode->setLeft(nullptr);
								delete currNode;
							}
						}

						return;
					}
				}
			}
			else if (nodeToDelete->hasLeft() || nodeToDelete->hasRight())
			{
				if (nodeToDelete->hasLeft())
				{
					if (nodeToDelete == m_root)
					{
						m_root = nodeToDelete->getLeft();
					}
					else if (nodeToDelete->getData() > parentNode->getData())
					{
						parentNode->setRight(nodeToDelete->getLeft());
						nodeToDelete->setLeft(nullptr);
						delete nodeToDelete;
					}
					else if (nodeToDelete->getData() < parentNode->getData())
					{
						parentNode->setLeft(nodeToDelete->getLeft());
						nodeToDelete->setLeft(nullptr);
						delete nodeToDelete;
					}
				}
				else if (nodeToDelete->hasRight())
				{
					if (nodeToDelete == m_root)
					{
						m_root = nodeToDelete->getRight();
					}
					else if (nodeToDelete->getData() > parentNode->getData())
					{
						parentNode->setRight(nodeToDelete->getRight());
						nodeToDelete->setRight(nullptr);
						delete nodeToDelete;
					}
					else if (nodeToDelete->getData() < parentNode->getData())
					{
						parentNode->setLeft(nodeToDelete->getRight());
						nodeToDelete->setRight(nullptr);
						delete nodeToDelete;
					}
				}
			}
			else
			{
				if (nodeToDelete == m_root)
				{
					delete nodeToDelete;
					m_root = nullptr;
				}
				else if (nodeToDelete->getData() < parentNode->getData())
				{
					delete nodeToDelete;
					parentNode->setLeft(nullptr);
				}
				else if (nodeToDelete->getData() > parentNode->getData())
				{
					delete nodeToDelete;
					parentNode->setRight(nullptr);
				}
			}
		}
	}
}

template<typename T>
inline TreeNode<T>* BinaryTree<T>::find(T value)
{
	if (!isEmpty())
	{
		TreeNode<T>* currentNode = m_root;

		while (currentNode != nullptr)
		{
			if (currentNode->getData() == value)
			{
				return currentNode;
			}

			if (value < currentNode->getData())
			{
				currentNode = currentNode->getLeft();
			}
			else if (value > currentNode->getData())
			{
				currentNode = currentNode->getRight();
			}
		}

		return nullptr;
	}
	else
	{
		return nullptr;
	}
}

template<typename T>
inline void BinaryTree<T>::draw(TreeNode<T>* selected)
{
	draw(m_root, 400, 40, 400, selected);
}
