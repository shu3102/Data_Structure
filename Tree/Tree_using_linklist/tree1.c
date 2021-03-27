
#include <stdio.h>
#include <stdlib.h>
#include"tree.h"
#include"tree_queue.h"
#include"tree_stack.h"


// function initializes the tree to null
void init(bst *l) {
    *l = NULL;
    return;
}


// function insert the node in binary search tree

void InsertNode(bst *l, int k) {

    // new node creation
    node *nn;
    nn = (node *)malloc(sizeof(node));
    nn->key = k;
    nn->left = NULL;
    nn->right = NULL;

    // if the malloc fails to return memory then return
    if(!nn) {
        return;
    }

    // pointing i to the root and q to null
    // q is follow ; p is current pointer
    node *p, *q = NULL;
    p = *l;

    // check if the tree is already empty
    // if already empty then return
    if(*l == NULL) {
        *l = nn;
        return;
    }

    // traversing the tree and finding the correct position
    // for inserting new node
    while(p) {
            // q is follow pointer
            q = p;

            // if the data we are inserting is already present
            // then free the momory of newnode
            if(p->key == k) {
                free(nn);
                return;
            }
            // if data less than current then go left
            if(k < p->key)
                p = p->left;
            else // else right
                p = p->right;
    }
    // if data is less than node then insert at left
    if(k < q->key) {
        q->left = nn;
    }
    else // else insert right
        q->right = nn;
    return;

}


// recursive function for traversing the tree
/*
Algorithm Inorder(tree)
   1. Traverse the left subtree, i.e., call Inorder(left-subtree)
   2. Visit the root.
   3. Traverse the right subtree, i.e., call Inorder(right-subtree)
*/
// this is a sorted order

void inorder(bst t) {
    // bst is pointer to the node

    if(!t)
        return;

    inorder(t->left);
    printf("%d ", t->key);
    inorder(t->right);
    return;

}


// recursive traverse of the preorder
//for traversing tree
/*
Algorithm preorder(tree)
   1. Visit the root.
   2. Traverse the left subtree, i.e., call Inorder(left-subtree)
   3. Traverse the right subtree, i.e., call Inorder(right-subtree)
*/

void preorder(bst t) {

    if(!t)
        return;

    printf("%d ", t->key);
    preorder(t->left);
    preorder(t->right);
    return;

}


// recursive function for traversing the tree
// postorder
/*
Algorithm postorder(tree)
   1. Traverse the left subtree, i.e., call Inorder(left-subtree)
   2. Traverse the right subtree, i.e., call Inorder(right-subtree)
   3. Visit the root.
*/

void postorder(bst t) {

    if(!t)
        return;

    postorder(t->left);
    postorder(t->right);
    printf("%d ", t->key);
    return;

}



// Iterative function to perform postorder traversal on the tree
// using two stack
//postorder() // write a non-recursive function for post order traversal.

/* ALGO
1.1 Create an empty stack
2.1 Do following while root is not NULL
    a) Push root's right child and then root to stack.
    b) Set root as root's left child.
2.2 Pop an item from stack and set it as root.
    a) If the popped item has a right child and the right child
       is at top of stack, then remove the right child from stack,
       push the root back and set root as root's right child.
    b) Else print root's data and set root as NULL.
2.3 Repeat steps 2.1 and 2.2 while stack is not empty.
*/

void postorder_twostack(bst t) {

    stack s1;
    init_stack(&s1, 10);

    stack s2;
    init_stack(&s2, 10);

    push_stack(&s1, *t);

    node n1;

    while(!isEmpty_stack(s1)) {

        n1 = pop_stack(&s1);

        push_stack(&s2, n1);

        if(n1.left)
            push_stack(&s1, *n1.left);
        if(n1.right)
            push_stack(&s1, *n1.right);

    }

    node n2;
    while(!isEmpty_stack(s2)){
        n2 = pop_stack(&s2);

        printf("%d ", n2.key);
    }
    return;
}



