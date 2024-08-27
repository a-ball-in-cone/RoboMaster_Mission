#include "image_matrix.cpp"

int main(){
	imageMatrix image1;
	image1.input("imageR.txt");
	image1.thresholding(100);
	image1.rotate();
	image1.flip();
	image1.draw_rectangle(0,0,9,13,100);
	image1.show();
	image1.binary_show();
	return 0;
}
