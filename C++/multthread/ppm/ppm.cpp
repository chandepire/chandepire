#include <stdio.h>
#include <stdlib.h>


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
 
int writePPMdataP3(FILE* f, unsigned char* img, int w, int h) {
	int i,j;
	for(i=0;i<h;i++) {	// every rwo
		for(j=0;j<w;j++) {	// every line
			fprintf(f, "%d ",img[i*w*3+3*j]);
			fprintf(f, "%d ",img[i*w*3+3*j+1]);
			fprintf(f, "%d ",img[i*w*3+3*j+2]);	// PS: 对于j=w-1的时候，最后一个空格可以不写，但是这里就不考虑了
		}
		fprintf(f, "\n");
	}
}
 
int writePPMdataP6(FILE* f, unsigned char* img, int w, int h) {
	int i,j;
	//fwrite(&img[0], 1, 1, f);
	//for(int i=0;i<1;++i)
	fwrite(img, 18, 1, f);
	/*for(i=0;i<h;i++) {
		for(j=0;j<w;j++) {
			fwrite(&img[w*i+j], 1, 1, f);
			fwrite(&img[w*i+j+1], 1, 1, f);
			fwrite(&img[w*i+j+2], 1, 1, f);
		}
    }*/
}
 
#define WIDTH	3
#define HEIGHT	2
unsigned char img[WIDTH*HEIGHT*3]={255,10,50,90,10,0,0,0,255,255,10,0,255,255,255,0,0,0};
 
int main(int argc,char **argv) {
	char *filename1 = "testP3.ppm";
	char *filename2 = "testP6.ppm";
 
    FILE *f3 = fopen(filename1, "w");
	if (f3==NULL) {
		printf("FILE error\n");
		exit(0);
	}
 
    FILE *f6 = fopen(filename2, "w");
	if (f6==NULL) {
		printf("FILE error\n");
		exit(0);
	}
 
	writePPMHeader(f3, 'A', WIDTH, HEIGHT, 255);
	writePPMdataP3(f3, img, WIDTH, HEIGHT);
 
	writePPMHeader(f6, 'B', WIDTH, HEIGHT, 255);
	writePPMdataP6(f6, img, WIDTH, HEIGHT);
 
	fclose(f3);
	fclose(f6);
 
	return 0;
}
