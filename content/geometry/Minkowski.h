/**
 * Author: CP-Algorithm
 * Date: 2026-09-17
 * License: CC0
 * Description: Find Minkowski sum of 2 convex polygons.
 */

#pragma once

#include "Point.h"

typedef Point<ll> P;
void minRotate(vector<P> &A) {
	int p = 0;
	for (int i = 1; i < sz(A); ++i)
		if (A[i].y < A[p].y || (A[i].y == A[p].y && A[i].x < A[p].x))
			p = i;
	rotate(A.begin(), A.begin() + p, A.end());
}
vector<P> minkowski(vector<P> A, vector<P> B) {
	minRotate(A); minRotate(B);
	A.push_back(A[0]); A.push_back(A[1]);
	B.push_back(B[0]); B.push_back(B[1]);
  int i = 0, j = 0;
	vector<P> ans;
  while(i < sz(A) - 2 || j < sz(B) - 2){
    ans.push_back(A[i] + B[j]);
    auto cross = (A[i + 1] - A[i]).cross(B[j + 1] - B[j]);
    if(cross >= 0 && i < sz(A) - 2) ++i;
    if(cross <= 0 && j < sz(B) - 2) ++j;
  }
  return ans;
}
