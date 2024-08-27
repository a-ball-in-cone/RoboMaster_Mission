//3.1
#ifndef IMAGE_MATRIX_H
#define IMAGE_MATRIX_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iterator>
using namespace std;

class imageMatrix{
	private:
		int w,h;
		vector< vector<int> > matrix;
	public:
		imageMatrix(int,int); 
		bool isBlank(){return w*h==0?1:0;}
		void input(const char* name);
		void output(const char* name);
		void show();
		void binary_show();
		void draw_point(int X,int Y,int VALUE);
		void draw_rectangle(int X,int Y,int W,int H,int VALUE);
		void thresholding(int THR);
		void flip();
		void rotate();
};

#include "image_matrix.cpp"

#endif 
