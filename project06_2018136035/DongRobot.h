#pragma once
#include "Mesh.h"

class DongRobot {
public:
    Mesh Head, Body, RightArm, RightHand, LeftArm, LeftHand;
    Mesh RightLeg, RightFoot, LeftLeg, LeftFoot;
    float scale;   // ∏µ®¿« Ω∫ƒ…¿œ
    int lastToggleTime = 0;

    DongRobot() {
        scale = 100;   // ¡¬«•∞™¿Ã -100~100 π¸¿ß

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
        if (bRun)
        animateRunBody();
        if (bSit)
        animateSitBody();
        if (bSit2)
        animateSit2Body();
        if (bSit3)
        animateSit3Body();
        Body.draw(0.30, 0.30, 0.30, scale, true);

        glPushMatrix();
        glTranslated(0.0, 0.25, -0.0);
        glScalef(1.0f, 1.0f, 1.0f);
        if (bRun)
        animateRunHead();
        if (bSit)
        animateSitHead();
        if (bSit2)
        animateSit2Head();
        if (bSit3)
        animateSit3Head();
        Head.draw(0.7, 0.37, 0.1, scale);
        glPopMatrix();

        glPushMatrix();
        glTranslated(-0.18, 0.06, 0.05);
        glScalef(1.0f, 1.0f, 1.0f);
        if (bRun)
        animateRunRightArm();
        if (bSit)
        animateSitRightArm();
        if (bSit2)
        animateSit2RightArm();
        if (bSit3)
        animateSit3RightArm();
        RightArm.draw(0.7, 0.37, 0.1, scale);
        glPushMatrix();
        glTranslated(-0.015, -0.24, -0.05);
        glScalef(1.0f, 1.0f, 1.0f);
        if (bRun)
        animateRunRightHand();
        if (bSit)
        animateSitRightHand();
        if (bSit2)
        animateSit2RightHand();
        if (bSit3)
        animateSit3RightHand();
        RightHand.draw(0.7, 0.37, 0.1, scale);
        glPopMatrix();
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.18, 0.06, 0.05);
        glScalef(1.0f, 1.0f, 1.0f);
        if (bRun)
        animateRunLeftArm();
        if (bSit)
        animateSitLeftArm();
        if (bSit2)
        animateSit2LeftArm();
        if (bSit3)
        animateSit3LeftArm();
        LeftArm.draw(0.7, 0.37, 0.1, scale);
        glPushMatrix();
        glTranslated(0.015, -0.24, -0.05);
        glScalef(1.0f, 1.0f, 1.0f);
        if (bRun)
        animateRunLeftHand();
        if (bSit)
        animateSitLeftHand();
        if (bSit2)
        animateSit2LeftHand();
        if (bSit3)
        animateSit3LeftHand();
        LeftHand.draw(0.7, 0.37, 0.1, scale);
        glPopMatrix();
        glPopMatrix();

