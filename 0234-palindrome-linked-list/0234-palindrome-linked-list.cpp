/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseLinkedList(ListNode* head)
    {
        ListNode* cur = head;
        ListNode* next = NULL;
        ListNode* prev = NULL;

        while(cur)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        while(fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast!=NULL) slow = slow->next;

        prev->next = NULL;
        ListNode* newHead = reverseLinkedList(slow);

        ListNode* temp1 = head;
        ListNode* temp2 = newHead;

        while(temp1 && temp2)
        {
            if(temp1->val != temp2->val)
            {
                return false;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        if(temp1 || temp2)
        {
            return false;
        }

        return true;
    }
};