#include<windows.h> // for MS Windows
#include<GL/glut.h> // GLUT, include glu.h and gl.h
#include<cstdio>
#include<GL/gl.h>
#include<math.h>
#define PI       3.14159265358979323846

GLfloat position1 = 0.0f;
GLfloat speed1 = 300.0f;

GLfloat position2 = 0.0f;
GLfloat speed2 = 5.0f;

GLfloat position3 = 0.0f;
GLfloat speed3 = 3.0f;

GLfloat position4 = 0.0f;
GLfloat speed4 = 10.0f;

GLint shipD1=0,shipD2=0, shipD3=0, shipD4=0,shipD5=10,iceBroke=-100,iceSink=-5,shipSink = 120;

void update(int value);

void SpecialInput(int key, int x, int y);

void display();

void display1();

void display2();

void display3();

void display4();

void display5();

void glFlush();

void ship();

void water1();

void sky1();

void cloud();

void sun();

void sun2();

void rain();

void moon();

void star();

void waterlines();

void windMill();

void trees();

void birds();

void miniices();

void miniices2();

void sound();

void sound2();

void ice();



void update(int value)
{
    shipD1+=10.0;

    if(position1<0.0)
    {
        position1 = -200.0f;
    }

    position1 -= speed1;

    glutPostRedisplay();

    if(position2>1000.0)
    {
        position2 = 0.0f;
    }

    position2 += speed2;
    glutPostRedisplay();

    if(position3>1000.0)
    {
        position3 = 0.0f;
    }

    position3 -= speed3;

    // Update position4
    if (position4 > 250.0)
    {
        position4 = 0.0f;
    }
    position4 += speed4;

    // Request a display refresh
    glutPostRedisplay();

    glutTimerFunc(150,update,0);
}

void SpecialInput(int key, int x, int y)
{

    switch(key)
    {
    case GLUT_KEY_UP:
        sound();
        break;

    case GLUT_KEY_DOWN:
        sound2();
        break;

    case GLUT_KEY_LEFT:
        speed2=5.0;
        break;

    case GLUT_KEY_RIGHT:
        speed2=30.0;
        break;
    }

    glutPostRedisplay();
}

void display()
{
    display1();

    if (shipD1 > 700)
    {
        shipD2 += 10;
        display2();
    }

    if (shipD2 > 700)
    {
        shipD3 += 10;
        display3();
    }

    if (shipD3 > 500)
    {
        shipD4 += 10;
        display4();
    }

    if (shipD4 > 700)
    {
        shipD5 += 10;
        display5();
    }

    glFlush();
}

void display1()
{
    glClear(GL_COLOR_BUFFER_BIT);

    sky1();
    birds();
    sun();
    cloud();



    //greenfield
    //glColor3ub(33,115,0);

    glBegin(GL_POLYGON);
    glColor3ub(33,115,0);
    glVertex2f(0,410);
    glColor3ub(96,206,52);
    glVertex2f(0,310);
    glColor3ub(33,115,0);
    glVertex2f(1000,410);
    glEnd();

    //riverside
    glColor3ub(80,80,80);
    glBegin(GL_POLYGON);
    glVertex2f(0,310);
    glVertex2f(0,110);
    glVertex2f(1000,400);
    glVertex2f(1000,410);
    glEnd();

    //Hill
    glColor3ub(3,102,12);
    glBegin(GL_POLYGON);
    glVertex2f(-100,410);
    glVertex2f(50,470);
    glVertex2f(100,415);
    glVertex2f(150,450);
    glVertex2f(200,460);
    glVertex2f(250,420);
    glVertex2f(300,450);
    glVertex2f(350,410);
    glEnd();

    //windmill();

    trees();

    water1();

    waterlines();

    glPushMatrix();

    glTranslated(shipD1,70,0.0);

    ship();

    glPopMatrix();

}

