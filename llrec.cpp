#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot){
 
  if(!head){ //if linked list is empty = base case
    smaller = nullptr;
    larger = nullptr;
    return;
  }

  Node *current = head;
	head = head->next;

	llpivot(head, smaller, larger, pivot);//recursive call
	current->next = nullptr;

	if(current->val <= pivot){ //if currrent node < pivot 

		current->next = smaller; //add val to smaller list
		smaller = current;

	}else{

		current->next = larger; //add it to larger list
		larger=current;
	}
}
