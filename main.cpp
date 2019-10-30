#include <windows.h>
#include <iostream>
#include <math.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;
bool tabrak = false;

float alpha = 4.71; //nilai default putar kamera
float pos[]={7.5,17,-0.5}; //posisi kamera
float viewdir[]={0.0,-1.0,0.0}; //mengarahkan pandangan

float ambient = true;
float diffuse = true;
float specular = true;

int posX;
int posY;

int randX = (rand()%7)*2+1;
int randY = (rand()%7)*2+1;

float putarX;
float putarY;

bool swapmap = true;
char modelMap = 'a';

char rotateNIM = 'z';
float spin[3]={0,0,0};

bool transCon = false;
float trans;

bool dayCon = true;

void material(float r, float g, float b, float a){
    GLfloat matSpecular[] = {r,g,b,a};
    GLfloat matShininess[] = { 20.0 };
    GLfloat matDiffuse[] = {r,g,b,a};

    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
    glMaterialfv(GL_FRONT, GL_SHININESS, matShininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse);
}

void nim(){
    /// ZERO
    //LEFT (DEPAN)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
	glVertex3f(0.0+randX, 1.0+randY, 0.0);
	glVertex3f(0.0+randX, 0.0+randY, 0.0);
	glVertex3f(0.1+randX, 0.0+randY, 0.0);
	glVertex3f(0.1+randX, 1.0+randY, 0.0);
    glEnd();

    //LEFT (BELAKANG)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
	glVertex3f(0.0+randX, 1.0+randY, -1.0);
	glVertex3f(0.0+randX, 0.0+randY, -1.0);
	glVertex3f(0.1+randX, 0.0+randY, -1.0);
	glVertex3f(0.1+randX, 1.0+randY, -1.0);
    glEnd();

    //LEFT (KIRI)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
	glVertex3f(0.0+randX, 1.0+randY, 0.0);
	glVertex3f(0.0+randX, 0.0+randY, 0.0);
	glVertex3f(0.0+randX, 0.0+randY, -1.0);
	glVertex3f(0.0+randX, 1.0+randY, -1.0);
    glEnd();

    //LEFT (KANAN)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
	glVertex3f(0.1+randX, 1.0+randY, 0.0);
	glVertex3f(0.1+randX, 0.0+randY, 0.0);
	glVertex3f(0.1+randX, 0.0+randY, -1.0);
	glVertex3f(0.1+randX, 1.0+randY, -1.0);
    glEnd();

    //LEFT (ATAS)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
	glVertex3f(0.0+randX, 1.0+randY, 0.0);
	glVertex3f(0.1+randX, 1.0+randY, 0.0);
	glVertex3f(0.1+randX, 1.0+randY, -1.0);
	glVertex3f(0.0+randX, 1.0+randY, -1.0);
    glEnd();

    //LEFT (BAWAH)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
	glVertex3f(0.0+randX, 0.0+randY, 0.0);
	glVertex3f(0.1+randX, 0.0+randY, 0.0);
	glVertex3f(0.1+randX, 0.0+randY, -1.0);
	glVertex3f(0.0+randX, 0.0+randY, -1.0);
    glEnd();

    ///===============================================================

    //UP (DEPAN)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
	glVertex3f(0.1+randX, 1.0+randY, 0.0);
	glVertex3f(0.1+randX, 0.9+randY, 0.0);
	glVertex3f(0.2+randX, 0.9+randY, 0.0);
	glVertex3f(0.2+randX, 1.0+randY, 0.0);
    glEnd();

    //UP (BELAKANG)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
	glVertex3f(0.1+randX, 1.0+randY, -1.0);
	glVertex3f(0.1+randX, 0.9+randY, -1.0);
	glVertex3f(0.2+randX, 0.9+randY, -1.0);
	glVertex3f(0.2+randX, 1.0+randY, -1.0);
    glEnd();

    //UP (KIRI)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
	glVertex3f(0.1+randX, 1.0+randY, 0.0);
	glVertex3f(0.1+randX, 0.9+randY, 0.0);
	glVertex3f(0.1+randX, 0.9+randY, -1.0);
	glVertex3f(0.1+randX, 1.0+randY, -1.0);
    glEnd();

    //UP (KANAN)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
	glVertex3f(0.2+randX, 0.9+randY, 0.0);
	glVertex3f(0.2+randX, 1.0+randY, 0.0);
	glVertex3f(0.2+randX, 1.0+randY, -1.0);
	glVertex3f(0.2+randX, 0.9+randY, -1.0);
    glEnd();

    //UP (ATAS)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
	glVertex3f(0.1+randX, 1.0+randY, 0.0);
	glVertex3f(0.2+randX, 1.0+randY, 0.0);
	glVertex3f(0.2+randX, 1.0+randY, -1.0);
	glVertex3f(0.1+randX, 1.0+randY, -1.0);
    glEnd();

    //UP (BAWAH)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
	glVertex3f(0.1+randX, 0.9+randY, 0.0);
	glVertex3f(0.2+randX, 0.9+randY, 0.0);
	glVertex3f(0.2+randX, 0.9+randY, -1.0);
	glVertex3f(0.1+randX, 0.9+randY, -1.0);
    glEnd();

    ///=============================================================

    //DOWN (DEPAN)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
	glVertex3f(0.1+randX, 0.1+randY, 0.0);
	glVertex3f(0.1+randX, 0.0+randY, 0.0);
	glVertex3f(0.2+randX, 0.0+randY, 0.0);
	glVertex3f(0.2+randX, 0.1+randY, 0.0);
    glEnd();

    //DOWN (BELAKANG)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
	glVertex3f(0.1+randX, 0.1+randY, -1.0);
	glVertex3f(0.1+randX, 0.0+randY, -1.0);
	glVertex3f(0.2+randX, 0.0+randY, -1.0);
	glVertex3f(0.2+randX, 0.1+randY, -1.0);
    glEnd();

    //DOWN (KIRI)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
	glVertex3f(0.1+randX, 0.1+randY, 0.0);
	glVertex3f(0.1+randX, 0.0+randY, 0.0);
	glVertex3f(0.1+randX, 0.0+randY, -1.0);
	glVertex3f(0.1+randX, 0.1+randY, -1.0);
    glEnd();

    //DOWN (KANAN)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
	glVertex3f(0.2+randX, 0.0+randY, 0.0);
	glVertex3f(0.2+randX, 0.1+randY, 0.0);
	glVertex3f(0.2+randX, 0.1+randY, -1.0);
	glVertex3f(0.2+randX, 0.0+randY, -1.0);
    glEnd();

    //DOWN (ATAS)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
	glVertex3f(0.1+randX, 0.1+randY, 0.0);
	glVertex3f(0.1+randX, 0.0+randY, 0.0);
	glVertex3f(0.2+randX, 0.0+randY, 0.0);
	glVertex3f(0.2+randX, 0.1+randY, 0.0);
    glEnd();

    //DOWN (BAWAH)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
	glVertex3f(0.1+randX, 0.1+randY, 0.0);
	glVertex3f(0.2+randX, 0.1+randY, 0.0);
	glVertex3f(0.2+randX, 0.1+randY, -1.0);
	glVertex3f(0.1+randX, 0.1+randY, -1.0);
    glEnd();

    ///============================================================

    //RIGHT (DEPAN)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
	glVertex3f(0.2+randX, 1.0+randY, 0.0);
	glVertex3f(0.2+randX, 0.0+randY, 0.0);
	glVertex3f(0.3+randX, 0.0+randY, 0.0);
	glVertex3f(0.3+randX, 1.0+randY, 0.0);
    glEnd();

    //RIGHT (BELAKANG)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
	glVertex3f(0.2+randX, 1.0+randY, -1.0);
	glVertex3f(0.2+randX, 0.0+randY, -1.0);
	glVertex3f(0.3+randX, 0.0+randY, -1.0);
	glVertex3f(0.3+randX, 1.0+randY, -1.0);
    glEnd();

    //RIGHT (KIRI)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
	glVertex3f(0.2+randX, 1.0+randY, 0.0);
	glVertex3f(0.2+randX, 0.0+randY, 0.0);
	glVertex3f(0.2+randX, 0.0+randY, -1.0);
	glVertex3f(0.2+randX, 1.0+randY, -1.0);
    glEnd();

    //RIGHT (KANAN)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
	glVertex3f(0.3+randX, 0.0+randY, 0.0);
	glVertex3f(0.3+randX, 1.0+randY, 0.0);
	glVertex3f(0.3+randX, 1.0+randY, -1.0);
	glVertex3f(0.3+randX, 0.0+randY, -1.0);
    glEnd();

    //RIGHT (ATAS)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
	glVertex3f(0.2+randX, 1.0+randY, 0.0);
	glVertex3f(0.3+randX, 1.0+randY, 0.0);
	glVertex3f(0.3+randX, 1.0+randY, -1.0);
	glVertex3f(0.2+randX, 1.0+randY, -1.0);
    glEnd();

    //RIGHT (BAWAH)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
	glVertex3f(0.2+randX, 0.0+randY, 0.0);
	glVertex3f(0.3+randX, 0.0+randY, 0.0);
	glVertex3f(0.3+randX, 0.0+randY, -1.0);
	glVertex3f(0.2+randX, 0.0+randY, -1.0);
    glEnd();

    ///=================================================================

    ///FOUR
    //FIRST LINE (DEPAN)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
	glVertex3f(0.4+randX, 1.0+randY, 0.0);
	glVertex3f(0.4+randX, 0.5+randY, 0.0);
	glVertex3f(0.5+randX, 0.5+randY, 0.0);
	glVertex3f(0.5+randX, 1.0+randY, 0.0);
    glEnd();

    //FIRST LINE (BELAKANG)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
	glVertex3f(0.4+randX, 1.0+randY, -1.0);
	glVertex3f(0.4+randX, 0.5+randY, -1.0);
	glVertex3f(0.5+randX, 0.5+randY, -1.0);
	glVertex3f(0.5+randX, 1.0+randY, -1.0);
    glEnd();

    //FIRST LINE (KIRI)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
	glVertex3f(0.4+randX, 1.0+randY, 0.0);
	glVertex3f(0.4+randX, 0.5+randY, 0.0);
	glVertex3f(0.4+randX, 0.5+randY, -1.0);
	glVertex3f(0.4+randX, 1.0+randY, -1.0);
    glEnd();

    //FIRST LINE (KANAN)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
	glVertex3f(0.5+randX, 0.5+randY, 0.0);
	glVertex3f(0.5+randX, 1.0+randY, 0.0);
	glVertex3f(0.5+randX, 1.0+randY, -1.0);
	glVertex3f(0.5+randX, 0.5+randY, -1.0);
    glEnd();

    //FIRST LINE (ATAS)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
	glVertex3f(0.4+randX, 1.0+randY, 0.0);
	glVertex3f(0.5+randX, 1.0+randY, 0.0);
	glVertex3f(0.5+randX, 1.0+randY, -1.0);
	glVertex3f(0.4+randX, 1.0+randY, -1.0);
    glEnd();

    //FIRST LINE (BAWAH)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
	glVertex3f(0.4+randX, 0.5+randY, 0.0);
	glVertex3f(0.5+randX, 0.5+randY, 0.0);
	glVertex3f(0.5+randX, 0.5+randY, -1.0);
	glVertex3f(0.4+randX, 0.5+randY, -1.0);
    glEnd();

    ///===========================================================

    //SECOND LINE (DEPAN)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
	glVertex3f(0.4+randX, 0.5+randY, 0.0);
	glVertex3f(0.4+randX, 0.4+randY, 0.0);
	glVertex3f(0.6+randX, 0.4+randY, 0.0);
	glVertex3f(0.6+randX, 0.5+randY, 0.0);
    glEnd();

    //SECOND LINE (BELAKANG)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
	glVertex3f(0.4+randX, 0.5+randY, -1.0);
	glVertex3f(0.4+randX, 0.4+randY, -1.0);
	glVertex3f(0.6+randX, 0.4+randY, -1.0);
	glVertex3f(0.6+randX, 0.5+randY, -1.0);
    glEnd();

    //SECOND LINE (KIRI)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
	glVertex3f(0.4+randX, 0.5+randY, 0.0);
	glVertex3f(0.4+randX, 0.4+randY, 0.0);
	glVertex3f(0.4+randX, 0.4+randY, -1.0);
	glVertex3f(0.4+randX, 0.5+randY, -1.0);
    glEnd();

    //SECOND LINE (KANAN)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
	glVertex3f(0.6+randX, 0.4+randY, 0.0);
	glVertex3f(0.6+randX, 0.5+randY, 0.0);
	glVertex3f(0.6+randX, 0.5+randY, -1.0);
	glVertex3f(0.6+randX, 0.4+randY, -1.0);
    glEnd();

    //SECOND LINE (ATAS)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
	glVertex3f(0.4+randX, 0.5+randY, 0.0);
	glVertex3f(0.6+randX, 0.5+randY, 0.0);
	glVertex3f(0.6+randX, 0.5+randY, -1.0);
	glVertex3f(0.4+randX, 0.5+randY, -1.0);
    glEnd();

    //SECOND LINE (BAWAH)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
	glVertex3f(0.4+randX, 0.4+randY, 0.0);
	glVertex3f(0.6+randX, 0.4+randY, 0.0);
	glVertex3f(0.6+randX, 0.4+randY, -1.0);
	glVertex3f(0.4+randX, 0.4+randY, -1.0);
    glEnd();

    ///===============================================================

    //THIRD LINE (DEPAN)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
	glVertex3f(0.6+randX, 1.0+randY, 0.0);
	glVertex3f(0.6+randX, 0.0+randY, 0.0);
	glVertex3f(0.7+randX, 0.0+randY, 0.0);
	glVertex3f(0.7+randX, 1.0+randY, 0.0);
    glEnd();

    //THIRD LINE (BELAKANG)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
	glVertex3f(0.6+randX, 1.0+randY, -1.0);
	glVertex3f(0.6+randX, 0.0+randY, -1.0);
	glVertex3f(0.7+randX, 0.0+randY, -1.0);
	glVertex3f(0.7+randX, 1.0+randY, -1.0);
    glEnd();

    //THIRD LINE (KIRI)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
	glVertex3f(0.6+randX, 1.0+randY, 0.0);
	glVertex3f(0.6+randX, 0.0+randY, 0.0);
	glVertex3f(0.6+randX, 0.0+randY, -1.0);
	glVertex3f(0.6+randX, 1.0+randY, -1.0);
    glEnd();

    //THIRD LINE (KANAN)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
	glVertex3f(0.7+randX, 0.0+randY, 0.0);
	glVertex3f(0.7+randX, 1.0+randY, 0.0);
	glVertex3f(0.7+randX, 1.0+randY, -1.0);
	glVertex3f(0.7+randX, 0.0+randY, -1.0);
    glEnd();

    //THIRD LINE (ATAS)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
	glVertex3f(0.6+randX, 1.0+randY, 0.0);
	glVertex3f(0.7+randX, 1.0+randY, 0.0);
	glVertex3f(0.7+randX, 1.0+randY, -1.0);
	glVertex3f(0.6+randX, 1.0+randY, -1.0);
    glEnd();

    //THIRD LINE (BAWAH)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
	glVertex3f(0.6+randX, 0.0+randY, 0.0);
	glVertex3f(0.7+randX, 0.0+randY, 0.0);
	glVertex3f(0.7+randX, 0.0+randY, -1.0);
	glVertex3f(0.6+randX, 0.0+randY, -1.0);
    glEnd();

    ///===============================================================


    ///TWO
    //FIRST LINE (DEPAN)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
	glVertex3f(0.8+randX, 1.0+randY, 0.0);
	glVertex3f(0.8+randX, 0.9+randY, 0.0);
	glVertex3f(1.0+randX, 0.9+randY, 0.0);
	glVertex3f(1.0+randX, 1.0+randY, 0.0);
    glEnd();

    //FIRST LINE (BELAKANG)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
	glVertex3f(0.8+randX, 1.0+randY, -1.0);
	glVertex3f(0.8+randX, 0.9+randY, -1.0);
	glVertex3f(1.0+randX, 0.9+randY, -1.0);
	glVertex3f(1.0+randX, 1.0+randY, -1.0);
    glEnd();

    //FIRST LINE (KIRI)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
	glVertex3f(0.8+randX, 1.0+randY, 0.0);
	glVertex3f(0.8+randX, 0.9+randY, 0.0);
	glVertex3f(0.8+randX, 0.9+randY, -1.0);
	glVertex3f(0.8+randX, 1.0+randY, -1.0);
    glEnd();

    //FIRST LINE (KANAN)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
	glVertex3f(1.0+randX, 0.9+randY, 0.0);
	glVertex3f(1.0+randX, 1.0+randY, 0.0);
	glVertex3f(1.0+randX, 1.0+randY, -1.0);
	glVertex3f(1.0+randX, 0.9+randY, -1.0);
    glEnd();

    //FIRST LINE (ATAS)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
	glVertex3f(0.8+randX, 1.0+randY, 0.0);
	glVertex3f(1.0+randX, 1.0+randY, 0.0);
	glVertex3f(1.0+randX, 1.0+randY, -1.0);
	glVertex3f(0.8+randX, 1.0+randY, -1.0);
    glEnd();

    //FIRST LINE (BAWAH)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
	glVertex3f(0.8+randX, 0.9+randY, 0.0);
	glVertex3f(1.0+randX, 0.9+randY, 0.0);
	glVertex3f(1.0+randX, 0.9+randY, -1.0);
	glVertex3f(0.8+randX, 0.9+randY, -1.0);
    glEnd();

    ///==============================================================

    //SECOND LINE (DEPAN)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
	glVertex3f(0.9+randX, 1.0+randY, 0.0);
	glVertex3f(0.9+randX, 0.5+randY, 0.0);
	glVertex3f(1.0+randX, 0.5+randY, 0.0);
	glVertex3f(1.0+randX, 1.0+randY, 0.0);
    glEnd();

    //SECOND LINE (BELAKANG)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
	glVertex3f(0.9+randX, 1.0+randY, -1.0);
	glVertex3f(0.9+randX, 0.5+randY, -1.0);
	glVertex3f(1.0+randX, 0.5+randY, -1.0);
	glVertex3f(1.0+randX, 1.0+randY, -1.0);
    glEnd();

    //SECOND LINE (KIRI)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
	glVertex3f(0.9+randX, 1.0+randY, 0.0);
	glVertex3f(0.9+randX, 0.5+randY, 0.0);
	glVertex3f(0.9+randX, 0.5+randY, -1.0);
	glVertex3f(0.9+randX, 1.0+randY, -1.0);
    glEnd();

    //SECOND LINE (KANAN)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
	glVertex3f(1.0+randX, 0.5+randY, 0.0);
	glVertex3f(1.0+randX, 1.0+randY, 0.0);
	glVertex3f(1.0+randX, 1.0+randY, -1.0);
	glVertex3f(1.0+randX, 0.5+randY, -1.0);
    glEnd();

    //SECOND LINE (ATAS)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
	glVertex3f(0.9+randX, 1.0+randY, 0.0);
	glVertex3f(1.0+randX, 1.0+randY, 0.0);
	glVertex3f(1.0+randX, 1.0+randY, -1.0);
	glVertex3f(0.9+randX, 1.0+randY, -1.0);
    glEnd();

    //SECOND LINE (BAWAH)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
	glVertex3f(0.9+randX, 0.5+randY, 0.0);
	glVertex3f(1.0+randX, 0.5+randY, 0.0);
	glVertex3f(1.0+randX, 0.5+randY, -1.0);
	glVertex3f(0.9+randX, 0.5+randY, -1.0);
    glEnd();

    ///=================================================================

    //THIRD LINE (DEPAN)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
	glVertex3f(0.8+randX, 0.5+randY, 0.0);
	glVertex3f(0.8+randX, 0.4+randY, 0.0);
	glVertex3f(1.0+randX, 0.4+randY, 0.0);
	glVertex3f(1.0+randX, 0.5+randY, 0.0);
    glEnd();

    //THIRD LINE (BELAKANG)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
	glVertex3f(0.8+randX, 0.5+randY, -1.0);
	glVertex3f(0.8+randX, 0.4+randY, -1.0);
	glVertex3f(1.0+randX, 0.4+randY, -1.0);
	glVertex3f(1.0+randX, 0.5+randY, -1.0);
    glEnd();

    //THIRD LINE (KIRI)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
	glVertex3f(0.8+randX, 0.5+randY, 0.0);
	glVertex3f(0.8+randX, 0.4+randY, 0.0);
	glVertex3f(0.8+randX, 0.4+randY, -1.0);
	glVertex3f(0.8+randX, 0.5+randY, -1.0);
    glEnd();

    //THIRD LINE (KANAN)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
	glVertex3f(1.0+randX, 0.4+randY, 0.0);
	glVertex3f(1.0+randX, 0.5+randY, 0.0);
	glVertex3f(1.0+randX, 0.5+randY, -1.0);
	glVertex3f(1.0+randX, 0.4+randY, -1.0);
    glEnd();

    //THIRD LINE (ATAS)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
	glVertex3f(0.8+randX, 0.5+randY, 0.0);
	glVertex3f(1.0+randX, 0.5+randY, 0.0);
	glVertex3f(1.0+randX, 0.5+randY, -1.0);
	glVertex3f(0.8+randX, 0.5+randY, -1.0);
    glEnd();

    //THIRD LINE (BAWAH)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
	glVertex3f(0.8+randX, 0.4+randY, 0.0);
	glVertex3f(1.0+randX, 0.4+randY, 0.0);
	glVertex3f(1.0+randX, 0.4+randY, -1.0);
	glVertex3f(0.8+randX, 0.4+randY, -1.0);
    glEnd();

    ///=============================================================

    //FOURTH LINE (DEPAN)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
	glVertex3f(0.8+randX, 0.5+randY, 0.0);
	glVertex3f(0.8+randX, 0.0+randY, 0.0);
	glVertex3f(0.9+randX, 0.0+randY, 0.0);
	glVertex3f(0.9+randX, 0.5+randY, 0.0);
    glEnd();

    //FOURTH LINE (BELAKANG)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
	glVertex3f(0.8+randX, 0.5+randY, -1.0);
	glVertex3f(0.8+randX, 0.0+randY, -1.0);
	glVertex3f(0.9+randX, 0.0+randY, -1.0);
	glVertex3f(0.9+randX, 0.5+randY, -1.0);
    glEnd();

    //FOURTH LINE (KIRI)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
	glVertex3f(0.8+randX, 0.5+randY, 0.0);
	glVertex3f(0.8+randX, 0.0+randY, 0.0);
	glVertex3f(0.8+randX, 0.0+randY, -1.0);
	glVertex3f(0.8+randX, 0.5+randY, -1.0);
    glEnd();

    //FOURTH LINE (KANAN)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
	glVertex3f(0.9+randX, 0.0+randY, 0.0);
	glVertex3f(0.9+randX, 0.5+randY, 0.0);
	glVertex3f(0.9+randX, 0.5+randY, -1.0);
	glVertex3f(0.9+randX, 0.0+randY, -1.0);
    glEnd();

    //FOURTH LINE (ATAS)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
	glVertex3f(0.8+randX, 0.5+randY, 0.0);
	glVertex3f(0.9+randX, 0.5+randY, 0.0);
	glVertex3f(0.9+randX, 0.5+randY, -1.0);
	glVertex3f(0.8+randX, 0.5+randY, -1.0);
    glEnd();

    //FOURTH LINE (BAWAH)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
	glVertex3f(0.8+randX, 0.0+randY, 0.0);
	glVertex3f(0.9+randX, 0.0+randY, 0.0);
	glVertex3f(0.9+randX, 0.0+randY, -1.0);
	glVertex3f(0.8+randX, 0.0+randY, -1.0);
    glEnd();

    ///=======================================================

    //FIFTH LINE (DEPAN)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
	glVertex3f(0.8+randX, 0.1+randY, 0.0);
	glVertex3f(0.8+randX, 0.0+randY, 0.0);
	glVertex3f(1.0+randX, 0.0+randY, 0.0);
	glVertex3f(1.0+randX, 0.1+randY, 0.0);
    glEnd();

    //FIFTH LINE (BELAKANG)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
	glVertex3f(0.8+randX, 0.1+randY, -1.0);
	glVertex3f(0.8+randX, 0.0+randY, -1.0);
	glVertex3f(1.0+randX, 0.0+randY, -1.0);
	glVertex3f(1.0+randX, 0.1+randY, -1.0);
    glEnd();

    //FIFTH LINE (KIRI)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
	glVertex3f(0.8+randX, 0.1+randY, 0.0);
	glVertex3f(0.8+randX, 0.0+randY, 0.0);
	glVertex3f(0.8+randX, 0.0+randY, -1.0);
	glVertex3f(0.8+randX, 0.1+randY, -1.0);
    glEnd();

    //FIFTH LINE (KANAN)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
	glVertex3f(1.0+randX, 0.0+randY, 0.0);
	glVertex3f(1.0+randX, 0.1+randY, 0.0);
	glVertex3f(1.0+randX, 0.1+randY, -1.0);
	glVertex3f(1.0+randX, 0.0+randY, -1.0);
    glEnd();

    //FIFTH LINE (ATAS)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
	glVertex3f(0.8+randX, 0.1+randY, 0.0);
	glVertex3f(1.0+randX, 0.1+randY, 0.0);
	glVertex3f(1.0+randX, 0.1+randY, -1.0);
	glVertex3f(0.8+randX, 0.1+randY, -1.0);
    glEnd();

    //FIFTH LINE (BAWAH)
    material(0.0,0.5,0.2,1);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
	glVertex3f(0.8+randX, 0.0+randY, 0.0);
	glVertex3f(1.0+randX, 0.0+randY, 0.0);
	glVertex3f(1.0+randX, 0.0+randY, -1.0);
	glVertex3f(0.8+randX, 0.0+randY, -1.0);
    glEnd();
}

