
class Solution {
public:
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*>seen;
        ListNode*curr = head;
        while (curr){
            if(seen.find(curr)!= seen.end()){
                return true;

            }
            else{
                seen.insert(curr);
                curr = curr->next;
            }
        }
        return false;
        
    }
};
