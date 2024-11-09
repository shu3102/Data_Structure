
#include<stdio.h>
#include<stdlib.h>

//creation of node
typedef struct node{
    int data;       // data part 
    struct node *next;      // pointer to next node 
}node;

// creating pointer to node name as list 
typedef node* list;




// initialization of the node
void init(list *l) {
   *l = NULL;
    return;
}



//traversing the Singly link list
void traverse(list l) {
    printf("[");
    node *p;
    p = l;
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("]\n");
    return;
}



// appending the node at the last of link list
void append(list *l, int d) {
    node *p, *newnode;
    newnode = (node*)malloc(sizeof(node));
    // put the data into the newly created node 
    if(newnode) {
        newnode -> data = d;
        newnode -> next = NULL;
    }
    else return;

    // if list is empty 
    // make newnode as head
    if(*l == NULL){
        *l = newnode;
        return;
    }
    p = *l;
    // keep traversing till the end of list is reached
    while(p -> next) {
        p = p->next;
    }
    // at last link the newnode 
    p->next = newnode;
    return;
}



//  add node at the start of the link list
void Addinlist(list *l, int d){
    node *p, *newnode;
    newnode = (node*)malloc(sizeof(node));
    // load data into the newnode 
    if(newnode){
        newnode -> data = d;
        newnode -> next = NULL;
    }
    else return;

    // if list is empty then make newnode as head 
    if(*l == NULL){
        *l = newnode;
        return;
    }
    // add newnode to the begining
    newnode->next = *l;
    *l = newnode;
    return;
}




