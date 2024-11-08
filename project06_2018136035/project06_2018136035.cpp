#include "DongRobot.h"

static DongRobot dongrobot;
static bool bRobotRun = false;
static bool bRobotSit = false;
static bool bRobotSit2 = false;
static bool bRobotSit3 = false;
static double tSpeed = 60;
static int lastToggleTime = 0;
static int currentTime = 0;
static int cnt = 0;
static bool a = false, b = false;
double near0 = 8.0;

void initRendering() {
    // 조명 처리
    GLfloat light_specular[] = { 0.8, 0.5, 0.8, 1.0 };
    GLfloat light_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
    GLfloat light_ambient[] = { 0.5, 0.5, 0.5, 1.0 };
    GLfloat light_position[] = { 0.f, -2.5f, 2.5f, 0.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);

    // Mesh의 재질
    GLfloat mat_specular[] = { 0.5, 1.0, 0.5, 1.0 };
    GLfloat mat_shininess[] = { 70.0 };
    GLfloat mat_color[] = { 0.5, 0.5, 0.5, 1.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
}

void display() {
    /*glClearColor(0.8, 0.9, 0.8, 1.0);
    glClear(
    GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    dongrobot.draw();
    glPopMatrix();

    glutSwapBuffers();
    glFlush();*/

    glClearColor(0.8, 0.9, 0.8, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    // 정면도 뷰포트 (왼쪽 아래)
    glViewport(0, 0, 300, 300);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -10, 10); // 정사투영 설정
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1, 1, -1);
    dongrobot.draw();
    glPopMatrix();

    // 측면도 뷰포트 (오른쪽 아래)
    glViewport(300, 0, 300, 300);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -10, 10); // 정사투영 설정
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glScalef(1, 1, -1);
    dongrobot.draw();
    glPopMatrix();

    //// 평면도 뷰포트 (왼쪽 위)
    glViewport(0, 300, 300, 300);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -10, 10); // 정사투영 설정
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glScalef(1, 1, -1);
    dongrobot.draw();
    glPopMatrix();

    //// 원근 투상 뷰포트 (오른쪽 위)
    glViewport(300, 300, 300, 300);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1, 1, -1, 1, near0, 20);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0, 0, -10);
    glRotatef(30, 1, 0, 0);
    glRotatef(45, 0, 1, 0);
    glScalef(1, 1, -1);
    dongrobot.draw();
    glPopMatrix();

    glutSwapBuffers();
    glFlush();
}

void timerCallback(int tId) {
   
    if (bRobotRun && tId == 1) {
        dongrobot.run();
        glutTimerFunc((int)(tSpeed), timerCallback, 1);
    }
    if (bRobotSit && tId == 2) {
        dongrobot.sit();
        currentTime = glutGet(GLUT_ELAPSED_TIME); // 현재 경과 시간 가져오기

        // 4초(4000ms)마다 상태 전환
        if (currentTime - lastToggleTime >= 2200) {
            cnt++;
            dongrobot.stopSit();
            lastToggleTime = currentTime; // 마지막 전환 시간을 현재 시간으로 갱신
            bRobotSit = false;
            bRobotSit2 = true;
            if (cnt % 3 == 0) {
                bRobotSit3 = true;
                bRobotSit2 = false;
                a = true;
                tSpeed = 30;
                glutTimerFunc((int)(tSpeed), timerCallback, 4);
            }
            glutTimerFunc((int)(tSpeed), timerCallback, 3);
        }
        glutTimerFunc((int)(tSpeed), timerCallback, 2);
    }
    if (bRobotSit2 && tId == 3) {
        dongrobot.sit2();
        currentTime = glutGet(GLUT_ELAPSED_TIME); // 현재 경과 시간 가져오기

        // 4초(4000ms)마다 상태 전환
        if (currentTime - lastToggleTime >= 2200) {
            cnt++;
            dongrobot.stopSit2();
            lastToggleTime = currentTime; // 마지막 전환 시간을 현재 시간으로 갱신
            bRobotSit2 = false;
            bRobotSit = true;
            if (cnt % 3 == 0) {
                bRobotSit3 = true;
                bRobotSit = false;
                b = true;
                tSpeed = 30;
                glutTimerFunc((int)(tSpeed), timerCallback, 4);
            }
            glutTimerFunc((int)(tSpeed), timerCallback, 2);
        }
        glutTimerFunc((int)(tSpeed), timerCallback, 3);
    }
    if (bRobotSit3 && tId == 4) {
        //cnt++;
        dongrobot.sit3();
        currentTime = glutGet(GLUT_ELAPSED_TIME); // 현재 경과 시간 가져오기

        // 4초(4000ms)마다 상태 전환
        if (currentTime - lastToggleTime >= 2200) {
            if (a) {
                dongrobot.stopSit3();
                lastToggleTime = currentTime; // 마지막 전환 시간을 현재 시간으로 갱신
                bRobotSit3 = false;
                bRobotSit2 = true;
                a = false;
                tSpeed = 60;
                glutTimerFunc((int)(tSpeed), timerCallback, 3);
            }

            else if (b) {
                dongrobot.stopSit3();
                lastToggleTime = currentTime; // 마지막 전환 시간을 현재 시간으로 갱신
                bRobotSit3 = false;
                bRobotSit = true;
                b = false;
                tSpeed = 60;

                glutTimerFunc((int)(tSpeed), timerCallback, 2);
            }
        }
        glutTimerFunc((int)(tSpeed), timerCallback, 4);
    }
    glutPostRedisplay();
}

static int PrevX, PrevY;
void mouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        PrevX = x;
        PrevY = y;
    }
}

void mouseMotion(GLint x, GLint y) {
    glMatrixMode(GL_MODELVIEW);
    glRotated(x - PrevX, 0, 1, 0);
    glRotated(y - PrevY, 1, 0, 0);
    PrevX = x;
    PrevY = y;
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'i') {
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }
    else if (key == 'w') {
        glPolygonMode(GL_FRONT, GL_LINE);
        glPolygonMode(GL_BACK, GL_POINT);
    }
    else if (key == 's') {
        glPolygonMode(GL_FRONT, GL_FILL);
        glPolygonMode(GL_BACK, GL_LINE);
    }
    else if (key == 'r') {
        bRobotRun = !bRobotRun;
        if (bRobotRun)
            glutTimerFunc(40, timerCallback, 1);
        else dongrobot.stopRun();
    }
    else if (key == 't') {
        bRobotSit = !bRobotSit;
        if (bRobotSit)
            glutTimerFunc(40, timerCallback, 2);
        else dongrobot.stopSit();
    }
    else if (key == 'q') {
        exit(0);
    }
    else if (key == 'n') {
        near0 += 0.1;
    }
    else if (key == 'm') {
        near0 -= 0.1;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(600, 600);
    glutCreateWindow("dongrobotWorld");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouseClick);
    glutMotionFunc(mouseMotion);

    initRendering();
    keyboard('s', 0, 0);

    glutMainLoop();
    return 0;
}