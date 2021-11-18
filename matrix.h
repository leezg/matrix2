//
// Created by lee on 2021/10/26.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include "matrixOperation.h"

class Matrix {
private:
    //存储矩阵A及R、Q、RQ矩阵
    vector<vector<double>> matrixA;
    vector<vector<double>> matrixQ;
    vector<vector<double>> matrixR;
    vector<vector<double>> matrixQR;
    //打印指定矩阵
    void printMatrix(vector<vector<double>>);
    //将矩阵中小于E值的数字置0
    void zeroMatrix(vector<vector<double>>&);
    //矩阵乘法
    void matrixMult(vector<vector<double>>&, vector<vector<double>>&, vector<vector<double>>&);
    //初始化R、Q、RQ矩阵
    void initQR();
    //初始化矩阵A
    void initMatrixA(vector<vector<double>>&);
    //QR方法的迭代过程
    void iterate(vector<vector<double>>&, int);
    ////Gauss消元法中的选主元
    void maxLine(vector<vector<double>>&, int);
public:
    //矩阵类构造函数
    Matrix();
    //打印矩阵A
    void printMatrix();
    //求拟上三角矩阵
    void hessenbergMat();
    //求R、Q、RQ矩阵
    void getQR();
    //双步位移的QR方法
    void QRMethod();
    //Gauss消去法
    void gauss(double);
};






#endif //MATRIX_MATRIX_H
