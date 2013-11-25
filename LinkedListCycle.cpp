/*
    Given a linked list, determine if it has a cycle in it.
*/

bool hasCycle(ListNode *head) {
    if (!head)
        return false;
    ListNode* slow = head->next;
    if (!slow)
        return false;
    ListNode* fast = slow->next;
    while (slow != fast)
    {
        if (!fast || !(fast->next))
            return false;
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}
