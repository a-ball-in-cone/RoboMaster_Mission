#ifndef IMAGE_MATRIX_CPP
#define IMAGE_MATRIX_CPP

#include "image_matrix.h"

imageMatrix::imageMatrix(const int W=0,const int H=0){
	w=W;h=H;
	for(int i=0;i<h;i++){
		vector<int> line_vector(w,0);
		matrix.push_back(line_vector);
	}
}
	
void imageMatrix::input(const char* name){
	ifstream file4in(name);
	if(file4in.fail()==0){
		matrix.clear();
		h=0;
		string line,pixel;
		int num;
		while(getline(file4in,line)){
			w=0;
			stringstream l(line);
			vector<int> line_vector;
			while(getline(l,pixel,',')){
				stringstream p(pixel);
				p>>num;
				line_vector.push_back(num);
				w++;
			}
			matrix.push_back(line_vector);
			h++;
		}
		file4in.close();
		cout<<"已导入文件。"<<endl;
	}
	else
		cout<<"文件不存在！"<<endl;	
	return;
}

void imageMatrix::output(const char* name){
	if(isBlank()){
		cout<<"图像为空！"<<endl;
	}
	else{
		ofstream file4out(name);
		for(int i=0;i<h;i++){
			for(int j=0;j<w-1;j++){
				file4out<<matrix[i][j]<<',';
			}
			file4out<<matrix[i][w-1]<<endl;
		}
		file4out.close();
		cout<<"已导出文件。"<<endl;
	}
	return;
}

void imageMatrix::show(){
	if(isBlank()){
		cout<<"图像为空！"<<endl;
	}
	else{
		for(int i=0;i<h;i++){
			for(int j=0;j<w-1;j++){
				cout<<matrix[i][j]<<'\t';
			}
			cout<<matrix[i][w-1]<<endl;
		}
	}
	return;
}

void imageMatrix::binary_show(){
	if(isBlank()){
		cout<<"图像为空！"<<endl;
	}
	else{
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				if(matrix[i][j]==0)
					cout<<". ";
				else
					cout<<"O ";
			}
			cout<<endl;
		}
	}
	return;
}

void imageMatrix::draw_point(int X,int Y,int VALUE){
	if(-1<X&&X<w&&-1<Y&&Y<h)
		matrix[Y][X]=VALUE;
}

void imageMatrix::draw_rectangle(int X,int Y,int W,int H,int VALUE){
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(((X<=j&&j<X+W)&&(Y<=i&&i<Y+H))&&(!((X<j&&j<X+W-1)&&(Y<i&&i<Y+H-1)))){
				matrix[i][j]=VALUE;
			}
		}
	}
}

void imageMatrix::thresholding(int THR){
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(matrix[i][j]<=THR){
				matrix[i][j]=0;
			}
		}
	}
}

void imageMatrix::flip(){
	for(int i=0;i<h;i++){
		reverse(matrix[i].begin(),matrix[i].end());
	}
}

void imageMatrix::rotate(){
	vector< vector<int> > matrix2;
	for(int i=0;i<w;i++){
		vector<int> line_vector(h,0);
		matrix2.push_back(line_vector);
	}
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			matrix2[j][h-i-1]=matrix[i][j];
		}
	}
	matrix.clear();
	copy(matrix2.begin(),matrix2.end(),back_inserter(matrix));
	swap(w,h);
}

#endif