void map1(){

    ///KOTAK 1(DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(0.0,15.0,0.0);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(1.0,0.0,0.0);
    glVertex3f(1.0,15.0,0.0);
    glEnd();

    ///KOTAK 1 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(0.0,15.0,-1.0);
    glVertex3f(0.0,0.0,-1.0);
    glVertex3f(1.0,0.0,-1.0);
    glVertex3f(1.0,15.0,-1.0);
    glEnd();

    ///KOTAK 1 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(0.0,15.0,0.0);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.0,0.0,-1.0);
    glVertex3f(0.0,15.0,-1.0);
    glEnd();

    ///KOTAK 1(KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(1.0,0.0,0.0);
    glVertex3f(1.0,15.0,0.0);
    glVertex3f(1.0,15.0,-1.0);
    glVertex3f(1.0,0.0,-1.0);
    glEnd();

    ///KOTAK 1 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(0.0,15.0,0.0);
    glVertex3f(1.0,15.0,0.0);
    glVertex3f(1.0,15.0,-1.0);
    glVertex3f(0.0,15.0,-1.0);
    glEnd();

    ///KOTAK 1 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(1.0,0.0,0.0);
    glVertex3f(1.0,0.0,-1.0);
    glVertex3f(0.0,0.0,-1.0);
    glEnd();

    ///---------------------------------------------------------------------------------------------

    ///KOTAK 2 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(1.0,15.0,0.0);
    glVertex3f(1.0,14.0,0.0);
    glVertex3f(7.0,14.0,0.0);
    glVertex3f(7.0,15.0,0.0);
    glEnd();

    ///KOTAK 2 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(1.0,15.0,-1.0);
    glVertex3f(1.0,14.0,-1.0);
    glVertex3f(7.0,14.0,-1.0);
    glVertex3f(7.0,15.0,-1.0);
    glEnd();

    ///KOTAK 2 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(1.0,15.0,0.0);
    glVertex3f(1.0,14.0,0.0);
    glVertex3f(1.0,14.0,-1.0);
    glVertex3f(1.0,15.0,-1.0);
    glEnd();

    ///KOTAK 2 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(7.0,14.0,0.0);
    glVertex3f(7.0,15.0,0.0);
    glVertex3f(7.0,15.0,-1.0);
    glVertex3f(7.0,14.0,-1.0);
    glEnd();

    ///KOTAK 2 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(1.0,15.0,0.0);
    glVertex3f(7.0,15.0,0.0);
    glVertex3f(7.0,15.0,-1.0);
    glVertex3f(1.0,15.0,-1.0);
    glEnd();

    ///KOTAK 2 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(1.0,14.0,0.0);
    glVertex3f(7.0,14.0,0.0);
    glVertex3f(7.0,14.0,-1.0);
    glVertex3f(1.0,14.0,-1.0);
    glEnd();

    ///--------------------------------------------------------------

    ///KOTAK 3 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(8.0,15.0,0.0);
    glVertex3f(8.0,14.0,0.0);
    glVertex3f(14.0,14.0,0.0);
    glVertex3f(14.0,15.0,0.0);
    glEnd();

    ///KOTAK 3 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(8.0,15.0,-1.0);
    glVertex3f(8.0,14.0,-1.0);
    glVertex3f(14.0,14.0,-1.0);
    glVertex3f(14.0,15.0,-1.0);
    glEnd();

    ///KOTAK 3 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(8.0,15.0,0.0);
    glVertex3f(8.0,14.0,0.0);
    glVertex3f(8.0,14.0,-1.0);
    glVertex3f(8.0,15.0,-1.0);
    glEnd();

    ///KOTAK 3 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(14.0,14.0,0.0);
    glVertex3f(14.0,15.0,0.0);
    glVertex3f(14.0,15.0,-1.0);
    glVertex3f(14.0,14.0,-1.0);
    glEnd();

    ///KOTAK 3 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(8.0,15.0,0.0);
    glVertex3f(14.0,15.0,0.0);
    glVertex3f(14.0,15.0,-1.0);
    glVertex3f(8.0,15.0,-1.0);
    glEnd();

    ///KOTAK 3 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(8.0,14.0,0.0);
    glVertex3f(14.0,14.0,0.0);
    glVertex3f(14.0,14.0,-1.0);
    glVertex3f(8.0,14.0,-1.0);
    glEnd();

    ///-------------------------------------------------------------------------

    ///KOTAK 4 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(14.0,15.0,0.0);
    glVertex3f(14.0,0.0,0.0);
    glVertex3f(15.0,0.0,0.0);
    glVertex3f(15.0,15.0,0.0);
    glEnd();

    ///KOTAK 4 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(14.0,15.0,-1.0);
    glVertex3f(14.0,0.0,-1.0);
    glVertex3f(15.0,0.0,-1.0);
    glVertex3f(15.0,15.0,-1.0);
    glEnd();

    ///KOTAK 4 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(14.0,15.0,0.0);
    glVertex3f(14.0,0.0,0.0);
    glVertex3f(14.0,0.0,-1.0);
    glVertex3f(14.0,15.0,-1.0);
    glEnd();

    ///KOTAK 4 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(15.0,15.0,0.0);
    glVertex3f(15.0,0.0,0.0);
    glVertex3f(15.0,0.0,-1.0);
    glVertex3f(15.0,15.0,-1.0);
    glEnd();

    ///KOTAK 4 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(14.0,15.0,0.0);
    glVertex3f(15.0,15.0,0.0);
    glVertex3f(15.0,15.0,-1.0);
    glVertex3f(14.0,15.0,-1.0);
    glEnd();

    ///KOTAK 4 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(14.0,0.0,0.0);
    glVertex3f(15.0,0.0,0.0);
    glVertex3f(15.0,0.0,-1.0);
    glVertex3f(14.0,0.0,-1.0);
    glEnd();

    ///------------------------------------------------------------

    ///KOTAK 5 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(8.0,1.0,0.0);
    glVertex3f(8.0,0.0,0.0);
    glVertex3f(14.0,0.0,0.0);
    glVertex3f(14.0,1.0,0.0);
    glEnd();

    ///KOTAK 5 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(8.0,1.0,-1.0);
    glVertex3f(8.0,0.0,-1.0);
    glVertex3f(14.0,0.0,-1.0);
    glVertex3f(14.0,1.0,-1.0);
    glEnd();

    ///KOTAK 5 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(8.0,1.0,0.0);
    glVertex3f(8.0,0.0,0.0);
    glVertex3f(8.0,0.0,-1.0);
    glVertex3f(8.0,1.0,-1.0);
    glEnd();

    ///KOTAK 5 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(14.0,0.0,0.0);
    glVertex3f(14.0,1.0,0.0);
    glVertex3f(14.0,1.0,-1.0);
    glVertex3f(14.0,0.0,-1.0);
    glEnd();

    ///KOTAK 5 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(8.0,1.0,0.0);
    glVertex3f(14.0,1.0,0.0);
    glVertex3f(14.0,1.0,-1.0);
    glVertex3f(8.0,1.0,-1.0);
    glEnd();

    ///KOTAK 5 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(8.0,0.0,0.0);
    glVertex3f(14.0,0.0,0.0);
    glVertex3f(14.0,0.0,-1.0);
    glVertex3f(8.0,0.0,-1.0);
    glEnd();

    ///---------------------------------------------------------------

    ///KOTAK 6 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(1.0,1.0,0.0);
    glVertex3f(1.0,0.0,0.0);
    glVertex3f(7.0,0.0,0.0);
    glVertex3f(7.0,1.0,0.0);
    glEnd();

    ///KOTAK 6 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(1.0,1.0,-1.0);
    glVertex3f(1.0,0.0,-1.0);
    glVertex3f(7.0,0.0,-1.0);
    glVertex3f(7.0,1.0,-1.0);
    glEnd();

    ///KOTAK 6 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(1.0,1.0,0.0);
    glVertex3f(1.0,0.0,0.0);
    glVertex3f(0.0,0.0,-1.0);
    glVertex3f(0.0,1.0,-1.0);
    glEnd();

    ///KOTAK 6 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(7.0,1.0,0.0);
    glVertex3f(7.0,0.0,0.0);
    glVertex3f(7.0,0.0,-1.0);
    glVertex3f(7.0,1.0,-1.0);
    glEnd();

    ///KOTAK 6 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(1.0,1.0,0.0);
    glVertex3f(7.0,1.0,0.0);
    glVertex3f(7.0,1.0,-1.0);
    glVertex3f(1.0,1.0,-1.0);
    glEnd();

    ///KOTAK 6 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(1.0,0.0,0.0);
    glVertex3f(7.0,0.0,0.0);
    glVertex3f(7.0,0.0,-1.0);
    glVertex3f(1.0,0.0,-1.0);
    glEnd();

    ///----------------------------------------------------------------

    ///KOTAK 7 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(2.0,14.0,0.0);
    glVertex3f(2.0,12.0,0.0);
    glVertex3f(3.0,12.0,0.0);
    glVertex3f(3.0,14.0,0.0);
    glEnd();

    ///KOTAK 7 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(2.0,14.0,-1.0);
    glVertex3f(2.0,12.0,-1.0);
    glVertex3f(3.0,12.0,-1.0);
    glVertex3f(3.0,14.0,-1.0);
    glEnd();

    ///KOTAK 7 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(2.0,14.0,0.0);
    glVertex3f(2.0,12.0,0.0);
    glVertex3f(2.0,12.0,-1.0);
    glVertex3f(2.0,14.0,-1.0);
    glEnd();

    ///KOTAK 7 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(3.0,14.0,0.0);
    glVertex3f(3.0,12.0,0.0);
    glVertex3f(3.0,12.0,-1.0);
    glVertex3f(3.0,14.0,-1.0);
    glEnd();

    ///KOTAK 7 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(2.0,14.0,0.0);
    glVertex3f(3.0,14.0,0.0);
    glVertex3f(3.0,14.0,-1.0);
    glVertex3f(2.0,14.0,-1.0);
    glEnd();

    ///KOTAK 7 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(2.0,12.0,0.0);
    glVertex3f(3.0,12.0,0.0);
    glVertex3f(3.0,12.0,-1.0);
    glVertex3f(2.0,12.0,-1.0);
    glEnd();

    ///--------------------------------------------------------------

    ///KOTAK 8 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(1.0,7.0,0.0);
    glVertex3f(1.0,6.0,0.0);
    glVertex3f(3.0,6.0,0.0);
    glVertex3f(3.0,7.0,0.0);
    glEnd();

    ///KOTAK 8 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(1.0,7.0,-1.0);
    glVertex3f(1.0,6.0,-1.0);
    glVertex3f(3.0,6.0,-1.0);
    glVertex3f(3.0,7.0,-1.0);
    glEnd();

    ///KOTAK 8 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(1.0,7.0,0.0);
    glVertex3f(1.0,6.0,0.0);
    glVertex3f(1.0,6.0,-1.0);
    glVertex3f(1.0,7.0,-1.0);
    glEnd();

    ///KOTAK 8 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(3.0,6.0,0.0);
    glVertex3f(3.0,7.0,0.0);
    glVertex3f(3.0,7.0,-1.0);
    glVertex3f(3.0,6.0,-1.0);
    glEnd();

    ///KOTAK 8 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(1.0,7.0,0.0);
    glVertex3f(3.0,7.0,0.0);
    glVertex3f(3.0,7.0,-1.0);
    glVertex3f(1.0,7.0,-1.0);
    glEnd();

    ///KOTAK 8 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(1.0,6.0,0.0);
    glVertex3f(3.0,6.0,0.0);
    glVertex3f(3.0,6.0,-1.0);
    glVertex3f(1.0,6.0,-1.0);
    glEnd();

    ///------------------------------------------------------

    ///KOTAK 9 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(2.0,6.0,0.0);
    glVertex3f(2.0,2.0,0.0);
    glVertex3f(3.0,2.0,0.0);
    glVertex3f(3.0,6.0,0.0);
    glEnd();

    ///KOTAK 9 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(2.0,6.0,-1.0);
    glVertex3f(2.0,2.0,-1.0);
    glVertex3f(3.0,2.0,-1.0);
    glVertex3f(3.0,6.0,-1.0);
    glEnd();

    ///KOTAK 9 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(2.0,6.0,0.0);
    glVertex3f(2.0,2.0,0.0);
    glVertex3f(2.0,2.0,-1.0);
    glVertex3f(2.0,6.0,-1.0);
    glEnd();

    ///KOTAK 9 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(3.0,6.0,0.0);
    glVertex3f(3.0,2.0,0.0);
    glVertex3f(3.0,2.0,-1.0);
    glVertex3f(3.0,6.0,-1.0);
    glEnd();

    ///KOTAK 9 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(2.0,6.0,0.0);
    glVertex3f(3.0,6.0,0.0);
    glVertex3f(3.0,6.0,-1.0);
    glVertex3f(2.0,6.0,-1.0);
    glEnd();

    ///KOTAK 9 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(2.0,2.0,0.0);
    glVertex3f(3.0,2.0,0.0);
    glVertex3f(3.0,2.0,-1.0);
    glVertex3f(2.0,2.0,-1.0);
    glEnd();

    ///-----------------------------------------------------------------

    ///KOTAK 10 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(3.0,5.0,0.0);
    glVertex3f(3.0,4.0,0.0);
    glVertex3f(5.0,4.0,0.0);
    glVertex3f(5.0,5.0,0.0);
    glEnd();

    ///KOTAK 10 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(3.0,5.0,-1.0);
    glVertex3f(3.0,4.0,-1.0);
    glVertex3f(5.0,4.0,-1.0);
    glVertex3f(5.0,5.0,-1.0);
    glEnd();

    ///KOTAK 10 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(3.0,5.0,0.0);
    glVertex3f(3.0,4.0,0.0);
    glVertex3f(3.0,4.0,-1.0);
    glVertex3f(3.0,5.0,-1.0);
    glEnd();

    ///KOTAK 10 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(5.0,5.0,0.0);
    glVertex3f(5.0,4.0,0.0);
    glVertex3f(5.0,4.0,-1.0);
    glVertex3f(5.0,5.0,-1.0);
    glEnd();

    ///KOTAK 10 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(3.0,5.0,0.0);
    glVertex3f(5.0,5.0,0.0);
    glVertex3f(5.0,5.0,-1.0);
    glVertex3f(3.0,5.0,-1.0);
    glEnd();

    ///KOTAK 10 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(3.0,4.0,0.0);
    glVertex3f(5.0,4.0,0.0);
    glVertex3f(5.0,4.0,-1.0);
    glVertex3f(3.0,4.0,-1.0);
    glEnd();

    ///-------------------------------------------------------

    ///KOTAK 11 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(4.0,4.0,0.0);
    glVertex3f(4.0,2.0,0.0);
    glVertex3f(5.0,2.0,0.0);
    glVertex3f(5.0,4.0,0.0);
    glEnd();

    ///KOTAK 11 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(4.0,4.0,-1.0);
    glVertex3f(4.0,2.0,-1.0);
    glVertex3f(5.0,2.0,-1.0);
    glVertex3f(5.0,4.0,-1.0);
    glEnd();

    ///KOTAK 11 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(4.0,4.0,0.0);
    glVertex3f(4.0,2.0,0.0);
    glVertex3f(4.0,2.0,-1.0);
    glVertex3f(4.0,4.0,-1.0);
    glEnd();

    ///KOTAK 11 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(5.0,4.0,0.0);
    glVertex3f(5.0,2.0,0.0);
    glVertex3f(5.0,2.0,-1.0);
    glVertex3f(5.0,4.0,-1.0);
    glEnd();

    ///KOTAK 11 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(4.0,4.0,0.0);
    glVertex3f(5.0,4.0,0.0);
    glVertex3f(5.0,4.0,-1.0);
    glVertex3f(4.0,4.0,-1.0);
    glEnd();

    ///KOTAK 11 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(4.0,2.0,0.0);
    glVertex3f(5.0,2.0,0.0);
    glVertex3f(5.0,2.0,-1.0);
    glVertex3f(4.0,2.0,-1.0);
    glEnd();

    ///---------------------------------------------------------

    ///KOTAK 12 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(6.0,14.0,0.0);
    glVertex3f(6.0,12.0,0.0);
    glVertex3f(7.0,12.0,0.0);
    glVertex3f(7.0,14.0,0.0);
    glEnd();

    ///KOTAK 12 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(6.0,14.0,-1.0);
    glVertex3f(6.0,12.0,-1.0);
    glVertex3f(7.0,12.0,-1.0);
    glVertex3f(7.0,14.0,-1.0);
    glEnd();

    ///KOTAK 12 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(6.0,14.0,0.0);
    glVertex3f(6.0,12.0,0.0);
    glVertex3f(6.0,12.0,-1.0);
    glVertex3f(6.0,14.0,-1.0);
    glEnd();

    ///KOTAK 12 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(7.0,12.0,0.0);
    glVertex3f(7.0,14.0,0.0);
    glVertex3f(7.0,14.0,-1.0);
    glVertex3f(7.0,12.0,-1.0);
    glEnd();

    ///KOTAK 12 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(6.0,14.0,0.0);
    glVertex3f(7.0,14.0,0.0);
    glVertex3f(7.0,14.0,-1.0);
    glVertex3f(6.0,14.0,-1.0);
    glEnd();

    ///KOTAK 12 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(6.0,12.0,0.0);
    glVertex3f(7.0,12.0,0.0);
    glVertex3f(7.0,12.0,-1.0);
    glVertex3f(6.0,12.0,-1.0);
    glEnd();

    ///---------------------------------------------------------

    ///KOTAK 13 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(4.0,13.0,0.0);
    glVertex3f(4.0,12.0,0.0);
    glVertex3f(6.0,12.0,0.0);
    glVertex3f(6.0,13.0,0.0);
    glEnd();

    ///KOTAK 13 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(4.0,13.0,-1.0);
    glVertex3f(4.0,12.0,-1.0);
    glVertex3f(6.0,12.0,-1.0);
    glVertex3f(6.0,13.0,-1.0);
    glEnd();

    ///KOTAK 13 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(4.0,13.0,0.0);
    glVertex3f(4.0,12.0,0.0);
    glVertex3f(4.0,12.0,-1.0);
    glVertex3f(4.0,13.0,-1.0);
    glEnd();

    ///KOTAK 13 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(6.0,12.0,0.0);
    glVertex3f(6.0,13.0,0.0);
    glVertex3f(6.0,13.0,-1.0);
    glVertex3f(6.0,12.0,-1.0);
    glEnd();

    ///KOTAK 13 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(4.0,13.0,0.0);
    glVertex3f(6.0,13.0,0.0);
    glVertex3f(6.0,13.0,-1.0);
    glVertex3f(4.0,13.0,-1.0);
    glEnd();

    ///KOTAK 13 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(4.0,12.0,0.0);
    glVertex3f(6.0,12.0,0.0);
    glVertex3f(6.0,12.0,-1.0);
    glVertex3f(4.0,12.0,-1.0);
    glEnd();

    ///------------------------------------------------------

    ///KOTAK 14 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(4.0,12.0,0.0);
    glVertex3f(4.0,10.0,0.0);
    glVertex3f(5.0,10.0,0.0);
    glVertex3f(5.0,12.0,0.0);
    glEnd();

    ///KOTAK 14 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(4.0,12.0,-1.0);
    glVertex3f(4.0,10.0,-1.0);
    glVertex3f(5.0,10.0,-1.0);
    glVertex3f(5.0,12.0,-1.0);
    glEnd();

    ///KOTAK 14 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(4.0,12.0,0.0);
    glVertex3f(4.0,10.0,0.0);
    glVertex3f(4.0,10.0,-1.0);
    glVertex3f(4.0,12.0,-1.0);
    glEnd();

    ///KOTAK 14 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(5.0,12.0,0.0);
    glVertex3f(5.0,10.0,0.0);
    glVertex3f(5.0,10.0,-1.0);
    glVertex3f(5.0,12.0,-1.0);
    glEnd();

    ///KOTAK 14 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(4.0,12.0,0.0);
    glVertex3f(5.0,12.0,0.0);
    glVertex3f(5.0,12.0,-1.0);
    glVertex3f(4.0,12.0,-1.0);
    glEnd();

    ///KOTAK 14 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(4.0,10.0,0.0);
    glVertex3f(5.0,10.0,0.0);
    glVertex3f(5.0,10.0,-1.0);
    glVertex3f(4.0,10.0,-1.0);
    glEnd();

    ///--------------------------------------------------------------

    ///KOTAK 15 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(2.0,11.0,0.0);
    glVertex3f(2.0,10.0,0.0);
    glVertex3f(4.0,10.0,0.0);
    glVertex3f(4.0,11.0,0.0);
    glEnd();

    ///KOTAK 15 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(2.0,11.0,-1.0);
    glVertex3f(2.0,10.0,-1.0);
    glVertex3f(4.0,10.0,-1.0);
    glVertex3f(4.0,11.0,-1.0);
    glEnd();

    ///KOTAK 15 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(2.0,11.0,0.0);
    glVertex3f(2.0,10.0,0.0);
    glVertex3f(2.0,10.0,-1.0);
    glVertex3f(2.0,11.0,-1.0);
    glEnd();

    ///KOTAK 15 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(4.0,10.0,0.0);
    glVertex3f(4.0,11.0,0.0);
    glVertex3f(4.0,11.0,-1.0);
    glVertex3f(4.0,10.0,-1.0);
    glEnd();

    ///KOTAK 15 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(2.0,11.0,0.0);
    glVertex3f(4.0,11.0,0.0);
    glVertex3f(4.0,11.0,-1.0);
    glVertex3f(2.0,11.0,-1.0);
    glEnd();

    ///KOTAK 15 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(2.0,10.0,0.0);
    glVertex3f(4.0,10.0,0.0);
    glVertex3f(4.0,10.0,-1.0);
    glVertex3f(2.0,10.0,-1.0);
    glEnd();

    ///-------------------------------------------------------------------

    ///KOTAK 16 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(2.0,9.0,0.0);
    glVertex3f(2.0,8.0,0.0);
    glVertex3f(6.0,8.0,0.0);
    glVertex3f(6.0,9.0,0.0);
    glEnd();

    ///KOTAK 16 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(2.0,9.0,-1.0);
    glVertex3f(2.0,8.0,-1.0);
    glVertex3f(6.0,8.0,-1.0);
    glVertex3f(6.0,9.0,-1.0);
    glEnd();

    ///KOTAK 16 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(2.0,9.0,0.0);
    glVertex3f(2.0,8.0,0.0);
    glVertex3f(2.0,8.0,-1.0);
    glVertex3f(2.0,9.0,-1.0);
    glEnd();

    ///KOTAK 16 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(6.0,9.0,0.0);
    glVertex3f(6.0,8.0,0.0);
    glVertex3f(6.0,8.0,-1.0);
    glVertex3f(6.0,9.0,-1.0);
    glEnd();

    ///KOTAK 16 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(2.0,9.0,0.0);
    glVertex3f(6.0,9.0,0.0);
    glVertex3f(6.0,9.0,-1.0);
    glVertex3f(2.0,9.0,-1.0);
    glEnd();

    ///KOTAK 16 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(2.0,8.0,0.0);
    glVertex3f(6.0,8.0,0.0);
    glVertex3f(6.0,8.0,-1.0);
    glVertex3f(2.0,8.0,-1.0);
    glEnd();

    ///----------------------------------------------------------------

    ///KOTAK 17 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(4.0,8.0,0.0);
    glVertex3f(4.0,6.0,0.0);
    glVertex3f(5.0,6.0,0.0);
    glVertex3f(5.0,8.0,0.0);
    glEnd();

    ///KOTAK 17 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(4.0,8.0,-1.0);
    glVertex3f(4.0,6.0,-1.0);
    glVertex3f(5.0,6.0,-1.0);
    glVertex3f(5.0,8.0,-1.0);
    glEnd();

    ///KOTAK 17 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(4.0,8.0,0.0);
    glVertex3f(4.0,6.0,0.0);
    glVertex3f(4.0,6.0,-1.0);
    glVertex3f(4.0,8.0,-1.0);
    glEnd();

    ///KOTAK 17 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(5.0,8.0,0.0);
    glVertex3f(5.0,6.0,0.0);
    glVertex3f(5.0,6.0,-1.0);
    glVertex3f(5.0,8.0,-1.0);
    glEnd();

    ///KOTAK 17 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(4.0,8.0,0.0);
    glVertex3f(4.0,6.0,0.0);
    glVertex3f(5.0,6.0,0.0);
    glVertex3f(5.0,8.0,0.0);
    glEnd();

    ///KOTAK 17 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(4.0,6.0,0.0);
    glVertex3f(5.0,6.0,0.0);
    glVertex3f(5.0,6.0,-1.0);
    glVertex3f(4.0,6.0,-1.0);
    glEnd();

    ///----------------------------------------------------------------

    ///KOTAK 18 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(6.0,10.0,0.0);
    glVertex3f(6.0,4.0,0.0);
    glVertex3f(7.0,4.0,0.0);
    glVertex3f(7.0,10.0,0.0);
    glEnd();

    ///KOTAK 18 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(6.0,10.0,-1.0);
    glVertex3f(6.0,4.0,-1.0);
    glVertex3f(7.0,4.0,-1.0);
    glVertex3f(7.0,10.0,-1.0);
    glEnd();

    ///KOTAK 18 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(6.0,10.0,0.0);
    glVertex3f(6.0,4.0,0.0);
    glVertex3f(6.0,4.0,-1.0);
    glVertex3f(6.0,10.0,-1.0);
    glEnd();

    ///KOTAK 18 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(7.0,10.0,0.0);
    glVertex3f(7.0,4.0,0.0);
    glVertex3f(7.0,4.0,-1.0);
    glVertex3f(7.0,10.0,-1.0);
    glEnd();

    ///KOTAK 18 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(6.0,10.0,0.0);
    glVertex3f(7.0,10.0,0.0);
    glVertex3f(7.0,10.0,-1.0);
    glVertex3f(6.0,10.0,-1.0);
    glEnd();

    ///KOTAK 18 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(6.0,4.0,0.0);
    glVertex3f(7.0,4.0,0.0);
    glVertex3f(7.0,4.0,-1.0);
    glVertex3f(6.0,4.0,-1.0);
    glEnd();

    ///-----------------------------------------------------------------

    ///KOTAK 19 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(6.0,11.0,0.0);
    glVertex3f(6.0,10.0,0.0);
    glVertex3f(8.0,10.0,0.0);
    glVertex3f(8.0,11.0,0.0);
    glEnd();

    ///KOTAK 19 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(6.0,11.0,-1.0);
    glVertex3f(6.0,10.0,-1.0);
    glVertex3f(8.0,10.0,-1.0);
    glVertex3f(8.0,11.0,-1.0);
    glEnd();

    ///KOTAK 19 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(6.0,11.0,0.0);
    glVertex3f(6.0,10.0,0.0);
    glVertex3f(6.0,10.0,-1.0);
    glVertex3f(6.0,11.0,-1.0);
    glEnd();

    ///KOTAK 19 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(8.0,11.0,0.0);
    glVertex3f(8.0,10.0,0.0);
    glVertex3f(8.0,10.0,-1.0);
    glVertex3f(8.0,11.0,-1.0);
    glEnd();

    ///KOTAK 19 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(6.0,11.0,0.0);
    glVertex3f(8.0,11.0,0.0);
    glVertex3f(8.0,11.0,-1.0);
    glVertex3f(6.0,11.0,-1.0);
    glEnd();

    ///KOTAK 19 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(6.0,10.0,0.0);
    glVertex3f(8.0,10.0,0.0);
    glVertex3f(8.0,10.0,-1.0);
    glVertex3f(6.0,10,-1.0);
    glEnd();

    ///-------------------------------------------------------------------

    ///KOTAK 20 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(8.0,13.0,0.0);
    glVertex3f(8.0,8.0,0.0);
    glVertex3f(9.0,8.0,0.0);
    glVertex3f(9.0,13.0,0.0);
    glEnd();

    ///KOTAK 20 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(8.0,13.0,-1.0);
    glVertex3f(8.0,8.0,-1.0);
    glVertex3f(9.0,8.0,-1.0);
    glVertex3f(9.0,13.0,-1.0);
    glEnd();

    ///KOTAK 20 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(8.0,13.0,0.0);
    glVertex3f(8.0,8.0,0.0);
    glVertex3f(8.0,8.0,-1.0);
    glVertex3f(8.0,13.0,-1.0);
    glEnd();

    ///KOTAK 20 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(9.0,13.0,0.0);
    glVertex3f(9.0,8.0,0.0);
    glVertex3f(9.0,8.0,-1.0);
    glVertex3f(9.0,13.0,-1.0);
    glEnd();

    ///KOTAK 20 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(8.0,13.0,0.0);
    glVertex3f(9.0,13.0,0.0);
    glVertex3f(9.0,13.0,-1.0);
    glVertex3f(8.0,13.0,-1.0);
    glEnd();

    ///KOTAK 20 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(8.0,8.0,0.0);
    glVertex3f(9.0,8.0,0.0);
    glVertex3f(9.0,8.0,-1.0);
    glVertex3f(8.0,8.0,-1.0);
    glEnd();

    ///-------------------------------------------------------------------

    ///KOTAK 21 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(9.0,9.0,0.0);
    glVertex3f(9.0,8.0,0.0);
    glVertex3f(11.0,8.0,0.0);
    glVertex3f(11.0,9.0,0.0);
    glEnd();

    ///KOTAK 21 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(9.0,9.0,-1.0);
    glVertex3f(9.0,8.0,-1.0);
    glVertex3f(11.0,8.0,-1.0);
    glVertex3f(11.0,9.0,-1.0);
    glEnd();

    ///KOTAK 21 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(9.0,9.0,0.0);
    glVertex3f(9.0,8.0,0.0);
    glVertex3f(9.0,8.0,-1.0);
    glVertex3f(9.0,9.0,-1.0);
    glEnd();

    ///KOTAK 21 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(11.0,9.0,0.0);
    glVertex3f(11.0,8.0,0.0);
    glVertex3f(11.0,8.0,-1.0);
    glVertex3f(11.0,9.0,-1.0);
    glEnd();

    ///KOTAK 21 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(9.0,9.0,0.0);
    glVertex3f(11.0,9.0,0.0);
    glVertex3f(11.0,9.0,-1.0);
    glVertex3f(9.0,9.0,-1.0);
    glEnd();

    ///KOTAK 21 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(9.0,8.0,0.0);
    glVertex3f(11.0,8.0,0.0);
    glVertex3f(11.0,8.0,-1.0);
    glVertex3f(9.0,8.0,-1.0);
    glEnd();

    ///----------------------------------------------------------------

    ///KOTAK 22 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(10.0,8.0,0.0);
    glVertex3f(10.0,6.0,0.0);
    glVertex3f(11.0,6.0,0.0);
    glVertex3f(11.0,8.0,0.0);
    glEnd();

    ///KOTAK 22 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(10.0,8.0,-1.0);
    glVertex3f(10.0,6.0,-1.0);
    glVertex3f(11.0,6.0,-1.0);
    glVertex3f(11.0,8.0,-1.0);
    glEnd();

    ///KOTAK 22 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(10.0,8.0,0.0);
    glVertex3f(10.0,6.0,0.0);
    glVertex3f(10.0,6.0,-1.0);
    glVertex3f(10.0,8.0,-1.0);
    glEnd();

    ///KOTAK 22 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(11.0,8.0,0.0);
    glVertex3f(11.0,6.0,0.0);
    glVertex3f(11.0,6.0,-1.0);
    glVertex3f(11.0,8.0,-1.0);
    glEnd();

    ///KOTAK 22 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(10.0,8.0,0.0);
    glVertex3f(11.0,8.0,0.0);
    glVertex3f(11.0,8.0,-1.0);
    glVertex3f(10.0,8.0,-1.0);
    glEnd();

    ///KOTAK 22 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(10.0,6.0,0.0);
    glVertex3f(11.0,6.0,0.0);
    glVertex3f(11.0,6.0,-1.0);
    glVertex3f(10.0,6.0,-1.0);
    glEnd();

    ///----------------------------------------------------------------------

    ///KOTAK 23 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(8.0,7.0,0.0);
    glVertex3f(8.0,6.0,0.0);
    glVertex3f(10.0,6.0,0.0);
    glVertex3f(10.0,7.0,0.0);
    glEnd();

    ///KOTAK 23 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(8.0,7.0,-1.0);
    glVertex3f(8.0,6.0,-1.0);
    glVertex3f(10.0,6.0,-1.0);
    glVertex3f(10.0,7.0,-1.0);
    glEnd();

    ///KOTAK 23 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(8.0,7.0,0.0);
    glVertex3f(8.0,6.0,0.0);
    glVertex3f(8.0,6.0,-1.0);
    glVertex3f(8.0,7.0,-1.0);
    glEnd();

    ///KOTAK 23 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(10.0,7.0,0.0);
    glVertex3f(10.0,6.0,0.0);
    glVertex3f(10.0,6.0,-1.0);
    glVertex3f(10.0,7.0,-1.0);
    glEnd();

    ///KOTAK 23 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(8.0,7.0,0.0);
    glVertex3f(10.0,7.0,0.0);
    glVertex3f(10.0,7.0,-1.0);
    glVertex3f(8.0,7.0,-1.0);
    glEnd();

    ///KOTAK 23 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(8.0,6.0,0.0);
    glVertex3f(10.0,6.0,0.0);
    glVertex3f(10.0,6.0,-1.0);
    glVertex3f(8.0,6.0,-1.0);
    glEnd();

    ///----------------------------------------------------------

    ///KOTAK 24 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(8.0,6.0,0.0);
    glVertex3f(8.0,3.0,0.0);
    glVertex3f(9.0,3.0,0.0);
    glVertex3f(9.0,6.0,0.0);
    glEnd();

    ///KOTAK 24 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(8.0,6.0,-1.0);
    glVertex3f(8.0,3.0,-1.0);
    glVertex3f(9.0,3.0,-1.0);
    glVertex3f(9.0,6.0,-1.0);
    glEnd();

    ///KOTAK 24 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(8.0,6.0,0.0);
    glVertex3f(8.0,3.0,0.0);
    glVertex3f(8.0,3.0,-1.0);
    glVertex3f(8.0,6.0,-1.0);
    glEnd();

    ///KOTAK 24 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(9.0,6.0,0.0);
    glVertex3f(9.0,3.0,0.0);
    glVertex3f(9.0,3.0,-1.0);
    glVertex3f(9.0,6.0,-1.0);
    glEnd();

    ///KOTAK 24 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(8.0,6.0,0.0);
    glVertex3f(9.0,6.0,0.0);
    glVertex3f(9.0,6.0,-1.0);
    glVertex3f(8.0,6.0,-1.0);
    glEnd();

    ///KOTAK 24 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(8.0,3.0,0.0);
    glVertex3f(9.0,3.0,0.0);
    glVertex3f(9.0,3.0,-1.0);
    glVertex3f(8.0,3.0,-1.0);
    glEnd();

    ///---------------------------------------------------------------------

    ///KOTAK 25 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(7.0,3.0,0.0);
    glVertex3f(7.0,2.0,0.0);
    glVertex3f(9.0,2.0,0.0);
    glVertex3f(9.0,3.0,0.0);
    glEnd();

    ///KOTAK 25 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(7.0,3.0,-1.0);
    glVertex3f(7.0,2.0,-1.0);
    glVertex3f(9.0,2.0,-1.0);
    glVertex3f(9.0,3.0,-1.0);
    glEnd();

    ///KOTAK 25 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(7.0,3.0,0.0);
    glVertex3f(7.0,2.0,0.0);
    glVertex3f(7.0,2.0,-1.0);
    glVertex3f(7.0,3.0,-1.0);
    glEnd();

    ///KOTAK 25 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(9.0,3.0,0.0);
    glVertex3f(9.0,2.0,0.0);
    glVertex3f(9.0,2.0,-1.0);
    glVertex3f(9.0,3.0,-1.0);
    glEnd();

    ///KOTAK 25 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(7.0,3.0,0.0);
    glVertex3f(9.0,3.0,0.0);
    glVertex3f(9.0,3.0,-1.0);
    glVertex3f(7.0,3.0,-1.0);
    glEnd();

    ///KOTAK 25 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(7.0,2.0,0.0);
    glVertex3f(9.0,2.0,0.0);
    glVertex3f(9.0,2.0,-1.0);
    glVertex3f(7.0,2.0,-1.0);
    glEnd();

    ///------------------------------------------------------------------

    ///KOTAK 26 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(6.0,3.0,0.0);
    glVertex3f(6.0,1.0,0.0);
    glVertex3f(7.0,1.0,0.0);
    glVertex3f(7.0,3.0,0.0);
    glEnd();

    ///KOTAK 26 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(6.0,3.0,-1.0);
    glVertex3f(6.0,1.0,-1.0);
    glVertex3f(7.0,1.0,-1.0);
    glVertex3f(7.0,3.0,-1.0);
    glEnd();

    ///KOTAK 26 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(6.0,3.0,0.0);
    glVertex3f(6.0,1.0,0.0);
    glVertex3f(6.0,1.0,-1.0);
    glVertex3f(6.0,3.0,-1.0);
    glEnd();

    ///KOTAK 26 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(7.0,3.0,0.0);
    glVertex3f(7.0,1.0,0.0);
    glVertex3f(7.0,1.0,-1.0);
    glVertex3f(7.0,3.0,-1.0);
    glEnd();

    ///KOTAK 26 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(6.0,3.0,0.0);
    glVertex3f(7.0,3.0,0.0);
    glVertex3f(7.0,3.0,-1.0);
    glVertex3f(6.0,3.0,-1.0);
    glEnd();

    ///KOTAK 26 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(6.0,1.0,0.0);
    glVertex3f(7.0,1.0,0.0);
    glVertex3f(7.0,1.0,-1.0);
    glVertex3f(6.0,1.0,-1.0);
    glEnd();

    ///-------------------------------------------------------------------

    ///KOTAK 27 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(12.0,14.0,0.0);
    glVertex3f(12.0,12.0,0.0);
    glVertex3f(13.0,12.0,0.0);
    glVertex3f(13.0,14.0,0.0);
    glEnd();

    ///KOTAK 27 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(12.0,14.0,-1.0);
    glVertex3f(12.0,12.0,-1.0);
    glVertex3f(13.0,12.0,-1.0);
    glVertex3f(13.0,14.0,-1.0);
    glEnd();

    ///KOTAK 27 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(12.0,14.0,0.0);
    glVertex3f(12.0,12.0,0.0);
    glVertex3f(12.0,12.0,-1.0);
    glVertex3f(12.0,14.0,-1.0);
    glEnd();

    ///KOTAK 27 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(13.0,14.0,0.0);
    glVertex3f(13.0,12.0,0.0);
    glVertex3f(13.0,12.0,-1.0);
    glVertex3f(13.0,14.0,-1.0);
    glEnd();

    ///KOTAK 27 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(12.0,14.0,0.0);
    glVertex3f(13.0,14.0,0.0);
    glVertex3f(13.0,14.0,-1.0);
    glVertex3f(12.0,14.0,-1.0);
    glEnd();

    ///KOTAK 27 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(12.0,12.0,0.0);
    glVertex3f(13.0,12.0,0.0);
    glVertex3f(13.0,12.0,-1.0);
    glVertex3f(12.0,12.0,-1.0);
    glEnd();

    ///--------------------------------------------------------------------

    ///KOTAK 28 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(10.0,13.0,0.0);
    glVertex3f(10.0,10.0,0.0);
    glVertex3f(11.0,10.0,0.0);
    glVertex3f(11.0,13.0,0.0);
    glEnd();

    ///KOTAK 28 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(10.0,13.0,-1.0);
    glVertex3f(10.0,10.0,-1.0);
    glVertex3f(11.0,10.0,-1.0);
    glVertex3f(11.0,13.0,-1.0);
    glEnd();

    ///KOTAK 28 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(10.0,13.0,0.0);
    glVertex3f(10.0,10.0,0.0);
    glVertex3f(10.0,10.0,-1.0);
    glVertex3f(10.0,13.0,-1.0);
    glEnd();

    ///KOTAK 28 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(11.0,13.0,0.0);
    glVertex3f(11.0,10.0,0.0);
    glVertex3f(11.0,10.0,-1.0);
    glVertex3f(11.0,13.0,-1.0);
    glEnd();

    ///KOTAK 28 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(10.0,13.0,0.0);
    glVertex3f(11.0,13.0,0.0);
    glVertex3f(11.0,13.0,-1.0);
    glVertex3f(10.0,13.0,-1.0);
    glEnd();

    ///KOTAK 28 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(10.0,10.0,0.0);
    glVertex3f(11.0,10.0,0.0);
    glVertex3f(11.0,10.0,-1.0);
    glVertex3f(10.0,10.0,-1.0);
    glEnd();

    ///--------------------------------------------------------------------

    ///KOTAK 29 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(11.0,11.0,0.0);
    glVertex3f(11.0,10.0,0.0);
    glVertex3f(13.0,10.0,0.0);
    glVertex3f(13.0,11.0,0.0);
    glEnd();

    ///KOTAK 29 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(11.0,11.0,-1.0);
    glVertex3f(11.0,10.0,-1.0);
    glVertex3f(13.0,10.0,-1.0);
    glVertex3f(13.0,11.0,-1.0);
    glEnd();

    ///KOTAK 29 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(11.0,11.0,0.0);
    glVertex3f(11.0,10.0,0.0);
    glVertex3f(10.0,10.0,-1.0);
    glVertex3f(10.0,11.0,-1.0);
    glEnd();

    ///KOTAK 29 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(13.0,11.0,0.0);
    glVertex3f(13.0,10.0,0.0);
    glVertex3f(13.0,10.0,-1.0);
    glVertex3f(13.0,11.0,-1.0);
    glEnd();

    ///KOTAK 29 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(11.0,11.0,0.0);
    glVertex3f(13.0,11.0,0.0);
    glVertex3f(13.0,11.0,-1.0);
    glVertex3f(11.0,11.0,-1.0);
    glEnd();

    ///KOTAK 29 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(11.0,10.0,0.0);
    glVertex3f(13.0,10.0,0.0);
    glVertex3f(13.0,10.0,-1.0);
    glVertex3f(11.0,10.0,-1.0);
    glEnd();

    ///-------------------------------------------------------------------------

    ///KOTAK 30 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(12.0,10.0,0.0);
    glVertex3f(12.0,2.0,0.0);
    glVertex3f(13.0,2.0,0.0);
    glVertex3f(13.0,10.0,0.0);
    glEnd();

    ///KOTAK 30 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(12.0,10.0,-1.0);
    glVertex3f(12.0,2.0,-1.0);
    glVertex3f(13.0,2.0,-1.0);
    glVertex3f(13.0,10.0,-1.0);
    glEnd();

    ///KOTAK 30 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(12.0,10.0,0.0);
    glVertex3f(12.0,2.0,0.0);
    glVertex3f(12.0,2.0,-1.0);
    glVertex3f(12.0,10.0,-1.0);
    glEnd();

    ///KOTAK 30 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(13.0,10.0,0.0);
    glVertex3f(13.0,2.0,0.0);
    glVertex3f(13.0,2.0,-1.0);
    glVertex3f(13.0,10.0,-1.0);
    glEnd();

    ///KOTAK 30 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(12.0,10.0,0.0);
    glVertex3f(13.0,10.0,0.0);
    glVertex3f(13.0,10.0,-1.0);
    glVertex3f(12.0,10.0,-1.0);
    glEnd();

    ///KOTAK 30 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(12.0,2.0,0.0);
    glVertex3f(13.0,2.0,0.0);
    glVertex3f(13.0,2.0,-1.0);
    glVertex3f(12.0,2.0,-1.0);
    glEnd();

    ///---------------------------------------------------------------------

    ///KOTAK 31 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(10.0,5.0,0.0);
    glVertex3f(10.0,4.0,0.0);
    glVertex3f(12.0,4.0,0.0);
    glVertex3f(12.0,5.0,0.0);
    glEnd();

    ///KOTAK 31 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(10.0,5.0,-1.0);
    glVertex3f(10.0,4.0,-1.0);
    glVertex3f(12.0,4.0,-1.0);
    glVertex3f(12.0,5.0,-1.0);
    glEnd();

    ///KOTAK 31 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(10.0,5.0,0.0);
    glVertex3f(10.0,4.0,0.0);
    glVertex3f(10.0,4.0,-1.0);
    glVertex3f(10.0,5.0,-1.0);
    glEnd();

    ///KOTAK 31 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(10.0,5.0,0.0);
    glVertex3f(12.0,5.0,0.0);
    glVertex3f(12.0,5.0,-1.0);
    glVertex3f(10.0,5.0,-1.0);
    glEnd();

    ///KOTAK 31 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(10.0,4.0,0.0);
    glVertex3f(12.0,4.0,0.0);
    glVertex3f(12.0,4.0,-1.0);
    glVertex3f(10.0,4.0,-1.0);
    glEnd();

    ///---------------------------------------------------------------------------

    ///KOTAK 32 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(10.0,4.0,0.0);
    glVertex3f(10.0,1.0,0.0);
    glVertex3f(11.0,1.0,0.0);
    glVertex3f(11.0,4.0,0.0);
    glEnd();

    ///KOTAK 32 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(10.0,4.0,-1.0);
    glVertex3f(10.0,1.0,-1.0);
    glVertex3f(11.0,1.0,-1.0);
    glVertex3f(11.0,4.0,-1.0);
    glEnd();

    ///KOTAK 32 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(10.0,4.0,0.0);
    glVertex3f(10.0,1.0,0.0);
    glVertex3f(10.0,1.0,-1.0);
    glVertex3f(10.0,4.0,-1.0);
    glEnd();

    ///KOTAK 32 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(11.0,4.0,0.0);
    glVertex3f(11.0,1.0,0.0);
    glVertex3f(11.0,1.0,-1.0);
    glVertex3f(11.0,4.0,-1.0);
    glEnd();

    ///KOTAK 32 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(10.0,4.0,0.0);
    glVertex3f(11.0,4.0,0.0);
    glVertex3f(11.0,4.0,-1.0);
    glVertex3f(10.0,4.0,-1.0);
    glEnd();

    ///KOTAK 32 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(10.0,1.0,0.0);
    glVertex3f(11.0,1.0,0.0);
    glVertex3f(11.0,1.0,-1.0);
    glVertex3f(10.0,1.0,-1.0);
    glEnd();
}

