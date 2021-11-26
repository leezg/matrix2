//
// Created by lee on 2021/11/9.
//

#include "matrix.h"

void Matrix::hessenbergMat() {
    for (int r = 0; r < maxLength -2; r++) {
        zeroMatrix(matrixA);
        vector<double> vectorU;
        vector<double> vectorP;
        vector<double> vectorQ;
        vector<double> vectorW;
        double d = 0;
        double c = 0;
        double h = 0;
        double t = 0;
        for (int i = r + 2; i < maxLength; i++) {
            d += matrixA[i][r] * matrixA[i][r];
        }
        if (d == 0) {
            continue;
        } else {
            d += matrixA[r + 1][r] * matrixA[r + 1][r];
            d = sqrt(d);
            if (matrixA[r + 1][r] != 0) {
                c = -abs(matrixA[r + 1][r]) / matrixA[r + 1][r] * d;
            } else {
                c = d;
            }
            h = c * c - c * matrixA[r + 1][r];
            for (int i = 0; i < r + 1; i++) {
                vectorU.push_back(0);
            }
            vectorU.push_back(matrixA[r + 1][r] - c);
            for (int i = r + 2; i < maxLength; i++) {
                vectorU.push_back(matrixA[i][r]);
            }
            for (int i = 0; i < maxLength; i++) {
                vectorP.push_back(0);
                vectorQ.push_back(0);
                for (int j = 0; j < maxLength; j++) {
                    vectorP[i] += matrixA[j][i] * vectorU[j] / h;
                    vectorQ[i] += matrixA[i][j] * vectorU[j] / h;
                }
            }
            for (int i = 0; i < maxLength; i++) {
                t += vectorP[i] * vectorU[i] /h;
            }
            for (int i = 0; i < maxLength; i++) {
                vectorW.push_back(vectorQ[i] - t * vectorU[i]);
            }
            for (int i = 0; i < maxLength; i++) {
                for (int j = 0; j < maxLength; j++) {
                    matrixA[i][j] -= (vectorW[i] * vectorU[j] + vectorU[i] * vectorP[j]);
                }
            }
        }
    }
    zeroMatrix(matrixA);
//    cout << "A(n-1)" << endl;
    fprintf(fp, "A(n-1)\n");
    printMatrix();
}
