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
#include<iomanip>
double x2;
double y2;
double z2;
double mass2;
RigidBody* rigidBody;



template < typename T, typename T2>
void solve(T &body, T2 h) {
    T k1(z2,x2,mass2), k2(z2,x2,mass2), k3(z2,x2,mass2), k4(z2,x2,mass2);
    ContextDynamic system;
    std::cout<<"___________________new frame____________________"<<"\n";
    T temp = body;
    k1 = system.setTypeOfBody(&temp);
    temp =(body + k1 * (h / 3));
    k2 = system.setTypeOfBody(&temp);
    temp = (body + ((k1 * (-h / 3)) + (k2 * h)));
    k3 = system.setTypeOfBody(&temp);
    temp = (body + ((k1 * h) + (k2 * (-h)) + (k3 * h)));
    k4 = system.setTypeOfBody(&temp);
    body = body + ((k1 * (1.0 / 8)) + (k2 * (3.0 / 8)) + (k3 * (3.0 / 8)) + (k4 * (1.0 / 8))) * h;
    body.q = body.q.normalize();
    body.R = body.q.toMatrix();

    Vector omega = (body.R * body.INERTIA_TENSOR * body.R.transpose()) * body.L;
    double E =  omega * body.L * 0.5;
    std::cout<<"E = "<<std::setprecision(16)<<E<<"\nOmega after runge kytti = "<<(omega.x + omega.y + omega.z)<<"\n\n";

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



    solve<RigidBody,double>(*rigidBody, 0.0001);
    glPushMatrix();
   // glTranslated(rigidBody->r.x, rigidBody->r.y, rigidBody->r.z - 100);

    glRotated(2*acos(rigidBody->q.r) * 180 / M_PI, rigidBody->q.i, rigidBody->q.j, rigidBody->q.k);
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
    //glTranslated(0, 0, 0);
    //glRotated(100,0,0,0);
    gluLookAt(0, 30, -60, 0, 0, 0, 0, 0, 1);


}

void Start(int argc, char * argv [],double height,double length,double mass) {
    z2 = height;
    x2 = length/2;
    y2 = length/2;
    mass2 = mass;
    rigidBody = new RigidBody(height,length,mass2);

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
