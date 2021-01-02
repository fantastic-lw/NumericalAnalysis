//
//  Chapter7.cpp
//  NumericalAnalysis
//
//  Created by weiliu on 2021/1/2.
//

#include "Chapter7.hpp"
vector<float> Question10::chasing(vector<float>& D,const vector<float>& U,vector<float>& L,vector<float>& b){
    unsigned length = D.size();
    vector<float> res(length,0);
    vector<float> bb,y;
    bb.push_back(D[0]);
    y.push_back(b[0]);
    //chasing
    for(int i = 1  ;i<length;i++){
        float l = L[i-1] / bb.back();
        bb.push_back(D[i] - l*U[i-1]);
        y.push_back(b[i]-l*y.back());
    }
    //回带
    res[length-1] = y.back()/bb.back();
    for(int i = length-2;i >-1;i--){
        res[i] = (y[i]-U[i]*res[i+1])/bb[i];
    }
    return res;
}
vector<vector<float> > Question10::calculate(){
    float h = (x_end-x_start)/M;
    float tau =(t_end-t_start)/N;
    float r =a*tau/(h*h);
    //系数矩阵，节约空间，用一数组表示
    vector<float> D1(M-1,1.0+r),D2(M-1,1.0-r);
    vector<float> U1(M-2,-r/2),U2(M-2,r/2);
    vector<float> L1(M-2,-r/2),L2(M-2,r/2);
    
    vector<vector<float> > result;
    vector<float> u_k;
    vector<float> u_k_1;
    for(int i = 1; i< M;i++){
        u_k.push_back(fai(x_start+i*h));
    }
//    cout<<"u_k"<<u_k.size()<<endl;
//    for(auto i:u_k)
//        cout<<i<<"  ";
//    cout<<endl;
    //开始迭代
    result.push_back(u_k);
    for(int k = 0;k < N;k++){
        vector<float> u(M-1,0);
        //u [i] m2*u_k + f
        for(int i = 1 ;i < M -2 ;i++)
            u[i] = u_k[i]*D2[i] +u_k[i-1]*L2[i-1]+u_k[i+1]*U2[i] + tau * f_x_t((x_start+(i+1)*h),(k+0.5)*tau);
        
        u[0] = u_k[0]*D2[0]+u_k[1]*U2[0]+0.5*r*(alpha(k*tau)+alpha((k+1)*tau))+ tau * f_x_t((x_start+1*h),(k+0.5)*tau);
        u[M-2] = u_k[M-2]*D2[M-2]+u_k[M-3]*L2[M-3]+0.5*r*(beta(k*tau)+beta((k+1)*tau))+tau* f_x_t((x_start+(M-1)*h),(k+0.5)*tau);
//        cout<<"u"<<u.size()<<endl;
//        for(auto i:u)
//            cout<<i<<"  ";
//        cout<<endl;
        u_k_1 = chasing(D1,U1,L1,u);
        result.push_back(u_k_1);
        u_k = u_k_1;
    }
    return result;
    
        
}

