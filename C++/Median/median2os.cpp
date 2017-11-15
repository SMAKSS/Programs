Median Problem < Order Statistic Problem

Median(A)
  n = A.length
  return OS_Select(A, n/2)

===================================

Order Statistic Problem < Median Problem

OS_Select(A, i)
  x = Median(A)
  q = Partition(A,x)
  if i==q then return x
  else if i<q then 
     return OS_Select(A[1..(q-1)],i)
  else // if i>q
     return OS_Select(A[(q+1)..n],i-q)
==================================
T(n) = T(n/2) + O(n) + f(n)
f(n) : Cost of median

beta = log(1) = 0
==> T(n) = O(n) + f(n) = O(max(n,f(n)))