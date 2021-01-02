//
//  Chapter7.hpp
//  NumericalAnalysis
//
//  Created by weiliu on 2021/1/2.
//

#ifndef Chapter7_hpp
#define Chapter7_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include "Chapter3.hpp"
using namespace std;
class Question10{
private:
    float (*f_x_t)(float,float) ; //指向函数f_x_t的指针
    float (*fai)(float) ; //指向函数fai的指针
    float (*alpha)(float) ; //指向函数alpha的指针
    float (*beta)(float) ; //指向函数beta的指针
    float a ;
    int M;
    int N;
    float x_start = 0;
    float x_end = 1;
    float t_start = 0;
    float t_end = 1;
    vector<float> chasing(vector<float>&,const vector<float>&,vector<float>&,vector<float>&);
public:
    Question10(float (*_f_x_t)(float,float),float (*_fai)(float),float (*_alpha)(float),float (*_beta)(float),float _a,int _M, int _N,float T = 1):f_x_t(_f_x_t),fai(_fai),alpha(_alpha),beta(_beta),a(_a),M(_M),N(_N),t_end(T){}
    vector<vector<float> > calculate();
};
#endif /* Chapter7_hpp */
