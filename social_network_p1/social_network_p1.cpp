// social_network_p1.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream> 
#include<fstream>
#include <string>
#include "vector"
#include <sstream>
using namespace std;
vector <int> list[916426];//nodes:875713 edges:5105039
int _tmain(int argc, _TCHAR* argv[])
{
	for(int i=0;i<916426;i++)
		list[i].clear();
	 vector<string> v ;
	 ifstream inputFile("web-Google.txt");
     string line;
	 int d1=0;
	 int d2=0;
	 int c=0;
     for(int i=0;i<5105030;i++)
     {
		 inputFile >> d1;
		 inputFile >> d2;
		list[d1].push_back(d2);
		 if(c>1000000){
			 c=0;
			 cout<<d1<<":"<<d2<<endl;
			 cout<<"###"<<endl;
		 }
		  c++;
     }
    system("pause");
	return 0;
}
