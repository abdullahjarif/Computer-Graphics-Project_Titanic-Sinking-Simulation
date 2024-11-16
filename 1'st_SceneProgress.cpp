#include<cstdio>
#include<GL/gl.h>
#include<windows.h> // for MS Windows
#include<GL/glut.h> // GLUT, include glu.h and gl.h
#include<math.h>
#include <stdlib.h>
#include<stdio.h>
#define PI 3.1416
// Global variables for ship movement
float shipPosX = -0.01f; // Initial x-position of the ship
float shipSpeed = -0.001f; // Speed of the ship movement

bool isMoving = false;



void Sky()
{
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(102, 212, 238);
    glVertex2f(0.375f, -0.161f);
    glVertex2f(0.542f, -0.153f);
    glVertex2f(0.540f, -0.232f);
    glVertex2f(0.575f, -0.228f);
    glVertex2f(0.820f, -0.042f);
    glVertex2f(1.000f, 0.037f);
    glVertex2f(1.000f, 1.001f);
    glVertex2f(-1.000f, 1.001f);
    glVertex2f(-1.000f, -0.485f);
    glVertex2f(-0.998f, -0.485f);
    glVertex2f(0.342f, -0.481f);
    glVertex2f(0.377f, -0.441f);
    glEnd();

}

void Water()
{
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(47, 136, 220);
    glVertex2f(-0.682f, -0.456f);
    glVertex2f(0.325f, -0.452f);
    glVertex2f(0.194f, -0.997f);
    glVertex2f(-1.000f, -0.997f);
    glVertex2f(-1.002f, -0.459f);
    glVertex2f(-1.002f, -0.463f);
    glEnd();
}

void Ship()
{

    if (isMoving)  // Calculate new ship position
    {
        shipPosX += shipSpeed;
    }

    // Draw the ship at the new position
    glPushMatrix();
    glTranslatef(shipPosX, 0.0f, 0.0f);


    //ship
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(11,62,101);
    glVertex2f(-0.562f, -0.815f);
    glVertex2f(-0.791f, -0.009f);
    glVertex2f(-0.793f, -0.009f);
    glVertex2f(0.296f, -0.274f);
    glVertex2f(0.198f, -0.625f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(124,124,124);
    glVertex2f(-0.415f, 0.106f);
    glVertex2f(-0.415f, 0.256f);
    glVertex2f(0.158f, -0.005f);
    glVertex2f(0.154f, -0.108f);
    glVertex2f(0.227f, -0.135f);
    glVertex2f(0.227f, -0.262f);
    glVertex2f(-0.522f, -0.084f);
    glVertex2f(-0.526f, -0.076f);
    glVertex2f(-0.522f, 0.126f);
    glEnd();

    //pipe1
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,162,0);
    glVertex2f(-0.160f, 0.394f);
    glVertex2f(-0.077f, 0.327f);
    glVertex2f(-0.077f, 0.394f);
    glVertex2f(-0.157f, 0.461f);
    glVertex2f(-0.160f, 0.394f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,0,0);
    glVertex2f(-0.164f, 0.126f);
    glVertex2f(-0.160f, 0.398f);
    glVertex2f(-0.077f, 0.331f);
    glVertex2f(-0.082f, 0.094f);
    glVertex2f(-0.164f, 0.126f);
    glEnd();


    //pipe 2
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,0,0);
    glVertex2f(-0.049f, 0.084f);
    glVertex2f(-0.052f, 0.084f);
    glVertex2f(-0.049f, 0.314f);
    glVertex2f(0.017f, 0.282f);
    glVertex2f(0.013f, 0.061f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,162,0);
    glVertex2f(-0.045f, 0.31f);
    glVertex2f(-0.047f, 0.31f);
    glVertex2f(-0.049f, 0.381f);
    glVertex2f(0.017f, 0.345f);
    glVertex2f(0.017f, 0.278f);
    glEnd();

    //pipe3
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,0,0);
    glVertex2f(0.037f, 0.045f);
    glVertex2f(0.035f, 0.045f);
    glVertex2f(0.040f, 0.262f);
    glVertex2f(0.091f, 0.235f);
    glVertex2f(0.084f, 0.021f);
    glEnd();


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,162,0);
    glVertex2f(0.044f, 0.258f);
    glVertex2f(0.042f, 0.262f);
    glVertex2f(0.042f, 0.318f);
    glVertex2f(0.093f, 0.29f);
    glVertex2f(0.091f, 0.231f);
    glEnd();



