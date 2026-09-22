
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*dummy = new ListNode();
        ListNode*k =dummy;
        int carry =0;
        int v1;
        int v2;
        while(l1!=nullptr || l2!=nullptr || carry!= 0){
            if(l1!=nullptr){
                v1 = l1->val;


            }
            else if(l1== nullptr){
                v1 = 0;
            }
            if(l2!=nullptr){
                v2 = l2->val;


            }
            else if(l2 == nullptr){
                v2 = 0;
            }
            int sum = v1+v2+carry;
            carry = sum/10;
            k->next = new ListNode(sum%10);
            k = k->next;

            if(l1!= nullptr){
                l1 = l1->next;
            }
            if(l2!= nullptr){
                l2 = l2->next;

            }



        }
        return dummy->next;
        


        
    }
};
