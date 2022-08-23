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
    bool isPalindrome(ListNode* head) {
        vector<int> vec;
        int i=0,j,n, cnt=0;
        ListNode* node1 = head;
        ListNode* node2 = head;
        while(node1)
        {
            cnt++;
            node1 = node1->next;
        }
      
       
        while(i!=cnt/2)
        {
            vec.push_back(node2->val);
            node2= node2->next;
            i++;
        }
       
        reverse(vec.begin(), vec.end()); 
        for(auto &x: vec)
            cout<<x<<" ";
        cout<<endl;
        i=0;
        if(cnt%2!=0)
            node2= node2->next;
        while(node2)
        {
            cout<<node2->val<<" "<<vec[i]<<endl;
            if(node2->val!=vec[i]){
                return false;
            }
            i++;
            node2= node2->next;
        }
        return true;
        
        
    }
};