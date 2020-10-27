#include <iostream>
#include <algorithm>
using namespace std;

//pull req ke liye comment add karra hu

void rotate_stl(int a[][1000], int n) {
    //reverse each row using stl
    for(int row=0;row<n;row++) {
        reverse(a[row],a[row]+n);
    }

    //transpose matrix
    for(int row=0;row<n;row++) {
        for(int col=0;col<n;col++) {
            if(row<col) {
                swap(a[row][col], a[col][row]);
            }
        }
    }
}

void rotate(int a[][1000], int n) {
    //reverse each row
    for(int row=0;row<n;row++) {
        int start_col=0;
        int end_col=n-1;
        while(start_col<end_col) {
            swap(a[row][start_col], a[row][end_col]);
            start_col++;
            end_col--;
        }
    }

    //transpose matrix
    for(int row=0;row<n;row++) {
        for(int col=0;col<n;col++) {
            if(row<col) {
                swap(a[row][col], a[col][row]);
            }
        }
    }
}

void display(int a[][1000], int n) {
    for(int row=0;row<n;row++) {
        for(int col=0;col<n;col++) {
            cout<<a[row][col]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int n;
    cin>>n;
    int a[1000][1000];
    for(int i=0;i<n;i++) 
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    rotate(a,n);
    display(a,n);
    
    return 0;
}