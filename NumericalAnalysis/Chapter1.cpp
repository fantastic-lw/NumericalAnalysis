//
//  Chapter1.cpp
//  NumericalAnalysis
//
//  Created by weiliu on 2020/11/14.
//

#include "Chapter1.hpp"
void Question_17::calculate(){
    exact_value = 0.0;
    estimated_value_s2l = 0.0;
    estimated_value_l2s = 0.0;
    if(N<2)
        throw std::runtime_error("N value must larger than 1");
    else{
        exact_value = 1.0/2.0 * (3.0/2.0 - 1/N -1/(N+1));
        for(float i =2.0 ; i<=N; i++){
            estimated_value_s2l += 1/ ( (N-i+2)*(N-i+2)  -1);
            estimated_value_l2s += 1/(i*i -1);
        }
    }
}
