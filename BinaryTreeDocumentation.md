|Katelyn West|
| :---          	|
| S218002   |
|Code Design and Data Structures|
|   Graphical Test Application|

## I. Requirements

1. **Description of problem**

    - **Name**: Implementation of a Binary Tree
    - **Problem statement**: Student must have a successful creation of a project which implements and demonstrates a binary 
tree 
    - **Problem specifications**:
        - The created program must maintain an ordered tree
        - The created program demonstrates insertion and removal of nodes 
        - The created program allows the user to search for a value in the tree
        - The created program uses a third-party library 
    
2. **Input Information**
    - 'Value box': The user is able to input an integer value to either insert into or remove from the data tree.

    - 'Insert button': When pressed, inserts the value inside the value box into the binary tree.

    - 'Remove button': When pressed, removes the value inside the value box from the binary tree.

3. **Output Information**

    - 

4. **User Interface Information**

## II. Design
1. _System Architecture_

2. _Object Information_

    - **Filename**: TreeNode.h
        - **Class Name**: TreeNode
            - Name: TreeNode()
            - Description: The base constructor of the tree node, creates an empty node
            - Visibility: public
            - Arguments: None

            - Name: Treenode()
            - Description: Override for the tree node constructor, sets the value to a specific value
            - Visibility: public
            - Arguments: value (T)

            - Name: ~TreeNode()
            - Description: The destructor for the tree node
            - Visibility: public
            - Arguments: none

            - Name: hasLeft()
            - Description: Returns a bool of true or false if the tree node does or does not have a left node.
            - Visibility: public
            - Arguments: none

            - Name: hasRight()
            - Description: Returns a bool of true or false if the tree node does or does not have a right node.
            - Visibility: public
            - Arguments: none

            - Name: getData()
            - Description: Returns the value stored inside the tree node.
            - Visibility: public
            - Arguments: none

            - Name: setLeft()
            - Description: Sets the tree node's left node to a tree node passed into the method.
            - Visibility: public
            - Arguments: node (TreeNode\<T\>)

            - Name: setRight()
            - Description: Sets the tree node's right node to a tree node passed into the method.
            - Visibility: public
            - Arguments: node (TreeNode\<T\>)

            - Name: draw()
            - Description: draws the tree node to the screen at a certain position, and highlighting it green if it is selected.
            - Visibility: public
            - Arguments: x (int), y (int), selected (bool) = false.

            - Name: m_value
            - Description: the value inside of the node
            - Visibility: private

            - Name: m_left
            - Description: The treenode that is on this tree node's left
            - Visibility: private

            - Name: m_right
            - Description: The treenode that is on this tree node's right.
            - Visibility: private
    - **Filename**: BinaryTree.h
        - **Class name**: BinaryTree
            - Name: BinaryTree()
            - Description: Constructor for the binary tree, creates a new, empty binary tree.
            - Visibility: public
            - Arguments: none

            - Name: ~BinaryTree()
            - Description: Destructor for the binary tree 
            - Visibility: public
            - Arguments:

            - Name: isEmpty() const
            - Description: Returns a bool, true if the head node exists, false if not.
            - Visibility: public
            - Arguments: none

            - Name: insert()
            - Description: Inserts a new node with a given value into the binary tree using a while loop and placing the node where it belongs in the tree depending on its value compared to the other values.
            - Visibility: public
            - Arguments: value (T)

            - Name: remove()
            - Description: Finds the node with the given value in the binary tree and then removes it, using the three different node removal methods depending on how many child nodes the node being deleted has and if it were the head node or not.
            - Visibility: public
            - Arguments: value (T)

            - Name: Find()
            - Description: Searches for a tree node inside the binary tree and returns the tree node if the node is found.  
            - Visibility: public
            - Arguments: value (T)

            - Name: draw()
            - Description: calls the private draw method 
            - Visibility: public
            - Arguments: selected(TreeNode\<T>) = nullptr

            - Name: findNode
            - Description: Searches the binary tree and finds a node in the tree based on a value passed through the method, then sets the nodeFound refrence to be that node if found and sets the parentNode refrence to be the parent of the node found (if any).
            - Visibility: private
            - Arguments: value (T), nodeFound (TreeNode\<T>), nodeParent (TreeNode\<T>).

            - Name: draw()
            - Description: Draws every node onto the screen using the draw function in the node class and draws lines using raylib to connect each node if the node has children.
            - Visibility: private
            - Arguments: currentNode (TreeNode\<T>), x (int), y(int), horizontalSpacing (int), selected(TreeNode\<T>) = nullptr

            - Name: m_root
            - Description: The root node where the binary tree starts 
            - Visibility: private

            