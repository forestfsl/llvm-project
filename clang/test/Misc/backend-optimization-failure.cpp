// RUN: %clang_cc1 %s -O3 -emit-llvm -gline-tables-only -S -verify -o /dev/null

// Test verifies optimization failures generated by the backend are handled
// correctly by clang. LLVM tests verify all of the failure conditions.

void test_switch(int *A, int *B, int Length) {
#pragma clang loop vectorize(enable) unroll(disable)
  for (int i = 0; i < Length; i++) {
    /* expected-warning {{loop not vectorized: failed explicitly specified loop vectorization}} */ switch (A[i]) {
    case 0:
      B[i] = 1;
      break;
    case 1:
      B[i] = 2;
      break;
    default:
      B[i] = 3;
    }
  }
}
