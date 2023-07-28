#include <iostream>
#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#define pi 3.142857
using namespace std;
void myInit ()
{
	//glClearColor(128.0f/255.0f,0, 0, 1.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// setting window dimension in X- and Y- direction
	glOrtho(0, 1300, 0, 700, -10.0, 10.0);
}

void circle(GLfloat rx,GLfloat ry,GLfloat x,GLfloat y)
{
    int i;
    float rad = 100;
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    for(i = 0;i<=360; i++){
    rad = i*(3.1416/180);
    glVertex2f(x+rx*cos(rad),y+ry*sin(rad));

    }
    glEnd();


}
void rectangle(int x, int y, int x1, int y1)
{
    glBegin(GL_QUADS);
        glVertex2d(x,y);
        glVertex2d(x,y1);
        glVertex2d(x1,y1);
        glVertex2d(x1,y);


    glEnd();
}

void triangle(int x, int y, int x1, int x2,int y1)
{
    glBegin(GL_POLYGON);
        glVertex2d(x,y);
        glVertex2d(x1,y);

        glVertex2d(x1,y);
        glVertex2d(x2,y1);

        glVertex2d(x2,y1);
        glVertex2d(x,y);
        glEnd();
}
void sun(float x1,float y1,float rx, float ry)
{
    float x2,y2;

    //glBegin(GL_POLYGON);
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(252, 5, 17); //Center Color of Circle
glVertex2f(x1,y1); //Center Vertex
int angle;
for (angle=0;angle<=360;angle++) //0,90,180,270
{
    glColor3ub(255, 243, 18); //Edge color of Circle
    x2 = x1+rx*sin((angle*3.1416)/180);  // convert degree to radian
    y2 = y1+ry*cos((angle*3.1416)/180);
    glVertex2f(x2,y2);
}

glEnd();

}
void rectangle1(int x1,int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    glBegin(GL_QUADS);
        glVertex2d(x1,y1);
        glVertex2d(x3,y3);
        glVertex2d(x4,y4);
        glVertex2d(x2,y2);
        glEnd();
}
void grass(int x,int y,int r,int g,int b)
{
    float x1,y1,x2,y2;
    float radiusx=1400;
    float radiusy=50;
    x1=x;
    y1=y;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(r,g,b);
glVertex2f(x1,y1);
float angle;
for (angle=0;angle<=360;angle+=0.2)
{
    int tx=rand() % 1;
    int ty=rand() % 50;
    x2 = tx+x1+sin((angle*3.1416)/180)*radiusx;
    y2 = ty+y1+cos((angle*3.1416)/180)*radiusy;
    glVertex2f(x2,y2);
}
glEnd();
}
void ghash(int x,int y,int r,int g,int b)
{
    grass(x,y,r,g,b);
}

void madecloud(int x, int y)
{
    glColor3ub (255, 247, 209);
    circle(30,30,x,y);
    circle(20,20,x+20,y);
    circle(20,20,x+40,y);
    circle(25,25,x+20,y-15);
    circle(20,20,x+30,y-20);
    circle(10,10,x+20,y+20);
    circle(20,20,x+30,y+20);

}
static float x3 =100;
void cloudMove(){
    x3=x3+.08;
    if(x3>600)
        x3 = -300;
    glutPostRedisplay();
}


void cloud1()
{
    glPushMatrix();
    glTranslatef(x3,0,0);
    madecloud(300,680);
    madecloud(500,580);
    madecloud(250,700);
    madecloud(400,510);
    madecloud(500,650);
    madecloud(100,750);
    madecloud(350,530);
    madecloud(00,500);
    madecloud(555,660);
    madecloud(250,540);
    madecloud(400,450);
    madecloud(200,520);
    madecloud(50,510);
    madecloud(350,490);
    glPopMatrix();
    cloudMove();

    glEnd();
}

void cloud2()
{
    glPushMatrix();
    glTranslatef(x3,0,0);
    madecloud(1100,680);
    madecloud(1200,580);
    madecloud(50,700);
    madecloud(700,530);
    madecloud(800,680);
    madecloud(850,700);
    madecloud(750,570);
    madecloud(600,580);
    madecloud(650,660);
    madecloud(520,540);
    madecloud(40,530);
    madecloud(120,520);
    madecloud(10,510);
    madecloud(635,500);
    glPopMatrix();
    cloudMove();

    glEnd();
}


