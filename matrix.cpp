//
// Created by lee on 2021/10/26.
//
#include "matrix.h"

vector<double> numA;

Matrix::Matrix() { //矩阵初始化
    for (int i = 0; i < maxLength; i++) {
        matrixA.push_back(vector<double>());
        for (int j = 0; j < maxLength; j++) {
            if (i == j) {
                matrixA[i].push_back(sin(0.5 * i + 0.2 * j));
            } else {
                matrixA[i].push_back(1.52 * cos(i + 1.2 * j));
            }
        }
    }
}

double Matrix::getMatrixByCoordinate(int i_, int j_) { //根据原坐标取值
    if (i_ < 0 || j_ < 0 || i_ >= maxLength || j_ >= maxLength) {
        return 0;
    }
    int i = i_;
    int j = j_ - i_ + 2;
    if (j < 0 || j >= 5) {
        return 0;
    }
    return matrixA[i][j];
}

vector<double> Matrix::matrixMultArr(vector<double> arr) {
    vector<double> ans;
    for (int i = 0; i < maxLength; i++) {
        double sum = 0;
        for (int j = 0; j < maxLength; j++) {
            sum += getMatrixByCoordinate(i, j) * arr[j];
        }
        ans.push_back(sum);
    }
    return ans;
}

void Matrix::plusIdentityMatrix(double times) {
    for (int i = 0; i < matrixA.size(); i++) {
        matrixA[i][2] += times;
    }
}

void Matrix::printMatrix() {
    cout << numA[0] << endl;
    for (int i = 0; i < maxLength; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%20.12lf", matrixA[i][j]);
        }
        cout << endl;
    }
    cout << numA[maxLength - 1] << endl;
}

void Matrix::printMatrix(vector<vector<int>> matrixA) {
    cout << numA[0] << endl;
    for (int i = 0; i < maxLength; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%20.12lf", matrixA[i][j]);
        }
        cout << endl;
    }
    cout << numA[maxLength - 1] << endl;
}

void Matrix::zeroMatrixA() {
    for(int i = 0; i < maxLength; i++) {
        for (int j = 0; j < maxLength; j++) {
            if (abs(matrixA[i][j])  < E) {
                matrixA[i][j] = 0;
            }
        }
    }
}