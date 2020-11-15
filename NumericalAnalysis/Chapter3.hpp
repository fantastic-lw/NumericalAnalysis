//
//  Chapter3.hpp
//  NumericalAnalysis
//
//  Created by weiliu on 2020/11/14.
//

#ifndef Chapter3_hpp
#define Chapter3_hpp
#define ARRAY_SIZE 9
#include <stdio.h>
#include <vector>
#include <iostream>
#include <iomanip>
class Question_41{
private:
    float w = 1;
    float max_err = 0.5e-5;
    int count;
    //vector<float> vec(arr, arr+arr_size);
    float A[ARRAY_SIZE][ARRAY_SIZE] = {0};
    float b[ARRAY_SIZE] = {0};
    float D[ARRAY_SIZE][ARRAY_SIZE] = {0};
    float L[ARRAY_SIZE][ARRAY_SIZE] = {0};
    float U[ARRAY_SIZE][ARRAY_SIZE] = {0};
    float distance(float x1[ARRAY_SIZE],float x2[ARRAY_SIZE]);
public:
    Question_41(float matrix_a[ARRAY_SIZE][ARRAY_SIZE] ,float matrix_b[ARRAY_SIZE],float set_w);
    std::vector<std::vector<float> > result;
    std::vector<float> errs;
    void calculate();
};
class Question_40{
private:
    std::vector<std::vector<float>> A;
    std::vector<float> b;
    std::vector<float> result;
    //向量数乘法
    void mutiAndAdd(std::vector<float>&,std::vector<float>,float);
public:
    Question_40(std::vector<std::vector<float>> matrix_a,std::vector<float> matrix_b):A(matrix_a),b(matrix_b){}
    std::vector<float> get_result()const {return result;}
    void calculate();
};
#endif /* Chapter3_hpp */
