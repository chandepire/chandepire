#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace cv;
using namespace std;

int writePPMHeader(FILE *f, char magic, int w, int h, int color) {
	if (f==NULL) {
		printf("FILE error\n");
		exit(0);
	}
 
	if (magic=='A') {// ASCII
		fprintf(f, "P3\n");
	} else if (magic=='B') {
		fprintf(f, "P6\n");
	} else {
		printf("Magic can only be A(ASCII) or B(binary)\n");
		exit(0);
	}
 
	fprintf(f, "%d %d\n", w, h);
    fprintf(f, "%d\n", color);
	return 0;
}
#define WIDTH	3
#define HEIGHT	2
unsigned char img1[WIDTH*HEIGHT*3]={255,0,0,0,255,0,0,0,255,255,255,0,255,255,255,0,0,0};
 
void jpg2ppm(string input,string output)
{
	Mat img = imread(input);
	unsigned char ptrB,ptrG,ptrR;

	//FILE *f = fopen(output.c_str(),"wb");
	ofstream ppm(output,ios::binary);
	//writePPMHeader(f, 'B', img.cols, img.rows, 255);
	ppm << "P6\n";
	ppm << img.cols << " " << img.rows << endl;
	ppm << 255 << endl;
	//fwrite(img.data, img.cols*img.channels(),1, f);
	//fwrite(&img1[0], sizeof(unsigned char), 2, f);

	for(int i=0;i<img.rows;++i)
	{
		//unsigned char *data = img.ptr<unsigned char>(i);
		//cout << fwrite(data, 1,img.channels()*img.cols, f);
		for(int j=0;j<img.cols;++j)
		{
			ptrB = img.at<Vec3b>(i,j)[0];
			ptrG = img.at<Vec3b>(i,j)[1];
			ptrR = img.at<Vec3b>(i,j)[2];

			ppm << ptrR <<  ptrG << ptrB;
		}
	}

	ppm.close();
}

void ppm2jpg(string input,string output)
{
	ifstream ppm(input,ios::binary);
	string str;
	ppm >> str;
	cout << str << endl;
		int width,height;
	ppm >> width >> height;
	cout << width << " " << height << endl;
	//int max_value;
	ppm >> str;
	cout << str << endl;
	unsigned char r,g,b;
	
	Mat img_std = imread("input.jpg");
	Mat M(height,width,CV_8UC3);
	for(int i=0;i<height;++i)
	{
		for(int j=0;j<width;j++)
		{
			ppm >> r >> g >> b;
			//ppm.read(&r,1);
			//ppm.read(&g,1);
			//ppm.read(&b,1);
			M.at<Vec3b>(i,j)[0] = (unsigned char)b;
			M.at<Vec3b>(i,j)[1] = (unsigned char)g;
			M.at<Vec3b>(i,j)[2] = (unsigned char)r;
			//cout << "(" << i << "," << j << ")" << ":" << (int)b << "    " << (int)(img_std.at<Vec3b>(i,j)[0]) << endl;
			//cout << "(" << i << "," << j << ")" << ":" << (int)g << "    " << (int)(img_std.at<Vec3b>(i,j)[1]) << endl;
			//cout << "(" << i << "," << j << ")" << ":" << (int)r << "    " << (int)(img_std.at<Vec3b>(i,j)[2]) << endl << endl;
			//break;
		}
		//break;
		//getchar();
	}
	imwrite(output,M);
	ppm.close();
}
int main(int argc, char **argv)
{
	//string img = "input.jpg";
	//string ppm = "input2.ppm";
	//jpg2ppm(img,ppm);
	string ppm = "input2.ppm";
	string img = "img3.jpg";
	//ppm2jpg(ppm, img);
	//Mat m = imread(ppm);
	ifstream fin(ppm, std::ifstream::binary);
	if(fin.fail())
		cout << "could not open the file" << endl;
	string str;
	fin >> str;
	cout << str << endl;
	int width,height;
	fin >> width >> height;
	cout << width << " " << height << endl;
	//int max_value;
	fin >> str;
	cout << str << endl;

	//char buffer;
	//string rgb( ( istreambuf_iterator<char>(fin) ),istreambuf_iterator<char>() ); 
	//cout << "rgb size:" << rgb.size() << endl;
	/*fin.get();
	for(int i=1;i<19;++i)
	{
		buffer = fin.get();
		if(buffer == '\n')
			cout << 10 << endl;
		else
			cout <<(int)buffer << endl;
	
	}*/
	/*unsigned char buffer;
	for(int i=0;i<18;++i)
	{
		fin >> buffer;
		cout << (int)buffer << endl;
		//printf("%d\n",(int)buffer);
		//cout << (unsigned int)((char)) << endl;
	}*/
	//if ( rgb.size()/3 != (width*height) )
	//	cout<<"Invalid pixel number!"<<endl;
	
	 char red;
	 char green;
	 char blue;
	 fin.get();
	// fin >> buf;
	Mat img_std = imread("input.jpg");
	int k = 0;
	Mat M(height,width,CV_8UC3);
	for(int i=0;i<img_std.rows;++i)
	{
		for(int j=0;j<img_std.cols;j++)
		{
			//fin >> red >> green >> blue;
			red  = fin.get();
			green = fin.get();
			blue = fin.get();
			//red = rgb[1+k*3];
			//green=rgb[1+k*3+1];
			//blue =rgb[1+k*3+2];
			M.at<Vec3b>(i,j)[0] = (int)(unsigned char)blue;
			M.at<Vec3b>(i,j)[1] = (int)(unsigned char)green;
			M.at<Vec3b>(i,j)[2] = (int)(unsigned char)red;
			cout << "(" << i << "," << j << ")" << ":" << (int)(unsigned char)blue << "    " << (int)(img_std.at<Vec3b>(i,j)[0]) << endl;
			cout << "(" << i << "," << j << ")" << ":" << (int)(unsigned char)green << "    " << (int)(img_std.at<Vec3b>(i,j)[1]) << endl;
			cout << "(" << i << "," << j << ")" << ":" << (int)(unsigned char)red << "    " << (int)(img_std.at<Vec3b>(i,j)[2]) << endl << endl;
			
			k++;
		}
		
		
	}
	imwrite(img,M);
	
	//imshow("a",M);
	//waitKey(10000);
	

	return 0;
}