void map2(){
   ///KOTAK 1(DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(0.0,15.0,0.0);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(1.0,0.0,0.0);
    glVertex3f(1.0,15.0,0.0);
    glEnd();

    ///KOTAK 1 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(0.0,15.0,-1.0);
    glVertex3f(0.0,0.0,-1.0);
    glVertex3f(1.0,0.0,-1.0);
    glVertex3f(1.0,15.0,-1.0);
    glEnd();

    ///KOTAK 1 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(0.0,15.0,0.0);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.0,0.0,-1.0);
    glVertex3f(0.0,15.0,-1.0);
    glEnd();

    ///KOTAK 1(KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(1.0,0.0,0.0);
    glVertex3f(1.0,15.0,0.0);
    glVertex3f(1.0,15.0,-1.0);
    glVertex3f(1.0,0.0,-1.0);
    glEnd();

    ///KOTAK 1 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(0.0,15.0,0.0);
    glVertex3f(1.0,15.0,0.0);
    glVertex3f(1.0,15.0,-1.0);
    glVertex3f(0.0,15.0,-1.0);
    glEnd();

    ///KOTAK 1 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(1.0,0.0,0.0);
    glVertex3f(1.0,0.0,-1.0);
    glVertex3f(0.0,0.0,-1.0);
    glEnd();

    ///---------------------------------------------------------------------------------------------

    ///KOTAK 2 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(1.0,15.0,0.0);
    glVertex3f(1.0,14.0,0.0);
    glVertex3f(7.0,14.0,0.0);
    glVertex3f(7.0,15.0,0.0);
    glEnd();

    ///KOTAK 2 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(1.0,15.0,-1.0);
    glVertex3f(1.0,14.0,-1.0);
    glVertex3f(7.0,14.0,-1.0);
    glVertex3f(7.0,15.0,-1.0);
    glEnd();

    ///KOTAK 2 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(1.0,15.0,0.0);
    glVertex3f(1.0,14.0,0.0);
    glVertex3f(1.0,14.0,-1.0);
    glVertex3f(1.0,15.0,-1.0);
    glEnd();

    ///KOTAK 2 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(7.0,14.0,0.0);
    glVertex3f(7.0,15.0,0.0);
    glVertex3f(7.0,15.0,-1.0);
    glVertex3f(7.0,14.0,-1.0);
    glEnd();

    ///KOTAK 2 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(1.0,15.0,0.0);
    glVertex3f(7.0,15.0,0.0);
    glVertex3f(7.0,15.0,-1.0);
    glVertex3f(1.0,15.0,-1.0);
    glEnd();

    ///KOTAK 2 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(1.0,14.0,0.0);
    glVertex3f(7.0,14.0,0.0);
    glVertex3f(7.0,14.0,-1.0);
    glVertex3f(1.0,14.0,-1.0);
    glEnd();

    ///--------------------------------------------------------------

    ///KOTAK 3 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(8.0,15.0,0.0);
    glVertex3f(8.0,14.0,0.0);
    glVertex3f(14.0,14.0,0.0);
    glVertex3f(14.0,15.0,0.0);
    glEnd();

    ///KOTAK 3 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(8.0,15.0,-1.0);
    glVertex3f(8.0,14.0,-1.0);
    glVertex3f(14.0,14.0,-1.0);
    glVertex3f(14.0,15.0,-1.0);
    glEnd();

    ///KOTAK 3 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(8.0,15.0,0.0);
    glVertex3f(8.0,14.0,0.0);
    glVertex3f(8.0,14.0,-1.0);
    glVertex3f(8.0,15.0,-1.0);
    glEnd();

    ///KOTAK 3 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(14.0,14.0,0.0);
    glVertex3f(14.0,15.0,0.0);
    glVertex3f(14.0,15.0,-1.0);
    glVertex3f(14.0,14.0,-1.0);
    glEnd();

    ///KOTAK 3 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(8.0,15.0,0.0);
    glVertex3f(14.0,15.0,0.0);
    glVertex3f(14.0,15.0,-1.0);
    glVertex3f(8.0,15.0,-1.0);
    glEnd();

    ///KOTAK 3 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(8.0,14.0,0.0);
    glVertex3f(14.0,14.0,0.0);
    glVertex3f(14.0,14.0,-1.0);
    glVertex3f(8.0,14.0,-1.0);
    glEnd();

    ///-------------------------------------------------------------------------

    ///KOTAK 4 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(14.0,15.0,0.0);
    glVertex3f(14.0,0.0,0.0);
    glVertex3f(15.0,0.0,0.0);
    glVertex3f(15.0,15.0,0.0);
    glEnd();

    ///KOTAK 4 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(14.0,15.0,-1.0);
    glVertex3f(14.0,0.0,-1.0);
    glVertex3f(15.0,0.0,-1.0);
    glVertex3f(15.0,15.0,-1.0);
    glEnd();

    ///KOTAK 4 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(14.0,15.0,0.0);
    glVertex3f(14.0,0.0,0.0);
    glVertex3f(14.0,0.0,-1.0);
    glVertex3f(14.0,15.0,-1.0);
    glEnd();

    ///KOTAK 4 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(15.0,15.0,0.0);
    glVertex3f(15.0,0.0,0.0);
    glVertex3f(15.0,0.0,-1.0);
    glVertex3f(15.0,15.0,-1.0);
    glEnd();

    ///KOTAK 4 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(14.0,15.0,0.0);
    glVertex3f(15.0,15.0,0.0);
    glVertex3f(15.0,15.0,-1.0);
    glVertex3f(14.0,15.0,-1.0);
    glEnd();

    ///KOTAK 4 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(14.0,0.0,0.0);
    glVertex3f(15.0,0.0,0.0);
    glVertex3f(15.0,0.0,-1.0);
    glVertex3f(14.0,0.0,-1.0);
    glEnd();

    ///------------------------------------------------------------

    ///KOTAK 5 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(8.0,1.0,0.0);
    glVertex3f(8.0,0.0,0.0);
    glVertex3f(14.0,0.0,0.0);
    glVertex3f(14.0,1.0,0.0);
    glEnd();

    ///KOTAK 5 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(8.0,1.0,-1.0);
    glVertex3f(8.0,0.0,-1.0);
    glVertex3f(14.0,0.0,-1.0);
    glVertex3f(14.0,1.0,-1.0);
    glEnd();

    ///KOTAK 5 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(8.0,1.0,0.0);
    glVertex3f(8.0,0.0,0.0);
    glVertex3f(8.0,0.0,-1.0);
    glVertex3f(8.0,1.0,-1.0);
    glEnd();

    ///KOTAK 5 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(14.0,0.0,0.0);
    glVertex3f(14.0,1.0,0.0);
    glVertex3f(14.0,1.0,-1.0);
    glVertex3f(14.0,0.0,-1.0);
    glEnd();

    ///KOTAK 5 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(8.0,1.0,0.0);
    glVertex3f(14.0,1.0,0.0);
    glVertex3f(14.0,1.0,-1.0);
    glVertex3f(8.0,1.0,-1.0);
    glEnd();

    ///KOTAK 5 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(8.0,0.0,0.0);
    glVertex3f(14.0,0.0,0.0);
    glVertex3f(14.0,0.0,-1.0);
    glVertex3f(8.0,0.0,-1.0);
    glEnd();

    ///---------------------------------------------------------------

    ///KOTAK 6 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(1.0,1.0,0.0);
    glVertex3f(1.0,0.0,0.0);
    glVertex3f(7.0,0.0,0.0);
    glVertex3f(7.0,1.0,0.0);
    glEnd();

    ///KOTAK 6 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(1.0,1.0,-1.0);
    glVertex3f(1.0,0.0,-1.0);
    glVertex3f(7.0,0.0,-1.0);
    glVertex3f(7.0,1.0,-1.0);
    glEnd();

    ///KOTAK 6 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(1.0,1.0,0.0);
    glVertex3f(1.0,0.0,0.0);
    glVertex3f(1.0,0.0,-1.0);
    glVertex3f(1.0,1.0,-1.0);
    glEnd();

    ///KOTAK 6 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(7.0,1.0,0.0);
    glVertex3f(7.0,0.0,0.0);
    glVertex3f(7.0,0.0,-1.0);
    glVertex3f(7.0,1.0,-1.0);
    glEnd();

    ///KOTAK 6 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(1.0,1.0,0.0);
    glVertex3f(7.0,1.0,0.0);
    glVertex3f(7.0,1.0,-1.0);
    glVertex3f(1.0,1.0,-1.0);
    glEnd();

    ///KOTAK 6 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(1.0,0.0,0.0);
    glVertex3f(7.0,0.0,0.0);
    glVertex3f(7.0,0.0,-1.0);
    glVertex3f(1.0,0.0,-1.0);
    glEnd();

    ///------------------------------------------------------------------

    ///KOTAK 7 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(1.0,9.0,0.0);
    glVertex3f(1.0,8.0,0.0);
    glVertex3f(3.0,8.0,0.0);
    glVertex3f(3.0,9.0,0.0);
    glEnd();

    ///KOTAK 7 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(1.0,9.0,-1.0);
    glVertex3f(1.0,8.0,-1.0);
    glVertex3f(3.0,8.0,-1.0);
    glVertex3f(3.0,9.0,-1.0);
    glEnd();

    ///KOTAK 7 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(1.0,9.0,0.0);
    glVertex3f(1.0,8.0,0.0);
    glVertex3f(1.0,8.0,-1.0);
    glVertex3f(1.0,9.0,-1.0);
    glEnd();

    ///KOTAK 7 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(3.0,9.0,0.0);
    glVertex3f(3.0,8.0,0.0);
    glVertex3f(3.0,8.0,-1.0);
    glVertex3f(3.0,9.0,-1.0);
    glEnd();

    ///KOTAK 7 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(1.0,9.0,0.0);
    glVertex3f(3.0,9.0,0.0);
    glVertex3f(3.0,9.0,-1.0);
    glVertex3f(1.0,9.0,-1.0);
    glEnd();

    ///KOTAK 7 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(1.0,8.0,0.0);
    glVertex3f(3.0,8.0,0.0);
    glVertex3f(3.0,8.0,-1.0);
    glVertex3f(1.0,8.0,-1.0);
    glEnd();

    ///-----------------------------------------------------------------

    ///KOTAK 8 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(2.0,14.0,0.0);
    glVertex3f(2.0,10.0,0.0);
    glVertex3f(3.0,10.0,0.0);
    glVertex3f(3.0,14.0,0.0);
    glEnd();

    ///KOTAK 8 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(2.0,14.0,-1.0);
    glVertex3f(2.0,10.0,-1.0);
    glVertex3f(3.0,10.0,-1.0);
    glVertex3f(3.0,14.0,-1.0);
    glEnd();

    ///KOTAK 8 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(2.0,14.0,0.0);
    glVertex3f(2.0,10.0,0.0);
    glVertex3f(2.0,10.0,-1.0);
    glVertex3f(2.0,14.0,-1.0);
    glEnd();

    ///KOTAK 8 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(3.0,14.0,0.0);
    glVertex3f(3.0,10.0,0.0);
    glVertex3f(3.0,10.0,-1.0);
    glVertex3f(3.0,14.0,-1.0);
    glEnd();

    ///KOTAK 8 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(2.0,14.0,0.0);
    glVertex3f(3.0,14.0,0.0);
    glVertex3f(3.0,14.0,-1.0);
    glVertex3f(2.0,14.0,-1.0);
    glEnd();

    ///KOTAK 8 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(2.0,10.0,0.0);
    glVertex3f(3.0,10.0,0.0);
    glVertex3f(3.0,10.0,-1.0);
    glVertex3f(2.0,10.0,-1.0);
    glEnd();

    ///-------------------------------------------------------------------

    ///KOTAK 9 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(4.0,13.0,0.0);
    glVertex3f(4.0,7.0,0.0);
    glVertex3f(5.0,7.0,0.0);
    glVertex3f(5.0,13.0,0.0);
    glEnd();

    ///KOTAK 9 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(4.0,13.0,-1.0);
    glVertex3f(4.0,7.0,-1.0);
    glVertex3f(5.0,7.0,-1.0);
    glVertex3f(5.0,13.0,-1.0);
    glEnd();

    ///KOTAK 9 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(4.0,13.0,0.0);
    glVertex3f(4.0,7.0,0.0);
    glVertex3f(4.0,7.0,-1.0);
    glVertex3f(4.0,13.0,-1.0);
    glEnd();

    ///KOTAK 9 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(5.0,13.0,0.0);
    glVertex3f(5.0,7.0,0.0);
    glVertex3f(5.0,7.0,-1.0);
    glVertex3f(5.0,13.0,-1.0);
    glEnd();

    ///KOTAK 9 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(4.0,13.0,0.0);
    glVertex3f(5.0,13.0,0.0);
    glVertex3f(5.0,13.0,-1.0);
    glVertex3f(4.0,13.0,-1.0);
    glEnd();

    ///KOTAK 9 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(5.0,7.0,0.0);
    glVertex3f(4.0,7.0,0.0);
    glVertex3f(4.0,7.0,-1.0);
    glVertex3f(5.0,7.0,-1.0);
    glEnd();

    ///-----------------------------------------------------------------

    ///KOTAK 10 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(1.0,7.0,0.0);
    glVertex3f(1.0,6.0,0.0);
    glVertex3f(13.0,6.0,0.0);
    glVertex3f(13.0,7.0,0.0);
    glEnd();

    ///KOTAK 10 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(1.0,7.0,-1.0);
    glVertex3f(1.0,6.0,-1.0);
    glVertex3f(13.0,6.0,-1.0);
    glVertex3f(13.0,7.0,-1.0);
    glEnd();

    ///KOTAK 10 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(1.0,7.0,0.0);
    glVertex3f(1.0,6.0,0.0);
    glVertex3f(1.0,6.0,-1.0);
    glVertex3f(1.0,7.0,-1.0);
    glEnd();

    ///KOTAK 10 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(13.0,6.0,0.0);
    glVertex3f(13.0,7.0,0.0);
    glVertex3f(13.0,7.0,-1.0);
    glVertex3f(13.0,6.0,-1.0);
    glEnd();

    ///KOTAK 10 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(1.0,7.0,0.0);
    glVertex3f(13.0,7.0,0.0);
    glVertex3f(13.0,7.0,-1.0);
    glVertex3f(1.0,7.0,-1.0);
    glEnd();

    ///KOTAK 10 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(1.0,6.0,0.0);
    glVertex3f(13.0,6.0,0.0);
    glVertex3f(13.0,6.0,-1.0);
    glVertex3f(1.0,6.0,-1.0);
    glEnd();

    ///--------------------------------------------------------------------

    ///KOTAK 11 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(2.0,5.0,0.0);
    glVertex3f(2.0,3.0,0.0);
    glVertex3f(3.0,3.0,0.0);
    glVertex3f(3.0,5.0,0.0);
    glEnd();

    ///KOTAK 11 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(2.0,5.0,-1.0);
    glVertex3f(2.0,3.0,-1.0);
    glVertex3f(3.0,3.0,-1.0);
    glVertex3f(3.0,5.0,-1.0);
    glEnd();

    ///KOTAK 11 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(2.0,5.0,0.0);
    glVertex3f(2.0,3.0,0.0);
    glVertex3f(2.0,3.0,-1.0);
    glVertex3f(2.0,5.0,-1.0);
    glEnd();

    ///KOTAK 11 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(3.0,3.0,0.0);
    glVertex3f(3.0,5.0,0.0);
    glVertex3f(3.0,5.0,-1.0);
    glVertex3f(3.0,3.0,-1.0);
    glEnd();

    ///KOTAK 11 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(2.0,5.0,0.0);
    glVertex3f(3.0,5.0,0.0);
    glVertex3f(3.0,5.0,-1.0);
    glVertex3f(2.0,5.0,-1.0);
    glEnd();

    ///KOTAK 11 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(2.0,3.0,0.0);
    glVertex3f(3.0,3.0,0.0);
    glVertex3f(3.0,3.0,-1.0);
    glVertex3f(2.0,3.0,-1.0);
    glEnd();

    ///--------------------------------------------------------------------

    ///KOTAK 12 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(2.0,3.0,0.0);
    glVertex3f(2.0,2.0,0.0);
    glVertex3f(5.0,2.0,0.0);
    glVertex3f(5.0,3.0,0.0);
    glEnd();

    ///KOTAK 12 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(2.0,3.0,-1.0);
    glVertex3f(2.0,2.0,-1.0);
    glVertex3f(5.0,2.0,-1.0);
    glVertex3f(5.0,3.0,-1.0);
    glEnd();

    ///KOTAK 12 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(2.0,3.0,0.0);
    glVertex3f(2.0,2.0,0.0);
    glVertex3f(2.0,2.0,-1.0);
    glVertex3f(2.0,3.0,-1.0);
    glEnd();

    ///KOTAK 12 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(5.0,3.0,0.0);
    glVertex3f(5.0,2.0,0.0);
    glVertex3f(5.0,2.0,-1.0);
    glVertex3f(5.0,3.0,-1.0);
    glEnd();

    ///KOTAK 12 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(2.0,3.0,0.0);
    glVertex3f(5.0,3.0,0.0);
    glVertex3f(5.0,3.0,-1.0);
    glVertex3f(2.0,3.0,-1.0);
    glEnd();

    ///KOTAK 12 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(2.0,2.0,0.0);
    glVertex3f(5.0,2.0,0.0);
    glVertex3f(5.0,2.0,-1.0);
    glVertex3f(2.0,2.0,-1.0);
    glEnd();

    ///------------------------------------------------------------------

    ///KOTAK 13 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(4.0,5.0,0.0);
    glVertex3f(4.0,3.0,0.0);
    glVertex3f(5.0,3.0,0.0);
    glVertex3f(5.0,5.0,0.0);
    glEnd();

    ///KOTAK 13 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(4.0,5.0,-1.0);
    glVertex3f(4.0,3.0,-1.0);
    glVertex3f(5.0,3.0,-1.0);
    glVertex3f(5.0,5.0,-1.0);
    glEnd();

    ///KOTAK 13 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(4.0,5.0,0.0);
    glVertex3f(4.0,3.0,0.0);
    glVertex3f(4.0,3.0,-1.0);
    glVertex3f(4.0,5.0,-1.0);
    glEnd();

    ///KOTAK 13 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(5.0,3.0,0.0);
    glVertex3f(5.0,5.0,0.0);
    glVertex3f(5.0,5.0,-1.0);
    glVertex3f(5.0,3.0,-1.0);
    glEnd();

    ///KOTAK 13 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(4.0,5.0,0.0);
    glVertex3f(5.0,5.0,0.0);
    glVertex3f(5.0,5.0,-1.0);
    glVertex3f(4.0,5.0,-1.0);
    glEnd();

    ///KOTAK 13 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(4.0,3.0,0.0);
    glVertex3f(5.0,3.0,0.0);
    glVertex3f(5.0,3.0,-1.0);
    glVertex3f(4.0,3.0,-1.0);
    glEnd();

    ///-----------------------------------------------------------------

    ///KOTAK 14 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(5.0,5.0,0.0);
    glVertex3f(5.0,4.0,0.0);
    glVertex3f(11.0,4.0,0.0);
    glVertex3f(11.0,5.0,0.0);
    glEnd();

    ///KOTAK 14 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(5.0,5.0,-1.0);
    glVertex3f(5.0,4.0,-1.0);
    glVertex3f(11.0,4.0,-1.0);
    glVertex3f(11.0,5.0,-1.0);
    glEnd();

    ///KOTAK 14 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(5.0,5.0,0.0);
    glVertex3f(5.0,4.0,0.0);
    glVertex3f(5.0,4.0,-1.0);
    glVertex3f(5.0,5.0,-1.0);
    glEnd();

    ///KOTAK 14 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(11.0,5.0,0.0);
    glVertex3f(11.0,4.0,0.0);
    glVertex3f(11.0,4.0,-1.0);
    glVertex3f(11.0,5.0,-1.0);
    glEnd();

    ///KOTAK 14 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(5.0,5.0,0.0);
    glVertex3f(11.0,5.0,0.0);
    glVertex3f(11.0,5.0,-1.0);
    glVertex3f(5.0,5.0,-1.0);
    glEnd();

    ///KOTAK 14 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(5.0,4.0,0.0);
    glVertex3f(11.0,4.0,0.0);
    glVertex3f(11.0,4.0,-1.0);
    glVertex3f(5.0,4.0,-1.0);
    glEnd();

    ///-------------------------------------------------------------------

    ///KOTAK 15 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(10.0,4.0,0.0);
    glVertex3f(10.0,1.0,0.0);
    glVertex3f(11.0,1.0,0.0);
    glVertex3f(11.0,4.0,0.0);
    glEnd();

    ///KOTAK 15 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(10.0,4.0,-1.0);
    glVertex3f(10.0,1.0,-1.0);
    glVertex3f(11.0,1.0,-1.0);
    glVertex3f(11.0,4.0,-1.0);
    glEnd();

    ///KOTAK 15 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(10.0,4.0,0.0);
    glVertex3f(10.0,1.0,0.0);
    glVertex3f(10.0,1.0,-1.0);
    glVertex3f(10.0,4.0,-1.0);
    glEnd();

    ///KOTAK 15 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(11.0,4.0,0.0);
    glVertex3f(11.0,1.0,0.0);
    glVertex3f(11.0,1.0,-1.0);
    glVertex3f(11.0,4.0,-1.0);
    glEnd();

    ///KOTAK 15 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(10.0,4.0,0.0);
    glVertex3f(11.0,4.0,0.0);
    glVertex3f(11.0,4.0,-1.0);
    glVertex3f(10.0,4.0,-1.0);
    glEnd();

    ///KOTAK 15 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(10.0,1.0,0.0);
    glVertex3f(11.0,1.0,0.0);
    glVertex3f(11.0,1.0,-1.0);
    glVertex3f(10.0,1.0,-1.0);
    glEnd();

    ///-------------------------------------------------------------------

    ///KOTAK 16 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(7.0,3.0,0.0);
    glVertex3f(7.0,2.0,0.0);
    glVertex3f(9.0,2.0,0.0);
    glVertex3f(9.0,3.0,0.0);
    glEnd();

    ///KOTAK 16 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(7.0,3.0,-1.0);
    glVertex3f(7.0,2.0,-1.0);
    glVertex3f(9.0,2.0,-1.0);
    glVertex3f(9.0,3.0,-1.0);
    glEnd();

    ///KOTAK 16 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(7.0,3.0,0.0);
    glVertex3f(7.0,2.0,0.0);
    glVertex3f(7.0,2.0,-1.0);
    glVertex3f(7.0,3.0,-1.0);
    glEnd();

    ///KOTAK 16 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(9.0,3.0,0.0);
    glVertex3f(9.0,2.0,0.0);
    glVertex3f(9.0,2.0,-1.0);
    glVertex3f(9.0,3.0,-1.0);
    glEnd();

     ///KOTAK 16 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(7.0,3.0,0.0);
    glVertex3f(9.0,3.0,0.0);
    glVertex3f(9.0,3.0,-1.0);
    glVertex3f(7.0,3.0,-1.0);
    glEnd();

    ///KOTAK 16 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(7.0,2.0,0.0);
    glVertex3f(9.0,2.0,0.0);
    glVertex3f(9.0,2.0,-1.0);
    glVertex3f(7.0,2.0,-1.0);
    glEnd();

    ///--------------------------------------------------------------------

    ///KOTAK 17 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(6.0,3.0,0.0);
    glVertex3f(6.0,1.0,0.0);
    glVertex3f(7.0,1.0,0.0);
    glVertex3f(7.0,3.0,0.0);
    glEnd();

    ///KOTAK 17 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(6.0,3.0,-1.0);
    glVertex3f(6.0,1.0,-1.0);
    glVertex3f(7.0,1.0,-1.0);
    glVertex3f(7.0,3.0,-1.0);
    glEnd();

    ///KOTAK 17 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(6.0,3.0,0.0);
    glVertex3f(6.0,1.0,0.0);
    glVertex3f(6.0,1.0,-1.0);
    glVertex3f(6.0,3.0,-1.0);
    glEnd();

    ///KOTAK 17 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(7.0,3.0,0.0);
    glVertex3f(7.0,1.0,0.0);
    glVertex3f(7.0,1.0,-1.0);
    glVertex3f(7.0,3.0,-1.0);
    glEnd();

    ///KOTAK 17 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(6.0,3.0,0.0);
    glVertex3f(7.0,3.0,0.0);
    glVertex3f(7.0,3.0,-1.0);
    glVertex3f(6.0,3.0,-1.0);
    glEnd();

    ///KOTAK 17 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(6.0,1.0,0.0);
    glVertex3f(7.0,1.0,0.0);
    glVertex3f(7.0,1.0,-1.0);
    glVertex3f(6.0,1.0,-1.0);
    glEnd();

    ///-------------------------------------------------------------------

    ///KOTAK 18 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(12.0,6.0,0.0);
    glVertex3f(12.0,2.0,0.0);
    glVertex3f(13.0,2.0,0.0);
    glVertex3f(13.0,6.0,0.0);
    glEnd();

    ///KOTAK 18 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(12.0,6.0,-1.0);
    glVertex3f(12.0,2.0,-1.0);
    glVertex3f(13.0,2.0,-1.0);
    glVertex3f(13.0,6.0,-1.0);
    glEnd();

    ///KOTAK 18 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(12.0,6.0,0.0);
    glVertex3f(12.0,2.0,0.0);
    glVertex3f(12.0,2.0,-1.0);
    glVertex3f(12.0,6.0,-1.0);
    glEnd();

    ///KOTAK 18 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(13.0,6.0,0.0);
    glVertex3f(13.0,2.0,0.0);
    glVertex3f(13.0,2.0,-1.0);
    glVertex3f(13.0,6.0,-1.0);
    glEnd();

    ///KOTAK 18 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(12.0,6.0,0.0);
    glVertex3f(13.0,6.0,0.0);
    glVertex3f(13.0,6.0,-1.0);
    glVertex3f(12.0,6.0,-1.0);
    glEnd();

    ///KOTAK 18 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(12.0,2.0,0.0);
    glVertex3f(13.0,2.0,0.0);
    glVertex3f(13.0,2.0,-1.0);
    glVertex3f(12.0,2.0,-1.0);
    glEnd();

    ///------------------------------------------------------------------

    ///KOTAK 19 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(10.0,10.0,0.0);
    glVertex3f(10.0,7.0,0.0);
    glVertex3f(11.0,7.0,0.0);
    glVertex3f(11.0,10.0,0.0);
    glEnd();

    ///KOTAK 19 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(10.0,10.0,-1.0);
    glVertex3f(10.0,7.0,-1.0);
    glVertex3f(11.0,7.0,-1.0);
    glVertex3f(11.0,10.0,-1.0);
    glEnd();

    ///KOTAK 19 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(10.0,10.0,0.0);
    glVertex3f(10.0,7.0,0.0);
    glVertex3f(10.0,7.0,-1.0);
    glVertex3f(10.0,10.0,-1.0);
    glEnd();

    ///KOTAK 19 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(11.0,10.0,0.0);
    glVertex3f(11.0,7.0,0.0);
    glVertex3f(11.0,7.0,-1.0);
    glVertex3f(11.0,10.0,-1.0);
    glEnd();

    ///KOTAK 19 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(10.0,10.0,0.0);
    glVertex3f(11.0,10.0,0.0);
    glVertex3f(11.0,10.0,-1.0);
    glVertex3f(10.0,10.0,-1.0);
    glEnd();

    ///KOTAK 19 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(10.0,10.0,0.0);
    glVertex3f(11.0,7.0,0.0);
    glVertex3f(11.0,7.0,-1.0);
    glVertex3f(10.0,10.0,-1.0);
    glEnd();

    ///-----------------------------------------------------------------

    ///KOTAK 20 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(12.0,9.0,0.0);
    glVertex3f(12.0,8.0,0.0);
    glVertex3f(14.0,8.0,0.0);
    glVertex3f(14.0,9.0,0.0);
    glEnd();

    ///KOTAK 20 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(12.0,9.0,-1.0);
    glVertex3f(12.0,8.0,-1.0);
    glVertex3f(14.0,8.0,-1.0);
    glVertex3f(14.0,9.0,-1.0);
    glEnd();

    ///KOTAK 20 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(12.0,9.0,0.0);
    glVertex3f(12.0,8.0,0.0);
    glVertex3f(12.0,8.0,-1.0);
    glVertex3f(12.0,9.0,-1.0);
    glEnd();

    ///KOTAK 20 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(14.0,9.0,0.0);
    glVertex3f(14.0,8.0,0.0);
    glVertex3f(14.0,8.0,-1.0);
    glVertex3f(14.0,9.0,-1.0);
    glEnd();

    ///KOTAK 20 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(12.0,9.0,0.0);
    glVertex3f(14.0,9.0,0.0);
    glVertex3f(14.0,9.0,-1.0);
    glVertex3f(12.0,9.0,-1.0);
    glEnd();

    ///KOTAK 20 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(12.0,8.0,0.0);
    glVertex3f(14.0,8.0,0.0);
    glVertex3f(14.0,8.0,-1.0);
    glVertex3f(12.0,8.0,-1.0);
    glEnd();

    ///-------------------------------------------------------------------

    ///KOTAK 21 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(8.0,11.0,0.0);
    glVertex3f(8.0,10.0,0.0);
    glVertex3f(13.0,10.0,0.0);
    glVertex3f(13.0,11.0,0.0);
    glEnd();

    ///KOTAK 21 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(8.0,11.0,-1.0);
    glVertex3f(8.0,10.0,-1.0);
    glVertex3f(13.0,10.0,-1.0);
    glVertex3f(13.0,11.0,-1.0);
    glEnd();

    ///KOTAK 21 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(8.0,11.0,0.0);
    glVertex3f(8.0,10.0,0.0);
    glVertex3f(8.0,10.0,-1.0);
    glVertex3f(8.0,11.0,-1.0);
    glEnd();

    ///KOTAK 21 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(13.0,10.0,0.0);
    glVertex3f(13.0,11.0,0.0);
    glVertex3f(13.0,11.0,-1.0);
    glVertex3f(13.0,10.0,-1.0);
    glEnd();

    ///KOTAK 21 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(8.0,11.0,0.0);
    glVertex3f(13.0,11.0,0.0);
    glVertex3f(13.0,11.0,-1.0);
    glVertex3f(8.0,11.0,-1.0);
    glEnd();

    ///KOTAK 21 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(8.0,10.0,0.0);
    glVertex3f(13.0,10.0,0.0);
    glVertex3f(13.0,10.0,-1.0);
    glVertex3f(8.0,10.0,-1.0);
    glEnd();

    ///-----------------------------------------------------------------------

    ///KOTAK 22 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(7.0,13.0,0.0);
    glVertex3f(7.0,12.0,0.0);
    glVertex3f(13.0,12.0,0.0);
    glVertex3f(13.0,13.0,0.0);
    glEnd();

    ///KOTAK 22 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(7.0,13.0,-1.0);
    glVertex3f(7.0,12.0,-1.0);
    glVertex3f(13.0,12.0,-1.0);
    glVertex3f(13.0,13.0,-1.0);
    glEnd();

    ///KOTAK 22 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(7.0,13.0,0.0);
    glVertex3f(7.0,12.0,0.0);
    glVertex3f(7.0,12.0,-1.0);
    glVertex3f(7.0,13.0,-1.0);
    glEnd();

    ///KOTAK 22 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(13.0,12.0,0.0);
    glVertex3f(13.0,13.0,0.0);
    glVertex3f(13.0,13.0,-1.0);
    glVertex3f(13.0,12.0,-1.0);
    glEnd();

    ///KOTAK 22 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(7.0,13.0,0.0);
    glVertex3f(13.0,13.0,0.0);
    glVertex3f(13.0,13.0,-1.0);
    glVertex3f(7.0,13.0,-1.0);
    glEnd();

    ///KOTAK 22 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(7.0,12.0,0.0);
    glVertex3f(13.0,12.0,0.0);
    glVertex3f(13.0,12.0,-1.0);
    glVertex3f(7.0,12.0,-1.0);
    glEnd();

    ///----------------------------------------------------------------------

    ///KOTAK 23 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(6.0,14.0,0.0);
    glVertex3f(6.0,9.0,0.0);
    glVertex3f(7.0,9.0,0.0);
    glVertex3f(7.0,14.0,0.0);
    glEnd();

    ///KOTAK 23 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(6.0,14.0,-1.0);
    glVertex3f(6.0,9.0,-1.0);
    glVertex3f(7.0,9.0,-1.0);
    glVertex3f(7.0,14.0,-1.0);
    glEnd();

    ///KOTAK 23 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(6.0,14.0,0.0);
    glVertex3f(6.0,9.0,0.0);
    glVertex3f(6.0,9.0,-1.0);
    glVertex3f(6.0,14.0,-1.0);
    glEnd();

    ///KOTAK 23 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(7.0,14.0,0.0);
    glVertex3f(7.0,9.0,0.0);
    glVertex3f(7.0,9.0,-1.0);
    glVertex3f(7.0,14.0,-1.0);
    glEnd();

    ///KOTAK 23 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(6.0,14.0,0.0);
    glVertex3f(7.0,14.0,0.0);
    glVertex3f(7.0,14.0,-1.0);
    glVertex3f(6.0,14.0,-1.0);
    glEnd();

    ///KOTAK 23 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(6.0,9.0,0.0);
    glVertex3f(7.0,9.0,0.0);
    glVertex3f(7.0,9.0,-1.0);
    glVertex3f(6.0,9.0,-1.0);
    glEnd();

    ///----------------------------------------------------------------------

    ///KOTAK 24 (DEPAN)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(6.0,9.0,0.0);
    glVertex3f(6.0,8.0,0.0);
    glVertex3f(9.0,8.0,0.0);
    glVertex3f(9.0,9.0,0.0);
    glEnd();

    ///KOTAK 24 (BELAKANG)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(6.0,9.0,-1.0);
    glVertex3f(6.0,8.0,-1.0);
    glVertex3f(9.0,8.0,-1.0);
    glVertex3f(9.0,9.0,-1.0);
    glEnd();

    ///KOTAK 24 (KIRI)
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(6.0,9.0,0.0);
    glVertex3f(6.0,8.0,0.0);
    glVertex3f(6.0,8.0,-1.0);
    glVertex3f(6.0,9.0,-1.0);
    glEnd();

    ///KOTAK 24 (KANAN)
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(9.0,8.0,0.0);
    glVertex3f(9.0,9.0,0.0);
    glVertex3f(9.0,9.0,-1.0);
    glVertex3f(9.0,8.0,-1.0);
    glEnd();

    ///KOTAK 24 (ATAS)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(6.0,9.0,0.0);
    glVertex3f(9.0,9.0,0.0);
    glVertex3f(9.0,9.0,-1.0);
    glVertex3f(6.0,9.0,-1.0);
    glEnd();

    ///KOTAK 24 (BAWAH)
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    material(0.0,0.0,1.0,trans);
    glVertex3f(6.0,8.0,0.0);
    glVertex3f(9.0,8.0,0.0);
    glVertex3f(9.0,8.0,-1.0);
    glVertex3f(6.0,8.0,-1.0);
    glEnd();
}

