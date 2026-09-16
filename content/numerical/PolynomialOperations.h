/**
 * Author: Bao Tran The
 * Date: 2026-09-17
 * License: CC0
 * Description: Polynomial Operations modulo $x^n$ using Hensel Lift.
 * $F(Q) = Q^{-1} - A$; $Q_{k+1} = Q_{k} - F(Q_{k}) / F'(Q_{k})$. Define polynomial addition, subtraction, ... before usage.
 * Time: O(N \log N)
 * Status: tested on QOJ
 */
#pragma once

#include "../numerical/NumberTheoreticTransform.h"

vl inv(vl A, int n) {
	int m = 1; vl Q = {modpow(A[0], mod - 2)};
	while (m < n) {
		m <<= 1; vl A1 = A; A1.resize(m);
		Q = conv(Q, vl{2} - conv(A1, Q)); Q.resize(m);
	}
	return Q; }
vl ln(vl P, int n) {
    return integr(conv(deriv(P), inv(P, n))); }
vl exp(vl P, int n) {
	int m = 1; vl Q = {1};
	while (m < n) {
		m <<= 1; vl P1 = P; P1.resize(m);
		Q = conv(Q, vl{1} + P1 - ln(Q, m)); Q.resize(m);
	}
	return Q; }