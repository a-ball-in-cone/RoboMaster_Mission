#include <iostream>
using namespace std;

int main(){
	int x;
	
	cout<<"请输入一个1-10之间的整数"<<endl; 
	cin>>x;
	if(0<x&&x<11){
		for(int i=0;i<x;i++){
			cout<<"Hello, RoboMaster!"<<endl;
		}
	}
	else
		cout<<"输入错误"<<endl;
	return 0;
}
