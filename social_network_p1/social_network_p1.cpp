// social_network_p1.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream> 
#include<fstream>
#include <string>
#include "vector"
#include <sstream>
using namespace std;
vector <int> list[916426];
//nodes:875713 edges:5105039
bool find_triple(int i,int j);
int combination(int x,int y);
bool check_exist(int d1,int d2);
int _tmain(int argc, _TCHAR* argv[])
{
	///////////////////////////////
	//存成林街串列/////////////////
	///////////////////////////////
	for(int i=0;i<916426;i++)
		list[i].clear();
	vector<string> v ;
	ifstream inputFile("web-Google.txt");
	string line;
	int d1=0;
	int d2=0;
	int c=0;
	for(int i=0;i<5105039;i++)
	{
		inputFile >> d1;
		inputFile >> d2;
		if(!check_exist(d1,d2))
			list[d1].push_back(d2);
		if(!check_exist(d2,d1))
			list[d2].push_back(d1);
		if(c>1000000){
			c=0;
			cout<<d1<<":"<<d2<<endl;
			cout<<"###"<<endl;
			//cout<<list[0].size()<<endl;
		}
		c++;
	}
	//////////////////////////////////////////////
	//印出林街串列////////////////////////////////
	//////////////////////////////////////////////
	/*
	fstream fp2;
    fp2.open("out.txt", ios::out);

	for(int j=0;j<916426;j++){
		if(list[j].size()>0){
			//cout<<j<<":{";
			fp2<<j<<":{";
			for(int i=0;i<list[j].size();i++){
				//cout<<list[j][i];
				fp2<<list[j][i]<<",";
			}
			//cout<<"}"<<endl;
			fp2<<"}"<<endl;
		}
	}
	fp2.close();
	*/
	/////////////////////////////////////////////////
	//計算clustering cofficient//////////////////////
	/////////////////////////////////////////////////
	
	fstream fp;
    fp.open("out2.txt", ios::out);
	double sum=0;
	for(int j=0;j<916426;j++){
		if(list[j].size()>0){
			double tmp=0;
			if(list[j].size()>1){
				double degree=(double)combination(list[j].size(),2);
				fp<<j<<":degree:"<<degree<<",";
				double triple=0;
				for(int i=0;i<list[j].size();i++){
					for(int k=i+1;k<list[j].size();k++){
						if(find_triple(list[j][i],list[j][k])){
							//cout<<"!!!"<<endl;
							triple++;
						}
					}
				}
				tmp=triple/degree;
				fp<<"triple:"<<triple<<"clustering cofficient:"<<tmp<<endl;
			}
			else
				fp<<j<<":degree:0,"<<"triple:0 clustering cofficient:0"<<endl;
			sum=sum+tmp;
		}

	}
	fp.close();
	
	//875711
	cout<<sum/875711<<endl;
	
	system("pause");
	return 0;
}
bool find_triple(int i,int j){
	for(int k=0;k<list[i].size();k++){
		if(list[i][k]==j)
			return true;
	}
	return false;
}
//排列組合
int combination(int x,int y){  
	if(x>=3)
		return x*(x-1)/2;
	else
		return 1;
}
bool check_exist(int d1,int d2){
	for(int n=0;n<list[d1].size();n++){
		if(list[d1][n]==d2)
			return true;
	}
	return false;
}