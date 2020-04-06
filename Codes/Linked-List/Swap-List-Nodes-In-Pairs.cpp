/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    if(A==NULL || A->next==NULL)return A;
    A->next->next = swapPairs(A->next->next);
    
    ListNode* temp = A->next;
    A->next = A->next->next;
    temp->next = A;
    return temp;
}
