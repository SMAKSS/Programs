#include <iostream>
#include <cstdlib>

using namespace std;

int partition( int A[], int p, int r ) {
  int x = A[r];
  int i = p-1;
  int j;
  for(j=p;j<r;j++){
    if(A[j]<=x){
      i++;
      int temp = A[j];
      A[j] = A[i];
      A[i] = temp;
    }
  }
  A[r] = A[i+1];
  A[i+1] = x;
  return (i+1);
}

int RandomizedPartition( int A[], int p, int r ){
  int i = p+rand()%(r-p+1); 
  int temp = A[i];
  A[i] = A[r];
  A[r] = temp;
  return partition(A,p,r);
}

// O(n) Median in average
int OS_Select( int A[], int p, int r, int i ) {  // A[p..r]
  int q = RandomizedPartition(A,p,r);
  int k = q-p;
  if (i==k) return A[q];
  else if (i<k) 
     return OS_Select(A,p,q-1,i);
  else // if i>q
     return OS_Select(A,q+1,r,i-k-1);
}

int main(){
  int A[11] = {0,1,2,3,4,5,6,7,8,9,10};
  cout << OS_Select(A,0,10,5) << endl;
  cout << OS_Select(A,0,10,10) << endl;
  cout << OS_Select(A,0,10,6) << endl;
  cout << OS_Select(A,0,10,2) << endl;
  cout << OS_Select(A,0,10,8) << endl;
}