class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        
        // study struct in c++
        
        ListNode h = ListNode(-1);
        ListNode* header = &h;
        header->next = head;
        
        helper(header,header->next);
        
        return header->next;
    }
    
    int helper(ListNode* node, ListNode* nxtnode)
    {    
        
        int mx=node->val;
        if(node->next == NULL)
            return node->val;
        
        mx = max(helper(node->next,nxtnode->next),nxtnode->val);
        
        
        if(mx>nxtnode->val)
        {
            node->next = nxtnode->next;
        }
        
        return mx;     
        
    }
};