void madeplane()
{
    glColor3ub (2, 25, 25);
    circle(25,15,1,0);
    rectangle(0,-15,70,15);
    glColor3ub (255, 255, 255);
    rectangle1(70,-15,90,35,70,15,90,40);
    glColor3ub (25, 255, 255);
    rectangle1(30,15,50,15,60,35,55,30);

glColor3ub (255, 255, 255);
circle(5,5,10,0);
circle(5,5,30,0);
circle(5,5,50,0);
circle(5,5,65,0);
rectangle(-5,-5,0,10);


}
static float	x5=  1000.0;
void planeMove(){
    x5 = x5 - 0.6;
    if(x5<-100)
    x5 = 1300;
        glutPostRedisplay();
}


void plane()
{
   planeMove();
    for(int i=0;i<1;i++)
     {

     glPushMatrix();
     glTranslatef(x5,550,0);
     madeplane();
     glPopMatrix();
       glPushMatrix();
     glTranslatef(x5+100,450,0);
     madeplane();
     glPopMatrix();


    }
}
void madeship(){
//NavyShip
glColor3ub (65, 77, 74);
glBegin(GL_POLYGON);
glVertex2d (600,200);
glVertex2d (650,150);
glVertex2d (950,170);
glVertex2d (1000,200);
glEnd();
//NavyShip upper
glColor3ub (146, 150, 149);
glBegin(GL_POLYGON);
glVertex2d (700,250);
glVertex2d (650,200);
glVertex2d (850,200);
glVertex2d (800,250);
glEnd();
//NavyShip upper1
glColor3ub (163, 184, 201);
glBegin(GL_POLYGON);
glVertex2d (700,265);
glVertex2d (700,250);
glVertex2d (800,250);
glVertex2d (800,265);
glEnd();
//NavyShip upper2
glColor3ub (146, 150, 149);
glBegin(GL_POLYGON);
glVertex2d (740,300);
glVertex2d (710,265);
glVertex2d (790,265);
glVertex2d (790,300);
glEnd();
//NavyShip upper3
glColor3ub (77, 90, 102);
glBegin(GL_POLYGON);
glVertex2d (760,300);
glVertex2d (770,300);
glVertex2d (770,350);
glVertex2d (760,350);
glEnd();
//NavyShip upper4
glColor3ub (77, 90, 102);
glBegin(GL_POLYGON);
glVertex2d (730,355);
glVertex2d (740,350);
glVertex2d (800,350);
glVertex2d (810,355);
glEnd();
//NavyShip Gun
glColor3ub (1,1,1);
glBegin(GL_POLYGON);
glVertex2d (910,220);
glVertex2d (900,200);
glVertex2d (980,200);
glVertex2d (970,220);
glEnd();
//NavyShip Gun 1
glColor3ub (1,1,1);
glBegin(GL_POLYGON);
glVertex2d (930,220);
glVertex2d (930,230);
glVertex2d (950,230);
glVertex2d (950,220);
glEnd();

//NavyShip Gun 2
glColor3ub (1,1,1);
glBegin(GL_POLYGON);
glVertex2d (930,250);
glVertex2d (900,240);
glVertex2d (900,230);
glVertex2d (980,230);
glVertex2d (990,240);
glVertex2d (980,250);
glEnd();

//NavyShip Gun 3
glColor3ub (1,1,1);
glBegin(GL_POLYGON);
glVertex2d (980,245);
glVertex2d (980,235);
glVertex2d (1100,235);
glVertex2d (1100,245);
glEnd();


}

static float x4 =  -300;
void shipMove(){
    x4 = x4 + 0.4;
    if(x4 == 400)
      x4 = -400;
        glutPostRedisplay();
}


void ship()
{
   shipMove();
    for(int i=0;i<1;i++)
     {

     glPushMatrix();
     glTranslatef(x4,120,0);
     madeship();

     glPopMatrix();
      glPushMatrix();
     glTranslatef(x4+400,1,0);
     madeship();

     glPopMatrix();
    }
}
//making fish

