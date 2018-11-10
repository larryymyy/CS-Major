#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159

/* ==== START STRUCTS ==== */
typedef struct {
	double minX, maxX, minY, maxY;
} Rectangle;

typedef struct {
	double radius, originX, originY;
} Circle;

typedef struct {
	double pt1X, pt2X, minY, maxY;
} Triangle;

typedef struct Shape Shape;
struct Shape {
	void * self;
	double (* area)(void *);
	void (* bbox)(void *, double *);
};
/* ====  END STRUCTS  ==== */



/* ==== START PROTOTYPES ==== */
Shape * CreateRectangle(double minX, double maxX, double minY, double maxY);
Shape * CreateCircle(double radius, double originX, double originY);
Shape * CreateTriangle(double pt1X, double pt2X, double minY, double maxY);

double GetRectangleArea(void * r);
double GetCircleArea(void * c);
double GetTriangleArea(void * t);
double GetArea(Shape * s);

void GetRectangleBoundingBox(void * r, double * bbox);
void GetCircleBoundingBox(void * c, double * bbox);
void GetTriangleBoundingBox(void * t, double * bbox);
void GetBoundingBox(Shape * s, double * bbox);
/* ====  END PROTOTYPES  ==== */



/* ==== START METHOD DEFINITIONS ==== */

/* --- START CREATE --- */
Shape * CreateRectangle(double minX, double maxX, double minY, double maxY) {
	Shape * s = malloc(sizeof(Shape));
	s->self = malloc(sizeof(Rectangle));
	((Rectangle *)s->self)->minX = minX;
	((Rectangle *)s->self)->maxX = maxX;
	((Rectangle *)s->self)->minY = minY;
	((Rectangle *)s->self)->maxY = maxY;
	s->area = &GetRectangleArea;
	s->bbox = &GetRectangleBoundingBox;
	return s;
}

Shape * CreateCircle(double radius, double originX, double originY) {
	Shape * s = malloc(sizeof(Shape));
	s->self = malloc(sizeof(Circle));
	((Circle *)s->self)->radius = radius;
	((Circle *)s->self)->originX = originX;
	((Circle *)s->self)->originY = originY;
	s->area = &GetCircleArea;
	s->bbox = &GetCircleBoundingBox;
	return s;
}

Shape * CreateTriangle(double pt1X, double pt2X, double minY, double maxY) {
	Shape * s = malloc(sizeof(Shape));
	s->self = malloc(sizeof(Triangle));
	((Triangle *)s->self)->pt1X = pt1X;
	((Triangle *)s->self)->pt2X = pt2X;
	((Triangle *)s->self)->minY = minY;
	((Triangle *)s->self)->maxY = maxY;
	s->area = &GetTriangleArea;
	s->bbox = &GetTriangleBoundingBox;
	return s;
}
/* ---  END CREATE  --- */



/* --- START AREA --- */
double GetRectangleArea(void * r) {
	double minX = ((Rectangle *)r)->minX;
	double maxX = ((Rectangle *)r)->maxX;
	double minY = ((Rectangle *)r)->minY;
	double maxY = ((Rectangle *)r)->maxY;
	return (maxX - minX) * (maxY - minY);
}

double GetCircleArea(void * c) {
	double radius = ((Circle *)c)->radius;
	return radius * radius * PI;
}

double GetTriangleArea(void * t) {
	double pt1X = ((Triangle *)t)->pt1X;
	double pt2X = ((Triangle *)t)->pt2X;
	double minY = ((Triangle *)t)->minY;
	double maxY = ((Triangle *)t)->maxY;
	return (pt2X - pt1X) * (maxY - minY) / 2;
}

double GetArea(Shape * s) {
	return s->area(s->self);
}
/* ---  END AREA  --- */



/* --- START BOUNDING BOX --- */
void GetRectangleBoundingBox(void * r, double * bbox) {
	bbox[0] = ((Rectangle *)r)->minX;
	bbox[1] = ((Rectangle *)r)->maxX;
	bbox[2] = ((Rectangle *)r)->minY;
	bbox[3] = ((Rectangle *)r)->maxY;
}

void GetCircleBoundingBox(void * c, double * bbox) {
	bbox[0] = ((Circle *)c)->originX - ((Circle *)c)->radius;
	bbox[1] = ((Circle *)c)->originX + ((Circle *)c)->radius;
	bbox[2] = ((Circle *)c)->originY - ((Circle *)c)->radius;
	bbox[3] = ((Circle *)c)->originY + ((Circle *)c)->radius;
}

void GetTriangleBoundingBox(void * t, double * bbox) {
	bbox[0] = ((Triangle *)t)->pt1X;
	bbox[1] = ((Triangle *)t)->pt2X;
	bbox[2] = ((Triangle *)t)->minY;
	bbox[3] = ((Triangle *)t)->maxY;
}

void GetBoundingBox(Shape * s, double * bbox) {
	s->bbox(s->self, bbox);
}
/* ---  END BOUNDING BOX  --- */


/* ====  END METHOD DEFINITIONS  ==== */

int main() {
	Shape * shapes[9];
	int i;

	shapes[0] = CreateCircle(1, 0, 0);
	shapes[1] = CreateCircle(1.5, 6, 8);
	shapes[2] = CreateCircle(0.5, -3, 4);

	shapes[3] = CreateRectangle(0, 1, 0, 1);
	shapes[4] = CreateRectangle(1, 1.1, 10, 20);
	shapes[5] = CreateRectangle(1.5, 3.5, 10, 12);

	shapes[6] = CreateTriangle(0, 1, 0, 1);
	shapes[7] = CreateTriangle(0, 1, 0, 0.1);
	shapes[8] = CreateTriangle(0, 10, 0, 50);

	for(i = 0; i < 9; i++) {
		double bbox[4];
		printf("Shape %d\n", i);
		printf("\tArea: %f\n", GetArea(shapes[i]));
		GetBoundingBox(shapes[i], bbox);
		printf("\tBbox: %f-%f, %f-%f\n", bbox[0], bbox[1], bbox[2], bbox[3]);
	}

	exit(EXIT_SUCCESS);
}


























