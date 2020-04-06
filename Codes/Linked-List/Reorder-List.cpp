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
    ListNode* prev = NULL;
    ListNode* front = NULL;
    
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

ListNode* Solution::reorderList(ListNode* A) {
    
    if(A==NULL || A->next==NULL || A->next->next==NULL)return A;
    ListNode* fast = A;
    ListNode* slow = A;
    
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    ListNode* l2 = slow->next;
    slow->next = NULL;
    l2 = rev(l2);
    
    ListNode * result = NULL;
    ListNode* resultTail = NULL;
    ListNode * current1 = A;
    ListNode * current2 = l2;
    
    while(current1!=NULL && current2!=NULL)
    {
        if(result==NULL)
        {
            result = current1;
            current1 = current1->next;
            resultTail = current2;
            current2 = current2->next;
            result->next = resultTail;
            resultTail->next = NULL;
            
        }
        
        else
        {
            resultTail->next = current1;
            current1 = current1->next;
            resultTail = resultTail->next;
            resultTail->next = current2;
            current2 = current2->next;
            resultTail = resultTail->next;
            resultTail->next = NULL;
        }
    }
    
    resultTail->next = current1;
    
    return result;
}