// depth is the function for counting the height
// height of the binary search tree

int depth(bst t) {

    if(!t)
        return -1;

    int l, r;
    l = depth(t->left);
    r = depth(t->right);

    // if left is greater than right
    // then return left + 1
    if(l>r)
        return l+1;
    else
        return r+1;
}


// count function counts the total number of nodes i
//n the binary search tree

int count(bst t) {

    if(!t)
        return 0;
    return 1 + count(t->left) + count(t->right);

}


// funtion to count the total number of
// leaf nodes in bst

int count_leaf(bst t) {

    if(!t)
        return 0;
    if(t->left == NULL && t->right == NULL)
        return 1;
    else
        return count_leaf(t->left) + count_leaf(t->right);

}


// function to find the tree is full or not

/* FULL BINARY TREE
A full binary tree (sometimes proper binary tree or 2-tree)
is a tree in which every node other than the leaves has two children.
*/


int isfullTree(bst t) {

    if(!t)
        return 1;
    if((t->left==NULL && t->right!=NULL) || (t->left !=NULL && t->right==NULL))
        return 0;

    if(t->left==NULL && t->right==NULL) {
        return 1;
    }

    int l = isfullTree(t->left);
    int r = isfullTree(t->right);

    return l*r;

}


//

/*
printLevelorder(tree)
1) Create an empty queue q
2) temp_node = root  // start from root
3) Loop while temp_node is not NULL
    a) print temp_node->data.
    b) Enqueue temp_node’s children
      (first left then right children) to q
    c) Dequeue a node from q.
*/

void level_traversal(bst t) {

    queue Q;
    init_queue(&Q, 10);

    node temp;

    enqueue(&Q, *t);
    temp = *t;
    while(!isEmpty(Q)) {
        printf("%d ", temp.key);
        if(temp.left != NULL)
            enqueue(&Q, *temp.left);
        if(temp.right != NULL)
            enqueue(&Q, *temp.right);
        temp = dequeue(&Q);
    }
    return;
}




// search the node in a binary search tree
node* search(bst t, int d) {

    node* p = t;
    if(!t)
        return p;

    while(p) {
        if(p->key == d)
            return p;
        if(d<p->key)
            p = p->left;
        else
            p = p->right;
    }
    return p;
}


// inorder traversing without recursion
/*
1) Create an empty stack S.
2) Initialize current node as root
3) Push the current node to S and set current = current->left until current is NULL
4) If current is NULL and stack is not empty then
     a) Pop the top item from stack.
     b) Print the popped item, set current = popped_item->right
     c) Go to step 3.
5) If current is NULL and stack is empty then we are done.
*/
void inorder_TWO_STACK(bst t) {

    if(!t)
        return;

    stack s;
    init_stack(&s, 10);

    node *current;
    current = t;

    node n;
    while(current || !isEmpty_stack(s)) {
        if(current) {
            push_stack(&s, *current);
            current = current->left;
        }
        else{
            n = pop_stack(&s);
            printf("%d ", n.key);
            current = n.right;
        }
    }
    return;
}


