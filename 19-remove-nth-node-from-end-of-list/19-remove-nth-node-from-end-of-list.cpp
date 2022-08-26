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
        ListNode* node = head;
        ListNode* node1 = head;
        ListNode* node2 = NULL;
        int i,j, cnt=0;
        while(node)
        {
            cnt++;
            node= node->next;
        }
      
        int pos = cnt - n;
        if(pos==0)
            head= head->next;
        while(pos--)
        {
           
            if(pos==0)
            {
                node1->next = node1->next->next;
            }
            node1 = node1->next;
        }
        return head;
        
    }
};