//
// Created by lee on 2021/10/26.
//
#include "matrix.h"

vector<double> numA;

Matrix::Matrix() { //矩阵初始化
    initMatrixA(matrixA);
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

void Matrix:: matrixMult(vector<vector<double>>& ma, vector<vector<double>>& mb, vector<vector<double>>& ms)  {
    for (int i = 0; i < maxLength; i++) {
        for (int j = 0; j < maxLength; j++) {
            for (int k = 0; k < maxLength; k++) {
                ms[i][j] += ma[i][k] * mb[k][j];
            }
        }
    }
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

void Matrix::printMatrix(vector<vector<double>> matrixA) {
    cout << numA[0] << endl;
    for (int i = 0; i < maxLength; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%20.12lf", matrixA[i][j]);
        }
        cout << endl;
    }
    cout << numA[maxLength - 1] << endl;
}

void Matrix::zeroMatrix(vector<vector<double>> &matrix) {
    for(int i = 0; i < maxLength; i++) {
        for (int j = 0; j < maxLength; j++) {
            if (abs(matrix[i][j])  < E) {
                matrix[i][j] = 0;
            }
        }
    }
}

void Matrix::gauss(double lambda) {
    vector<vector<double>> matrixA;
    vector<double> vectorX = vector<double>(10);
    initMatrixA(matrixA);

    for (int i = 0; i < maxLength; i++) {
        matrixA[i][i] -= lambda;
        //TODO: fix bugs
        matrixA[i][maxLength] = 0;
    }

    for (int k = 0; k < maxLength - 1; k++) {
        maxline(matrixA, k);
        for (int i = k + 1; i < maxLength; i++) {
            double m;
            m = matrixA[i][k] / matrixA[k][k];
            for (int j = k; j < maxLength + 1; j++)
                matrixA[i][j] = matrixA[i][j] - m * matrixA[k][j];
        }
    }

    vectorX[maxLength - 1] = 1;
    double t = 0;
    for (int k = maxLength - 2; k >= 0; k--) {
        double sigma = 0;
        for (int j = k + 1; j < maxLength; j++)
            sigma += matrixA[k][j] * vectorX[j];
        //TODO: bugs
        vectorX[k] = (matrixA[k][maxLength] - sigma) / matrixA[k][k];
    }
    for (int i = 0; i < maxLength; i++) {
        t += vectorX[i] * vectorX[i];
    }
    t = sqrt(t);
    printf("eigenvector = ( ");
    for (int i = 0; i < maxLength; i++) {
        printf("%.12e ", vectorX[i]/t);
    }
    printf(")\n");
}

void Matrix::initMatrixA(vector<vector<double>> &matrixA) {
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

void Matrix::maxline(vector<vector<double>> &matrixA, int k) {
    double c;
    int i, M;
    M = k;
    for (i = k; i < maxLength; i++) {
        if (abs(matrixA[i][k]) > abs(matrixA[M][k]))
            M = i;
    }
    if (M > k) {
        for (i = k; i < maxLength + 1; i++) {
            c = matrixA[k][i];
            matrixA[k][i] = matrixA[M][i];
            matrixA[M][i] = c;
        }
    }
}