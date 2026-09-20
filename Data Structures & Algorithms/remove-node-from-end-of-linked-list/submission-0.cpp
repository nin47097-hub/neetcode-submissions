
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*curr= head;
        int length = 0;
        while(curr){
            length +=1;
            curr = curr->next;
        }
        if(length == n){
            return head->next;
        }
        ListNode*k = head;
        int i = 0;
        while(k){
            if((length-i)==n+1){
                k->next = k->next->next;
                break;
            }
            k=k->next;
            i+=1;
        }
        return head;
        
    }
};
