/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* rev(ListNode* A)
{
    ListNode * prev = NULL;
    ListNode * front = NULL;
    
    while(A->next!=NULL)
    {
        front = A->next;
        A->next = prev;
        prev = A;
        A = front;
    }
    
    A->next = prev;
    return A;
}

ListNode* Solution::reverseList(ListNode* A, int B) {
    
    if(A==NULL || A->next==NULL || B==1)return A;
    
    ListNode * front = A;
    ListNode * current = A;
    ListNode * prevhead = NULL;
    while(current!=NULL)
    {
        ListNode * prev = NULL;
        int i = 0;
        while(i<B)
        {
            prev = current;
            current = current->next;
            i++;
        }
        
        prev->next = NULL;
        prev = rev(front);
        if(front==A)
        {
            A = prev;
        }
        else prevhead->next = prev;
        front->next = current;
        prevhead = front;
        front = current;
    }
    
    return A;
}
