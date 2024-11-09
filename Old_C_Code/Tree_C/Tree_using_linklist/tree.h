
// structure of node
    // which contain value and pointers to childs
typedef struct node{
    int key;
    struct node* left;
    struct node* right;
}node;

// bst is a pointer to node
typedef node* bst;


// init() function to initialize the tree
void init(bst *l);

// InsertNode() function to insert a node/ value into the tree
void InsertNode(bst *l, int k);

// inorder() function to traverse tree
// this is a sorted order
void inorder(bst t);

// postorder() function to traverse tree
void postorder(bst t);

// preorder() function to traverse tree
void preorder(bst t);

// count function counts the total nodes in the tree
int count(bst t);

// count_leaf() function counts the total leaf nodes
// total leaf nodes
int count_leaf(bst t);

// isfilltree() tree returns the boolian type if the tree is full or not
// tree is full or not
int isfullTree(bst t);

// depth function return maximum number of nodes from root to the leaf
// similar to height of binary tree
int depth(bst t);

// level traversal function print the all nodes of a tree in level wise
// similar to how node stores in array
void level_traversal(bst t);

//  this is iterative inorder function
void inorder_rec(bst t);

// search() function search the given node in the tree
node* search(bst t, int d);

// showlongest() function for printing longest paths from the root
void showlongest(bst t);

// step() function counts the depth of the perticular node from root
int step(bst t, int d);

// function to check if the given tree is a BST or not
int isBST(bst t);

// showlongest() function for printing longest paths from the root
void LONG_PATH(bst t,int _height, bst root);

// height() function calculates the height of tree
int height(bst t);



// function to remove the node
void remoov(bst *t, int d);
