#include <windows.h>
#include <iostream>
#include <GL/glut.h>
#include <math.h>

//////water
int waterStatus = 0;
float waterX = 0;
float waterY = 0;
float shipx=0;
float shipy=0;

//////cloud
int meghmegh = 1;
int meghStatus = 0;
float meghX = 0;
float meghY = 0;
/////sun
int sunStatus = 0;
float sunX = 0;
float sunY = 0;

//////
float shipX = 0;
float shipY =0;

int springstatus=0;
int lightstatus = 0;

int  ships1 =1;
GLfloat cloudSpeed=5.0f;
GLfloat Position3= 330;


void drawQuad(GLint x0, GLint y0, GLint x1, GLint y1, GLint x2, GLint y2, GLint x3, GLint y3)
{ glBegin(GL_QUADS);
  glVertex2f(x0,y0);glVertex2f(x1,y1);glVertex2f(x2,y2);glVertex2f(x3,y3);
  glEnd();
}

void drawTriangle(GLint x0, GLint y0, GLint x1, GLint y1, GLint x2, GLint y2)
{   glBegin(GL_TRIANGLES);
    glVertex2f(x0,y0);glVertex2f(x1,y1);glVertex2f(x2,y2);
    glEnd();
}
void DrawCircle(float cx, float cy, float r, int num_segments) {

	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < num_segments; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get current angle

		float x = r * cosf(theta);//calculate x
		float y = r * sinf(theta);//calculate y

		glVertex2f(x + cx, y + cy);//output vertex

	}
	glEnd();
	glFlush();
}

void update3(int value){
    if(Position3<-300)
    {
        Position3=+30.0f;
    }
    if(Position3>300)
       {
           Position3=3;
       }
      Position3 -= cloudSpeed;
      glutPostRedisplay();
      glutTimerFunc(400, update3, 0);////snow spped increase/decrease
}

////////////////// sun movement
float position2 = 0.0f;
float speed2 = 0.6f;

void update2(int value){
    if(position2 > 300)
    position2 = +1500;
    position2 += speed2;
    glutPostRedisplay();
    glutTimerFunc(130, update2, 0);//sun spped increase/decrease
}
void sky(){
    glColor3ub (102, 212, 238);
    glBegin(GL_QUADS);
    glVertex2f(0, 480);
    glVertex2f(0, 255);
    glVertex2f(640, 255);
    glVertex2f(640, 480);
    glEnd();
}

void hills(){
    //from left 1st hill
    glColor3ub (150, 129, 117);
    glBegin(GL_TRIANGLES);
    glVertex2f(0, 250);
    glVertex2f(0, 300);
    glVertex2f(55, 250);

    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(0, 250);
    glVertex2f(0, 400);
    glVertex2f(0, 400);
    glVertex2f(55, 255);
    glEnd();


    glColor3ub (150, 129, 117);
    glBegin(GL_TRIANGLES);
    glVertex2f(20, 255);
    glVertex2f(120, 340);
    glVertex2f(200, 255);

    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(30, 275);
    glVertex2f(120, 340);

    glVertex2f(120, 340);
    glVertex2f(200, 255);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(20, 255);
    glVertex2f(120, 340);

    glVertex2f(120, 340);
    glVertex2f(200, 255);
    glEnd();

    glColor3ub (150, 129, 117);
    glBegin(GL_TRIANGLES);
    glVertex2f(20, 255);
    glVertex2f(120, 340);
    glVertex2f(200, 255);

    glColor3ub (150, 129, 117);
    glBegin(GL_TRIANGLES);
    glVertex2f(180, 255);
    glVertex2f(270, 320);
    glVertex2f(360, 255);
    glEnd();
    //////line shape
    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(180, 255);
    glVertex2f(270, 320);

    glVertex2f(270, 320);
    glVertex2f(360, 255);
    glEnd();

    glColor3ub (150, 129, 117);
    glBegin(GL_TRIANGLES);
    glVertex2f(260, 255);
    glVertex2f(340, 360);
    glVertex2f(450, 255);
    glEnd();
    //////line shape
    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(293, 299);
    glVertex2f(340, 360);
    glVertex2f(340, 360);
    glVertex2f(450, 255);
    glEnd();
    //right last hills
    glColor3ub (150, 129, 117);
    glBegin(GL_TRIANGLES);
    glVertex2f(440, 255);
    glVertex2f(535, 385);
    glVertex2f(650, 250);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(440, 255);
    glVertex2f(535, 385);
    glVertex2f(535, 385);
    glVertex2f(650, 250);
    glEnd();

    glFlush();
}

