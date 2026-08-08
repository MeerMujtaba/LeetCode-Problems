/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {

        if (head == NULL) {
            return head;
        }

        Node* curr = head;

        while (curr != NULL) {

            if (curr->child != NULL) {

                Node* Next = curr->next;

                // Flatten the child list
                curr->next = flatten(curr->child);

                // Connect child list back to curr
                curr->next->prev = curr;

                // Remove child pointer
                curr->child = NULL;

                // Go to the end of the child list
                while (curr->next != NULL) {
                    curr = curr->next;
                }

                // Connect original next part
                if (Next != NULL) {
                    curr->next = Next;
                    Next->prev = curr;
                }
            }

            curr = curr->next;
        }

        return head;
    }
};