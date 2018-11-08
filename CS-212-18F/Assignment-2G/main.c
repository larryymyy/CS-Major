#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Pixel struct */
typedef struct {
	/* Color values of the pixel */
	unsigned char r;
	unsigned char g;
	unsigned char b;
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

#if 0
	/* Combine two images, placing one on the left and one on the right */
	LeftRightCombine(&source, &yellowDiag, &leftRight);
	WriteImage("2G_output.pnm", &leftRight);
#endif

	exit(EXIT_SUCCESS);
}

/* Verifies that the input files exist */
void VerifyInput() {
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
}

/* Reads an image from a file into an Image struct */
void ReadImage(char * filename, Image * img) {
	fprintf(stderr, "Reading image \"%s\"\n", filename);

	char buff[16];
	int maxval;
	FILE * f_in = fopen(filename, "r");

	fgets(buff, sizeof(buff), f_in);
	fscanf(f_in, "%d %d", &img->width, &img->height);
	fscanf(f_in, "%d", &maxval);

	img->pixels = (Pixel *)malloc(img->width * img->height * sizeof(Pixel));
	fread(img->pixels, 3 * img->width, img->height, f_in);

	fclose(f_in);
	fprintf(stderr, "Done reading image \"%s\"\n", filename);
}

/* Writes an Image struct to a file, following the PPM format */
void WriteImage(char * filename, Image * img) {
	fprintf(stderr, "Writing image \"%s\"\n", filename);

	FILE * f_out = fopen(filename, "w");

	fprintf(f_out, "P6\n");
	fprintf(f_out, "%d %d\n", img->width, img->height);
	fprintf(f_out, "%d", 255);

	fwrite(img->pixels, 3 * img->width, img->height, f_out);

	fputc('\0', f_out);

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

// Places a yellow line along the diagonal of an image
void YellowDiagonal(Image * src, Image * dest) {
	fprintf(stderr, "Executing YellowDiagonal\n");

	dest->width = src->width;
	dest->height = src->height;

	dest->pixels = (Pixel *) malloc(sizeof(Pixel) * dest->width * dest->height);

	/* HINTS: 
	 *   You will need to assign values to every data member of the output.
	 *   For the output's Pixel array you will need to do a malloc to get
	 *   a new array.
	 *   Yellow in R/G/B is 255/255/0.
	 */
	
	for(int i = 0; i < dest->height; i++) {
		for(int j = 0; j < dest->width; j++) {
			int index = GetPixelIndex(dest->width, dest->height, i, j);
			if(i == j) {
				dest->pixels[index].r = 0xFF;
				dest->pixels[index].g = 0xFF;
				dest->pixels[index].b = 0x00;
			} else {
				dest->pixels[index] = src->pixels[index];
			}
		}
	}

	fprintf(stderr, "Done executing YellowDiagonal\n");
}