// function to remove the node
void remoov(bst *t, int d) {

        // tree is empty
        if(!t)
            return;

        node *p, *q;
        // set the pointer p to the root and q = NULL
        p = *t;
        q = NULL;

        // searching for the node in the tree
        int side;
        while(p) {
            if(d == p->key) {
                break;
            }
            q = p;
            if(d < p->key) {
                p = p->left;
                side = 0;
            }
            else {
                p = p->right;
                side = 1;
            }
        }

            // if p is null that means node is not found so return p
            if(!p)
                return;


            // we come here means node is found so now check cases and free
            // p is not null


            // leaf node
            if(!p->left && !p->right) {
                if(!q) {
                    *t = NULL;
                    free(p);
                    return;
                }
                if(side) {
                    q->right = NULL;
                }
                else {
                    q->left = NULL;
                }
                free(p);
                return;
            }

            // one chilren
            // suppose the P node have only one child and that is left child
            if(p->left && !p->right) {
                // p can be a root node
                if(q == NULL) {
                    *t = p->left;
                    free(p);
                    return;
                }
                //
                if(side == 0) {
                    q->left = p->left;
                    free(p);
                    return;
                }
                else {
                    q->right = p->left;
                    free(p);
                    return;
                }
            }

            // suppose the P node have only one child and that is right child
            if(!p->left && p->right) {
                // p can be a root node
                if(q == NULL) {
                    *t = p->right;
                    free(p);
                    return;
                }
                //
                if(side == 0) {
                    q->left = p->right;
                    free(p);
                    return;
                }
                else {
                    q->right = p->right;
                    free(p);
                    return;
                }
            }



            //two children
            //
            if(p->left && p->right) { // p is the node with both children

                node *r, *s = NULL;
                r = p->left;

                while(r->right) {
                    s = r;
                    r = r->right;
                }

                // if the S is null
                // copy R to P
                // make p-> left as null and free r

                if(!s) {
                    p->key = r->key;
                    p->left = NULL;
                    free(r);
                    return;
                }
                // we are at the rightmost place of the left subtree
                // if there is a node at the left of the R then
                if(r->left) {
                    s->right = r->left;
                }
                else
                    s->right = NULL;

                // transfer the data from the R to P
                p->key = r->key;
                s->right = r->left;
                free(r);
            }
        return;
    }


/*

int iscomplete(bst t) {

    if(!t)
        return 1;

    queue Q;
    init_queue(&Q, 10);

    node temp;

    enqueue(&Q, *t);
    temp = *t;
    while(!isEmpty(Q)) {
        printf("%d ", temp.key);
        if(temp.left != NULL)
            enqueue(&Q, *temp.left);
        if(temp.right != NULL)
            enqueue(&Q, *temp.right);
        temp = dequeue(&Q);
    }
    re
}

*/


// ***********************************************************************************************************************************

// bst is a pointer to the node
// bst tree
// function that print all nodes from root to the data node
void printroute(bst t, int data) {
    node *p = t;

    while(p) {
        if(p->key == data) {
            printf("%d ", p->key);
            return;
        }
        if(data<p->key) {
            printf("%d -> ", p->key);
            p = p->left;
        }
        else {
            printf("%d -> ", p->key);
            p = p->right;
        }
    }
    return;
}




// bst is a pointer to the node
// bst tree
// argument 1 bst t for current pointer of the tree
// int height is the total height of the funvtion
// argument 3 is the pointer to root always
void LONG_PATH(bst t,int _height, bst root) {

    // if null return
    if(!t)
        return;
    // traverse left
    LONG_PATH(t->left, _height, root);
    LONG_PATH(t->right, _height, root);
    int ttt = step(root, t->key);
    if(ttt == _height) {
        printroute(root, t->key);
    }
    //return;
}



// step function count the height of the perticulur node
// from the top
// bst is a pointer to the node
// bst tree
int step(bst t, int d) {

    int pos = 0;

    node* p = t;
    if(!t)
        return pos;

    while(p) {
        if(p->key == d)
            return pos;
        if(d<p->key)
            p = p->left;
        else
            p = p->right;
        pos++;
    }
    return INT_MIN;
}




// depth is the function for counting the height
// height of the binary search tree
int height(bst t) {

    if(!t)
        return -1;

    int l, r;
    l = height(t->left);
    r = height(t->right);

    // if left is greater than right
    // then return left + 1
    if(l>r)
        return l+1;
    else
        return r+1;
}


// ***********************************************************************************************************************************

// bst is a pointer to node
// function to find maximum number
int findMax(bst root) {
    // Base condition
    if (root == NULL)
        return INT_MIN;


    int res = root->key;
    int lres = findMax(root->left);
    int rres = findMax(root->right);
    if (lres > res)
        res = lres;
    if (rres > res)
        res = rres;
    return res;
}


