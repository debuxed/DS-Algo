#include<iostream>
#define endl '\n'
using namespace std;

struct Node {
	int data;
	struct Node *next;
};

// Creating the first node of type struct which can be used to store the starting 
// position of the node and can be used while passing as the parameter from the main function
struct Node *first = NULL;

void create(int A[], int n) {
	
	struct Node *t, *last;

	// setting the first value of the node.
	first = new struct Node;
	first->data = A[0];
	first->next = NULL;
	last = first;
	
	// Create new node for all other elements starting from 1
	for(int i=1; i<n ; i++) {
		t = new struct Node;
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}

void display(struct Node *t) {
	while(t) {
		cout << t->data << "->";
		t = t->next;
	}
}

void removeDuplicates(struct Node *p){
	struct Node *q = p->next;
	while(q!=NULL){
		cout << p->data << endl;
		// Check if the current node is equal to the next node
		if(p->data != q->data) {
			p = q;
			q = q->next;
		} else {
			p->next = q->next;
			delete q;
			q = p->next;
		}
	}
}

int main() {
	int A[] = {10, 20, 20, 20, 30, 40, 50};
	create(A, 7);
	removeDuplicates(first);
	display(first);	
}