void river(){
    glColor3ub (47, 136, 220);
    glBegin(GL_POLYGON);
    glVertex2f(0, 0);
    glVertex2f(640, 0);
    glVertex2f(640, 255);
      glVertex2f(0, 255);

    glEnd();
}

////////////////ship///////////////
void ship()
{

    glTranslated(0,110,0);
    glScaled(20,15,0);

    glBegin(GL_POLYGON);
    glColor3ub(16,58,65);
    glVertex2f(1,5.5);
    glColor3ub(0,49,57);
    glVertex2f(3,1);
    glColor3ub(0,49,57);
    glVertex2f(19,1);
    glColor3ub(16,58,65);
    glVertex2f(21,5.5);
    glEnd();

    glColor3f(0.5,0.5,0.5);
    glBegin(GL_POLYGON);
    glVertex2f(3.5,5.5);
    glVertex2f(3.5,7);
    glVertex2f(19.5,7);
    glVertex2f(19.5,5.5);
    glEnd();

    glColor3f(0.5,0.5,0.5);
    glBegin(GL_POLYGON);
    glVertex2f(4.5,8);
    glVertex2f(4.5,7);
    glVertex2f(18.5,7);
    glVertex2f(18.5,8);
    glEnd();

    // Windows
    glColor3f(0.9,0.9,0.9);
    glBegin(GL_POLYGON);
    glVertex2f(6,7);
    glVertex2f(6,7.5);
    glVertex2f(8,7.5);
    glVertex2f(8,7);
    glEnd();

    glTranslated(3,-0.5,0);

    glBegin(GL_POLYGON);
    glVertex2f(6,7.5);
    glVertex2f(6,8);
    glVertex2f(8,8);
    glVertex2f(8,7.5);
    glEnd();

    glTranslated(3,0,0);

    glBegin(GL_POLYGON);
    glVertex2f(6,7.5);
    glVertex2f(6,8);
    glVertex2f(8,8);
    glVertex2f(8,7.5);
    glEnd();

    glTranslated(3,0,0);

    glBegin(GL_POLYGON);
    glVertex2f(6,7.5);
    glVertex2f(6,8);
    glVertex2f(8,8);
    glVertex2f(8,7.5);
    glEnd();

    // Steam Pipes
    glColor3ub(21,21,21);
    glTranslated(-8,-1.6,0);
    glBegin(GL_POLYGON);
    glVertex2f(4.1,10);
    glVertex2f(4,12.9);
    glVertex2f(5.6,12.9);
    glVertex2f(5.7,10);
    glEnd();

    glColor3ub(221,147,0);
    glBegin(GL_POLYGON);
    glVertex2f(4,12.9);
    glVertex2f(3.9,13.5);
    glVertex2f(5.5,13.5);
    glVertex2f(5.6,12.9);
    glEnd();

    glTranslated(3,0,0);

    glColor3ub(21,21,21);
    glBegin(GL_POLYGON);
    glVertex2f(4.1,10);
    glVertex2f(4,12.9);
    glVertex2f(5.6,12.9);
    glVertex2f(5.7,10);
    glEnd();

    glColor3ub(221,147,0);
    glBegin(GL_POLYGON);
    glVertex2f(4,12.9);
    glVertex2f(3.9,13.5);
    glVertex2f(5.5,13.5);
    glVertex2f(5.6,12.9);
    glEnd();

    glTranslated(3,0,0);

    glColor3ub(21,21,21);
    glBegin(GL_POLYGON);
    glVertex2f(4.1,10);
    glVertex2f(4,12.9);
    glVertex2f(5.6,12.9);
    glVertex2f(5.7,10);
    glEnd();

    glColor3ub(221,147,0);
    glBegin(GL_POLYGON);
    glVertex2f(4,12.9);
    glVertex2f(3.9,13.5);
    glVertex2f(5.5,13.5);
    glVertex2f(5.6,12.9);
    glEnd();
}
//////////////Ship end////////////////////


///////////////////moving ship
void moveship(int xx){

if(ships1==1)

    {

        shipx+= 1;//change left or right

    }

    glPushMatrix();
    glTranslatef(shipx, shipy, 0);
    if(xx==1)
        {

    ship();
    }
    else{
       ship();
    }
    glPopMatrix();
    glFlush();

}

