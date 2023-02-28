#include<iostream>
using namespace std;

/* Brute force        O(n2)
int main(){
    int arr[8] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int sum = -9999,l = 0,r = 0;
    for(int i = 0;i < 8;i++){
        int x = arr[i];
        for(int j = i+1; j < 8 ;j++){
            x += arr[j];
            if(x>sum){
                sum = x;
                l = i;
                r = j;
            }
        }
    }
    cout << sum << " " << l << " " << r<< endl;
}
*/


/*Divine and conquer     O(nlogn)
struct info{
    int l;
    int r;
    int sum;
};

info crossing_sum(int A[],int l,int h,int m){
    int lsum = -99999;
    int rsum = -99999;
    info i;
    int l_ind,r_ind,sum = 0;
    for(int i = m;i>=l;i--){
        sum += A[i];
        if(sum>lsum){
            lsum = sum;
            l_ind = i;
        }
    }
    sum = 0;
    for(int i = m+1;i<=h;i++){
        sum += A[i];
        if(sum>rsum){
            rsum = sum;
            r_ind = i;
        }
    }
    i.l = l_ind;
    i.r = r_ind;
    i.sum = lsum + rsum;
    return i;
}

info max_sub(int A[],int l, int h){
    info l_i,r_i,c_i,i;
    int mid = (l+h)/2;
    if (l == h){
        i.l = l;
        i.r = h;
        i.sum = A[l];
        return i;
    }
    l_i =  max_sub(A,l,mid);
    r_i =  max_sub(A,mid+1,h);
    c_i =  crossing_sum(A,l,h,mid);
    if(l_i.sum > r_i.sum && l_i.sum > c_i.sum)
        return l_i;
    else if (r_i.sum > l_i.sum && r_i.sum > c_i.sum)
        return r_i;
    return c_i;
}
*/


//Kadane's Algorithm      O(n)

struct info{
    int l;
    int r;
    int sum;
};

info max_sub(int A[],int n){
    info m;
    int sum,tmp,li,ri;
    sum = -999999;
    tmp = 0;
    for(int i = 0;i < n;i++){
        tmp += A[i];
        if(tmp <= 0 ){
            tmp = 0;
            li = i;
            ri = i;
        }
        if(tmp>sum){
            sum = tmp;
            ri = i;
        }
    }
    m.l = li+1;
    m.r = ri;
    m.sum = sum;
    return m;
}

int main(){
    int arr[8] = {-2, -5, 6, -2, -3, 1, 5, -6};
    info i;
    i = max_sub(arr,8);
    cout << i.l << " " << i.r << " " << i.sum << endl;
    return 0;
}
