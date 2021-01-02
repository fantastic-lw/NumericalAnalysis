//
//  Chapter5.cpp
//  NumericalAnalysis
//
//  Created by weiliu on 2021/1/2.
//

#include "Chapter5.hpp"

void Romberg::calculate(){
    cout<<max_err<<endl;
    double length =end_point-start_point;
    double T_n = length*(p(start_point)+p(end_point))/2.0;
    Tn.push_back(T_n);
    double h  = length;
    while(true){
        double  T_2n = 0;
        h = length / split_num;
        for(int k = 0;k < split_num;k++){
            T_2n += p(start_point+(k+0.5)*h);
        }
        T_2n  = (T_n + h*T_2n)*0.5;
        Tn.push_back(T_2n);
        T_n = T_2n;
        split_num *= 2;
        if(Tn.size()>1){
            Sn.push_back(4.0/3.0*Tn.back()- 1.0/3* (*(Tn.end() - 2)));
        }
        if(Sn.size()>1){
            Cn.push_back(16.0/15*Sn.back()- 1.0/15* (*(Sn.end() - 2)));
        }
        if(Cn.size()>1){
            Rn.push_back(64.0/63*Cn.back()- 1.0/63* (*(Cn.end() - 2)));
        }
        if(Rn.size()>1){
            double err = abs(Rn.back()- *(Rn.end()-2));
            if(err <= max_err){
                cout<<"max_err is "<<max_err<<endl;
                cout<<"err is "<<setprecision(10)<<err<<endl;
                break;
            }
                
        }
    }
}
void Romberg::vec_print(vector<double> vec){
    for(auto i:vec)
        cout <<setprecision(10)<<i<<'\t';
    cout<<endl;
}
void Romberg::result_print(){
    cout<<"final result is "<<Rn.back()<<endl;
    cout<<"Tn(f)"<<endl;
    vec_print(Tn);
    cout<<"Sn(f)"<<endl;
    vec_print(Sn);
    cout<<"Cn(f)"<<endl;
    vec_print(Cn);
    cout<<"Rn(f)"<<endl;
    vec_print(Rn);
}