void display2()
{
    glClear(GL_COLOR_BUFFER_BIT);

    //ship();

    glBegin(GL_POLYGON);
    glColor3ub(237,97,8);
    glVertex2f(0,800);
    glColor3ub(241,168,76);
    glVertex2f(1000,410);
    glColor3ub(237,97,8);
    glVertex2f(1000,800);
    glEnd();

    birds();

    //greenfield
    //glClear3ub(33,115,0);
    glBegin(GL_POLYGON);
    glColor3ub(33,115,0);
    glVertex2f(0,410);
    glColor3ub(96,206,52);
    glVertex2f(0,360);
    glColor3ub(33,115,0);
    glVertex2f(1000,410);
    glEnd();

    //water2
    glBegin(GL_POLYGON);
    glColor3ub(75,160,240);
    glVertex2f(0,0);
    glColor3ub(47,136,220);
    glVertex2f(0,360);
    glColor3ub(47,136,220);
    glVertex2f(500,476);
    glColor3ub(75,160,240);
    glVertex2f(1000,410);
    glColor3ub(75,160,240);
    glVertex2f(1000,0);
    glEnd();


    waterlines();

    glPushMatrix();
    glTranslated(shipD2,70,0.0);
    ship();
    glPopMatrix();


    sun2();
    cloud();
    rain();

}

//Display 3

void display3()
{
    //ship();

    //sky3
    glColor3ub(34,34,34);
    glBegin(GL_POLYGON);
    glVertex2f(0,800);
    glVertex2f(0,410);
    glVertex2f(1000,410);
    glVertex2f(1000,800);
    glEnd();

    //water3
    glColor3ub(47,136,220);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(0,410);
    glVertex2f(1000,410);
    glVertex2f(1000,0);
    glEnd();

    miniices();

    waterlines();

    ice();

    glPushMatrix();
    glTranslated(shipD3,70,0.0);
    ship();
    glPopMatrix();

    //water3.1
    glColor3ub(47,136,220);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(0,200);
    //glVertex2f(1000,200);
    //glVertex2f(1000,0);

    //water3.2
    glColor3ub(47,136,220);
    glBegin(GL_POLYGON);



    //waterlines
    glBegin(GL_LINES);
    glColor3ub(248,249,249);
    glVertex2f(100,100);
    glVertex2f(200,100);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(248,249,249);
    glVertex2f(400,120);
    glVertex2f(500,100);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(248,249,249);
    glVertex2f(400,300);
    glVertex2f(500,300);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(248,249,249);
    glVertex2f(800,130);
    glVertex2f(900,130);
    glEnd();

    moon();
    star();

}


void display4()
{
    // Placeholder for additional graphics elements
    //Sky3
    //sky3
    glColor3ub(34,34,34);
    glBegin(GL_POLYGON);
    glVertex2f(0,800);
    glVertex2f(0,410);
    glVertex2f(1000,410);
    glVertex2f(1000,800);
    glEnd();

    //water3
    glColor3ub(47,136,220);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(0,410);
    glVertex2f(1000,410);
    glVertex2f(1000,0);
    glEnd();

    miniices();

    waterlines();

    //ice
    glPushMatrix();
    glColor3ub(227,227,227);
    glTranslated(400,150,0);
    glScaled(20,10,0);
    glBegin(GL_POLYGON);
    glVertex2f(5.5,2.5);
    glVertex2f(12.5,19.5);
    glVertex2f(15,19.5);
    glVertex2f(12.5,19.5);
    glVertex2f(13.5,18.5);
    glVertex2f(16.5,20.5);
    glVertex2f(17.5,18.5);
    glVertex2f(18.5,3.5);
    glVertex2f(15,3);
    glVertex2f(15.5,2.5);
    glEnd();
    glPopMatrix();

    iceBroke -= 0.05;
    iceSink -= 5;
    shipD1 += 10;

    glPushMatrix();
    glColor3ub(227,227,227);
    glTranslated(iceBroke,iceSink,0);
    glTranslated(400,150,0);
    glScaled(20,10,0);
    glBegin(GL_POLYGON);
    glVertex2f(5.5,2.5);
    glVertex2f(6,3);
    glVertex2f(8.25,3.5);
    glVertex2f(8.5,18.5);
    glVertex2f(15,17);
    glVertex2f(12.5,19.5);
    glVertex2f(8.5,9.5);
    glVertex2f(12.5,2.5);
    glVertex2f(5.5,2.5);
    glEnd();
    glPopMatrix();



    glPushMatrix();
    glTranslated(shipD3,70,0.0);
    ship();
    glPopMatrix();


    //water3
    glColor3ub(47,136,220);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(0,200);
    glVertex2f(1000,200);
    glVertex2f(1000,0);
    glEnd();

    miniices2();


    //waterlines
    glBegin(GL_LINES);
    glColor3ub(248,249,249);
    glVertex2f(100,100);
    glVertex2f(200,100);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(248,249,249);
    glVertex2f(400,120);
    glVertex2f(500,120);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(248,249,249);
    glVertex2f(400,300);
    glVertex2f(500,300);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(248,249,249);
    glVertex2f(800,130);
    glVertex2f(900,130);
    glEnd();

    moon();
    star();

}

