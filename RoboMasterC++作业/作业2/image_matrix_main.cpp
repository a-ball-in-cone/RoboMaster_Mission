#include "image_matrix.cpp"

int main(){
	//3.2 
	imageMatrix image1(5,7);
	image1.draw_rectangle(0,0,5,7,255);
	image1.draw_point(0,0,0);
	image1.show();
	cout<<endl;
	//3.3
	//上下翻转==旋转+翻转+旋转+旋转+旋转
	image1.rotate();
	image1.flip();
	for(int i=0;i<3;i++)
		image1.rotate();
	image1.show();
	cout<<endl;
	//3.4
	imageMatrix imageR;
	imageR.input("imageR.txt");
	imageR.thresholding(100);
	imageR.rotate();
	imageR.flip();
	imageR.binary_show();
	 
	system("pause");
	return 0;
}