// ***********************************************************************************************************************************






/* Function to get the count of non_leaf Nodes in

a binary tree*/


// tree is a pointer to node
int itrative_Count(bst t){
// If tree is empty
    if (!t)
       return 0;
  //queue data structure is include
// Initialize empty queue.
    queue q;
// Do level order traversal starting from root
     int count = 0; // Initialize count of leaves
     enqueue(&q, *t);
     while (!isEmpty(q)){
        node temp = dequeue(&q);
        if (temp.left != NULL)
           enqueue(&q, *temp.left);
        if (temp.right != NULL)
           enqueue(&q, *temp.right);
       if (temp.left != NULL && temp.right != NULL)
           count++;
       }
       return count;
}



// bst is a pointer to the node
// bst tree
int countNonleaf(bst t) {
     // Base cases.
     if (t == NULL)
        return 0;
    if(t->left == NULL && t->right == NULL)
         return 0;

    // If root is Not NULL and its one of its child is also not NULL
    return 1 + countNonleaf(t->left) + countNonleaf(t->right);
}



// Iterative function to perform inorder traversal on the tree
void Inorder_ONE_STACK(bst root) {
    // create an empty stack
    stack S;
    init_stack(&S, 10);

    // start from the root node (set current node to the root node)
    node *curr = root;

    // if the current node is null and the stack is also empty, we're done
    while (!isEmpty_stack(S) || curr != NULL)
    {
        // if the current node exists, push it into the stack (defer it)
        // and move to its left child
        if (curr != NULL)
        {
            push_stack(&S, *curr);
            curr = curr->left;
        }
        else
        {
            // otherwise, if the current node is null, pop an element from the stack,
            // print it, and finally set the current node to its right child
            node Nodenode1 = pop_stack(&S);
            curr = &Nodenode1;
            printf("%d ", curr->key);
            //cout << curr->data << " ";

            curr = curr->right;
        }
    }
}





// mirror() function gives mirror of binary tree
void mirror(bst t) {
  if (!t)
    return;
  else
  {
    node* temp;

    /* do the subtrees */
    mirror(t->left);
    mirror(t->right);

    /* swap the pointers in this node */
    temp = t->left;
    t->left  = t->right;
    t->right = temp;
  }
}


// not perfect working
int is_complete_bst(bst t){
    if( t == NULL)
        return 1;

    queue q;
    init_queue(&q, 30);

    int flag = 0;
    enqueue(&q, *t);
    node p;
    while(!isEmpty(q)){

        p = dequeue(&q);

        if(p.left){
            if(flag == 1)
                return 0;
            enqueue(&q, *p.left);
        }
        else
            flag = 1;

        if(p.right){
            if(flag == 1)
                return 0;
            enqueue(&q, *p.right);
        }
        else
            flag = 1;
    }
    return 1;
}


//
int isBST(bst t)  {
    // null tree is a binary search tree
    if(!t)
        return 1;

    // false if left is > than right node
    if (t->left != NULL && t->left->key > t->key)
        return 0;

    // false if right is < than node
    if (t->right != NULL && t->right->key< t->key)
        return 0;

    // false if, recursively, the left or right is not a BST
    if (!isBST(t->left) || !isBST(t->right))
        return 0;

    // passing all that, it's a BST
    return 1;
}




/* Get width of a given level */
int getWidth(bst root, int level) {

    if (root == NULL)
        return 0;

    if (level == 1)
        return 1;

    if (level > 1)
        return getWidth(root->left, level - 1) + getWidth(root->right, level - 1);

    return 0;
}




/* Function to get the maximum width of a binary tree*/
int getMaxWidth(bst root) {
    int maxWidth = 0;
    int width;
    int h = height(root);
    int i;

    /* Get width of each level and compare
       the width with maximum width so far */
    for (i = 1; i <= h; i++) {
        width = getWidth(root, i);
        if (width > maxWidth)
            maxWidth = width;
    }

    return maxWidth;
}
