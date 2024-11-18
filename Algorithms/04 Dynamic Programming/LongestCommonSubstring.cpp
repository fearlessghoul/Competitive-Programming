#include <iostream>
using namespace std;

void swapped(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int max(int &a, int &b)
{
    return a > b ? a : b;
}
int main()
{
    char A[] = {'A', 'B', 'C', 'B', 'D', 'A', 'B'};
    char B[] = {'B', 'D', 'C', 'A', 'B', 'A'};
    int dp[8][7] = {0}, k = 0,max=0;
    for (int i = 1; i < 8; i++)
    {
        for (int j = 1; j < 7; j++)
        {
            if (A[i - 1] == B[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if(dp[i][j]>max){
                    max=dp[i][j];
                    k=i-1;
                }
            }
            cout<<dp[i][j]<<"endl";
        }
    }
    for (int i = k-(max-1); i <= k; i++)
    {   
        cout<<A[i]<<" ";
    }
    
    return 0;
}