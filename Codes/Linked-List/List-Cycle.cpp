/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    ListNode* slow = A;
    ListNode* fast = A;
    
    int flag = 0;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow==fast)
        {
            flag = 1;
            break;
        }
    }
    
    if(!flag)return NULL;
    else
    {
        ListNode* temp = A;
        while(temp!=slow)
        {
            temp = temp->next;
            slow = slow->next;
        }
    }
    
    return slow;
}
