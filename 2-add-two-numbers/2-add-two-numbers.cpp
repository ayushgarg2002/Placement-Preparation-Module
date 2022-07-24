class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1, *temp2=l2;
        ListNode* ans= new ListNode(-1);
        ListNode* res=ans;
        int carry=0;
        
        while(temp1 and temp2){
            int sum=temp1->val+temp2->val+carry;
            ans->next=new ListNode(sum%10);
            carry=sum/10;
            
            temp1=temp1->next;
            temp2=temp2->next;
            ans=ans->next;
        }
        
        while(temp1){
            int sum=temp1->val+carry;
            ans->next=new ListNode(sum%10);
            carry=sum/10;
            ans=ans->next;
            temp1=temp1->next;
        }
        
        while(temp2){
            int sum=temp2->val+carry;
            ans->next=new ListNode(sum%10);
            carry=sum/10;
            ans=ans->next;
            temp2=temp2->next;
        }
        
        if(carry) ans->next= new ListNode(carry);
        
        return res->next;
    }
};