#pragma once
#include <stdio.h>
#include <memory.h>
#include <gl/glut.h>

#define _USE_MATH_DEFINES
#include <math.h>
#define SIN(x) sin(x*M_PI / 180.)
#define COS(x) cos(x*M_PI / 180.)

inline void gldongMatSet(double* m,
    double m00, double m01, double m02, double m03,
    double m10, double m11, double m12, double m13,
    double m20, double m21, double m22, double m23,
    double m30, double m31, double m32, double m33)
{
    double mat[16] = { m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33 };
    memcpy(m, mat, sizeof(double) * 16);
}

inline void gldongMatMult(double* m1, double* m2) {
    double n[16];
    for (int k = 0; k < 16; k++) {
        n[k] = 0;
        double* p = m1 + (k / 4) * 4;
        double* q = m2 + (k % 4);
        for (int i = 0; i < 4; i++)
            n[k] += p[i] * q[i * 4];
    }
    memcpy(m1, n, sizeof(double) * 16);
}

inline void gldongMatPrint(double* m) {
    for (int i = 0; i < 4; i++) {
        printf("\t[");
        for (int j = 0; j < 4; j++)
            printf("%6.2f", m[i * 4 + j]);
        printf("]\n");
    }
    printf("\n");
}

inline void gldongMatIdentity(double* m) {
    gldongMatSet(m, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
}
inline void gldongMatTrans(double* m, double tx, double ty, double tz) {
    gldongMatSet(m, 1, 0, 0, tx, 0, 1, 0, ty, 0, 0, 1, tz, 0, 0, 0, 1);
}
inline void gldongMatScale(double* m, double sx, double sy, double sz) {
    gldongMatSet(m, sx, 0, 0, 0, 0, sy, 0, 0, 0, 0, sz, 0, 0, 0, 0, 1);
}
inline void gldongMatRotateZ(double* m, double a) {
    gldongMatSet(m, COS(a), -SIN(a), 0, 0, SIN(a), COS(a), 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
}
inline void gldongMatRotateX(double* m, double a) {
    gldongMatSet(m, 1, 0, 0, 0, 0, COS(a), -SIN(a), 0, 0, SIN(a), COS(a), 0, 0, 0, 0, 1);
}
inline void gldongMatRotateY(double* m, double a) {
    gldongMatSet(m, COS(a), 0, SIN(a), 0, 0, 1, 0, 0, -SIN(a), 0, COS(a), 0, 0, 0, 0, 1);
}
inline void gldongMatShearX(double* m, double dy, double dz) {
    gldongMatSet(m, 1, dy, dz, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
}
inline void gldongMatShearY(double* m, double dx, double dz) {
    gldongMatSet(m, 1, 0, 0, 0, dx, 1, dz, 0, 0, 0, 1, 0, 0, 0, 0, 1);
}
inline void gldongMatShearZ(double* m, double dx, double dy) {
    gldongMatSet(m, 1, 0, 0, 0, 0, 1, 0, 0, dx, dy, 1, 0, 0, 0, 0, 1);
}

// 정점의 변환함수 [q] = [M] [p]
inline void gldongTransform(double* m, double* p, double* q) {
    q[0] = q[1] = q[2] = q[3] = 0;
    for (int i = 0; i < 4; i++) {
        q[0] += m[i] * p[i];
        q[1] += m[i + 4] * p[i];
        q[2] += m[i + 8] * p[i];
        q[3] += m[i + 12] * p[i];
    }
}
// 간단한 그리기 함수들(선분, 삼각형, 좌표축)
inline void gldongLine(double x1, double y1, double z1, double x2, double y2, double z2) {
    glBegin(GL_LINES);
    glVertex3d(x1, y1, z1);
    glVertex3d(x2, y2, z2);
    glEnd();
}
inline void gldongTriangle4d(double* p) {
    glBegin(GL_TRIANGLES);
    glVertex4dv(p);
    glVertex4dv(p + 4);
    glVertex4dv(p + 8);
    glEnd();
}
inline void gldongCoord() {
    glBegin(GL_LINES);
    glColor3d(1, 0, 0); glVertex3d(-0.1, 0, 0); glVertex3d(1, 0, 0);
    glColor3d(0, 1, 0); glVertex3d(0, -0.1, 0); glVertex3d(0, 1, 0);
    glColor3d(0, 0, 1); glVertex3d(0, 0, -0.1); glVertex3d(0, 0, 1);
    glEnd();
}

extern void gldongString(const char* s);
extern void gldongSetColor(float r, float g, float b, float a);
extern void gldongDrawCoord(double len);

#define FILTER_ASE   "ASE 3D data (*.ase)\0*.ase\0ALL (*.*)\0*.*\0"
#define FILTER_BVH   "BVH Motion Data (*.bvh)\0*.bvh\0ALL (*.*)\0*.*\0"
