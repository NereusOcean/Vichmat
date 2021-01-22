//
// Created by nereus on 18.12.2020.
//

#ifndef VMTRIANGLE_TRIANGLE_H
#define VMTRIANGLE_TRIANGLE_H
#include "GL/glut.h"
#include "Rb/RigidBody.h"
#include "ContextDynamic.h"
#include "DynamicSystem.h"
#include <iostream>
double x2;
double y2;
double z2;
double mass2;
RigidBody* rigidBody;


void updateAfterSolve(RigidBody &body){
    body.q = body.q.normalize();
    body.R = body.q.toMatrix();
}
template < typename T, typename T2>
void solve(T &body, T2 h) {
    T k1(z2,x2,mass2), k2(z2,x2,mass2), k3(z2,x2,mass2), k4(z2,x2,mass2);
    ContextDynamic system;
    k1 = system.setTypeOfBody(&body);
    body =(body + k1 * (h / 3));
    k2 = system.setTypeOfBody(&body);
    body = (body + ((k1 * (-h / 3)) + (k2 * h)));
    k3 = system.setTypeOfBody(&body);
    body = (body + ((k1 * h) + (k2 * (-h)) + (k3 * h)));
    k4 = system.setTypeOfBody(&body);
    body = body + ((k1 * (1.0 / 8)) + (k2 * (3.0 / 8)) + (k3 * (3.0 / 8)) + (k4 * (1.0 / 8))) * h;
    updateAfterSolve(body);
}


void Idle() {
    glutPostRedisplay();
}

void drawTriangle() {


    glBegin(GL_TRIANGLES);
    glColor3f(0.52, 0.44, 1.0);// фиолетовой
    glVertex3f(0, y2, -(z2/4));
    glVertex3f(-x2, -y2, -(z2/4));
    glVertex3f(0, 0, z2-(z2/4));
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.84, 0.0);  // желтой
    glVertex3f(x2, -y2, -z2/4);
    glVertex3f(0, y2, -z2/4);
    glVertex3f(0, 0, z2-(z2/4));
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.94, 0.5, 0.5);// розовой
    glVertex3f(-x2 , -y2 , -(z2/4));
    glVertex3f(x2, -y2 , -(z2/4));
    glVertex3f(0, 0, z2-(z2/4));
    glEnd();

    glBegin(GL_TRIANGLES);// основание пирамиды
    glColor3f(1.0, 0.51, 0.28); // рыжим
    glVertex3f(0, y2, -(z2/4));
    glVertex3f(-x2, -y2, -(z2/4));
    glVertex3f(x2, -y2, -(z2/4));
    glEnd();
}
void displayXYZ()
{


    glBegin(GL_LINES);

    glColor3f (1.0, 1.0, 0.0);//x yellow
    glVertex3f(-5.0, 0.0, 0.0);
    glVertex3f(5.0, 0.0, 0.0);

    glBegin(GL_LINES);
    glColor3f (1.0, 1.0, 1.0);//y white
    glVertex3f(0.0, -5.0, 0.0);
    glVertex3f(0.0, 5.0, 0.0);

    glBegin(GL_LINES);
    glColor3f (0, 1, 0);//z green
    glVertex3f(0.0, 0.0, -5.0);
    glVertex3f(0.0, 0.0, 5.0);
    glEnd();

}

void Display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    solve<RigidBody,double>(*rigidBody, 0.000001);
    glPushMatrix();
   // glTranslated(rigidBody->r.x, rigidBody->r.y, rigidBody->r.z - 100);

    glRotated(acos(rigidBody->q.r) * 360 / M_PI, rigidBody->q.i, rigidBody->q.j, rigidBody->q.k);
    glTranslated(0, 0, 0);
    glPolygonMode(GL_FRONT, GL_FILL);
    drawTriangle();
    displayXYZ();
    glPopMatrix();
    glFlush();
    glutSwapBuffers();
}

void Reshape(int W, int H) {
    glViewport(0, 0, W, H);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(15.0, ((float)W)/((float)H), 10.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 30, 0, 0, 0, 0, 0, 0, 1);
}

void Start(int argc, char * argv [],double z,double x,double y,double mass) {
    z2 = z;
    x2 = x;
    y2 = y;
    mass2 = mass;
    rigidBody = new RigidBody(z2,x2,mass2);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Stop it");
   glutReshapeFunc(Reshape);
    glutDisplayFunc(Display);
    glutIdleFunc(Idle);
    glClearColor(0, 0, 0, 0);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    glutMainLoop();

    return;
}
#endif //VMTRIANGLE_TRIANGLE_H
