#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    string simplifyPath(string path){
        int leng = path.length(), dots = 0;
        char *ans = new char[leng + 1]{};
        ans[0] = '/';
        int i = 1,k = 1;
        while (i < leng && path[i] == '/')i++;
        while (i < leng){
            while (i < leng && path[i] == '.'){
                i++;
                dots++;
            }
            if (dots > 0 && i<leng && path[i] != '/'){
                i -= dots;
                dots = 0;
            }
            switch (dots){
            case 0:
                cout<<"case 0"<<endl;
                while (i < leng && path[i] != '/'){
                    ans[k++] = path[i++];
                }
                break;
            case 1:
                cout<<"case 1"<<endl;
                while (i < leng && path[i] == '/')
                    i++;
                break;
            case 2:
                cout<<"case 2"<<endl;
                cout<<k<<endl;
                if(k>1){
                    k-=2;
                    while(k >= 0 && ans[k]!='/'){
                        k--;
                    }
                    k++;
                }
                while (i < leng && path[i] == '/')
                        i++;
                break;
            default:
                for (int m = 0; m < dots; m++)
                    ans[k++] = '.';
                break;
            }
            dots = 0;
            if (i < leng && path[i] == '/'){
                ans[k++] = path[i++];
            }
            while (i < leng && path[i] == '/')
                i++;
                cout<<ans<<endl;
        }
        ans[k--] = 0;
        while (k > 0 && ans[k] == '/')
            ans[k--] = 0;
        return ans;
    }
};
int main(){
    Solution a;
    string res = a.simplifyPath("///TJbrd/owxdG//");
    cout << res << endl;
}