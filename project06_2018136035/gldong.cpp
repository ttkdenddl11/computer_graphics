#include "gldong.h"

// GLUT를 이용한 문자열 출력
#include <string.h>
void gldongString(const char* s) {
    unsigned int i;
    for (i = 0; i < strlen(s); i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s[i]);
}
// 재질의 색상 설정
void gldongSetColor(float r, float g, float b, float a) {
    float color[4] = { r, g, b, a };
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, color);
}
// 좌표계 그리기, 원점에서 +X(red), +y(blue), +z(gray)로 길이 len인 선분.
void gldongDrawCoord(double len)
{
    glDisable(GL_LIGHTING);   // 조명 사용 설정
    glColor3f(1.0f, 0, 0);
    gldongLine(0, 0, 0, len, 0, 0); // RED ==> +x axis
    glRasterPos3f(len, 0, 0);
    gldongString("x");

    glColor3f(0, 1.0f, 0);
    gldongLine(0, 0, 0, 0, len, 0); // GREEN ==> +y axis
    glRasterPos3f(0, len, 0);
    gldongString("y");

    glColor3f(0, 0, 1.0f);
    gldongLine(0, 0, 0, 0, 0, -len); // BLUE ==> +z axis
    glRasterPos3f(0, 0, -len);
    gldongString("z");
    glEnable(GL_LIGHTING); // 조명 사용 설정
}
