/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
struct Comp{
    int length;
    ListNode* A;
};

struct Comp revlen(ListNode* A)
{
    int length = 0;
    ListNode * prev = NULL;
    ListNode * front = NULL;
    
    while(A->next!=NULL)
    {
        front = A->next;
        A->next = prev;
        prev = A;
        A = front;
        length++;
    }
    
    A->next = prev;
    length++;
    struct Comp ans;
    ans.A = A;
    ans.length = length;
    return ans;
}
 
ListNode * rotate(ListNode * A,int k)
{
    ListNode * prev = NULL;
    ListNode * current = A;
    ListNode * tail = A;
    
    while(tail->next!=NULL)tail = tail->next;
    
    int i=0;
    while(i<k)
    {
        prev = current;
        current = current->next;
        i++;
    }
    
    tail->next = A;
    prev->next = NULL;
    A = current;
    return A;
}
 
ListNode* Solution::rotateRight(ListNode* A, int B) {
    if(A==NULL || A->next==NULL)return A;
    
    struct Comp aux;
    aux = revlen(A);
    A = aux.A;
    int length = aux.length;
    B = B%length;
    if(B!=0)
    A = rotate(A,B);
    aux = revlen(A);
    
    return aux.A;
}