void player(){
    ///DEPAN
    material(1,0.3,0,1.0);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(7.0+posX, 15.0+posY, 0.0);
    glVertex3f(7.0+posX, 14.0+posY, 0.0);
    glVertex3f(8.0+posX, 14.0+posY, 0.0);
    glVertex3f(8.0+posX, 15.0+posY, 0.0);
    glEnd();

    ///BELAKANG
    material(1,0.3,0,1.0);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    glVertex3f(7.0+posX, 15.0+posY, -1.0);
    glVertex3f(7.0+posX, 14.0+posY, -1.0);
    glVertex3f(8.0+posX, 14.0+posY, -1.0);
    glVertex3f(8.0+posX, 15.0+posY, -1.0);
    glEnd();

    ///KIRI
    material(1,0.3,0,1.0);
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    glVertex3f(7.0+posX, 15.0+posY, 0.0);
    glVertex3f(7.0+posX, 14.0+posY, 0.0);
    glVertex3f(7.0+posX, 14.0+posY, -1.0);
    glVertex3f(7.0+posX, 15.0+posY, -1.0);
    glEnd();

    ///KANAN
    material(1,0.3,0,1.0);
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    glVertex3f(8.0+posX, 15.0+posY, 0.0);
    glVertex3f(8.0+posX, 14.0+posY, 0.0);
    glVertex3f(8.0+posX, 14.0+posY, -1.0);
    glVertex3f(8.0+posX, 15.0+posY, -1.0);
    glEnd();

    ///ATAS
    material(1,0.3,0,1.0);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    glVertex3f(7.0+posX, 15.0+posY, 0.0);
    glVertex3f(8.0+posX, 15.0+posY, 0.0);
    glVertex3f(8.0+posX, 15.0+posY, -1.0);
    glVertex3f(7.0+posX, 15.0+posY, -1.0);
    glEnd();

    ///BAWAH
    material(1,0.3,0,1.0);
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    glVertex3f(7.0+posX, 14.0+posY, 0.0);
    glVertex3f(8.0+posX, 14.0+posY, 0.0);
    glVertex3f(8.0+posX, 14.0+posY, -1.0);
    glVertex3f(7.0+posX, 14.0+posY, -1.0);
    glEnd();
}

