#include <iostream>
using namespace std;

int main(){
	int x;
	
	cout<<"������һ��1-10֮�������"<<endl; 
	cin>>x;
	if(0<x&&x<11){
		for(int i=0;i<x;i++){
			cout<<"Hello, RoboMaster!"<<endl;
		}
	}
	else
		cout<<"�������"<<endl;
	return 0;
}
