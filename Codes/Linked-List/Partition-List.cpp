/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    
    if(A==NULL || A->next==NULL)return A;
    ListNode * list1 = NULL;
    ListNode * list1tail = NULL;
    ListNode * list2 = NULL;
    ListNode * list2tail = NULL;
    
    ListNode* current = A;
    
    while(current!=NULL)
    {
        if(current->val<B)
        {
            if(list1==NULL)
            {
                list1 = current;
                list1tail = current;
                current = current->next;
                list1->next = NULL;
            }
            
            else
            {
                list1tail->next = current;
                current = current->next;
                list1tail = list1tail->next;
                list1tail->next = NULL;
            }
        }
        
        else
        {
            if(list2==NULL)
            {
                list2 = current;
                list2tail = current;
                current = current->next;
                list2->next = NULL;
            }
            
            else
            {
                list2tail->next = current;
                current = current->next;
                list2tail = list2tail->next;
                list2tail->next = NULL;
            }
        }
        
    }
    
    if(list1==NULL)return list2;
    list1tail->next = list2;
    return list1;
    
}