// Function to reverse the linked list 
void reverse_list(list *l) {
    node* prev = NULL;
    node* current = *l;
    node* next = NULL;

    while (current != NULL) {
        // Store next
        next = current->next;

        // Reverse current node's pointer
        current->next = prev;
        
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    *l = prev;
}


// find lenght of link list
int lenght(list l) {
    node *p = l;
    int c = 0;  // variable to return the lenght 
    while(p) {
        // run loop till p not become nulll and keep incrementing c
        c++;
        p = p->next;
    }
    return c;
}




// inserting at given position the node at the given position of link list
void insertat(list *l, int d,int pos) {
    // position at start 
    if(pos == 1) {
        Addinlist(l, d);
        return;
    }
    // position is beyond lenght
    if(pos>= lenght(*l)) {
        append(l, d);
        return;
    }

    node *p, *newnode, *temp;
    newnode = (node*)malloc(sizeof(node));
    if(newnode){
        newnode -> data = d;
        newnode -> next = NULL;
    }
    else return;

    if(*l == NULL){
        *l = newnode;
        return;
    }
    int counter = 1;

    p = *l;
    while(counter != pos-1) {
        p = p->next;
        counter++;
    }
    temp = p->next;
    p->next = newnode;
    newnode->next = temp;
    return;
}

// search the node into link list 
int search(list l, int d) {
    node* p = l;
    while(p) {
        if(p->data == d)
            return 1;
        p = p->next;
    }
    return 0;
}




// addition of list l1 snd list l2
// result will be in list l3
// if we want to implement for number then we have to first reverse the lists
// complete
void Addition_of_list(list *l1, list *l2, list *l3) {

    node *p, *q, *r;
    p = *l1;
    q = *l2;
    r = *l3;

    int sum = 0, carry = 0, temp = 0;
    while(p && q) {
            temp = p->data + q->data + carry;
            sum = temp % 10;
            carry = temp / 10;
            p = p->next;
            q = q->next;
            append(l3, sum);
    }
    while(p) {
        temp = p->data;
        sum = temp % 10 + carry;
        carry = temp / 10;
        p = p->next;
        append(l3, sum);
    }
    while(q) {
        temp = q->data;
        sum = temp % 10 + carry;
        carry = temp / 10;
        q = q->next;
        append(l3, sum);
    }
    if(carry != 0) {
        append(l3, carry);
    }
    return;
}



// subtraction of list l1 snd list l2
// result will be in list l3
// if we want to implement for number then we have to first reverse the lists
// 
void Subtraction_of_list(list *l1, list *l2, list *l3) {
    node *p, *q, *r;
    p = *l1;
    q = *l2;
    r = *l3;

    int sum = 0, carry = 0, temp = 0;
    while(p && q) {

            if(p->data < q->data) {
                p->next ->data--;
                p->data = p->data + 10;
            }

            temp = p->data - q->data;
            sum = temp % 10;
            //carry = temp / 10;
            p = p->next;
            q = q->next;
            append(l3, sum);
            traverse(*l3);
    }
    while(p) {
        temp = p->data;
        sum = temp % 10;
        //carry = temp / 10;
        p = p->next;
        append(l3, sum);
    }
    while(q) {
        temp = q->data;
        sum = temp % 10;
        //carry = temp / 10;
        q = q->next;
        append(l3, sum);
    }
    if(carry != 0) {
        append(l3, carry);
    }
    return;
}



// multipliaction of list l1 and list l2 
// funtion will return result pointer
// complete
node* Multiplication_of_list(list *l1, list *l2) {

    list L3;
    init(&L3);

    int m = lenght(*l1);
    int n = lenght(*l2);
    for(int z = 0; z < m+n+1; z++) {
        append(&L3,0);
    }
    node *p, *q;
    q = *l2;

    node *reference = L3, *r_run;

    while(q) {
        int carry = 0;
        r_run = reference;
        p = *l1;
        while(p) {
            int mul = p->data * q->data + carry;
            r_run->data += mul % 10;
            carry = mul / 10 + r_run->data/10;
            r_run->data = r_run->data%10;  
            p = p->next;
            r_run = r_run->next;
        }
        if(carry > 0) {
            r_run->data += carry;
        }
        reference = reference->next;
        q = q->next;
    }
    // remove zeros if there in start
    reverse_list(&L3);
    while(L3->data == 0 && lenght(L3) > 1) {
        node *temp_remove = L3;
        L3 = L3->next;
    }
    reverse_list(&L3);
    return L3;
}





// Function to get union of two linked lists head1 and head2 
node* Union(list head1, list head2) {
    list l3;
    init(&l3);
    node *t1 = head1, *t2 = head2;
 
    // Insert all elements of
    // list1 to the result list
    while (t1 != NULL) {
        append(&l3, t1->data);
        t1 = t1->next;
    }
    // Insert those elements of list2
    // which are not present in result list
    while (t2 != NULL) {
        if (!search(l3, t2->data)) { 
            append(&l3, t2->data);
        }
        t2 = t2->next;
    }
    return l3;
}


 
// Function to get intersection of two linked lists head1 and head2 
node* Intersection(list head1, list head2) {
    list l3;
    init(&l3);
    node* t1 = head1;
 
    // Traverse list1 and search each element of it in list2.
    //  If the element is present in list 2, then
    // insert the element to result
    while (t1 != NULL) {
        if(search(head2, t1->data))
           append(&l3, t1->data);
        t1 = t1->next;
    }
    return l3;
}


void begdelete(list *head) {  
        node *ptr;  
        if(head == NULL) {  
            printf("\nList is empty");  
        }  
        else {  
            ptr = *head;  
            *head = ptr->next;  
            free(ptr);  
            printf("Node deleted from the begining ...\n");  
        }  
    }  




// Function to delete the entire linked list 
void deleteList(list* head_ref) {
   // deref head_ref to get the real head 
   node* current = *head_ref;
   node* next;
 
   while (current != NULL) {
       next = current->next;
       free(current);
       current = next;
   }
   
   /* deref head_ref to affect the real head back in the caller. */
   *head_ref = NULL;
}







int main() {

    // link list creation and initialization 
    list l;
    init(&l);

    list l2;
    init(&l2);

    list l3;
    init(&l3);

    append(&l, 1);
    Addinlist(&l,9);
    append(&l, 5);
    Addinlist(&l, 8);
    //insertat(&l, 15, 3);
    traverse(l);
    append(&l2, 1);
    Addinlist(&l2, 7);
    append(&l2, 2);
    Addinlist(&l2, 6);
    //insertat(&l, 15, 1111);
    traverse(l2);
    begdelete(&l2);
    traverse(l2);
    //reverse_list(&l);
    //Addition_of_list(&l, &l2, &l3);
    //node *res = Multiplication_of_list(&l, &l2);
    //node *res = Intersection(l, l2);
    

}
