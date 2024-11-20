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

class Solution{
public:
    ListNode *reverseList(ListNode *head){
        ListNode *prev = nullptr, *current = head, *next = nullptr;
        while (current != nullptr){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    void merge(ListNode*l1,ListNode*l2){
        ListNode*head;
        while(l1 && l2){
            head=l1;
            l1=l1->next;
            head->next=l2;
            head=l2;
            l2=l2->next;
            head->next=l1;
        }
    }
    void reorderList(ListNode *head){
        if (!head || !head->next)
            return;
        ListNode*one=head,*two=head->next;
        while(two && two->next){
            one=one->next;
            two= two->next->next;
        }
        two=reverseList(one->next);
        one->next=nullptr;
        merge(head,two);
    }
};
int main(){
    Solution a;

    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    printList(head2);
    a.reorderList(head2);
    printList(head2);
}