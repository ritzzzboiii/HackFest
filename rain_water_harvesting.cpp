#include<iostream>
using namespace std;

void computeLeft(int arr[], int left[], int n) {
    left[0] = arr[0];
    for(int i=1;i<n;i++) {
        left[i] = max(arr[i], left[i-1]);
    }
}

void computeRight(int arr[], int right[], int n) {
    right[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--) {
        right[i] = max(arr[i], right[i+1]);
    }
}

int trappedWater(int arr[], int left[], int right[], int n) {
    int count = 0;
    for(int i=0; i<n; i++) {
        count = count + (min(left[i], right[i])-arr[i]);
    }
    return count;
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    int left[n],right[n];
    computeLeft(arr,left,n);
    computeRight(arr,right,n);

    cout<<trappedWater(arr,left,right,n)<<endl;

    return 0;
}