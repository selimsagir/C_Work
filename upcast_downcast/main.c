#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point p;
    int z;
} Point3D;

typedef struct {
    Point3D p3d;
    int w;
} Point4D;

int main() {
    // Upcasting
    Point p = {1, 2};
    Point3D p3d = {p, 3};
    Point* pp = &p3d.p;

    printf("Upcasted point: (%d, %d)\n", pp->x, pp->y);

    // Downcasting
    Point* pp2 = &p;
    Point3D* p3d2 = (Point3D*) pp2;

    printf("Downcasted point: (%d, %d, %d)\n", p3d2->p.x, p3d2->p.y, p3d2->z);

    // Inheritance
    Point4D p4d = {{{1, 2}, 3}, 4};
    printf("Point4D: (%d, %d, %d, %d)\n", p4d.p3d.p.x, p4d.p3d.p.y, p4d.p3d.z, p4d.w);

    // Upcasting
    Point3D* p3d3 = &p4d.p3d;
    Point* pp3 = &p3d3->p;

    printf("Upcasted point3D: (%d, %d)\n", pp3->x, pp3->y);

    // Downcasting
    Point4D* p4d2 = (Point4D*) p3d3;
    printf("Downcasted point4D: (%d, %d, %d, %d)\n", p4d2->p3d.p.x, p4d2->p3d.p.y, p4d2->p3d.z, p4d2->w);

    return 0;
}
