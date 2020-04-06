/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
    
    unordered_set<ListNode*> ourset;
    ListNode* prev = NULL;
    ListNode* current = A;
    
    while(ourset.find(current)==ourset.end())
    {
        ourset.insert(current);
        prev=current;
        current=current->next;
    }
    prev->next = NULL;
    return A;
}
