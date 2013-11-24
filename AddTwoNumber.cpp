#include <iostream>
#include <stdlib.h>
using namespace std;

struct ListNode {
     int val;     
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* previous = dummy;
    int total;
    int carry = 0;
    while (l1 || l2)
    {
        total = ((l1)?l1->val:0) + ((l2)?l2->val:0) + carry;
        ListNode* current = new ListNode(total%10);
        previous->next = current;
        previous = current;
        carry = total/10;
        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }
    if (carry)
    {
        ListNode* last = new ListNode(carry);
        previous->next = last;
    }
    return dummy->next;
}

int main()
{
    ListNode* newNode = new ListNode(5);
    ListNode* newNode2 = new ListNode(6);
    ListNode* out = addTwoNumbers(newNode, newNode2);
    cout<< out->val << " "<< ((out->next != NULL) ? out->next->val : 0) <<endl;
}
