//
// Created by nereus on 18.12.2020.
//

#ifndef VMTRIANGLE_TRIANGLE_H
#define VMTRIANGLE_TRIANGLE_H
#include "GL/glut.h"
#include "Rb/RigitBody.h"

RigidBody rigidBody = RigidBody();

void solve(RigidBody &body, double h) {
    RigidBody k1, k2, k3, k4;

    k1 = body.f();
    k2 = (body + k1 * (h / 3)).f();
    k3 = (body + ((k1 * (-h / 3)) + (k2 * h))).f();
    k4 = (body + ((k1 * h) + (k2 * (-h)) + (k3 * h))).f();
    body = body + ((k1 * (1.0 / 8)) + (k2 * (3.0 / 8)) + (k3 * (3.0 / 8)) + (k4 * (1.0 / 8))) * h;

    body.q = body.q.normalize();
    body.R = body.q.toMatrix();
}

void Idle() {
    glutPostRedisplay();
}
void drawTriangle() {
    double length = 1.5;
    double width = 1.5;
    double height = 1.5;

    glBegin(GL_TRIANGLES);
    glColor3f(0.52, 0.44, 1.0);// фиолетовой
    glVertex3f(0, (length / 2.0), -height/4.0);
    glVertex3f(-(length / 2.0), -(width / 2.0), -height/4.0);
    glVertex3f(0, 0, height*3.0/4.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.84, 0.0);  // желтой
    glVertex3f((length / 2.0), -(width / 2.0), -height/4.0);
    glVertex3f(0, (length / 2.0), -height/4.0);
    glVertex3f(0, 0, height*3.0/4.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.94, 0.5, 0.5);// розовой
    glVertex3f(-(length / 2.0), -(width / 2.0), -height/4.0);
    glVertex3f((length / 2.0), -(width / 2.0), -height/4.0);
    glVertex3f(0.0, 0.0, height*3.0/4.0);
    glEnd();

    glBegin(GL_TRIANGLES);// основание пирамиды
    glColor3f(1.0, 0.51, 0.28); // рыжим
    glVertex3f(0, (width / 2.0), -height/4.0);
    glVertex3f(-(length / 2.0), -(width / 2.0), -height/4.0);
    glVertex3f((length / 2.0), -(width / 2.0), -height/4.0);
    glEnd();
}

void Display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    solve(rigidBody, 0.000005);
    glPushMatrix();
    glRotated(2*acos(rigidBody.q.r) * 180 / M_PI, rigidBody.q.i, rigidBody.q.j, rigidBody.q.k);
    glTranslated(0, 0, 0);
    glPolygonMode(GL_FRONT, GL_FILL);
    drawTriangle();
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

void Start(int argc, char * argv []) {
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
