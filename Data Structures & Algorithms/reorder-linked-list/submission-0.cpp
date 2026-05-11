class Solution {
public:
    void reorderList(ListNode* head) {

        if(!head || !head->next) return;

        // Step 1: Find middle
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // Step 2: Reverse second half
        ListNode* curr = slow->next;
        slow->next = NULL;
        ListNode* prev = NULL;

        while(curr) {

            ListNode* nextNode = curr->next;

            curr->next = prev;

            prev = curr;

            curr = nextNode;
        }

        // prev = reversed second half
        ListNode* l1 = head;
        ListNode* l2 = prev;

        // Step 3: Merge
        while(l2) {

            ListNode* n1 = l1->next;
            ListNode* n2 = l2->next;

            l1->next = l2;

            l2->next = n1;

            l1 = n1;
            l2 = n2;
        }
    }
};