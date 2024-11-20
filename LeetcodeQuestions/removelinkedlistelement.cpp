#include <bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution{
public:
    ListNode *removeElements(ListNode *head, int val){
        if (!head)
            return head;
        while (head->val == val){
            head = head->next;
        }
        ListNode *temp = head;
        while (temp->next){
            while (temp->next && temp->next->val != val){
                temp = temp->next;
            }
            while (temp->next && temp->next->val == val){
                temp->next = temp->next->next;
            }
            temp = temp->next;
        }
        return head;
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
    // head1->next = new ListNode(2);
    // head1->next->next = new ListNode(6);
    // head1->next->next->next = new ListNode(3);
    // head1->next->next->next->next = new ListNode(4);
    // head1->next->next->next->next->next = new ListNode(5);
    // head1->next->next->next->next->next->next = new ListNode(6);
    printList(a.removeElements(head1, 2));
}