void megh(){
     glColor3ub (200, 220, 220);
	DrawCircle(20, 450, 25, 2000);
	DrawCircle(50, 450, 35, 2000);
	DrawCircle(80, 450, 25, 2000);

    glColor3ub (200, 220, 220);
	DrawCircle(220, 400, 25, 2000);
	DrawCircle(250, 400, 35, 2000);
	DrawCircle(280, 400, 25, 2000);

    glColor3ub (200, 220, 220);
	DrawCircle(300, 420, 25, 2000);
	DrawCircle(330, 420, 35, 2000);
	DrawCircle(360, 420, 25, 2000);

    glColor3ub (200, 220, 220);
	DrawCircle(400, 400, 25, 2000);
	DrawCircle(430, 400, 35, 2000);
	DrawCircle(460, 400, 25, 2000);
	glFlush();

	glColor3ub (200, 220, 220);
	DrawCircle(580, 480, 25, 2000);
	DrawCircle(510, 480, 35, 2000);
	DrawCircle(540, 480, 25, 2000);
	glFlush();
}




void drawSun(){

    // Set the position of the sun on the left side
    float sunPosX = 100.0f; // Adjust this value to change the position
    float sunPosY = 400.0f; // Adjust this value to change the position
    float sunRadius = 50.0f;

    glColor3ub(255, 255, 0); // Yellow color for the sun
    DrawCircle(sunPosX, sunPosY, sunRadius, 2000);

}






void moveMegh(int x){

            if(meghStatus ==1){
            meghX +=.5;//move megh right or left
            }
    if (meghX>400)
        {
            meghX = -10;
        }
    glPushMatrix();
    glTranslatef(meghX, meghY, 0);


      if(x==1)
    {
       megh();

    }


    glPopMatrix();
    glFlush();
}



void myDisplay(void){
if(position2>= -250.0f){
    sky();

    hills();
    drawSun();
    river();

    moveMegh(1);
    moveship(1);

    glFlush();
    glutPostRedisplay();
    glutSwapBuffers();}
    else{
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_LIGHTING);
    GLfloat global_ambient[] = {0.41,1.31,1.88, 0.1};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);
    sky();

    GLfloat global_ambient2[] = {1.29,1.29,1.29, 0.1};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient2);
    hills();
    glDisable(GL_LIGHTING);

    glEnable(GL_LIGHTING);
    GLfloat global_ambient3[] = {1.9,1.9,1.9, 0.1};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient3);
    glDisable(GL_LIGHTING);

    glEnable(GL_LIGHTING);
    GLfloat global_ambient1[] = {.60,1.90,2.76, 0.1};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient1);
    river();

    glDisable(GL_LIGHTING);

    glEnable(GL_LIGHTING);
    GLfloat global_ambient4[] = {4.0,4.0,4.0, 0.1};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient4);
    //drawMoon();
     //moveMoon(1);
    glDisable(GL_LIGHTING);

    glEnable(GL_LIGHTING);
    GLfloat global_ambient5[] = {0.0,1.50,1.25, 0.1};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient5);

    glDisable(GL_LIGHTING);

    moveMegh(2);
    moveship(1);


    glFlush();
    glutPostRedisplay();
    glutSwapBuffers();
    }
}

void mykeyboard(unsigned char key, int x, int y){


	 if (key == 'C' || key == 'c'){		////////megh starting
		meghStatus = 1;
	}
	else if (key == 'V' || key == 'v'){		//////megh STOP
		meghStatus = 0;
	}
	else if (key == 'o' || key == 'O'){		////water strting
		waterStatus = 1;
	}
	else if (key == 'u' || key == 'u'){		//water stop
		waterStatus = 0;
	}


      else if (key == 'A' || key == 'a'){ // Start moving the ship
        ships1 = 1;
        shipx -= 5;
    }
    else if (key == 'D' || key == 'd'){ // Stop moving the ship
        ships1 = 0;
        shipx += 5;
    }


}

void myInit(void){
    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glColor3f(.0f,.0f,.0f);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1920,1080);
    glutCreateWindow("Ship Sink on the River");
    glutPostRedisplay();
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(mykeyboard);
    myInit();
    glutTimerFunc(30, update2, 0);
    glutTimerFunc(5,update3,0);
    glutMainLoop();
    return 0;
}
