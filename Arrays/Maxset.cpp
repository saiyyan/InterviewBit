#include <iostream>
#include <vector>

/*
Find out the maximum sub-array of non negative numbers from an array.
The sub-array should be continuous. That is, a sub-array created by choosing the second and fourth element and skipping the third element is invalid.
Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).
Example:
A : [1, 2, 5, -7, 2, 3]
The two sub-arrays are [1, 2, 5] [2, 3].
The answer is [1, 2, 5] as its sum is larger than [2, 3]
*/

vector<int> Solution::maxset(vector<int> &A) {
	int s = -1; int e = 0;
	int max_s = -1; int max_e = -1;
	long long sum = 0; long long max_sum = -1;
	vector<int> res;
	for (int i = 0; i < A.size(); ++i){ //find first positive element
		if (A[i] >= 0){
			s = i;
			e = i;
			break;
		}
	}
	if (s == -1){ //all elements are negative, return empty array
		return res;
	}
	for (int i = s; i < A.size(); ++i){
		if (A[i] < 0){
			if (sum > max_sum){
				max_sum = sum;
				max_s = s;
				max_e = e;
			}
			else if (sum == max_sum){ //choose the (s,e) pair with larger distance
				if (e - s > max_e - max_s){
					max_e = e;
					max_s = s;
				}
			}
			//find next positive element
				while (i < A.size()){
					if (A[i] > 0){
						s = i;
						e = i;
						sum = A[i];
						break;
					}
					else{
						++i;
					}
				}
				
		}
		else{
			e = i;
			sum += A[i];
		}
	}
	//check if last chosen sum( A[s..e] ) > sum(A[max_s...max_e])
	if (sum > max_sum){
		max_sum = sum;
		max_s = s;
		max_e = e;
	}
	
	for (int i = max_s; i <= max_e; ++i){
		res.push_back(A[i]);
	}
	return res;
}
