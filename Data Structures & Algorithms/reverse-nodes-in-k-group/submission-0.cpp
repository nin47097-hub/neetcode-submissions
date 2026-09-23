class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* curr = head;
        for (int i = 0; i < k; i++) {
            if (curr == nullptr) return head;
            curr = curr->next;
        }

  
        ListNode* prev = nullptr;
        ListNode* nextNode = nullptr;
        curr = head;
        for (int i = 0; i < k; i++) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }


        if (nextNode != nullptr) {
            head->next = reverseKGroup(nextNode, k);
        }

        return prev;
    }
};

