/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    
    ListNode* current = A;
    ListNode* prev = NULL;
    while(current!=NULL && current->next!=NULL)
    {
        if(current->val==current->next->val)
        {
            int temp = current->val;
            while(current->next!=NULL && current->next->val==temp)
            {
                current = current->next;
            }
            
            ListNode* delStart = NULL;
            ListNode* delEnd = NULL;
            if(prev!=NULL)
            {
                delStart = prev->next;
                prev->next = current->next;
                delEnd = current;
                current = prev->next;
                delEnd->next = NULL;
                
                
            }
            
            else
            {
                delStart = A;
                A = current->next;
                delEnd = current;
                current = A;
                delEnd->next = NULL;
            }
            
            while(delStart!=NULL)
                {
                    ListNode* aux = delStart;
                    delStart = delStart->next;
                    delete aux;
                }
        }
        
        else
        {
            prev = current;
            current = current->next;
        }
    }
    
    return A;
        
}
