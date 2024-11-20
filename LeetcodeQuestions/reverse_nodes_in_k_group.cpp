#include <bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k,bool reverse=true) {
        if(!head) return head;
        ListNode *prev = nullptr, *current = head, *next = nullptr;
        int len=0;
        while (current != nullptr && len < k) {
            cout<<current->val<<" ";
            next = current->next; // Store the next node
            current->next = prev; // Reverse the current node's pointer
            prev = current; // Move pointers one position ahead
            current = next;
            len++;
        }
        cout<<endl;
        if(len<k)
            return  reverse ? reverseKGroup(prev,k,false): prev;
        head->next= reverseKGroup(current,k);
        return prev;
    }
};
void printList(ListNode *head){
    ListNode *current = head;
    while (current != nullptr){
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}
int main(){
    Solution a;
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(6);
    head1->next->next->next = new ListNode(3);
    head1->next->next->next->next = new ListNode(4);
    printList(a.reverseKGroup(head1,3));
}