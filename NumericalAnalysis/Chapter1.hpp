//
//  Chapter1.hpp
//  NumericalAnalysis
//
//  Created by weiliu on 2020/11/14.
//

#ifndef Chapter1_hpp
#define Chapter1_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
class Question_17{
private:
    float N = 2.0;
    float exact_value = 0 ;
    float estimated_value_s2l = 0; //small to large
    float estimated_value_l2s = 0; //large to small
    float err = 0;
public:
    Question_17(float n):N(n){}
    float get_exact_value() {return exact_value;}
    float get_estimated_s2l() {return estimated_value_s2l;}
    float get_estimated_l2s() {return estimated_value_l2s;}
    float get_err_s2l() {return exact_value - estimated_value_s2l;}
    float get_err_l2s() {return exact_value - estimated_value_l2s;}
    void calculate();
};
#endif /* Chapter1_hpp */
