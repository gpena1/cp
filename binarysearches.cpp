#include <bits/stdc++.h>

using namespace std;

int first_greq(vector<int>& x, int target){
    int left=0,right=x.size()-1;
    while(left<right){
        int mid=left+(right-left)/2;
        if(x[mid]>=target){
            /*
             * Since our middle element
             * is greater than or equal to target,
             * it is a possible candidate, but
             * that does not rule out the elements
             * to the left of the middle from being
             * candidates as well.
             */
            right=mid;
        }else{
            /*
             * At this point, we know x[mid]<target,
             * which disqualifies it from
             * being a candidate; we're looking for
             * the first element >= to target, so
             * we must move our left bound up one.
             */
            left=mid+1;
        }
    }
    return x[left]>=target?left:-1;
}
int first_gr(vector<int>& x, int target){
    int left=0,right=x.size()-1;
    while(left<right){
        int mid=left+(right-left)/2;
        if(x[mid]>target){
            // logic from first_greq
            // applies here, just change
            // >= operator to >
            right=mid;
        }else{
            // consult previous comment
            left=mid+1;
        }
    }
    return x[left]>target?left:-1;
}
