#include <iostream>

using namespace std;

// Node definition with templates so it can accept any type of data
template<class T = int>
class Node
{
private:
    T data{};
    union
    {
        Node<T> *next;
        Node<T> *left;
    };
    Node<T> *right;
public:
    T        getData() { return data; }
    Node<T> *getNext() { return next; }
    Node<T> *getLeft() { return left; }
    Node<T> *getRight() { return right; }
    void  setNext(Node<T> *n) { if (n != nullptr) next = n; }
    void  setLeft(Node<T> *l) { if (l != nullptr) left = l; }
    void setRight(Node<T> *r) { if (r != nullptr) right = r; }
    // Constructors
    Node()    :            left{ nullptr }, right{ nullptr } {}
    Node(T d) : data{ d }, left{ nullptr }, right{ nullptr } {}
    // Copy constructor
    Node(const Node<T>& node) : data{ node.data }, left{ node.left }, right{ node.right } {}
};

// Implementation of a simple stack to use it on the DFS algorithm
template<typename T>
class Stack
{
private:
    Node<T> *top;
public:
    Stack() : top{ nullptr } {}
    ~Stack();
    bool isEmpty() { return top == nullptr; }
    void push(T data);
    T pop();
};

// Implementation of a simple queue to use it on the BFS algorithm
template<typename T>
class Queue
{
private:
    Node<T> *front;
    Node<T> *rear;
public:
    Queue() : front{ nullptr }, rear{ nullptr } {}
    ~Queue();
    bool isEmpty() { return front == nullptr; }
    void enqueue(T data);
    T dequeue();
};

// Destructor of the Stack class
template<typename T>
Stack<T>::~Stack()
{
    Node<T> *tmp;
    while (!isEmpty())
    {
        tmp = top;
        top = tmp->getNext();
        delete tmp;
    }
}

// Method to add an element to the Stack
template<typename T>
void Stack<T>::push(T data)
{
    Node<T> *tmp = new Node<T>(data);
    if (top != nullptr)
        tmp->setNext(top);
    top = tmp;
}

// Method to remove an element from the Stack
template<typename T>
T Stack<T>::pop()
{
    if (isEmpty())
        exit(1);
    T data;
    Node<T> *tmp(top);
    top = tmp->getNext();
    data = tmp->getData();
    delete tmp;
    return data;
}

template<typename T>
Queue<T>::~Queue()
{
    Node<T> *tmp;
    while (!isEmpty())
    {
        tmp = front;
        front = tmp->getNext();
        delete tmp;
    }
}

template<typename T>
void Queue<T>::enqueue(T data)
{
    Node<T> *tmp = new Node<T>(data);
    if (front == nullptr)
        front = tmp;
    else
        rear->setNext(tmp);
    rear = tmp;
}

template<typename T>
T Queue<T>::dequeue()
{
    if (isEmpty())
        exit(1);
    T data;
    Node<T> *tmp(front);
    data = tmp->getData();
    front = tmp->getNext();
    delete tmp;
    return data;
}

// Insert method for the tree, it receives the root and finds the correct place to insert the new element
template<typename T = int>
void insertElement(Node<T> &root, T data)
{
    Node<T> *tmp = &root;
    while (tmp != nullptr)
    {
        if (data < tmp->getData())
        {
            auto left = tmp->getLeft();
            if (left == nullptr)
            {
                tmp->setLeft(new Node<T>(data));
                return;
            }
            else
                tmp = left;
        }
        else
        {
            auto right = tmp->getRight();
            if (right == nullptr)
            {
                tmp->setRight(new Node<T>(data));
                return;
            }
            else
                tmp = right;
        }
    }
}

// Iterative method to search for an element in a binary search tree
template<typename T>
bool findElementI(Node<T> *root, T data)
{
    while (root != nullptr)
    {
        // Check if the value being looked for was already found
        auto d = root->getData();
        cout << d << ", ";
        if (data == d)
            return true;
        else if (data < d)
            root = root->getLeft();
        else
            root = root->getRight();
    }
    return false;
}

// Recursive method to search for an element in a binary search tree
template<typename T>
Node<T> *findElementR(Node<T> *root, int data)
{
    // Base case to exit the recursion
    if (root == nullptr)
        return root;
    // Check if the value being looked for was already found
    auto d = root->getData();
    cout << d << ", ";
    if (data == d)
        return root;
    else if (data < d)
        return findElementR(root->getLeft(), data);
    return findElementR(root->getRight(), data);
}

