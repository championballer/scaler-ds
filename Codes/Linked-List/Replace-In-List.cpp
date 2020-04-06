/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A, ListNode* B, int C, int D) {
    
    int f = 0;
    int s = 0;
    if(A==NULL)return B;
    if(B==NULL)return NULL;
    ListNode* headB = B;
    ListNode* tailB = B;
    
    while(tailB->next!=NULL)
    {
        tailB=tailB->next;
    }
    
    ListNode* prev = NULL;
    ListNode* current = A;
    ListNode* next = A->next;
    while(f!=C)
    {
        f++;
        prev = current;
        current = current->next;
    }
    while(s!=D)
    {
        s++;
        next = next->next;
        
    }
    
    if(prev==NULL)A = headB;
    else 
    {
        current = prev->next;
        prev->next = headB;
    }
    
    tailB->next = next;
    while(current!=next)
    {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }
    
    return A;
}
