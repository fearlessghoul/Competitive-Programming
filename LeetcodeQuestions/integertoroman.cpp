#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    string intToRoman(int num){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        string s(16, ' ');
        int i = 15, j = 0, temp;
        char mapped[4][2] = {{'I', 'V'}, {'X', 'L'}, {'C', 'D'}, {'M', 'S'}};
        while (num != 0){
            temp = num % 10;
            switch (temp){
            case 0:
                break;

            case 1:
            case 2:
            case 3:
                for (int k = 0; k < temp; k++){
                    s[i--] = mapped[j][0];
                }
                break;

            case 4:
                s[i--] = mapped[j][1];
                s[i--] = mapped[j][0];
                break;

            case 5:
            case 6:
            case 7:
            case 8:
                temp = temp - 5;
                for (int k = 0; k < temp; k++){
                    s[i--] = mapped[j][0];
                }
                s[i--] = mapped[j][1];
                break;

            case 9:
                s[i--] = mapped[j + 1][0];
                s[i--] = mapped[j][0];
                break;
            }

            j++;
            num /= 10;
        }
        return s.substr(i + 1, 16 - i);
    }
};
int main(){
    Solution a;
    cout << a.intToRoman(8888) << endl;
}