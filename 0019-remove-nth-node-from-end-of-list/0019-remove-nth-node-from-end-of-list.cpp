class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* slow = head;
        ListNode* fast = head;

        // move fast n steps ahead
        while(n--) {
            fast = fast->next;
        }

        // if deleting first node
        if(fast == nullptr) {
            ListNode* temp = head;
            head = head->next;
            delete(temp);
            return head;
        }

        // move both pointers
        while(fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // delete node
        ListNode* temp = slow->next;
        slow->next = temp->next;

        delete(temp);

        return head;
    }
};