#include <stdio.h>
#include <stdlib.h>

typedef struct {
	unsigned char r;
	unsigned char g;
	unsigned char b;
} Pixel;

typedef struct {
	int width;
	int height;
	Pixel * pixels;
} Image;

void squeeze(FILE * src) {
	char current = fgetc(src);
	while(current == ' ' || current == '\t' || current == '\r' || current == '\n')
		current = fgetc(src);
	fseek(src, -1L, SEEK_CUR);
}

void readImage(FILE * src, Image * dest) {
	printf("Loading image into memory . . .\n");
	char current = fgetc(src);

	// Read File Format
	while(current != '\t' && current != '\n' &&
		  current != '\r' && current != ' ') {
		printf("%c", current);
		current = fgetc(src);
	}
	printf("\n");

	// Seek to next relevant information (skip whitespace);
	squeeze(src);

	// Read width into dest image
	dest->width = 0;
	current = fgetc(src);
	while(current != ' ' && current != '\t' && current != '\r' && current != '\n') {
		dest->width *= 10;
		dest->width += (current - '0');
		current = fgetc(src);
	}
	printf("Width: %d\n", dest->width);

	// Skip Whitespace
	squeeze(src);

	// Read height into dest image
	dest->height = 0;
	current = fgetc(src);
	while(current != ' ' && current != '\t' && current != '\r' && current != '\n') {
		dest->height *= 10;
		dest->height += (current - '0');
		current = fgetc(src);
	}
	printf("Height: %d\n", dest->height);

	squeeze(src);

	// Determine maximum color value
	short max_val = 0;
	current = fgetc(src);
	while(current != ' ' && current != '\t' && current != '\r' && current != '\n') {
		max_val *= 10;
		max_val += (current - '0');
		current = fgetc(src);
	}
	printf("Max Color Value: %d\n", max_val);
	squeeze(src);

	int num_pixels = dest->width * dest->height;
	Pixel * pixel = malloc(sizeof(Pixel));
	for(int i = 0; i < num_pixels; i++) {
		if(max_val < 256) {
			pixel->r = (unsigned char)fgetc(src);
			pixel->g = (unsigned char)fgetc(src);
			pixel->b = (unsigned char)fgetc(src);
			printf("r: %3d | g: %3d | b: %3d\n", pixel->r, pixel->g, pixel->b);
			squeeze(src);
		} else {
			fread(&pixel->r, 2, 1, src);
			fread(&pixel->g, 2, 1, src);
			fread(&pixel->b, 2, 1, src);
			printf("r: %5d | g: %5d | b: %5d\n", pixel->r, pixel->g, pixel->b);
		}
	}
	free(pixel);
}

int main(int argc, char * argv[]) {
	FILE * source = fopen(argv[1], "r");

	Image * image = malloc(sizeof(Image));
	readImage(source, image);
	fclose(source);

	free(image->pixels);
	free(image);
	exit(EXIT_SUCCESS);
}
