//
// Created by lee on 2021/10/26.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include "matrixOperation.h"

class Matrix {
private:
    //存储矩阵A及LU分解得到的两个矩阵
    vector<vector<double>> matrixA;
    vector<vector<double>> matrixQ;
    vector<vector<double>> matrixR;
    vector<vector<double>> matrixQR;
    void printMatrix(vector<vector<double>>);
    void zeroMatrix(vector<vector<double>>&);
    void matrixMult(vector<vector<double>>&, vector<vector<double>>&, vector<vector<double>>&);
    void initQR();
    void initMatrixA(vector<vector<double>>&);
    void iterate(vector<vector<double>>&, int);
    void maxLine(vector<vector<double>>&, int);
public:
    //矩阵类构造函数
    Matrix();

    void printMatrix();
    //求拟上三角矩阵
    void hessenbergMat();

    void getQR();

    void QRMethod();

    void gauss(double);
};






#endif //MATRIX_MATRIX_H
