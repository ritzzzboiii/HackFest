#include<iostream>
using namespace std;
//esai 
void magical_park(char a[][100], int rows, int cols, int k, int s) {
    bool success = true;
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            char ch = a[i][j];
            if(s<k) {
                success=false;
                break;
            }

            if(ch=='*') {
                s = s+5;
            }
            else if(ch=='.') {
                s = s-2;
            }
            else {
                break;
            }

            if(j!=cols-1) {
                s=s-1;
            }
        }
    }
    if(success) {
        cout<<"Yes"<<endl;
        cout<<s<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
}   

int main() {
    int row,col,k,s;
    cin>>row>>col>>k>>s;
    char a[100][100];
    for(int i=0;i<row;i++) {
        for(int j=0; j<col; j++) {
            cin>>a[i][j];
        }
    }
    magical_park(a,row,col,k,s);
    return 0;
}