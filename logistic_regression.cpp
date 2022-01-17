#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

std::vector<double> theta {-6,0.05,1.0}; 
  double sigmoid(double x) {
  double tmp =1.0 / (1.0 + exp(-x)); 
  std::cout << "prob=" << tmp<<std::endl; 
  return tmp;
}
double hypothesis(std::vector<double> x){
  double z;
  z=std::inner_product(std::begin(x), std::end(x), std::begin(theta), 0.0);
  std::cout << "inner_product=" << z<<std::endl; 
  return sigmoid(z);
}
int classify(std::vector<double> x){
  int hypo=hypothesis(x) > 0.5f;
  std::cout << "hypo=" << hypo<<std::endl; 
  return hypo;
}
int main() {
  std::vector<double> x1 {1,40,3.5};
  classify(x1);
 }
