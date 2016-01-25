#include <iostream>
#include <vector>
using namespace std;
/*
You’re given a read only array of n integers. 
Find out if any integer occurs more than n/3 times in the array in linear time and constant additional space.
If so, return the integer. If not, return -1.
If there are multiple solutions, return any one.

----------------------------

It is important to note that if at a given time, you have 3 distinct element from the array, if you remove them from the array, your answer does not change.

Assume that we maintain 2 elements with their counts as we traverse along the array.

When we encounter a new element, there are 3 cases possible :

We don’t have 2 elements yet. So add this to the list with count as 1.

This element is different from the existing 2 elements. As we said before, we have 3 distinct numbers now. Removing them does not change the answer. So decrement 1 from count of 2 existing elements. If their count falls to 0, obviously its not a part of 2 elements anymore.

The new element is same as one of the 2 elements. Increment the count of that element.

Consequently, the answer will be one of the 2 elements left behind. If they are not the answer, then there is no element with count > N / 3.

*/
int Solution::repeatedNumber(const vector<int> &A) {
    
    int elem1 = A[0];
    int elem2 = A[1];
    
    int count1 = 1; int count2 = 1;
    if(elem1 == elem2){
        count1++;
        count2++;
    }
    
    for(int i = 2; i < A.size(); ++i){
        if(count1 > A.size()/3) return elem1;
        if(count2 > A.size()/3) return elem2;
        if(elem1 == A[i]){
            count1++;
            count2--;
        }
        else if (elem2 == A[i]){
            count2++;
            count1--;
        }
        else{
            count1--;
            count2--;
            if(count1 < 0 && count2 < 0){
                if(count1 == count2){
                    elem1 = A[i];
                    count1 = 1;
                } else if(count1 < count2){
                    elem1 = A[i];
                    count1 = 1;
                } else{
                    elem2 = A[i];
                    count2 = 1;
                }
            } else if(count1 < 0){
                elem1 = A[i];
                count1 = 1;
            } else if(count2 < 0){
                elem2 = A[i];
                count2 = 1;
            }
        }
    }
    if(count1 > 0){
        int i = 0;
        while(A[i++] != elem1){}
        count1 = 1;
        for(i = i + 1; i < A.size(); ++i){
            if(A[i] == elem1)++count1;
        }
        if(count1 > (A.size()/3) )return elem1;
    }
    if(count2 > 0){
        int j = 0;
        while(A[j++] != elem2){}
        count2 = 1;
        for(int j = j + 1; j < A.size(); ++j){
            if(A[j] == elem2)++count2;
        }
        if(count2 > (A.size()/3)) return elem2;
    }
    return -1;    
    
}
