//
// Created by lee on 2021/11/11.
//

#include "matrix.h"

void Matrix::initQR() {
    for (int i = 0; i < maxLength; i++) {
        matrixQ.push_back(vector<double>());
        matrixR.push_back(vector<double>());
        matrixQR.push_back(vector<double>());
        for (int j = 0; j < maxLength; j++) {
            if (i == j) {
                matrixQ[i].push_back(1);
            } else {
                matrixQ[i].push_back(0);
            }
            matrixR[i].push_back(matrixA[i][j]);
            matrixQR[i].push_back(0);
        }
    }
    zeroMatrix(matrixR);
}

void Matrix::getQR() {
//    double c, d, h, w[maxLength], p[maxLength], u[maxLength];
    initQR();
    for(int r = 0; r < maxLength - 1; r++){
        double d = 0;
        double c = 0;
        double h = 0;
        vector<double> vectorU;
        vector<double> vectorW;
        vector<double> vectorP;
        for(int i = r + 1; i < maxLength; i++) {
            d += matrixR[i][r] * matrixR[i][r];
        }
        if(abs(d) == 0) {
            continue;
        }
        d += matrixR[r][r] * matrixR[r][r];
        d = sqrt(d);
        if (matrixR[r][r] == 0) {
            c = d;
        }
        else {
            c = -sgn(matrixR[r][r]) * d;
        }
        h = c * c - c * matrixR[r][r];
        for(int i = 0; i < r; i++) {
            vectorU.push_back(0);
        }
        vectorU.push_back(matrixR[r][r] - c);
        for(int i = r + 1; i < maxLength; i++) {
            vectorU.push_back(matrixR[i][r]);
        }
        for(int i = 0; i < maxLength; i++) {
            vectorW.push_back(0);
            for(int j = 0; j < maxLength; j++) {
                vectorW[i] += matrixQ[i][j] * vectorU[j];
            }
        }
        for(int i = 0; i < maxLength; i++) {
            for(int j = 0; j < maxLength; j++)
                matrixQ[i][j] -= vectorW[i] * vectorU[j] / h;
        }
        for(int i = 0; i < maxLength; i++){
            vectorP.push_back(0);
            for(int j = 0; j < maxLength; j++) {
                vectorP[i] += matrixR[j][i] * vectorU[j] / h;
            }
        }
        for(int i = 0; i < maxLength; i++) {
            for (int j = 0; j < maxLength; j++)
                matrixR[i][j] -= vectorU[i] * vectorP[j];
        }
    }
    zeroMatrix(matrixR);
    zeroMatrix(matrixQ);
    matrixMult(matrixR, matrixQ, matrixQR);
    zeroMatrix(matrixQR);
    printMatrix(matrixR);
    printMatrix(matrixQ);
    printMatrix(matrixQR);
}