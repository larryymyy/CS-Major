
/* NEW FUNCTIONS */

double GetArea(Shape *s);
void GetBoundingBox(Shape *s, double *bbox);

/* NEW MAIN */

int main()
{
    Shape *shapes[9];
    int    i;
    shapes[0] = CreateCircle(1, 0, 0);
    shapes[1] = CreateCircle(1.5, 6, 8);
    shapes[2] = CreateCircle(0.5, -3, 4);

    shapes[3] = CreateRectangle(0, 1, 0, 1);
    shapes[4] = CreateRectangle(1, 1.1, 10, 20);
    shapes[5] = CreateRectangle(1.5, 3.5, 10, 12);

    shapes[6] = CreateTriangle(0, 1, 0, 1);
    shapes[7] = CreateTriangle(0, 1, 0, 0.1);
    shapes[8] = CreateTriangle(0, 10, 0, 50);

    for (i = 0 ; i < 9 ; i++)
    {
        double bbox[4];
        printf("Shape %d\n", i);
        printf("\tArea: %f\n", GetArea(shapes[i]));
        GetBoundingBox(shapes[i], bbox);
        printf("\tBbox: %f-%f, %f-%f\n", bbox[0], bbox[1], bbox[2], bbox[3]);
    }
}
