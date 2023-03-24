#include <GL/gl.h>
#include <GL/glut.h>

void display(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
	glClear (GL_COLOR_BUFFER_BIT);

    glColor3f (1.0, 1.0, 1.0);
    
    
    // MALHA
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);

    glBegin(GL_TRIANGLE_STRIP);
        glVertex3f (0.46, 0.04, 0.0);
        glVertex3f (0.30, 0.08, 0.0);
        glVertex3f (0.46, 0.08, 0.0);
        glVertex3f (0.34, 0.4, 0.0);
        glVertex3f (0.475, 0.4, 0.0);
    glEnd();

    glFlush ();
}

void displayNew(void){
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glClear (GL_COLOR_BUFFER_BIT);
 
    glColor3f (1.0, 1.0, 1.0);
    
    // PREENCHIDO
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    
    glBegin(GL_TRIANGLE_STRIP);
        glVertex3f (0.46, 0.04, 0.0);
        glVertex3f (0.30, 0.08, 0.0);
        glVertex3f (0.46, 0.08, 0.0);
        glVertex3f (0.34, 0.4, 0.0);
        glVertex3f (0.475, 0.4, 0.0);
    glEnd();

    glFlush ();
}

void init (void) 
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
  case 27:
	exit(0);
	break;
  }
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500); 
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Atividade 1 - OpenGL");
    init ();
    glutDisplayFunc(display); 
    glutKeyboardFunc(keyboard);
    glutMouseFunc(displayNew);
    glutMainLoop();
    return 0;
}