        glPushMatrix();
        glTranslated(-0.08, -0.32, -0.02);
        glScalef(1.0f, 1.0f, 1.0f);
        if (bRun)
        animateRunRightLeg();
        if (bSit)
        animateSitRightLeg();
        if (bSit2)
        animateSit2RightLeg();
        if (bSit3)
        animateSit3RightLeg();
        RightLeg.draw(0.7, 0.37, 0.1, scale);
        glPushMatrix();
        glTranslated(-0.02, -0.27, -0.05);
        glScalef(1.0f, 1.0f, 1.0f);
        if (bRun)
        animateRunRightFoot();
        if (bSit)
        animateSitRightFoot();
        if (bSit2)
        animateSit2RightFoot();
        if (bSit3)
        animateSit3RightFoot();
        RightFoot.draw(0.7, 0.37, 0.1, scale);
        glPopMatrix();
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.08, -0.32, -0.02);
        glScalef(1.0f, 1.0f, 1.0f);
        if (bRun)
        animateRunLeftLeg();
        if (bSit)
        animateSitLeftLeg();
        if (bSit2)
        animateSit2LeftLeg();
        if (bSit3)
        animateSit3LeftLeg();
        LeftLeg.draw(0.7, 0.37, 0.1, scale);
        glPushMatrix();
        glTranslated(0.02, -0.27, -0.05);
        glScalef(1.0f, 1.0f, 1.0f);
        if (bRun)
        animateRunLeftFoot();
        if (bSit)
        animateSitLeftFoot();
        if (bSit2)
        animateSit2LeftFoot();
        if (bSit3)
        animateSit3LeftFoot();
        LeftFoot.draw(0.7, 0.37, 0.1, scale);
        glPopMatrix();
        glPopMatrix();
    }
    //---------------------------------------------------------
    // æ÷¥œ∏ﬁ¿Ãº«¿ª ¿ß«— ƒ⁄µÂ
    double tAngle, sin_t = 0, sin_t2 = 0, cos_t = 0;
    bool bRun = false, bSit = false , bSit2 = false, bSit3 = false;
    void reset() {
        bRun = false;
        bSit = false;
        bSit2 = false;
        bSit3 = false;
        scale = 100;
        tAngle = 0;
    }
    void stopRun() { bRun = false; }
    void stopSit() { bSit = false; }
    void stopSit2() { bSit2 = false; }
    void stopSit3() { bSit3 = false; }
    void run() {
        bRun = true;
        tAngle += 20;
        if (tAngle >= 360)
            tAngle -= 360;
        sin_t = SIN(tAngle);
        cos_t = COS(tAngle);
        sin_t2 = SIN(2 * tAngle);
    }
    void sit() {
        bSit = true;
        tAngle += 20;
        if (tAngle >= 360)
            tAngle -= 360;
        sin_t = SIN(tAngle);
        cos_t = COS(tAngle);
        sin_t2 = SIN(2 * tAngle);
    }
    void sit2() {
        bSit2 = true;
        tAngle += 20;
        if (tAngle >= 360)
            tAngle -= 360;
        sin_t = SIN(tAngle);
        cos_t = COS(tAngle);
        sin_t2 = SIN(2 * tAngle);
    }
    void sit3() {
        bSit3 = true;
        tAngle += 20;
        if (tAngle >= 360)
            tAngle -= 360;
        sin_t = SIN(tAngle);
        cos_t = COS(tAngle);
        sin_t2 = SIN(2 * tAngle);
    }
    
    // ∞¢ ∫Œ«∞ø° ¥Î«— æ÷¥œ∏ﬁ¿Ãº« ∫Ø»Ø(∏µ® ∫Ø»Ø)
    void animateRunBody() {
        glTranslated(0.0, (sin_t2 * 0.08), 0);
        glRotatef(-sin_t2 * 15 - 10, 1, 0, 0);
        glRotatef(-sin_t * 13, 0, 1, 0);
    }
    void animateRunHead() {
        glRotatef(-cos_t * 20, 0, 1, 0);
    }
    void animateRunRightArm() {
        glRotatef(-cos_t * 65, 1, 0, 0);
    }
    void animateRunRightHand() {
        glRotatef(-cos_t * 45, 1, 0, 0);
    }
    void animateRunLeftArm() {
        glRotatef(cos_t * 65, 1, 0, 0);
    }
    void animateRunLeftHand() {
        glRotatef(cos_t * 45, 1, 0, 0);
    }
    void animateRunRightLeg() {
        glRotatef(cos_t * 45, 1, 0, 0);
    }
    void animateRunRightFoot() {
        glRotatef(sin_t * 50, 1, 0, 0);
    }
    void animateRunLeftLeg() {
        glRotatef(-cos_t * 45, 1, 0, 0);
    }
    void animateRunLeftFoot() {
        glRotatef(-sin_t * 50, 1, 0, 0);
    }

    //----------------------------------------------------------------------------------
    // ªﬂ≥¢ªﬂ≥¢ ø°¥œ∏ﬁ¿Ãº«
    void animateSitBody() {
        glTranslated(0.0, (sin_t2 * 0.03), 0);
        //glRotatef(-sin_t2 * 15 - 10, 1, 0, 0);
        glRotatef(90, 0, 1, 0);
    }
    void animateSitHead() {
        glRotatef(-70, 0, 1, 0);
        glRotatef(-cos_t * 20, 0, 1, 0);
    }
    void animateSitRightArm() {
        //glRotatef(-cos_t * 65, 1, 0, 0);
    }
    void animateSitRightHand() {
        glRotatef(-cos_t * 45, 1, 0, 0);
    }
    void animateSitLeftArm() {
        glRotatef(40, 1, 0, 0);
        glRotatef(cos_t * 65, 1, 0, 0);
    }
    void animateSitLeftHand() {
        //glRotatef(cos_t * 45, 1, 0, 0);
        glRotatef(70, 1, 0, 0);
        glRotatef(cos_t * 40, 1, 0, 0);
    }
    void animateSitRightLeg() {
        //glRotatef(cos_t * 45, 1, 0, 0);
        glRotatef(10, 1, 0, 0);
    }
    void animateSitRightFoot() {
        //glRotatef(sin_t * 50, 1, 0, 0);
        glRotatef(-20, 1, 0, 0);
    }
    void animateSitLeftLeg() {
        //glRotatef(-cos_t * 45, 1, 0, 0);
        glRotatef(10, 1, 0, 0);
    }
    void animateSitLeftFoot() {
        //glRotatef(-sin_t * 50, 1, 0, 0);
        glRotatef(-20, 1, 0, 0);
    }

    //------------------------------------------------------------------------------------
    // ªﬂ≥¢ªﬂ≥¢ ø°¥œ∏ﬁ¿Ãº« π›¥Î∆Ì
    void animateSit2Body() {
        glTranslated(0.0, (sin_t2 * 0.03), 0);
        glRotatef(-90, 0, 1, 0);
    }
    void animateSit2Head() {
        glRotatef(70, 0, 1, 0);
        glRotatef(-cos_t * 20, 0, 1, 0);
    }
    void animateSit2RightArm() {
        glRotatef(40, 1, 0, 0);
        glRotatef(cos_t * 65, 1, 0, 0);
    }
    void animateSit2RightHand() {
        glRotatef(70, 1, 0, 0);
        glRotatef(cos_t * 40, 1, 0, 0);
    }
    void animateSit2LeftArm() {
    }
    void animateSit2LeftHand() {
        glRotatef(-cos_t * 45, 1, 0, 0);
    }
    void animateSit2RightLeg() {
        glRotatef(10, 1, 0, 0);
    }
    void animateSit2RightFoot() {
        glRotatef(-20, 1, 0, 0);
    }
    void animateSit2LeftLeg() {
        glRotatef(10, 1, 0, 0);
    }
    void animateSit2LeftFoot() {
        glRotatef(-20, 1, 0, 0);
    }

    //------------------------------------------------------------------------------------
    // ªﬂ≥¢ªﬂ≥¢ ø°¥œ∏ﬁ¿Ãº« ∞°øÓµ•
    void animateSit3Body() {
        //glTranslated(0.0, (sin_t2 * 0.03), 0);
        //glRotatef(-90, 0, 1, 0);
    }
    void animateSit3Head() {
        //glRotatef(70, 0, 1, 0);
        glRotatef(-cos_t * 20, 0, 1, 0);
    }
    void animateSit3RightArm() {
        //glRotatef(20, 1, 0, 0);
        glRotatef(cos_t * 75, 0, 1, 0);
    }
    void animateSit3RightHand() {
        glRotatef(90, 1, 0, 0);
        //glRotatef(cos_t * 45, 0, 1, 0);
    }
    void animateSit3LeftArm() {
        glRotatef(-(cos_t * 75), 0, 1, 0);
    }
    void animateSit3LeftHand() {
        glRotatef(90, 1, 0, 0);
        //glRotatef(cos_t * 45, 0, 1, 0);
    }
    void animateSit3RightLeg() {
        //glRotatef(10, 1, 0, 0);
    }
    void animateSit3RightFoot() {
        //glRotatef(-20, 1, 0, 0);
    }
    void animateSit3LeftLeg() {
        //glRotatef(10, 1, 0, 0);
    }
    void animateSit3LeftFoot() {
        //glRotatef(-20, 1, 0, 0);
    }
};