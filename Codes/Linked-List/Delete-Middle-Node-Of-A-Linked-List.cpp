/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
    if(A==NULL)return NULL;
    if(A->next==NULL)
    {
        delete A;
        return NULL;
    }
    
    ListNode* slow = A;
    ListNode* fast = A;
    
    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    ListNode* temp = A;
    while(temp->next!=slow)
    {
        temp = temp->next;
    }
    
    temp->next = slow->next;
    delete slow;
    
    return A;
    
}
