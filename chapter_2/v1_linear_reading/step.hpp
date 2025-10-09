#pragma once

// Computes: r[i,j] = min_k ( d[i,k] + d[k,j] ), for 0 <= i,j,k < n
// r and d are row-major n x n matrices.
void step(float* r, const float* d, int n);