void display5()
{
    // Placeholder for additional graphics elements
    //sky4
    glColor3ub(34,34,34);
    glBegin(GL_POLYGON);
    glVertex2f(0,800);
    glVertex2f(0,410);
    glVertex2f(1000,410);
    glVertex2f(1000,800);
    glEnd();

    //water4
    glColor3ub(47,136,220);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(0,410);
    glVertex2f(1000,410);
    glVertex2f(1000,0);
    glEnd();

    miniices();

    waterlines();

    shipSink -= 5;
    glPushMatrix();
    glTranslated(shipD5,shipSink,0.0);
    glRotated(-10,0,0,1);
    ship();
    glPopMatrix();


    //water4
    glColor3ub(47,166,220);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(0,200);
    glVertex2f(1000,200);
    glVertex2f(1000,0);
    glEnd();


    miniices2();

    //waterlines
    glBegin(GL_POLYGON);
    glColor3ub(248,249,249);
    glVertex2f(100,100);
    glVertex2f(200,100);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(248,249,249);
    glVertex2f(200,200);
    glVertex2f(300,200);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(248,249,249);
    glVertex2f(400,120);
    glVertex2f(500,120);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(248,249,249);
    glVertex2f(400,300);
    glVertex2f(500,300);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(248,249,249);
    glVertex2f(800,130);
    glVertex2f(900,130);
    glEnd();

    moon();
    star();
}

void ship()
{
    // Placeholder for drawing the ship
    //Body
    glTranslated(0,110,0);
    glScaled(28,23,0);

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




    //windows
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

    //Steam Pipes
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

void sky1()
{
    // Placeholder for drawing sky
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3ub(168,243,255);
    glVertex2f(0,800);
    glColor3ub(32,180,220);
    glVertex2f(0,410);
    glColor3ub(168,243,255);
    glVertex2f(1000,410);
    glColor3ub(32,180,220);
    glVertex2f(1000,800);
    glEnd();
    glPopMatrix();
}

void water1()
{
    // Placeholder for drawing water
    glPushMatrix();

    glBegin(GL_POLYGON);
    glColor3ub(75,160,240); // Start with a darker blue
    glVertex2f(0,0);
    glColor3ub(75,160,240); // Transition to a lighter blue
    glVertex2f(0,300);
    glColor3ub(75,160,240); // Continue with the lighter blue
    glVertex2f(1000,400);
    glColor3ub(75,160,240); // Transition back to the darker blue
    glVertex2f(1000,0);
    glEnd();
    glPopMatrix();
}


void ice()
{
    // Placeholder for drawing icebergs
    glPushMatrix();
    glTranslated(400,150,0.0);
    glScaled(20,10,0);
    glColor3ub(255,255,255);

    glBegin(GL_POLYGON);
    glVertex2f(5.5,2.5);

    glVertex2f(12.5,19.5);
    glVertex2f(15,19.5);
    glVertex2f(12.5,19.5);
    glVertex2f(13.5,18.5);
    glVertex2f(16.5,20.5);
    glVertex2f(17.5,18.5);
    glVertex2f(18.5,3.5);
    glVertex2f(19,3);
    glVertex2f(19.5,2.5);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(5.5,2.5);
    glVertex2f(6,3);
    glVertex2f(8.25,3.5);
    glVertex2f(8.5,18.5);
    glVertex2f(12,15);
    glVertex2f(13,17);
    glVertex2f(12.5,19.5);
    glVertex2f(8.5,9.5);
    glVertex2f(12.5,2.5);
    glVertex2f(5.5,2.5);
    glEnd();
    glPopMatrix();


}

void cloud()
{
    glPushMatrix();
    glTranslated(position2,0.0f,0.0f);

    int j;

    GLfloat x = 100.0f;
    GLfloat y = 700.5f;
    GLfloat radius = 25.0f;
    int triangleamount = 20;
    GLfloat twicePI = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255); // White color for clouds
    glVertex2f(x,y);
    for(j=0; j<=triangleamount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePI / triangleamount)),
            y + (radius * sin(j * twicePI / triangleamount))
        );
    }
    glEnd();

    x = 110.0f;
    y = 720.0f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255); // White color for clouds
    glVertex2f(x,y);
    for(j=0; j<=triangleamount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePI / triangleamount)),
            y + (radius * sin(j * twicePI / triangleamount))
        );
    }
    glEnd();

    x = 125.0f;
    y = 700.0f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255); // White color for clouds
    glVertex2f(x,y);
    for(j=0; j<=triangleamount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePI / triangleamount)),
            y + (radius * sin(j * twicePI / triangleamount))
        );
    }
    glEnd();

    glTranslatef(200.0,-60.0f,0.0f);

    x = 100.0f;
    y = 700.0f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255); // White color for clouds
    glVertex2f(x,y);
    for(j=0; j<=triangleamount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePI / triangleamount)),
            y + (radius * sin(j * twicePI / triangleamount))
        );
    }
    glEnd();

    x = 110.0f;
    y = 720.0f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255); // White color for clouds
    glVertex2f(x,y);
    for(j=0; j<=triangleamount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePI / triangleamount)),
            y + (radius * sin(j * twicePI / triangleamount))
        );
    }
    glEnd();

    x = 125.0f;
    y = 700.0f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255); // White color for clouds
    glVertex2f(x,y);
    for(j=0; j<=triangleamount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePI / triangleamount)),
            y + (radius * sin(j * twicePI / triangleamount))
        );
    }
    glEnd();

    glTranslatef(260.0,70.f,0.0f);

    x = 100.0f;
    y = 700.0f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255); // White color for clouds
    glVertex2f(x,y);
    for(j=0; j<=triangleamount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePI / triangleamount)),
            y + (radius * sin(j * twicePI / triangleamount))
        );
    }
    glEnd();

    x = 110.0f;
    y = 720.0f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255); // White color for clouds
    glVertex2f(x,y);
    for(j=0; j<=triangleamount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePI / triangleamount)),
            y + (radius * sin(j * twicePI / triangleamount))
        );
    }
    glEnd();

    x = 125.0f;
    y = 700.0f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255); // White color for clouds
    glVertex2f(x,y);
    for(j=0; j<=triangleamount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePI / triangleamount)),
            y + (radius * sin(j * twicePI / triangleamount))
        );
    }
    glEnd();

    glPopMatrix();
}


