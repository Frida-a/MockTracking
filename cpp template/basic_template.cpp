using namespace std;
#include <iostream>
#include <vector>
//quick sort
void quick_sort(vector<int>& arr, int left, int right){
    //终止条件
    if(right <= left) return;
    // [left, right]
    //本层处理
    int i = left -1, j = right+1;
    int p = arr[(left+right) >>1];
    while(i<j){
        do{i++;} while(arr[i]<p);
        do{j--;} while(arr[j]>p);
        if(i<j) swap(arr[i],arr[j]);
    }
    //递归
    quick_sort(arr, left, j);
    quick_sort(arr, j+1, right);
}

//merge sort
void merge_sort(vector<int>&arr,const int left,const int right){
    //终止条件
    if(left >= right) return;
    //递归
    int mid = (left+right)/2;
    merge_sort(arr, left, mid), merge_sort(arr, mid+1, right);
    //本层处理
    vector<int>tmp (right-left+1);
    int rightp = mid+1, leftp = left, tmpp = 0;
    while(leftp<=mid && rightp<=right){
        if(arr[leftp]>arr[rightp]){
            tmp[tmpp++] = arr[rightp++];
        }else{
            tmp[tmpp++] = arr[leftp++];
        }
    }
    while(leftp<=mid) tmp[tmpp++] = arr[leftp++];
    while(rightp<=right) tmp[tmpp++] = arr[rightp++];
    //复制回原数组
    for(int i=0; i<tmp.size(); i++){
        arr[left+i] = tmp[i];
    }
    return ;
}

//bubble sort

//binary search
//upper_bound
//(left, right)
int binary_search1(vector<int>&arr, int target){
    int left = -1, right = arr.size();
    while(left+1<right){
        int mid = left + (right-left)/2;
        if(arr[mid]<target){
            left = mid;
        }else{
            right = mid;
        }
    }
    return right;
}
//[left,right]
int binary_search2(vector<int>&arr, int target){
    int left = 0, right = arr.size()-1;
    while(left<=right){
        int mid = left + (right-left)/2;
        if(arr[mid]<target){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    return left;//right+1
}
//[left, right)
int binary_search3(vector<int>&arr, int target){
    int left = 0, right = arr.size();
    while(left<right){
        int mid = left + (right-left)/2;
        if(arr[mid]<target){
            left = mid+1;
        }else{
            right = mid;
        }
    }
    return left;//right
}
//lowerbound(x)-> upper_bound(x+1)
//<x ->upperbound(x)-1
//<=x ->upper_bound(x+1)-1

//prefix 

//posfix

//diff array

//mono stack

//mono queue

//sliding window

//bit operation

//math