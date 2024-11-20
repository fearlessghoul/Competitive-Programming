#include <bits/stdc++.h>
using namespace std;
class CustomDeque{
private:
    int *arr;
    int head;
    int rear;
    int capacity;
    int count;

public:
    CustomDeque(int size=1){
        arr = new int[size];
        capacity = size;
        head = -1;
        rear = 0;
        count = 0;
    }
    ~CustomDeque(){
        delete[] arr;
    }
    void resize(int size){
        delete[] arr;
        arr = new int[size];
        capacity = size;
        head = -1;
        rear = 0;
        count = 0;
    }
    void push_front(int value){
        if (isFull()){
            cout << "Deque overflow!" << endl;
            return;
        }
        if (isEmpty()){
            head = 0;
            rear = 0;
        }
        else if (head == 0){
            head = capacity - 1;
        }
        else{
            head--;
        }
        arr[head] = value;
        count++;
    }
    void push_back(int value){
        if (isFull()){
            cout << "Deque overflow!" << endl;
            return;
        }
        if (isEmpty()){
            head = 0;
            rear = 0;
        }
        else if (rear == capacity - 1){
            rear = 0;
        }
        else{
            rear = rear + 1;
        }
        arr[rear] = value;
        count++;
    }
    void pop_front(){
        if (isEmpty()){
            cout << "Deque underflow!" << endl;
            return;
        }
        if (head == rear){
            head = -1;
            rear = 0;
        }
        else{
            head = (head + 1) % capacity;
        }
        count--;
    }
    void pop_back(){
        if (isEmpty()){
            cout << "Deque underflow!" << endl;
            return;
        }
        if (head == rear){
            head = -1;
            rear = 0;
        }
        else{
            rear = (capacity + rear - 1) % capacity;
        }
        count--;
    }
    int front() const{
        if (isEmpty()){
            cout << "Deque is empty!" << endl;
            return -1;
        }
        return arr[head];
    }
    int back() const{
        if (isEmpty()){
            cout << "Deque is empty!" << endl;
            return -1;
        }
        return arr[rear];
    }
    bool isFull() const{
        return count == capacity;
    }
    bool isEmpty() const{
        return count == 0;
    }
    int size() const{
        return count;
    }
};
class Solution {
    CustomDeque window;
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k==1)return nums;
        else if(k == nums.size()){
            for(int i=1;i<nums.size();i++){
                if(nums[i]!=nums[i-1]+1){
                    return {-1};
                }
            }
        }
        window.resize(k);
        vector<int>  ans(nums.size()-k+1);
        int j=0;
        for(int i=0;i<k;i++){
            while(!window.isEmpty() && nums[window.back()]+1!=nums[i]) window.pop_back();
            window.push_back(i);
        }
        if(window.size()<k)ans[j++]=-1;
        else ans[j++]=nums[window.back()];
        for (int i = k; i < nums.size(); i++){
            while(!window.isEmpty() && window.front() <= i-k) window.pop_front();
            while(!window.isEmpty() && nums[window.back()]+1!=nums[i]) window.pop_back();
            window.push_back(i);
            if(window.size()<k)ans[j++]=-1;
            else ans[j++]=nums[window.back()];
        }
        return ans;
    }
};
int main(){
    Solution a;
    vector<int> nums{3,2,3,2,3,2};
    vector<int> res = a.resultsArray(nums,2);
    for(int j:res)cout<<j<<" ";
}