void pencahayaan(){
//    GLfloat light_position_amb[] = { 15.0, 15.0, 5.0, 0.6 };
    GLfloat ambient_light[] = { 0.9, 0.9, 0.9, 1.0 };

    GLfloat light_position_diff[] = { 1.0, 1.0, 1.0, 0.0 };
    GLfloat diffuse_light[] = { 1.0, 1.0, 1.0, 1.0 };

    GLfloat light_position_spec[] = { 10.0, 10.0, 10.0, 0.0 };
    GLfloat specular_light[] = { 1.0, 1.0, 1.0, 1.0 };

//    glLightfv(GL_LIGHT1, GL_POSITION, light_position_amb);
//    glLightfv(GL_LIGHT1, GL_AMBIENT, ambient_light);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambient_light);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position_diff);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);

    glLightfv(GL_LIGHT1, GL_POSITION, light_position_spec);
    glLightfv(GL_LIGHT1, GL_SPECULAR, specular_light);

    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glShadeModel (GL_SMOOTH);
    glEnable(GL_LIGHT0); ///diff
    glEnable(GL_LIGHT1); ///spec

}

void transparant(){
    material(0.5, 0.5, 0.5, 0.5);
    ///DEPAN
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    glVertex3f(0.0,15.0,-1.01);
    glVertex3f(0.0,0.0,-1.01);
    glVertex3f(15.0,0.0,-1.01);
    glVertex3f(15.0,15.0,-1.01);
    glEnd();

    ///BELAKANG
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,-1.0);
    glVertex3f(0.0,15.0,-1.2);
    glVertex3f(0.0,0.0,-1.2);
    glVertex3f(15.0,0.0,-1.2);
    glVertex3f(15.0,15.0,-1.2);
    glEnd();

    ///KIRI
    glBegin(GL_POLYGON);
    glNormal3f(-1.0,0.0,0.0);
    glVertex3f(0.0,15.0,-1.01);
    glVertex3f(0.0,0.0,-1.01);
    glVertex3f(0.0,0.0,-1.2);
    glVertex3f(0.0,15.0,-1.2);
    glEnd();

    ///KANAN
    glBegin(GL_POLYGON);
    glNormal3f(1.0,0.0,0.0);
    glVertex3f(15.0,15.0,-1.01);
    glVertex3f(15.0,0.0,-1.01);
    glVertex3f(15.0,0.0,-1.2);
    glVertex3f(15.0,15.0,-1.2);
    glEnd();

    ///ATAS
    glBegin(GL_POLYGON);
    glNormal3f(0.0,1.0,0.0);
    glVertex3f(0.0,15.0,-1.01);
    glVertex3f(15.0,15.0,-1.01);
    glVertex3f(15.0,15.0,-1.2);
    glVertex3f(0.0,15.0,-1.2);
    glEnd();

    ///BAWAH
    glBegin(GL_POLYGON);
    glNormal3f(0.0,-1.0,0.0);
    glVertex3f(15.0,15.0,-1.01);
    glVertex3f(15.0,15.0,-1.01);
    glVertex3f(15.0,15.0,-1.2);
    glVertex3f(15.0,15.0,-1.2);
    glEnd();
}

