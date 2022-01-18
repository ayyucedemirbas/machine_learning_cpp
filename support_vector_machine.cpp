
//Source: https://medium.com/@dr.sunhongyu/machine-learning-c-svm-support-vector-machine-simple-example-deff5d55d43e

#include <iostream>
using namespace std;
#include <vector>
#include <bits/stdc++.h>

double getHingeLoss(double &x1, double &x2, int &y, double &w1, double &w2, double &b){
	double loss = 0;
	if(y==1){
		loss = 1-(w1*x1 + w2*x2 + b);
	}
	else{
		loss = 1+(w1*x1 + w2*x2 + b);
	}
	if(loss < 0) {
		loss = 0;
		
	}
	return loss;
}

double getSVMCost(vector<double> &x1, vector<double> &x2, vector<int> &y,double w1, double w2, double b,
double &dw1, double &dw2, double &db){
	int n = static_cast<int>(y.size());
	// hinge loss
	double cost=0;
	dw1 = 0;
	dw2 = 0;
	db = 0;
	for(int i = 0; i<n;i++){
		double loss = getHingeLoss(x1[i], x2[i], y[i], w1, w2, b);
		cost += loss;
		// when loss = 0, all derivatives are 0
		if(loss > 0){
			dw1 += (-x1[i]*y[i]);
			dw2 += (-x2[i]*y[i]);
			db += (-y[i]);
		}
	}
	cost /= n;
	dw1 /= n;
	dw2 /= n;
	db /=n;
	return cost;
}
void trainSVM(vector<double> &x1, vector<double> &x2, vector<int> &y){
	double lrate = 0.0005;
	double threshold = 0.001;
	double w1 = 1;
	double w2 = 1;
	double b = 0;
	double dw1 = 0;
	double dw2 = 0;
	double db = 0;
	int iter = 0;
	while(true){
		double cost = getSVMCost(x1, x2, y, w1, w2, b, dw1, dw2, db);
		if(iter%1000==0){
			std::cout<<"Iter: "<<iter<< " cost = "<<cost<< " dw1 = " << dw1 << " dw2 = " << dw2 << " db = "<< db << std::endl;
		}
		iter++;
		if(abs(dw1) < threshold && abs(dw2) < threshold && abs(db) < threshold){
			std::cout<<"y = "<<w1<<" * x1 + "<<w2<<" * x2 + "<<b<<std::endl;
			break;
		}
		w1 -= lrate* dw1;
		w2 -= lrate* dw2;
		b -= lrate * db;
	}
}
int main() {
	// age
	vector<double> X1 = {35,27,19,25,26,45,46,48,47,29,27,28,27,30,28,23,27,18};
	// income in K
	vector<double> X2 = {20,57,76,33,52,26,28,29,49,43,137,44,90,49,84,20,54,44};
	// buy a house
	vector<int> Y = {-1, -1, -1, -1, -1, 1, 1, 1, 1, -1, 1, -1, -1, -1, -1, -1, -1, -1 };
	trainSVM(X1, X2, Y);
	return 0;
}
