#include <iostream>

using namespace std;

// Tree node definition with templates so it can accept any type of data
template<class T = int>
class Node
{
private:
	T data{};
	Node<T> *left;
	Node<T> *right;
public:
	T getData() { return data; }
	Node<T> *getLeft() { return left; }
	Node<T> *getRight() { return right; }
	void setLeft(Node<T> *l) { if (l != nullptr) left = l; }
	void setRight(Node<T> *r) { if (r != nullptr) right = r; }
	Node() : left(nullptr), right(nullptr) {}
	Node(T d) : data(d), left(nullptr), right(nullptr) {}
};

template<typename T = int>
void insertElement(Node<T> &root, T data)
{
	Node<T> *tmp = &root;
	while (tmp != nullptr)
	{
		if (data < tmp->getData())
		{
			if (tmp->getLeft() == nullptr)
			{
				tmp->setLeft(new Node<T>(data));
				return;
			}
			else
				tmp = tmp->getLeft();
		}
		else
		{
			if (tmp->getRight() == nullptr)
			{
				tmp->setRight(new Node<T>(data));
				return;
			}
			else
				tmp = tmp->getRight();
		}
	}
}

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

	// The first element is the root
	Node<> root(5);
	// Insert the next elements in the correct order to produce the sample tree
	insertElement<int>(root, 3);
	insertElement<>(root, 8);
	insertElement<int>(root, 6);

	return 0;
}
