#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];

    int l=0,r=n-1,key=6,index=-1;
    while(l<=r){
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        // Check if the key is present at mid1
        if (arr[mid1] == key) {
            index=mid1;
            break;
        }

        // Check if the key is present at mid2
        if (arr[mid2] == key) {
            index=mid2;
            break;
        }

        // Determine which segment to search next
        if (key < arr[mid1]) {
            r = mid1 - 1;
        }
        else if (key > arr[mid2]) {
            l = mid2 + 1;
        }
        else {
            l = mid1 + 1;
            r = mid2 - 1;
        }
    }

    if(index==-1)cout<<"Not Found";
    else cout<<index<<endl;
}
