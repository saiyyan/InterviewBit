#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <unordered_set>
using namespace std;

/*
Given an array of times (hh:mm) ranging from 00:00 to   24:00 (inclusive),
calculate the smallest number of minutes between any two times.
Includes wrap-around (ie. 23:20 and 00:10 would be a 00:50 interval)
*/
struct _time{
	int hh;
	int mm;
	_time(int _hh, int _mm) : hh(_hh), mm(_mm){}
};


bool compare(const _time& t1, const _time& t2){
	int m1 = (t1.hh * 60) + t1.mm;
	int m2 = (t2.hh * 60) + t2.mm;
	return m1 < m2;

}

int smallestAmountMinutesAny2Times(vector<_time> times){
	sort(times.begin(), times.end(), compare);
	int lowest = INT_MAX;
	for (int i = 0; i < times.size()-1; ++i){
		int t1 = (times[i].hh*60)+times[i].mm;
		int t2 = (times[i + 1].hh * 60) + times[i + 1].mm;
		if (abs(t1 - t2) < lowest) lowest = abs(t1 - t2);
	}
	int t1 = (times[0].hh * 60 )+ times[0].mm;
	int t2 = (times[times.size() - 1].hh * 60) + times[times.size() - 1].mm;
	int diff_from_24 = 24 * 60 - (t2);
	int diff_from_0 = t1 + 0;
	if (diff_from_24 + diff_from_0 < lowest) lowest = diff_from_24 + diff_from_0;
	return lowest;

}


int main(){

  _time t1(0, 10);
	_time t2(23, 20);
	_time t3(7, 10);
	vector<_time> times;
	times.push_back(t1);	times.push_back(t2); 	times.push_back(t3);

	cout << smallestAmountMinutesAny2Times(times);
	return 0;

}
