#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Pixel struct */
typedef struct {
	/* Color values of the pixel */
	unsigned char r, g, b;
} Pixel;

/* Image struct */
typedef struct {
	/* Dimensions of image */
	int width;
	int height;
	/* Array to store pixels */
	Pixel * pixels;
} Image;

/* Method Prototypes */
void VerifyInput();
void ReadImage(char * filename, Image * img);
void WriteImage(char * filename, Image * img);
int GetPixelIndex(int width, int height, int row, int column);
void YellowDiagonal(Image * src, Image * dest);
void LeftRightCombine(Image * left, Image * right, Image * dest);

/* Main Method */
int main(int argc, char * argv[]) {
	VerifyInput();

	Image source;
	Image yellowDiag;
	Image leftRight;


	/* Read an image from a file into an Image object */
	ReadImage("2G_input.pnm", &source);
	WriteImage("output_of_read.pnm", &source);

	/* Create a copy of the source image with a yellow line along the diagonal */
	YellowDiagonal(&source, &yellowDiag);
	WriteImage("yellow_diagonal.pnm", &yellowDiag);

	/* Combine two images, placing one on the left and one on the right */
	LeftRightCombine(&source, &yellowDiag, &leftRight);
	WriteImage("2G_output.pnm", &leftRight);

	exit(EXIT_SUCCESS);
}

/* Verifies that the input files exist */
void VerifyInput() {
	fprintf(stderr, "Verifying input files . . . \n");
	FILE *f_in = fopen("2G_input.pnm", "r");
	if (f_in == NULL) {
		fprintf(stderr, "Cannot open 2G_input.pnm for reading.\n");
		exit(EXIT_FAILURE);
	}
	fclose(f_in);

	FILE *f_out = fopen("2G_output.pnm", "w");
	if (f_out == NULL) {
		fprintf(stderr, "Cannot open 2G_output.pnm for writing.\n");
		exit(EXIT_FAILURE);
	}
	fclose(f_out);
	fprintf(stderr, "Verified!\n");
}

/* Reads an image from a file into an Image struct */
void ReadImage(char * filename, Image * img) {
	fprintf(stderr, "Reading image \"%s\"\n", filename);

	FILE * f_in = fopen(filename, "r");

	char magicNum[128];
	int width, height, maxval;
	if(f_in == NULL) {
		fprintf(stderr, "Unable to open \"%s\" for reading!\n", filename);
		exit(EXIT_FAILURE);
	}

	fscanf(f_in, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxval);
	fprintf(stdin, "%s\n%d %d\n%d\n", magicNum, width, height, maxval);

	if(strcmp(magicNum, "P6") != 0) {
		fprintf(stderr, "Unable to read \"%s\" because it is not a PNM file!\n", filename);
		fclose(f_in);
		exit(EXIT_FAILURE);
	}

	img->width = width;
	img->height = height;
	img->pixels = (Pixel *) malloc(img->width * img->height * sizeof(Pixel));

	fread(img->pixels, sizeof(Pixel), img->width * img->height, f_in);

	fclose(f_in);

	fprintf(stderr, "Done reading image \"%s\"\n", filename);
}

/* Writes an Image struct to a file, following the PPM format */
void WriteImage(char * filename, Image * img) {
	fprintf(stderr, "Writing image \"%s\"\n", filename);

	FILE * f_out = fopen(filename, "wb");
	if(f_out == NULL) {
		fprintf(stderr, "Unable to open \"%s\" for writing!\n", filename);
		exit(EXIT_FAILURE);
	}

	fprintf(f_out, "P6\n");
	fprintf(f_out, "%d %d\n", img->width, img->height);
	fprintf(f_out, "%d\n", 255);

	fwrite(img->pixels, sizeof(Pixel), img->width * img->height, f_out);

	fclose(f_out);

	fprintf(stderr, "Done writing image \"%s\"\n", filename);
}

/* Gets the indext of a pixel requested pixel */
int GetPixelIndex(int width, int height, int row, int column) {
	if (column < 0 || column >= width)
	{
		fprintf(stderr, "You asked for a pixel index for column %d, but the only valid values are between 0 and %d\n", column, width-1);
		exit(EXIT_FAILURE);
	}
	if (row < 0 || row >= height)
	{
		fprintf(stderr, "You asked for a pixel index for row %d, but the only valid values are between 0 and %d\n", row, height-1);
		exit(EXIT_FAILURE);
	}
	return row*width + column;
}

/* Places a yellow line along the diagonal of an image */
void YellowDiagonal(Image * src, Image * dest) {
	fprintf(stderr, "Executing YellowDiagonal\n");

	/* HINTS: 
	 *   You will need to assign values to every data member of the output.
	 *   For the output's Pixel array you will need to do a malloc to get
	 *   a new array.
	 *   Yellow in R/G/B is 255/255/0.
	 */

	int x = src->width;
	int y = src->height;

	dest->width = x;
	dest->height = y;
	dest->pixels = (Pixel *)malloc(x * y * sizeof(Pixel));
	memcpy(dest->pixels, src->pixels, x * y * sizeof(Pixel));

	for(int i = 0; i < y; i++) {
		int index = GetPixelIndex(x, y, i, i);
		dest->pixels[index].r = 0xFF;
		dest->pixels[index].g = 0xFF;
		dest->pixels[index].b = 0x00;
	}

	fprintf(stderr, "Done executing YellowDiagonal\n");
}

/* Combine Two images, image one on the left, image two on the right */
void LeftRightCombine(Image * left, Image * right, Image * dest) {
	fprintf(stderr, "Executing LeftRightCombine\n");

	int x = left->width + right->width;
	int y = left->height;
	dest->width = x;
	dest->height = y;

	dest->pixels = (Pixel *) malloc(x * y * sizeof(Pixel));

	for(int i = 0; i < y; i++) {
		for(int j = 0; j < x; j++) {
			int index = GetPixelIndex(x, y, i, j);
			if(j < left->width) {
				int srcIndex = GetPixelIndex(left->width, left->height, i, j);
				dest->pixels[index] = left->pixels[srcIndex];
			} else {
				int srcIndex = GetPixelIndex(right->width, right->height, i, j - left->width);
				dest->pixels[index] = right->pixels[srcIndex];
			}
		}
	}

	fprintf(stderr, "Done executing LeftRightCombine\n");
}
