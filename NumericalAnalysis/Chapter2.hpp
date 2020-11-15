//
//  Chapter2.hpp
//  NumericalAnalysis
//
//  Created by weiliu on 2020/11/14.
//

#ifndef Chapter2_hpp
#define Chapter2_hpp

#include <stdio.h>
#include <iostream>
class Question_20{
private:
    float x0 = 0;
    float x = 0;
    int count = 0;
    float err = 9999;
    float max_err = 1e-03;
    float (*p)(float) ; //指向f(x)的指针
    float (*p1)(float); //指向f'(x)的指针
public:
    Question_20(float start_point,float set_err, float (*f)(float),float (*f1)(float)):x0(start_point),max_err(set_err),p(f),p1(f1){}
    int get_count(){return count;}
    float calculate(){
        //count = 0;
        //err = 9999;
        x = x0;
        do{
            //std::cout<<count++<<std::endl;
            count++;
            x = x - (*p)(x)/(*p1)(x);
            err  = (*p)(x) >0 ? (*p)(x): -(*p)(x) ;
        }while(err > max_err);
        return x;
    }
};
    
#endif /* Chapter2_hpp */
