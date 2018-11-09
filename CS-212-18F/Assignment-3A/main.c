#include <stdio.h>
#include <stdlib.h>

typedef struct {
	double minX, maxX, minY, maxY;
} Rectangle;

typedef struct {
	double pt1X, pt2X, minY, maxY;
} Triangle;

typedef struct {
	double radius, originX, originY;
} Circle;

typedef struct Shape Shape;
struct Shape {
	void * self;
	double (* area)(Shape *);
	void (* bbox)(Shape *, double *);
};

Shape * CreateRectangle(double minX, double maxX, double minY, double maxY) {
	Shape * shape;
	return shape;
}

void CreateTriangle(Triangle * t, double pt1X, double pt2X, double minY, double maxY) {
	t->pt1X = pt1X;
	t->pt2X = pt2X;
	t->minY = minY;
	t->maxY = maxY;
}

void CreateCircle(Circle * c, double radius, double originX, double originY) {
	c->radius = radius;
	c->originX = originX;
	c->originY = originY;
}

double GetRectangleArea(Rectangle * r) {
	return (r->maxX - r->minX) * (r->maxY - r->minY);
}

int main() {
	Shape * rect = CreateRectangle(0, 2, 0, 2);
	return 0;
}