//window
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255,255);
    glVertex2f(-0.376f, 0.163f);
    glVertex2f(-0.378f, 0.167f);
    glVertex2f(-0.380f, 0.116f);
    glVertex2f(-0.269f, 0.076f);
    glVertex2f(-0.267f, 0.124f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255,255);
    glVertex2f(-0.238f, 0.069f);
    glVertex2f(-0.240f, 0.069f);
    glVertex2f(-0.240f, 0.116f);
    glVertex2f(-0.145f, 0.08f);
    glVertex2f(-0.147f, 0.033f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255,255);
    glVertex2f(-0.116f, 0.025f);
    glVertex2f(-0.118f, 0.025f);
    glVertex2f(-0.116f, 0.069f);
    glVertex2f(-0.018f, 0.029f);
    glVertex2f(-0.020f, -0.014f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255,255);
    glVertex2f(0.011f, -0.022f);
    glVertex2f(0.008f, -0.022f);
    glVertex2f(0.008f, 0.021f);
    glVertex2f(0.104f, -0.018f);
    glVertex2f(0.104f, -0.062f);
    glEnd();
    glPopMatrix();

}



void Platfrom()
{

    //platfrom
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(168,128,128);
    glVertex2f(0.544f, -0.457f);
    glVertex2f(0.917f, -0.568f);
    glVertex2f(1.002f, -0.568f);
    glVertex2f(1.002f, -1.003f);
    glVertex2f(0.197f, -0.995f);
    glVertex2f(0.197f, -0.995f);
    glVertex2f(0.315f, -0.449f);
    glEnd();




}
void Person(float x, float y)
{
    // Draw head
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(90, 69,60); // Red color for head
    glVertex2f(x, y);
    for (int i = 0; i <= 360; i += 10)
    {
        float angle = i * PI / 180;
        glVertex2f(x + 0.02f * cos(angle), y + 0.02f * sin(angle));
    }
    glEnd();

    // Draw body
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(x, y);
    glVertex2f(x, y - 0.08f); // Length of body can be adjusted
    glEnd();

    // Draw arms
    glBegin(GL_LINES);

    glVertex2f(x, y - 0.03f); // Arm starting point
    glVertex2f(x - 0.03f, y - 0.05f); // Left arm
    glVertex2f(x, y - 0.03f); // Arm starting point
    glVertex2f(x + 0.03f, y - 0.05f); // Right arm
    glEnd();

    // Draw legs
    glBegin(GL_LINES);

    glVertex2f(x, y - 0.08f); // Body ending point
    glVertex2f(x - 0.03f, y - 0.12f); // Left leg
    glVertex2f(x, y - 0.08f); // Body ending point
    glVertex2f(x + 0.03f, y - 0.12f); // Right leg
    glEnd();
}

void drawPeopleOnPlatform()
{
    // Draw people on the platform
    Person(0.5f, -0.5f);
    Person(0.55f, -0.5f);
    Person(0.7f, -0.52f);
    Person(0.6f, -0.5f); // Adjust coordinates as needed
    Person(0.65f, -0.52f);
    Person(0.7f, -0.49f);
    Person(0.75f, -0.55f);
}