void madefish()
{
glBegin(GL_TRIANGLES);//tail
  glColor3ub(12, 240, 236);
    glVertex2f(300,170);
   glVertex2f(300,120);
   glVertex2f(270,150);
  glEnd();
   glColor3ub(77, 90, 102);//body
  glBegin(GL_POLYGON);
   glVertex2f(220,150);
   glVertex2f(250,120);
   glVertex2f(280,150);
   glVertex2f(250,180);
  glEnd();

  glBegin(GL_TRIANGLES);//upperfin
  glColor3ub(2, 42, 77);
    glVertex2f(250,180);
   glVertex2f(260,165);
   glVertex2f(270,210);

  glEnd();

glBegin(GL_TRIANGLES);//lowerfin
glColor3ub(2, 42, 77);
    glVertex2f(250,120);
   glVertex2f(269,95);
   glVertex2f(265,140);
  glEnd();
  sun(235,150,5,5);
}

static float x6 =  700;
void fishMove(){
    x6 = x6 - 2;
    if(x6 <- 100)
      x6 = 1200;
        glutPostRedisplay();
}


void fish()
{
   fishMove();
    for(int i=0;i<1;i++)
     {

     glPushMatrix();
     glTranslatef(x6,50,0);
     madefish();
      glTranslatef(x6+100,30,0);
      madefish();
     glPopMatrix();

    }
}

//

//making fishy

void madefishy()
{
  glBegin(GL_TRIANGLES);//tail
  glColor3ub(12, 240, 236);
    glVertex2f(220,150);
   glVertex2f(200,160);
   glVertex2f(200,140);
  glEnd();
   glColor3ub(134, 245, 252);//body
  glBegin(GL_POLYGON);
  glVertex2f(220,150);
   glVertex2f(250,120);
   glVertex2f(280,150);
   glVertex2f(250,180);
  glEnd();
  glBegin(GL_TRIANGLES);//upperfin
  glColor3ub(134, 245, 252);
    glVertex2f(250,180);
   glVertex2f(240,165);
   glVertex2f(230,210);

  glEnd();

glBegin(GL_TRIANGLES);//lowerfin
glColor3ub(134, 245, 252);
    glVertex2f(250,120);
   glVertex2f(245,100);
   glVertex2f(230,145);
  glEnd();



sun(260,150,5,5);
}



static float x7 =  -200;
void fishyMove(){
    x7 = x7 + 0.5;
    if(x7 == 1300)
      x7 = 1;
    glutPostRedisplay();
}


void fishy()
{
   fishyMove();
    for(int i=0;i<1;i++)
     {

     glPushMatrix();
     glTranslatef(x7,25,5);
     madefishy();
      glTranslatef(x7+200,30,2);
      madefishy();

      glTranslatef(x7+100,10,1);
      madefishy();

     glPopMatrix();

    }
}


void drawPebble(float x, float y, float radius)
{
    int numSegments = 100;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of the pebble
    for (int i = 0; i <= numSegments; i++)
    {
        float angle = i * 2.0f * 3.14159f / numSegments; // angle in radians
        float px = x + radius * cos(angle);
        float py = y + radius * sin(angle);
        glVertex2f(px, py);
    }
    glEnd();
}
void drawWaterLily(float x, float y, float radius)
{
    int numPetals = 10;
    float angleIncrement = 2.0f * 3.14159f / numPetals;
    float petalLength = radius * 0.6f;

    glColor3f(0.0f, 1.0f, 0.0f); // green color for water lily

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of the water lily
    for (int i = 0; i <= numPetals; i++)
    {
        float angle = i * angleIncrement;
        float px = x + radius * cos(angle);
        float py = y + radius * sin(angle);
        glVertex2f(px, py);
    }
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f); // white color for the petals

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of the water lily
    for (int i = 0; i <= numPetals; i++)
    {
        float angle = i * angleIncrement;
        float px = x + petalLength * cos(angle);
        float py = y + petalLength * sin(angle);
        glVertex2f(px, py);
    }
    glEnd();
}

