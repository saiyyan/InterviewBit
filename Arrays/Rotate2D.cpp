#include <iostream>

/*
You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).
You need to do this in place.
*/

void Solution::rotate(vector<vector<int> > &A) {
    
  int n = A.size();
	int num_layers = n / 2;
	for (int x = 0; x < num_layers; ++x){
		int first_col = x;
		int last_col = n-1 - x;
		for (int y = first_col; y < last_col; ++y){
			int a = A[x][y];
			int b = A[y][n - 1 - x];
			int c = A[n - 1 - x][n - 1 - y];
			int d = A[n - 1 - y][x];
			A[x][y] = d;
			A[y][n - 1 - x] = a;
			A[n - 1 - x][n - 1 - y] = b;
			A[n - 1 - y][x] = c;
		}
	}
}