void Buildings()
{


    //building
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(166,89,89);
    glVertex2f(0.608f, -0.354f);
    glVertex2f(0.602f, -0.181f);
    glVertex2f(0.817f, 0.001f);
    glVertex2f(0.884f, 0.001f);
    glVertex2f(1.002f, 0.072f);
    glVertex2f(1.002f, -0.568f);
    glVertex2f(0.922f, -0.576f);
    glVertex2f(0.542f, -0.461f);
    glVertex2f(0.540f, -0.465f);
    glVertex2f(0.542f, -0.362f);
    glEnd();


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(166, 89, 89);
    glVertex2f(0.547f, -0.369f);
    glVertex2f(0.547f, -0.475f);
    glVertex2f(0.360f, -0.456f);
    glVertex2f(0.360f, -0.452f);
    glVertex2f(0.356f, -0.155f);
    glVertex2f(0.538f, -0.151f);
    glVertex2f(0.540f, -0.214f);
    glVertex2f(0.607f, -0.207f);
    glVertex2f(0.612f, -0.361f);
    glEnd();
//building

    //w1

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(245,209,158);
    glVertex2f(0.887f, -0.04f);
    glVertex2f(0.887f, -0.139f);
    glVertex2f(1.000f, -0.127f);
    glVertex2f(1.000f, 0.054f);
    glVertex2f(0.885f, -0.04f);

    glEnd();


    //w2
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(245,209,158);
    glVertex2f(0.887f, -0.175f);
    glVertex2f(0.887f, -0.286f);
    glVertex2f(1.000f, -0.29f);
    glVertex2f(1.003f, -0.175f);
    glVertex2f(0.887f, -0.175f);
    glEnd();
    //w3
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(245,209,158);
    glVertex2f(0.918f, -0.554f);
    glVertex2f(0.892f, -0.55f);
    glVertex2f(0.892f, -0.309f);
    glVertex2f(0.889f, -0.305f);
    glVertex2f(1.003f, -0.305f);
    glVertex2f(0.998f, -0.542f);
    glEnd();
//w4
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(242,234,140);
    glVertex2f(0.627f, -0.226f);
    glVertex2f(0.820f, -0.08f);
    glVertex2f(0.816f, -0.179f);
    glVertex2f(0.632f, -0.297f);
    glVertex2f(0.627f, -0.226f);
    glEnd();
//w5
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(242,234,140);
    glVertex2f(0.625f, -0.487f);
    glVertex2f(0.627f, -0.384f);
    glVertex2f(0.656f, -0.388f);
    glVertex2f(0.654f, -0.499f);
    glVertex2f(0.625f, -0.491f);
    glEnd();
//w6
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(242,234,140);
    glVertex2f(0.704f, -0.506f);
    glVertex2f(0.702f, -0.388f);
    glVertex2f(0.744f, -0.38f);
    glVertex2f(0.744f, -0.526f);
    glVertex2f(0.707f, -0.51f);
    glEnd();
//w7
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(242,234,140);
    glVertex2f(0.783f, -0.532f);
    glVertex2f(0.783f, -0.397f);
    glVertex2f(0.820f, -0.4f);
    glVertex2f(0.820f, -0.55f);
    glVertex2f(0.780f, -0.535f);
    glEnd();
//w8
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(242,234,140);
    glVertex2f(0.376f, -0.325f);
    glVertex2f(0.374f, -0.266f);
    glVertex2f(0.372f, -0.262f);
    glVertex2f(0.589f, -0.254f);
    glVertex2f(0.589f, -0.321f);
    glEnd();
//w9
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(242,234,140);
    glVertex2f(0.512f, -0.471f);
    glVertex2f(0.512f, -0.396f);
    glVertex2f(0.478f, -0.396f);
    glVertex2f(0.476f, -0.471f);
    glVertex2f(0.512f, -0.471f);
    glEnd();
//w10
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(242,234,140);
    glVertex2f(0.385f, -0.456f);
    glVertex2f(0.385f, -0.392f);
    glVertex2f(0.409f, -0.388f);
    glVertex2f(0.407f, -0.463f);
    glVertex2f(0.383f, -0.459f);
    glEnd();

}

void drawCircle(float cx, float cy, float radius)
{
    int num_segments = 100;
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < num_segments; i++)
    {
        float theta = 2.0f * PI * float(i) / float(num_segments);
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}
void Cloud()
{
    glColor3ub(255, 255, 255);
    drawCircle(-0.5f, 0.7f, 0.2f);  // Example cloud
    drawCircle(-0.3f, 0.8f, 0.15f);
    drawCircle(-0.5f, 0.7f, 0.1f);
    drawCircle(0.3f, 0.6f, 0.15f);  // Another example cloud
    drawCircle(0.6f, 0.8f, 0.1f);   // Third cloud
    drawCircle(0.5f, 0.7f, 0.2f);   // Third cloud
}



// Keyboard callback function
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 's':
    case 'S':
        isMoving = !isMoving; // Toggle ship movement
        break;
    }
}


void myDisplay(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
//Put your display her

    Sky();

    Water();

    Ship();

    Platfrom();

    Buildings();
    Cloud();
    drawPeopleOnPlatform();





    glFlush ();
}

void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);  // Adjusted to normalized coordinates
}

// Timer function to control ship movement
void timer(int)
{
    glutPostRedisplay(); // Request a redraw
    glutTimerFunc(16, timer, 0); // 60 fps

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1280, 720);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("");
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(keyboard); // Register keyboard input function
    myInit();
    glutTimerFunc(0, timer, 0); // Start the timer
    glutMainLoop();
    return 0;
}
