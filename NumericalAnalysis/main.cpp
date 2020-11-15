//
//  main.cpp
//  NumericalAnalysis
//
//  Created by weiliu on 2020/11/14.
//

#include <iostream>
#include <string>
#include "Chapter1.hpp"
#include "Chapter2.hpp"
#include "Chapter3.hpp"
using namespace::std;

//第二章所需要计算的函数
float f(float x ){
    return x*x*x /3 -x;
}
float f1(float x ){
    return x*x -1;
}

void solution_for_chapter1();
void solution_for_chapter2();
void solution_for_chapter3();
int main(int argc, const char * argv[]) {
    solution_for_chapter1();
    solution_for_chapter2();
    solution_for_chapter3();
    return 0;
}
void solution_for_chapter1(){
    cout<<"******************************************"<<endl;
    cout<<"第一章解题开始"<<endl;
    vector<float> N{100.0,10000.0,1000000.0};
    for(auto i : N){
        cout<<"Now the N is "<< i <<endl;
        Question_17 solutin(i);
        solutin.calculate();
        cout <<"准确值是：             " << solutin.get_exact_value()<<endl;
        cout <<"从大到小顺序计算结果为： "<<solutin.get_estimated_l2s()<<endl;
        cout <<"误差为：              "<<solutin.get_err_l2s()<<endl;
        cout <<"从小到大顺序计算结果为： "<<solutin.get_estimated_s2l()<<endl;
        cout <<"误差为：              "<<solutin.get_err_s2l()<<endl;
        cout<<"----------------------------"<<endl;
    }
    cout<<"第一章解题结束"<<endl;
    cout<<"******************************************"<<endl;
    cout<<endl;
}
void solution_for_chapter2(){
    cout<<"******************************************"<<endl;
    cout<<"第二章解题开始"<<endl;
    
    float lf = -1;
    float rg = 0;
    float mid = (lf+rg)/2.0;
    for(unsigned i=0;i<30;i++){
        Question_20 solution(mid, 1E-6, &f, &f1);
        float x  =solution.calculate();
        // 若收敛于x2 = 0
        if( abs(x) < abs(abs(x)-1.73205)){
            rg = mid;
        }
        else{
            lf = mid;
        }
        mid = (lf+rg)/2.0;
    }
    cout<<"经过30次二分法寻找迭代后所得segama为"<<mid<<endl;
    cout<<"接下来进行测试"<<endl;
    vector<float> x0{-4,-0.775,-0.774,0.774,0.775,4};
    for(auto i :x0){
        Question_20 solution(i, 1E-6, &f, &f1);
        cout<<"当起始点为:"<<i<<std::setw(20)<<"       此时方程的解为"<<std::left<<std::setw(15)<<solution.calculate()<< "迭代次数为："<<std::left<<std::setw(10)<<solution.get_count()<<endl;
        //std::cout<<
    }
    cout<<"第二章解题结束"<<endl;
    cout<<"******************************************"<<endl;
    cout<<endl;
}
void solution_for_chapter3(){
    cout<<"******************************************"<<endl;
    cout<<"第三章解题开始"<<endl;
    vector<vector<float>> A{{31,-13,0,0,0,-10,0,0,0},
        {-13,35,-9,0,-11,0,0,0,0},
        {0,-9,31,-10,0,0,0,0,0},
        {0,0,-10,79,-30,0,0,0,-9},
        {0,0,0,-30,57,-7,0,-5,0},
        {0,0,0,0,-7,47,-30,0,0},
        {0,0,0,0,0,-30,41,0,0},
        {0,0,0,0,-5,0,0,27,-2},
        {0,0,0,-9,0,0,0,-2,29}};

    vector<float> b{-15,27,-23,0,-20,12,-7,7,10};
    Question_40 so(A, b);
    so.calculate();
    
        
    cout<<"第三章解题结束"<<endl;
    cout<<"******************************************"<<endl;
    cout<<endl;
}
