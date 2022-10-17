#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------


bool comp(int i) {
    if(i % 2 == 0) return true;
    if(i % 2 == 1) return false;
}


int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    Node* head = readList(argv[1]);
    cout << "Original list: ";
    print(head);
    cout << "filter" << endl;
    Node* l = llfilter(head, comp);
    print(l);
    // Test out your linked list code

    // Node* head = new Node(1, new Node(2, new Node(4, new Node(5, new Node(10, new Node(15, new Node(100, NULL)))))));
    // print(head);
    // cout << "split " << endl;
    // Node* small = NULL;
    // Node* large = NULL;
    // llpivot(head, small, large, 50);
    // cout << "first smaller " << small->val << " next " << small->next << endl;
    // cout << "Smaller: ";
    // print(small);
    // cout << endl << "Larger: ";
    // print(large);
    // cout << "head " << head;

    
    return 0;

}
