//
//  Chapter3.cpp
//  NumericalAnalysis
//
//  Created by weiliu on 2020/11/14.
//

#include "Chapter3.hpp"
Question_41::Question_41(float matrix_a[ARRAY_SIZE][ARRAY_SIZE] ,float matrix_b[ARRAY_SIZE],float set_w = 1){
    w = set_w;
    for(int i = 0 ;i<ARRAY_SIZE;i++){
        b[i] =matrix_b[i];
        for(int j = 0 ;j<ARRAY_SIZE;j++){
            A[i][j]=matrix_a[i][j];
            if(i==j)
                D[i][j] = matrix_a[i][j];
            if(i<j)
                U[i][j] = matrix_a[i][j];
            if(i>j)
                L[i][j] = matrix_a[i][j];
        }
        
    }
}
float Question_41::distance(float x1[ARRAY_SIZE],float x2[ARRAY_SIZE]){
    float max_num = 0;
    for(int i =0;i<ARRAY_SIZE;i++){
        float err = x1[i]-x2[i]>0 ? x1[i]-x2[i] : x2[i]-x1[i];
        if( err>max_num)
            max_num = err;
    }
    return max_num;
}
void Question_41::calculate(){
    float x0[ARRAY_SIZE] = {0};
    float x1[ARRAY_SIZE] = {0};
    errs.clear();
    result.clear();
    float err = 999;
    std::vector<float> xk;
    do{
        float LX[ARRAY_SIZE] = {0};
        float UX[ARRAY_SIZE] = {0};
        
        for(int i = 0;i<ARRAY_SIZE;i++){
            for(int j = 0 ;j<ARRAY_SIZE;j++){
                //计算LX UX
                LX[i] += L[i][j]*x1[j];
                UX[i] += U[i][j]*x0[j];
            }
            //更新x[i]
            x1[i] = (1-w)*x0[i]+w*(b[i]- LX[i]-UX[i])/D[i][i];
//            std::cout<<x1[i]<<std::endl;
        }
        err = distance(x0, x1);
        errs.push_back(err);
        //std::cout<<"err:"<<err<<std::endl;
        for(int i = 0;i<ARRAY_SIZE;i++){
            x0[i] = x1[i];
            xk.push_back(x1[i]);
        }
        result.push_back(xk);
        xk.clear();
    }while(err>max_err);
}
void Question_40::calculate(){
    //增广矩阵
    std::vector<std::vector<float>> A1(A);
    for(int i = 0;i<A.size();i++){
        A1[i].push_back(b[i]);
    }
    
    auto width = A.size();
    auto height = A.size();
    //列主元
    for(int i = 0;i <width;i++){
        decltype(width) max_j = 0;
        float max_value = 0;
        for(int j = i;j<height;j++){
            //在i列的下寻找最大的元素在哪行，与第一行互换
            if(A1[j][i]>max_value){
                max_j = j;
                max_value = A1[j][i];
            }
        }
        //std::cout<<max_j<<std::endl;
        //交换当前行
        swap(A1[i],A1[max_j]);
        //消元
        for(int k=i+1;k<height;k++){
            mutiAndAdd(A1[k],A1[i],A1[k][i]/A1[i][i]);
        }
    }
    std::cout<<"经过列主元消元法后所得的增广矩阵为："<<std::endl;
    for(auto x=A1.begin();x!=A1.end();x++){
        for(auto i = x->begin();i != x->end();i++)
        
            std::cout<<std::left<<std::setw(10)<<*i<<"   ";
        std::cout<<std::endl;
    }
    //回带计算
    result.push_back(A1[height-1][width]/A1[width-1][width-1]);
    for(int i=height-2;i>=0 ;i--){
        float temp =A1[i][width]; //第i行最后一个元素；
        for(int j = width-1;j>i;j--){
            temp -= result[width-1-j]*A1[i][j];
        }
        temp /=A1[i][i];
        result.push_back(temp);
    }
    std::cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<std::endl;
    std::cout<<"方程的解从x0 x1 。。。xn依次为"<<std::endl;
    for(auto x=result.rbegin();x!=result.rend();x++){
        std::cout << std::setprecision(5)<<std::setw(10)<<*x;
    }
    std::cout<<std::endl;
}

void Question_40::mutiAndAdd(std::vector<float>&x1,std::vector<float>x2,float k){
    //x1 += x2*k
    for(int i =0 ;i<x1.size();i++){
        x1[i] -= x2[i]*k;
    }
}