void sun()
{
    // Placeholder for drawing sun
    //int i;


}

void sun2()
{
    // Placeholder for drawing another representation of the sun
}

void rain()
{
    // Placeholder for drawing rain
    /*glPushMatrix();
    glTranslated(position4,position1,0.0f);

    glPushMatrix();
    glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-70,470);
    glVertex2f(-50,440);
    glEnd();

    glTranslated(50,20,0.0f);
*/
}

void moon()
{
    // Placeholder for drawing moon
}

void star()
{
    // Placeholder for drawing stars
}

void waterlines()
{
    // Placeholder for drawing water lines
    glBegin(GL_LINES);
    glColor3ub(248,249,249);
    glVertex2f(100,100);
    glVertex2f(100,100);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(248,249,249);
    glVertex2f(200,200);
    glVertex2f(300,200);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(248,249,249);
    glVertex2f(400,120);
    glVertex2f(500,120);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(248,249,249);
    glVertex2f(600,220);
    glVertex2f(700,220);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(248,249,249);
    glVertex2f(400,300);
    glVertex2f(500,300);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(248,249,249);
    glVertex2f(700,300);
    glVertex2f(800,320);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(248,249,249);
    glVertex2f(800,130);
    glVertex2f(900,130);
    glEnd();


}

void windMill()
{
    //propellers
    //1
    glBegin(GL_TRIANGLES);
    glColor3ub(169,50,38);
    glVertex2f(0.0f,0.0f);
    glVertex2f(10.0f,-50.0f);
    glVertex2f(10.0f,50.0f);
    glEnd();

    //2
    glBegin(GL_TRIANGLES);
    glColor3ub(34,153,84);
    glVertex2f(0.0f,0.0f);
    glVertex2f(50.0f,10.0f);
    glVertex2f(-50.0f,10.0f);
    glEnd();

    //3
    glBegin(GL_TRIANGLES);
    glColor3ub(211,84,0);
    glVertex2f(0.0f,0.0f);
    glVertex2f(-10.0f,50.0f);
    glVertex2f(-10.0f,-50.0f);
    glEnd();

    //4
    glBegin(GL_TRIANGLES);
    glColor3ub(36,113,163);
    glVertex2f(0.0f,0.0f);
    glVertex2f(-50.0f,-10.0f);
    glVertex2f(50.0f,-10.0f);
    glEnd();

}

