// test formula based sparse matrix class

#include <iostream.h>
#include "smatrix1.h"

void main(void)
{
   try{
      SparseMatrix<int> A(20), B(20), C(20);
      cin >> A;
      cout << "Matrix A is" << endl << A;
      cin >> B;
      cout << "Matrix B is" << endl << B;
      A.Transpose(C);
      cout << "The transpose of A is" << endl << C;
      A.Add(B,C);
      cout << "The sum of A and B is" << endl << C;
      }
   catch (...) {
      cerr << "An exception has occurred" << endl;
      }
}
