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
    ListNode *reverseList(ListNode *head,ListNode*exm){
        ListNode *prev = nullptr, *current = head, *next = nullptr;
        while (current != nullptr){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head->next=exm;
        return prev;
    }
    ListNode *reverseBetween(ListNode *head, int left, int right){
        if (left == right)
            return head;
        ListNode *temp1 = head;
        for (int i = 2; i < left; i++)
                temp1 = temp1->next;
        ListNode *temp2 = head;
        for (int i = 1; i < right; i++)
                temp2 = temp2->next;
        ListNode*exm = temp2->next;
        temp2->next=nullptr;
        if(left == 1){
            return reverseList(head,exm);
        }
        temp1->next=reverseList(temp1->next,exm);
        return head;
        
    }
};
int main(){
    Solution a;

    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);
    ListNode *res = a.reverseBetween(head2, 3,4);
    printList(res);
}