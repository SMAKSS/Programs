
#include <math.h>
#include <GL/glut.h>

static GLfloat x = 0.0;
static GLfloat y = 0.0;
static GLfloat z = 0.0;
static GLfloat t = 0.0;
static GLfloat r;
static GLfloat dr;
static GLfloat gu[190];
static GLfloat gx[190];
static GLfloat gy[190];
static int n = 190;
static int c = 1;

void display(void) {

    glEnable(GL_DEPTH_TEST);
    /* clear all pixels */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glOrtho(-3.0, 9.0, -10.0, 10.0, -50.0, 50.0);

    glColor3f(0.0, 0.8, 1.0);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < c; i++)
        glVertex3f(gx[i]-2, gy[i]-2, z-2);
    glEnd();

    /* don't wait, start processing buffered OpenGL routines */
    glFlush();
}

void timehandler(int)
{
    if (t < 10.01)
    {
        t += 0.01;
        for (int i = 1; i < n; i++) {
            if (r <= gu[i]) {
                x = (i - 1) * 0.05;
                double uwe = (r - gu[i - 1]);
                double uwe2 = (gu[i] - gu[i - 1]);
                x +=  uwe / uwe2 * 0.05;
                gx[c] = x;
                y = 5*sin(x);
                gy[c] = y;
                c++;
                break;
            }
        }
        r += dr;
    }
    else {
        t = 0.0;
        c = 1;
        r = dr;
    }
    glLoadIdentity();
    glutPostRedisplay();
    glutTimerFunc(20, timehandler, 0);
}

void lengthofcurve() {
    gu[0] = 0;
    gx[0] = 0;
    gy[0] = 0;
    GLfloat x1;
    GLfloat x2;

    GLfloat y1;
    GLfloat y2;
    for (int i = 1; i < n; i++) {
        x1 = t;
        y1 = 5*sin(t);
        t += 0.05;
        x2 = t;
        y2 = 5*sin(t);

        gu[i] = gu[i - 1] + sqrt(pow(y2 - y1, 2.0) + pow(x2 - x1, 2.0));
    }
    dr = gu[n - 1] / (n - 1);
    r = dr;
    t = 0.0;
}

void init(void) {

    /* select clearing (background) color */
    glClearColor(0.0, 0.0, 0.0,1.0);

    /* initialize viewing values */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
//    glOrtho(0.0, 10.0, 0.0, 190.0, -50.0, 50.0);
    lengthofcurve();
}

/* Declare initial window size, position, and display mode
 * (single buffer and RGBA). Open window with "hello"
 * in its title bar. Call initialization routines.
 * Register callback function to display graphics.
 * Enter main loop and process events. */

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1900, 700);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Curve");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(500, timehandler, 0);
    glutMainLoop();
    return 0;	/* ISO C requires main to return int. */
}
