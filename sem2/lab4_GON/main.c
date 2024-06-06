#include <stdio.h>
#include <math.h>

#include "labengine.h"

#define PI 3.1415


struct Polygon {
    int x_center;
    int y_center;
    double angle;
    int rad;
    int n_angles;
};


void DrawPolygon(struct Polygon* poly) {
    int current_x = poly->x_center + poly->rad * cos(poly->angle);
    int current_y = poly->y_center + poly->rad * sin(poly->angle);
    double angle_diff = 2 * PI / poly->n_angles;
    double angle = poly->angle;

    for (int i = 0; i < poly->n_angles; i++) {
        angle += angle_diff;
        int next_x = poly->x_center + poly->rad * cos(angle);
        int next_y = poly->y_center + poly->rad * sin(angle);

        LabSetColor(LABCOLOR_GREEN);
        LabDrawLine(current_x, current_y, next_x, next_y);
        
        current_x = next_x;
        current_y = next_y;
    }
}


int main(void)
{
    if (LabInit())
    {   
        int width = LabGetWidth();
        int height = LabGetHeight();
        int rad = height / 2;

        int x_center = width / 2;
        int y_center = height / 2;

        double radian = 0.;
        while (LabInputKeyReady() != LAB_TRUE){
            radian += 0.1;

            struct Polygon p;
            p.angle = radian;
            p.n_angles = 6;
            p.rad = rad;
            p.x_center = x_center;
            p.y_center = y_center;

            DrawPolygon(&p);
            LabDrawFlush();

            LabDelay(10);
            LabClear();
        }

        LabTerm();
    }
    return 0;
}