void putarNim(){
    if(rotateNIM == 'x'){
            spin[0] += 3;
    }if(rotateNIM == 'y'){
            spin[1] += 3;
    }if(rotateNIM == 'z'){
            spin[2] += 3;
    }
    glutPostRedisplay();
}

void init(void){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (modelMap == 'c'){
        gluPerspective(80,1,1,50);
        gluLookAt(pos[0],pos[1],pos[2], pos[0]+viewdir[0],pos[1]+viewdir[1],pos[2]+viewdir[2], 0.0, 0.0, 1.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }else{
        glOrtho(-3.0,18.0,-3.0,18.0,-17.0,17.0);
        glMatrixMode(GL_MODELVIEW);
    }

    glShadeModel (GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    //transparant
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    //-----------------------
    glEnable(GL_NORMALIZE);
}


void display(void){
    init();
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    ///rotasi-----------------------------------------
    if (modelMap == 'b'){
        glTranslated(7.5,7.5,0);
        glRotated(putarY,0,1,0);
        glRotated(putarX,1,0,0);
        glTranslated(-7.5,-7.5,0);
    }

    ///transparant------------------------------------
    if (transCon == false){
        trans = 1.0;
    }else{
        trans = 0.3;
    }


    ///ganti map--------------------------------------
    if (swapmap == true){
        map1();
    }else{
        map2();
    }

    ///ganti rotasi nim-------------------------------
    glPushMatrix();
    if (modelMap == 'b' || modelMap == 'c'){
        glTranslated(0.5+randX,0.5+randY,-0.5);
            glRotatef(spin[0],1,0,0);
            glRotatef(spin[1],0,1,0);
            glRotatef(spin[2],0,0,1);
        glScaled(0.6,0.6,0.10);
        glTranslated(-0.5-randX,-0.5-randY,0.0);
        nim();
    }else{
        glTranslated(0.5+randX,0.5+randY,-0.5);
        glScaled(0.6,0.6,0.10);
        glTranslated(-0.5-randX,-0.5-randY,0.0);
        nim();
    }
    glPopMatrix();
    //----------------------------------------------

    player();
    transparant();
    glPopMatrix();
    glutSwapBuffers();
}

void keyboard (unsigned char key, int x, int y){
    //ganti map------------------------------------
    if (key == 'c' || key == 'C'){
        if (swapmap == true){
            swapmap = false;
        }else{
            swapmap = true;
        }
        posX = 0;
        posY = 0;
        randX = (rand()%7)*2+1;
        randY = (rand()%7)*2+1;

//        cout << "rand X: " << randX << endl;
//        cout << "rand Y: " << randY << endl;
    }

    //kondisi 3D & animasi-------------------------
    if (key == 'v' || key == 'V'){
        if (modelMap == 'a'){
            modelMap = 'b' ;
            glRotated(-20,1,0,0);
            glutIdleFunc(putarNim);
        }else if (modelMap == 'b' ){
            modelMap = 'c';
//            glRotated(-50,0,1,0);
        }else if (modelMap == 'c'){
            modelMap = 'a';
            glutIdleFunc(NULL);
            glLoadIdentity();
        }
    }

    //pergerakan player----------------------------
    if(key == 'w'|| key == 'W'){
                posY += 1.0;
//                cout << "Pos Y: " << posY << endl;
        }else if(key == 'a'|| key == 'A'){
                posX -= 1.0;
//                cout << "Pos X: " << posX << endl;
        }else if(key == 's'|| key == 'S'){
                posY -= 1.0;
//                cout << "Pos Y: " << posY << endl;
        }else if(key == 'd'|| key == 'D'){
                posX += 1.0;
//                cout << "Pos X: " << posX << endl;
        }

    if(posX+7 == randX&& posY+14 == randY){
        if (tabrak == false){
            cout << "DAPATNRP" << endl;
        tabrak = true;

        }
    }


    //cahaya
    if (key =='1'){
        if (ambient == true){
            GLfloat ambient_light[] = { 0.3, 0.3, 0.3, 5.0 };
            glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambient_light);
            ambient = false;
        }
        else{
            GLfloat ambient_light[] = { 0.9, 0.9, 0.9, 5.0 };
            glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambient_light);
            ambient = true;
        }
    }

    if (key =='2'){
        if (diffuse == true){
            glDisable(GL_LIGHT0);
            diffuse = false;
        }
        else{
            glEnable(GL_LIGHT0);
            diffuse = true;
        }
    }

    if (key =='3'){
        if (specular == true){
            glDisable(GL_LIGHT1);
            specular = false;
        }
        else{
            glEnable(GL_LIGHT1);
            specular = true;
        }
    }

        //day/night
    if (key == '4'){
        if (dayCon == true){
            glClearColor(1.0,1.0,1.0,1.0);
            dayCon = false;
        }else{
            glClearColor(0.0,0.0,0.0,1.0);
            dayCon = true;
        }
    }

    //transparant
    if (key == '5'){
        if (transCon == false){
            transCon = true;
        }else{
            transCon = false;
        }
    }


    //rotasi---------------------------------------
    if (modelMap == 'b'){
        if (key == 'j' || key == 'J'){
            putarY -= 2;
        }else if (key == 'l' || key == 'L'){
            putarY += 2;
        }else if (key == 'i' || key == 'I'){
            putarX -= 2;
        }else if (key == 'k' || key == 'K'){
            putarX += 2;
        }
    }
    display();
}

