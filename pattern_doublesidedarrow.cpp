#include<iostream>
using namespace std;

void give_space(int start, int end) {
    for(int i=start; i<=end; i++) 
        cout<<" ";
}

void print_numbers(int start, int end) {
    if(start>end) 
        for(int i=start; i>=end ; i--) 
            cout<<i<<" ";
    else 
       for(int i=start; i<=end ; i++) 
            cout<<i<<" ";
}

int main() {
    int N=11;
    //cin>>N;
    int mid = (N+1)/2;
    int spaces = (mid-1)*4;
    int inner_spaces = 2;
    for(int i = 1; i<=N; i++) {
        if(i==1 or i==N) {
            give_space(1,(mid-1)*4);
            cout<<1<<endl;
        }
        else if(i<=mid) {
            spaces = spaces - 4;
            give_space(1,spaces);
            print_numbers(i,1);
            give_space(1, inner_spaces);
            inner_spaces += 4;
            print_numbers(1,i);
            cout<<endl;
        }
        else if(i>mid) {
            if(i==mid+1)
                inner_spaces -= 4;    
            spaces = spaces + 4;
            give_space(1, spaces);
            print_numbers((mid-i%mid),1);
            inner_spaces -= 4;
            give_space(1, inner_spaces);
            print_numbers(1,(mid-i%mid));
            cout<<endl;
        }
    }
    return 0;
}