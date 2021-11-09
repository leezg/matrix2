//
// Created by lee on 2021/10/26.
//
#include "matrix.h"
#define E exp(-20)

vector<double> numA;

Matrix::Matrix() { //矩阵初始化
    for (int i = 0; i < maxLength; i++) {
        matrixA.push_back(vector<double>());
        for (int j = 0; j < maxLength; j++) {
            if (i == j) {
                matrixA.push_back(sin(0.5 * i + 0.2 * j));
            } else {
                matrixA.push_back(1.52 * cos(i + 1.2 * j));
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

void Matrix::LU_Factorization() {
    matrixL = vector<vector<double>>();
    matrixU = vector<vector<double>>();
    for (int i = 0; i < maxLength; i++) {
        matrixL.push_back(vector<double>());
        matrixU.push_back(vector<double>());
        for (int j = 0; j < maxLength; j++) {
            matrixL[i].push_back(0);
            matrixU[i].push_back(0);
            if (i == j) {
                matrixL[i][j] = 1;
            }
        }
    }

    for (int k = 0; k < maxLength; k++) {
        for (int j = k; j < maxLength; j++) {
            matrixU[k][j] = getMatrixByCoordinate(k, j) - sumLktUtj(k, j);
        }
        if (k < maxLength - 1) {
            for (int i = k + 1; i < maxLength; i++) {
                matrixL[i][k] = (getMatrixByCoordinate(i, k) - sumLjtUtk(k, i)) / matrixU[k][k];
            }
        }
    }


}

vector<double> Matrix::LU_Solve(vector<double> b) {
    vector<double> y;
    y.push_back(b[0]);
    for (int i = 1; i < maxLength; i++) {
        double sum = 0;
        for (int k = 0; k < i; k++) {
            sum += matrixL[i][k] * y[k];
        }
        y.push_back(b[i] - sum);
    }

    vector<double> x;

    for (int i = 0; i < maxLength; i++) {
        x.push_back(0);
    }
    x[maxLength - 1] = y[maxLength - 1] / matrixU[maxLength - 1][maxLength - 1];
    for (int i = maxLength - 2; i >= 0; i--) {
        double sum = 0;
        for (int k = i + 1; k < maxLength; k++) {
            sum += matrixU[i][k] * x[k];
        }
        x[i] = (y[i] - sum) / matrixU[i][i];
    }
    return x;
}

double Matrix::getDetA() {
    double detA = 1;
    for (int i = 0; i < maxLength; i++) {
        detA *= matrixU[i][i];
    }
    return detA;
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