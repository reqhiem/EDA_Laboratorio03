// A C++ program to demonstrate operations of KD tree
#include<bits/stdc++.h>
using namespace std;

template<typename T>
class KDTree{
private:
    const int k = 3;
    // A structure to represent node of kd tree
    struct Node
    {
        array<T, 3> point; // To store k dimensional point
        Node *left, *right;
    };

    // A method to create a node of K D tree
    struct Node* newNode(array<T, 3> arr)
    {
        struct Node* temp = new Node;

        for (int i=0; i<k; i++)
        temp->point[i] = arr[i];

        temp->left = temp->right = NULL;
        return temp;
    }

    // Inserts a new node and returns root of modified tree
    // The parameter depth is used to decide axis of comparison
    Node *insertRec(Node *root, array<T, 3> point, unsigned depth)
    {
        // Tree is empty?
        if (root == NULL)
        return newNode(point);

        // Calculate current dimension (cd) of comparison
        unsigned cd = depth % k;

        // Compare the new point with root on current dimension 'cd'
        // and decide the left or right subtree
        if (point[cd] < (root->point[cd]))
            root->left = insertRec(root->left, point, depth + 1);
        else
            root->right = insertRec(root->right, point, depth + 1);

        return root;
    }

    // Function to insert a new point with given point in
    // KD Tree and return new root. It mainly uses above recursive
    // function "insertRec()"
    Node* insert(Node *root, array<T, 3> point)
    {
        return insertRec(root, point, 0);
    }

    // A utility method to determine if two Points are same
    // in K Dimensional space
    bool arePointsSame(array<T, 3> point1, array<T, 3> point2)
    {
        // Compare individual pointinate values
        for (int i = 0; i < k; ++i)
            if (point1[i] != point2[i])
                return false;

        return true;
    }

    // Searches a Point represented by "point[]" in the K D tree.
    // The parameter depth is used to determine current axis.
    bool searchRec(Node* root, array<T, 3> point, unsigned depth)
    {
        // Base cases
        if (root == NULL)
            return false;
        if (arePointsSame(root->point, point))
            return true;

        // Current dimension is computed using current depth and total
        // dimensions (k)
        unsigned cd = depth % k;

        // Compare point with root with respect to cd (Current dimension)
        if (point[cd] < root->point[cd])
            return searchRec(root->left, point, depth + 1);

        return searchRec(root->right, point, depth + 1);
    }

    // Searches a Point in the K D tree. It mainly uses
    // searchRec()
    bool search(Node* root, array<T, 3> point)
    {
        // Pass current depth as 0
        return searchRec(root, point, 0);
    }
public:
    struct Node *root;
    KDTree(){
        root = NULL;
    }

    // Inserts a new point with given point
    void insert(array<T, 3> point){
        root = insert(root, point);
    }

    // Searches a Point represented by "point[]" in the K D tree.
    bool search(array<T, 3> point){
        return search(root, point);
    }

};


// Driver program to test above functions
int main()
{
	KDTree<long double> kdtree;
	
    array<long double, 3> points[3] = {{(long double)3, (long double)6, (long double)3}, {(long double)17, (long double)15, (long double)2}};

	int n = 3;

	for (int i=0; i<n; i++)
        kdtree.insert(points[i]);
	//root = insert(root, points[i]);

	array<long double, 3> point1 = {(long double)3, (long double)6, (long double)3};

	(kdtree.search(point1) == 1) ? cout << "Found\n": cout << "Not Found\n";

	return 0;
}