void display ()
{

glClear(GL_COLOR_BUFFER_BIT);
//sky
glColor3ub (255, 251, 119);
glBegin(GL_POLYGON);
glVertex2d (0, 700);
glVertex2d (0,300);
glVertex2d (1300,300);
glVertex2d (1300,700);
glEnd();
//mountain
glColor3ub (99, 70, 11);
glBegin(GL_POLYGON);
glVertex2d (1300, 300);
glVertex2d (1200,300);
glVertex2d (1250, 400);
glEnd();
glColor3ub (99, 70, 11);
glBegin(GL_POLYGON);
glVertex2d (1000, 300);
glVertex2d (1150,600);
glVertex2d (1250,300);

glEnd();

ghash(-50,250,33, 130, 57);
//river
glColor3ub (82, 214, 250);
glBegin(GL_POLYGON);
glVertex2d (0, 300);
glVertex2d (0,0);
glVertex2d (1300, 0);
glVertex2d (1300,300);
glEnd();

sun(150, 550, 80, 80);
plane();


cloud1();
cloud2();
fish();
fishy();
ship();
// Draw water grass
    glColor3ub(0, 128, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(100, 0);
    glVertex2f(130, 0);
    glVertex2f(115, 90);
    glEnd();

    glColor3ub(0, 128, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(130, 0);
    glVertex2f(160, 0);
    glVertex2f(145, 100);
    glEnd();

    glColor3ub(0, 128, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(160, 0);
    glVertex2f(190, 0);
    glVertex2f(175, 60);
    glEnd();

    glColor3ub(0, 128, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(190, 0);
    glVertex2f(220, 0);
    glVertex2f(205, 45);
    glEnd();

     glColor3ub(0, 128, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(300, 0);
    glVertex2f(330, 0);
    glVertex2f(315, 90);
    glEnd();

    glColor3ub(0, 128, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(430, 0);
    glVertex2f(460, 0);
    glVertex2f(445, 100);
    glEnd();

    glColor3ub(0, 128, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(560, 0);
    glVertex2f(590, 0);
    glVertex2f(575, 60);
    glEnd();

    glColor3ub(0, 128, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(690, 0);
    glVertex2f(620, 0);
    glVertex2f(605, 45);
    glEnd();



glColor3f(0.5f, 0.5f, 0.5f); // gray color for pebbles
// Draw pebbles
drawPebble(100, 10, 10);
drawPebble(200, 10, 10);
drawPebble(300, 10, 10);
drawPebble(400, 10, 10);
drawPebble(500, 10, 10);
drawPebble(100, 50, 10);
drawPebble(200, 50, 10);
drawPebble(300, 50, 10);
drawPebble(400, 50, 10);
drawPebble(500, 50, 10);
drawPebble(600, 10, 10);
drawPebble(700, 10, 10);
drawPebble(800, 10, 10);
drawPebble(400, 5, 10);
drawPebble(500, 5, 10);
drawPebble(100, 5, 10);
drawPebble(200, 5, 10);
drawPebble(300, 5, 10);
drawPebble(400, 5, 10);
drawPebble(500, 5, 10);

drawPebble(150, 10, 10);
drawPebble(250, 10, 10);
drawPebble(350, 10, 10);
drawPebble(450, 10, 10);
drawPebble(550, 10, 10);
drawPebble(150, 20, 10);
drawPebble(250, 20, 10);
drawPebble(350, 20, 10);
drawPebble(450, 20, 10);
drawPebble(550, 20, 10);
drawPebble(650, 10, 10);
drawPebble(750, 10, 14);
drawPebble(850, 10, 20);
drawPebble(450, 5, 11);
drawPebble(550, 5, 16);
drawPebble(150, 5, 15);
drawPebble(250, 5, 14);
drawPebble(350, 5, 13);
drawPebble(450, 5, 12);
drawPebble(550, 5, 11);





glFlush();
}

void update(int val) {
	glutPostRedisplay();
	glutTimerFunc(20, update, 0);
}
int main (int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// giving window size in X- and Y- direction
	glutInitWindowSize(1300,700);
	glutInitWindowPosition(0,0);

	// Giving name to window
	glutCreateWindow("Emon 193-15-1078");
	myInit();
	glutDisplayFunc(display);
	glutTimerFunc(0, update, 1);
    update(1);
	glutMainLoop();
}

