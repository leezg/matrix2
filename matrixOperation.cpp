//
// Created by lee on 2021/10/26.
//

#include "matrixOperation.h"

double sgn(double n) {
    if (n > 0) {
        return 1;
    } else if (n < 0) {
        return -1;
    } else {
        return 0;
    }
}