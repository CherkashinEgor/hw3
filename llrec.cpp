#include "llrec.h"
// #include <iostream>

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
// using namespace std;

void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot){
    if(head == NULL){
        if(smaller != NULL) smaller = NULL;
        if(larger != NULL) larger = NULL;
        return; 
    }
    if(head->val <= pivot){
        smaller = head;
        head = head->next;
        llpivot(head, smaller->next, larger, pivot);
    } else {
        larger = head;
        head = head->next;
        llpivot(head, smaller, larger->next, pivot);
    }
    head = NULL;
}
