#include <stdio.h>

/* === START Shape Structs === */

/* -Rectangle- */
typedef struct {
	double minX;
	double maxX;
	double minY;
	double maxY;
} Rectangle;


/* -Triangle- */
typedef struct {
	double pt1X;
	double pt2X;
	double minY;
	double maxY;
} Triangle;


/* -Circle- */
typedef struct {
	double radius;
	double originX;
	double originY;
} Circle;

/* === END Shape Structs === */


/* === START Shape Procedures === */

/* Initialize Circle */
void InitializeCircle(Circle * c, double radius, double originX, double originY) {
	c->radius = radius;
	c->originX = originX;
	c->originY = originY;
}

/* Initialize Rectangle */
void InitializeRectangle(Rectangle * r, double minX, double maxX, double minY, double maxY) {
	r->minX = minX;
	r->maxX = maxX;
	r->minY = minY;
	r->maxY = maxY;
}

/* Initialize Triangle */
void InitializeTriangle(Triangle * t, double pt1X, double pt2X, double minY, double maxY) {
	t->pt1X = pt1X;
	t->pt2X = pt2X;
	t->minY = minY;
	t->maxY = maxY;
}

/* Get Circle Area */
double GetCircleArea(Circle * c) {
	return c->radius * c->radius * 3.14159;
}

/* Get Rectangle Area */
double GetRectangleArea(Rectangle * r) {
	return (r->maxX - r->minX) * (r->maxY - r->minY);
}

/* Get Triangle Area */
double GetTriangleArea(Triangle * t) {
	return (t->pt2X - t->pt1X) * (t->maxY - t->minY) / 2;
}

/* Get Circle Bounding Box */
void GetCircleBoundingBox(Circle * c, double * bbox) {
	bbox[0] = c->originX - c->radius;
	bbox[1] = c->originX + c->radius;
	bbox[2] = c->originY - c->radius;
	bbox[3] = c->originY + c->radius;
}

/* Get Rectangle Bounding Box */
void GetRectangleBoundingBox(Rectangle * r, double * bbox) {
	bbox[0] = r->minX;
	bbox[1] = r->maxX;
	bbox[2] = r->minY;
	bbox[3] = r->maxY;
}

/* Get Triangle Bounding Box */
void GetTriangleBoundingBox(Triangle * t, double * bbox) {
	bbox[0] = t->pt1X;
	bbox[1] = t->pt2X;
	bbox[2] = t->minY;
	bbox[3] = t->maxY;
}

/* === END Shape Procedures === */

/* === START Print Procedures === */

/* Print Circle */
void PrintCircle(Circle * c) {
	double bbox[4];
	double area = GetCircleArea(c);
	GetCircleBoundingBox(c, bbox);
    printf("Circle has area %f and bounding box [%f->%f], [%f->%f]\n",
           area, bbox[0], bbox[1], bbox[2], bbox[3]);
}

/* Print Rectangle */
void PrintRectangle(Rectangle * r) {
	double bbox[4];
	double area = GetRectangleArea(r);
	GetRectangleBoundingBox(r, bbox);
    printf("Rectangle has area %f and bounding box [%f->%f], [%f->%f]\n",
           area, bbox[0], bbox[1], bbox[2], bbox[3]);
}

/* Print Triangle */
void PrintTriangle(Triangle * t) {
	double bbox[4];
	double area = GetTriangleArea(t);
	GetTriangleBoundingBox(t, bbox);
	printf("Triangle has area %f and bounding box [%f->%f], [%f->%f]\n",
			area, bbox[0], bbox[1], bbox[2], bbox[3]);
}

/* === END Print Procedures === */

/* === START Main === */
int main() {
    Circle c;
    Triangle t;
    Rectangle r;

    InitializeCircle(&c, 1, 0, 0);
    PrintCircle(&c);
    InitializeCircle(&c, 1.5, 6, 8);
    PrintCircle(&c);
    InitializeCircle(&c, 0.5, -3, 4);
    PrintCircle(&c);

    InitializeRectangle(&r, 0, 1, 0, 1);
    PrintRectangle(&r);
    InitializeRectangle(&r, 1, 1.1, 10, 20);
    PrintRectangle(&r);
    InitializeRectangle(&r, 1.5, 3.5, 10, 12);
    PrintRectangle(&r);

    InitializeTriangle(&t, 0, 1, 0, 1);
    PrintTriangle(&t);
    InitializeTriangle(&t, 0, 1, 0, 0.1);
    PrintTriangle(&t);
    InitializeTriangle(&t, 0, 10, 0, 50);
    PrintTriangle(&t);
}
/* === END Main === */
