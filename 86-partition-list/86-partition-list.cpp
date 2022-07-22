// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* partition(ListNode* head, int x) {
//         ListNode* temp = head;
//         ListNode* first;
//         ListNode* second;
//         ListNode* newList;
//         ListNode* temp1;
//         temp1 = newList;
//         while(temp)
//         {
//             if(temp->val < x && temp== head){
//                     newList = temp;
//                     newList= newList->next;
//                     temp = temp->next;
//                     second = temp;
//             }
            
//             else if(temp->val< x){
//                 newList->next = temp;
//                 newList= newList->next;
//                 second->next = temp->next;
//                 temp = temp->next;
//             }
//             else
//                 temp = temp->next;
                
//         }
//         while(temp1)
//         {
//             cout<<temp1->val<<" ";
//             temp1= temp1->next;
//         }
//         return second;
//     }
// };

class Solution {
public:
    
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* small = new ListNode(-1);
        ListNode* large = new ListNode(-1);
        ListNode* small_head = small;
        ListNode* large_head = large;
        
        while (head){
            if (head->val < x){
                small->next = head;
                small = small -> next;
                head = head -> next;
                small->next = NULL;
            }
            else{
                large->next = head;
                large = large -> next;
                head = head -> next;
                large -> next = NULL;
            }
        }
        small -> next = large_head -> next;

        return small_head -> next;
    }
};