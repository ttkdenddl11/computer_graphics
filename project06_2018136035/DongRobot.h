#pragma once
#include "Mesh.h"

class DongRobot {
public:
    Mesh Head, Body, RightArm, RightHand, LeftArm, LeftHand;
    Mesh RightLeg, RightFoot, LeftLeg, LeftFoot;
    float scale;   // 모델의 스케일

    DongRobot() {
        scale = 100;   // 좌표값이 -100~100 범위

        printf("Loading Ironman Models....\n");
        Head.readAse("Head.ASE");               printf("loading Head....... OK.\n");
        Body.readAse("Body.ASE");               printf("loading Body....... OK.\n");
        RightArm.readAse("Right_arm.ASE");         printf("loading RightArm....... OK.\n");
        RightHand.readAse("Right_hand.ASE");      printf("loading RightHand....... OK.\n");
        LeftArm.readAse("Left_arm.ASE");         printf("loading LeftArm....... OK.\n");
        LeftHand.readAse("Left_hand.ASE");         printf("loading LeftHand....... OK.\n");
        RightLeg.readAse("Right_leg.ASE");         printf("loading RightLeg....... OK.\n");
        RightFoot.readAse("Right_foot.ASE");      printf("loading RightFoot....... OK.\n");
        LeftLeg.readAse("Left_leg.ASE");         printf("loading LeftLeg....... OK.\n");
        LeftFoot.readAse("Left_foot.ASE");         printf("loading LeftFoot....... OK.\n");
    }
    void draw() {
        Body.draw(0.30, 0.30, 0.30, scale, true);

        glPushMatrix();
            glTranslated(0.0, 0.25, -0.0);
            glScalef(1.0f, 1.0f, 1.0f);
            Head.draw(0.7, 0.37, 0.1, scale);
        glPopMatrix();

        glPushMatrix();
            glTranslated(-0.18, 0.06, 0.05);
            glScalef(1.0f, 1.0f, 1.0f);
            RightArm.draw(0.7, 0.37, 0.1, scale);
            glPushMatrix();
                glTranslated(-0.015, -0.24, -0.05);
                glScalef(1.0f, 1.0f, 1.0f);
                RightHand.draw(0.7, 0.37, 0.1, scale);
            glPopMatrix();
        glPopMatrix();

        glPushMatrix();
            glTranslated(0.18, 0.06, 0.05);
            glScalef(1.0f, 1.0f, 1.0f);
            LeftArm.draw(0.7, 0.37, 0.1, scale);
            glPushMatrix();
                glTranslated(0.015, -0.24, -0.05);
                glScalef(1.0f, 1.0f, 1.0f);
                LeftHand.draw(0.7, 0.37, 0.1, scale);
            glPopMatrix();
        glPopMatrix();

        glPushMatrix();
            glTranslated(-0.08, -0.32, -0.02);
            glScalef(1.0f, 1.0f, 1.0f);
            RightLeg.draw(0.7, 0.37, 0.1, scale);
            glPushMatrix();
                glTranslated(-0.02, -0.27, -0.05);
                glScalef(1.0f, 1.0f, 1.0f);
                RightFoot.draw(0.7, 0.37, 0.1, scale);
            glPopMatrix();
        glPopMatrix();

        glPushMatrix();
            glTranslated(0.08, -0.32, -0.02);
            glScalef(1.0f, 1.0f, 1.0f);
            LeftLeg.draw(0.7, 0.37, 0.1, scale);
            glPushMatrix();
                glTranslated(0.02, -0.27, -0.05);
                glScalef(1.0f, 1.0f, 1.0f);
                LeftFoot.draw(0.7, 0.37, 0.1, scale);
            glPopMatrix();
        glPopMatrix();

    }
};