// Method to search for an element in tree using Breadth-First Search (BFS)
template<typename T>
bool breadthFirstSearch(Node<T> *root, T data)
{
    Queue<Node<T>*> queue;
    queue.enqueue(root);
    while (!queue.isEmpty())
    {
        Node<T> *tmp = queue.dequeue();
        cout << tmp->getData() << ", ";
        if (data == tmp->getData())
            return true;
        if (tmp->getLeft() != nullptr)
            queue.enqueue(tmp->getLeft());
        if (tmp->getRight() != nullptr)
            queue.enqueue(tmp->getRight());
    }
    return false;
}

// Method to search for an element in tree using Depth-First Search (DFS)
template<typename T>
bool depthFirstSearch(Node<T> *root, T data)
{
    Stack<Node<T>*> stack;
    // Insert the root element in the stack
    stack.push(root);
    // Loop in the stack while there are any elements left
    while (!stack.isEmpty())
    {
        Node<T> *tmp = stack.pop();
        cout << tmp->getData() << ", ";
        if (data == tmp->getData())
            return true;
        if (tmp->getLeft() != nullptr)
            stack.push(tmp->getLeft());
        if (tmp->getRight() != nullptr)
            stack.push(tmp->getRight());
    }
    return false;
}

// Traversing a binary tree with PreOrder approach (root, left, right) and recursion
template<typename T>
void preOrderTraversal(Node<T> *root)
{
    // Base condition to exit the resursion
    if (root == nullptr)
        return;
    // First show the element on the root, then go to left and and then to right
    cout << root->getData() << ", ";
    preOrderTraversal(root->getLeft());
    preOrderTraversal(root->getRight());
}

// Traversing a binary tree with InOrder approach (left, root, right) and recursion
template<typename T>
void inOrderTraversal(Node<T> *root)
{
    // Base condition to exit the recursion
    if (root == nullptr)
        return;
    // First go to the left, then display the root element and then go to the right
    inOrderTraversal(root->getLeft());
    cout << root->getData() << ", ";
    inOrderTraversal(root->getRight());
}

// Traversing a binary tree with PostOrder approach (left, right, root) and recursion
template<typename T>
void postOrderTraversal(Node<T> *root)
{
    // Base condition to exit the recursion
    if (root == nullptr)
        return;
    // First go to the left, then to the right and then display the root element
    postOrderTraversal(root->getLeft());
    postOrderTraversal(root->getRight());
    cout << root->getData() << ", ";
}

// Entry point of the application
int main()
{
    // Create the sample tree
    //         R
    //        / \
    //       A   B
    //          /
    //         C
    // R = 5
    // A = 3
    // B = 8
    // C = 6

    // The first element is the root (using default template value of int)
    Node<int> root(5);
    // Insert the next elements in the correct order to produce the sample tree
    insertElement(root, 3);
    insertElement(root, 8);
    insertElement(root, 6);

    // Search for an element using normal binary search on the tree
    cout << "Binary search on the tree" << endl;
    // Using boolalpha to display true/false for boolean values instead of 1/0
    cout << "Looking for element 6, found?: " << boolalpha << findElementI(&root, 6) << endl;
    cout << "Looking for element 1, found?: " << findElementI(&root, 1) << endl;
    cout << "Looking for element 6, found?: " << (findElementR(&root, 6) == nullptr ? "false" : "true") << endl;
    cout << "Looking for element 1, found?: " << (findElementR(&root, 1) == nullptr ? "false" : "true") << endl;

    // Search for an element using BFS
    cout << "Search on the tree with BFS" << endl;
    cout << "Looking for element 6, found?: " << breadthFirstSearch(&root, 6) << endl;
    cout << "Looking for element 1, found?: " << breadthFirstSearch(&root, 1) << endl;

    // Search for an element using DFS
    cout << "Search on the tree with DFS" << endl;
    cout << "Looking for element 6, found?: " << depthFirstSearch(&root, 6) << endl;
    cout << "Looking for element 1, found?: " << depthFirstSearch(&root, 1) << endl;

    // Displaying the content of the binary tree with the different traversal methods: PreOrder, InOrder and PostOrder
    cout << "\nPreOrder traversal: ";
    preOrderTraversal(&root);
    cout << "\b\b " << endl;

    cout << "InOrder traversal: ";
    inOrderTraversal(&root);
    cout << "\b\b " << endl;

    cout << "PostOrder traversal: ";
    postOrderTraversal(&root);
    cout << "\b\b \n\n";

    return 0;
}
