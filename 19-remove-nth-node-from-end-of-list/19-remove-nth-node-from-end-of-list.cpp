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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
     int i,j, len=0, pos=0;
     ListNode* list1 = head;
         ListNode* list2 = head;
        while(list1)
        {
            list1 = list1->next;
            len++;
        }
        pos = len - n;
        if(pos==0)
            return head->next;
       
        while(pos--)
        {
            if(pos==0)
                 list2->next = list2->next->next;
            list2 = list2->next;
            
        }
       
        return head;
    }
};