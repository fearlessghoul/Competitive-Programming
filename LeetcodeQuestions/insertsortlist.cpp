#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode *head){
    ListNode *current = head;
    while (current != nullptr){
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
class Solution {
public:
    void insert(ListNode*& dest,ListNode*head){
        if(head->val < dest->val){
            head->next=dest;
            dest=head;
            return;
        }
        ListNode * temp=dest;
        while(temp->next && temp->next->val < head->val){
            temp=temp->next;
        }
        head->next=temp->next;
        temp->next=head;
    }
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *temp=head->next,*next;
        head->next=nullptr;
        while(temp){
            next=temp->next;
            insert(head,temp);
            temp=next;
        }
        return head;
    }
};
int main(){
    Solution a;
    ListNode *head1 = new ListNode(4);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(1);
    head1->next->next->next = new ListNode(3);
    ListNode *res = a.insertionSortList(head1);
    printList(res);
}