void trees()
{
    /*
    // Placeholder for drawing trees
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3ub(156,139,102);
    glVertex2f(35,330);
    glVertex2f(45,330);
    glVertex2f(45,380);
    glVertex2f(35,380);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(35,174,43);
    glVertex2f(20,380);
    glVertex2f(60,380);
    glVertex2f(40,415);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(36,211,47);
    glVertex2f(20,390);
    glVertex2f(60,390);
    glVertex2f(40,425);
    glEnd();

    glTranslatef(100,15,0.0f);

    glBegin(GL_QUADS)
    glColor3ub(156,139,102);
    glVertex2f(20,390);
    glVertex2f(60,390);
    glVertex2f(40,425);
    glEnd();

    // glTranslatef(100,15,0.0f);
    glColor3ub(36,211,47);
    glVertex2f(20,390);
    glVertex2f(60,390);
    glVertex2f(40,425);
    // glVertex2f(35,380);
    glEnd(); */
}

void birds()
{
    // Placeholder for drawing birds

    /*glPushMatrix();
    glTranslatef(position3,0.0f,0.0f);
    glBegin(GL_TRIANGLES);
    glColor3ub(36,113,163);
    glVertex2f(310.0f,600.0f);
    glVertex2f(320.0f,600.0f);
    glVertex2f(302.0f,608.0f);
    glEnd();

    glBegin(GL_TRIANGLES);*/
}

void miniices()
{
    // Placeholder for drawing mini icebergs
    glPushMatrix();
    glTranslated(200,250,0.0);
    glScaled(6,3,0);
    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
        glVertex2f(5.5,2.5);
        glVertex2f(12.5,19.5);
        glVertex2f(15,19.5);
        glVertex2f(12.5,19.5);
        glVertex2f(13.5,18.5);
        glVertex2f(16.5,20.5);
        glVertex2f(17.5,18.5);
        glVertex2f(18.5,3.5);
        glVertex2f(19,3);
        glVertex2f(19.5,2.5);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(5.5,2.5);
        glVertex2f(6,3);
        glVertex2f(8.25,3.5);
        glVertex2f(8.5,18.5);
        glVertex2f(12,15);
        glVertex2f(13,17);
        glVertex2f(12.5,19.5);
        glVertex2f(8.5,9.5);
        glVertex2f(12.5,2.5);
        glVertex2f(5.5,2.5);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslated(380,350,0.0);
    glScaled(6,3,0);
    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
        glVertex2f(5.5,2.5);
        glVertex2f(12.5,19.5);
        glVertex2f(15,19.5);
        glVertex2f(12.5,19.5);
        glVertex2f(13.5,18.5);
        glVertex2f(16.5,20.5);
        glVertex2f(17.5,18.5);
        glVertex2f(18.5,3.5);
        glVertex2f(19,3);
        glVertex2f(19.5,2.5);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(5.5,2.5);
        glVertex2f(6,3);
        glVertex2f(8.25,3.5);
        glVertex2f(8.5,18.5);
        glVertex2f(12,15);
        glVertex2f(13,17);
        glVertex2f(12.5,19.5);
        glVertex2f(8.5,9.5);
        glVertex2f(12.5,2.5);
        glVertex2f(5.5,2.5);
    glEnd();
    glPopMatrix();
}

void miniices2()
{
    // Placeholder for drawing additional mini icebergs
}

void sound()
{

    //PlaySound("a.wav", NULL, SND_ASYNC|SND_FILENAME);
    //PlaySound("Titanic-Ringtones.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);

}

void sound2()
{
    // Placeholder for stopping sound effects
    //PlaySound(NULL,NULL,SND_ASYNC|SND_FILENAME);
}

int main(int argc,char* argv[])
{
    glutInit(&argc,argv);

    glutInitWindowSize(1280,720);

    glutInitWindowPosition(0,0);

    glutCreateWindow("Titanic");

    glutSpecialFunc(SpecialInput);

    glutDisplayFunc(display);

    glClearColor(0.1f,0.1f,0.1f,0.1f);

    gluOrtho2D(0.0,999.0,0.0,799.0);

    glutTimerFunc(100,update,0);

    // PlaySound("Titanic-Ringtones.wav",NULL,SND_ASYNC);

    glutMainLoop();

    return 0;
}