void camMove(int key, int x, int y){
    if(key == GLUT_KEY_RIGHT && modelMap == 'c'){
        alpha -= 0.1;
        viewdir[0] = cos(alpha);
        viewdir[1] = sin(alpha);
	}
	else if (key == GLUT_KEY_LEFT && modelMap == 'c'){
	    alpha += 0.1;
        viewdir[0] = cos(alpha);
        viewdir[1] = sin(alpha);
	}
	else if (key == GLUT_KEY_UP){
        pos[0] += 0.2 *  viewdir[0];
        pos[1] += 0.2 *  viewdir[1];
//        pos[2] += 0.5 *  viewdir[2];
	}
	else if (key == GLUT_KEY_DOWN){
        pos[0] -= 0.2 *  viewdir[0];
        pos[1] -= 0.2 *  viewdir[1];
//        pos[2] -= 0.5 *  viewdir[2];
	}
	display();
 }

void mouse(int button, int state, int x, int y){
    switch (button)
    {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN)
                rotateNIM = 'x';
            break;
        case GLUT_MIDDLE_BUTTON:
            if (state == GLUT_DOWN)
                rotateNIM = 'y';
            break;
        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_DOWN)
                rotateNIM = 'z';
            break;
        default:
            break;
    }
 }

int main(int argc, char** argv){
    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Maze2");
    init();
    pencahayaan();
    glutDisplayFunc(display);
    glutSpecialFunc(camMove);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMainLoop();

    return 0;
 }
