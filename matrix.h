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
public:
    //矩阵类构造函数
    Matrix();
    //实现稀疏矩阵的读取
    double getMatrixByCoordinate(int, int);
    //矩阵与向量相乘
    vector<double> matrixMultArr(vector<double>);
    //矩阵A的LU分解
    void LU_Factorization();
    //解方程
    vector<double> LU_Solve(vector<double>);
    //计算detA
    double getDetA();
    //矩阵平移
    void plusIdentityMatrix(double);

    void printMatrix();
    //求拟上三角矩阵
    void hessenbergMat();

    void getQR();
};






#endif //MATRIX_MATRIX_H
