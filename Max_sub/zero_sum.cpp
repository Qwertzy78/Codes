#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,tmp;
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        a.push_back(tmp);
    }
    int sum,l=0,r=l+1,flag = 0;
    sum = a[l] + a[r];
    
    
    while(true){
        if(sum == 0){
            flag = 1;
            break;
        }
        r++;
        if(r < n)
            sum = sum + a[r];
        else{
            l++;
            r = l+1;
            sum = a[l] + a[r];
        }
        if(l>=n)
            break;
    }
    
    if(flag == 0)            //sum never became 0
        cout << "-1";
    else                     // if sum became 0,a[l.....r]
        cout << l+1 << " " << r+1;
        
    return 0;
}
