//
//  Chapter5.hpp
//  NumericalAnalysis
//
//  Created by weiliu on 2021/1/2.
//

#ifndef Chapter5_hpp
#define Chapter5_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
using namespace::std;
class Romberg{
private:
    vector<double> Tn;
    vector<double> Sn;
    vector<double> Cn;
    vector<double> Rn;
    int split_num = 1;
    double max_err = 0.5e-07;
    double start_point;
    double end_point;
    double (*p)(double) ; //指向被积函数f(x)的指针
    void vec_print(vector<double> vec);
public:
    /// 构造函数
    /// @param start 积分上界
    /// @param end 积分下界
    /// @param set_err 设定误差
    Romberg(double start,double end,double set_err,double (*f)(double)):
    start_point(start),end_point(end),max_err(set_err),p(f){};
    void calculate();
    void result_print();
    
};
#endif /* Chapter5_hpp */
