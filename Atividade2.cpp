#include<stdlib.h>
#include<GL/glut.h>

static int rot = 0;
static int zoom = 0;
static int lat = 0;

void init(void){
  glClearColor (0.0, 0.0, 0.0, 0.0);
}

void display(void){
  glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

glPushMatrix();
glTranslatef(lat, 0.0, zoom);
glRotatef((GLfloat) rot, 0.0, 1.0, 0.0);


//chao
glColor3f(0.3, 0.3, 0.3);
glPushMatrix();
glTranslatef(1.0, 0.0, -4.0);
glScalef(12.0, 0.2, 24.0);
glutSolidCube(1.0);
glPopMatrix();

// ################## COBERTURA ABAIXO ##################
glColor3f(0.6, 0.6, 0.6);
//teto
glPushMatrix();
glTranslatef(-0.5, 4.7, -4.0);
glScalef(9.0, 1.0, 24.0);
glutSolidCube(1.0);
glPopMatrix();

//fundo
glPushMatrix();
glTranslatef(-0.5, 2.15, -15.5);
glScalef(9.0, 4.1, 1.0);
glutSolidCube(1.0);
glPopMatrix();
// ################## COBERTURA ACIMA ##################

// ################## LAMPADAS ABAIXO ##################

glColor3f(1.0, 1.0, 1.0);

// linha 0
glPushMatrix();
glTranslatef(-4.2, 4.4, 0.0);
glRotatef(90.0, -1.0, 0.0, 0.0);
glutSolidCone(0.25, 0.1, 13, 13);
glPopMatrix();

glPushMatrix();
glTranslatef(3.0, 4.4, 0.0);
glRotatef(90.0, -1.0, 0.0, 0.0);
glutSolidCone(0.25, 0.1, 13, 13);
glPopMatrix();

// linha 1
glPushMatrix();
glTranslatef(-4.2, 4.4, -2.0);
glRotatef(90.0, -1.0, 0.0, 0.0);
glutSolidCone(0.25, 0.1, 13, 13);
glPopMatrix();

glPushMatrix();
glTranslatef(3.0, 4.4, -2.0);
glRotatef(90.0, -1.0, 0.0, 0.0);
glutSolidCone(0.25, 0.1, 13, 13);
glPopMatrix();

// linha 2
glPushMatrix();
glTranslatef(-4.2, 4.4, -4.0);
glRotatef(90.0, -1.0, 0.0, 0.0);
glutSolidCone(0.25, 0.1, 13, 13);
glPopMatrix();

glPushMatrix();
glTranslatef(3.0, 4.4, -4.0);
glRotatef(90.0, -1.0, 0.0, 0.0);
glutSolidCone(0.25, 0.1, 13, 13);
glPopMatrix();

// linha 3
glPushMatrix();
glTranslatef(-4.2, 4.4, -6.0);
glRotatef(90.0, -1.0, 0.0, 0.0);
glutSolidCone(0.25, 0.1, 13, 13);
glPopMatrix();

glPushMatrix();
glTranslatef(3.0, 4.4, -6.0);
glRotatef(90.0, -1.0, 0.0, 0.0);
glutSolidCone(0.25, 0.1, 13, 13);
glPopMatrix();

// linha 4
glPushMatrix();
glTranslatef(-4.2, 4.4, -8.0);
glRotatef(90.0, -1.0, 0.0, 0.0);
glutSolidCone(0.25, 0.1, 13, 13);
glPopMatrix();

glPushMatrix();
glTranslatef(3.0, 4.4, -8.0);
glRotatef(90.0, -1.0, 0.0, 0.0);
glutSolidCone(0.25, 0.1, 13, 13);
glPopMatrix();

// ################## LAMPADAS ACIMA ##################



// PILASTRA 1 ATRAS direita

glColor4f(0.5, 0.2, 0.0, 0.0);
glPushMatrix();
glTranslatef(-1.0, 1.2, -25.0);
glScalef(1., 5.2, 9.8);
glutSolidCube(1.0);
glPopMatrix();

//parede lateral direita

glColor4f(0.5, 0.2, 0.0, 0.0);
glPushMatrix();
glTranslatef(1.8, 1.2, -25.0);
glScalef(4.5, 5.2, 9.8);
glutSolidCube(1.0);
glPopMatrix();

// Parede ATRAS esquerda

glMatrixMode(GL_MODELVIEW); //efeito espelhado
glPushMatrix();
glColor4f(0.5f, 0.5f, 0.5f, 1.0f);
glTranslatef(-4.3, 0.5, -25.5);
glScalef(0.5, 3.7, 9.8);
glutSolidCube(1.0);

glPopMatrix();

//parede de baixo
glColor4f(0.0, 0.0, 0.0, 0.0);
glPushMatrix();
glTranslatef(-4.3, -0.7, -25.5);
glScalef(0.5, 1.4, 9.8);
glutSolidCube(1.0);
glPopMatrix();


// Parede superior esquerda

glColor4f(0.5, 0.2, 0.0, 0.0);
glPushMatrix();
glTranslatef(-2.5, 3.7, -25.0);
glScalef(-4.0, 2.8, 9.8);
glutSolidCube(1.0);
glPopMatrix();

// Pilastra Superior Esquerda

glColor4f(0.5, 0.2, 0.0, 0.0);
glPushMatrix();
glTranslatef(-3.7, 4.5, -25.0);
glScalef(1.5, 1.5, 9.8);
glutSolidCube(1.0);
glPopMatrix();

// HORIZONTAL SUPERIOR PRETA

glColor4f(0.0, 0.0, 0.0, 0.0);
glPushMatrix();
glTranslatef(0.7, 4.5, -25.0);
glScalef(-9.1, 1.5, 9.8);
glutSolidCube(1.0);
glPopMatrix();

/*estaca lado direito tr?s*/
glColor3f(1.0, 1.0, 1.0);
glPushMatrix();
glTranslatef(-1.8, 0.1, -26.0);
glScalef(0.2, 4.0, 0.2);
glutSolidCube(1.0);
glPopMatrix();

/*estaca lado esquerdo tr?s*/
glColor3f(1.0, 1.0, 1.0);
glPushMatrix();
glTranslatef(-4.1, 0.1, -26.0);
glScalef(0.2, 4.0, 0.2);
glutSolidCube(1.0);
glPopMatrix();

// estaca inferiores port?o //
glColor3f(1.0, 1.0, 1.0);

glPushMatrix();
glTranslatef(-3.0, 0.4, -26.0);
glScalef(2.1, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(-3.0, 0.8, -26.0);
glScalef(2.1, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();


glPushMatrix();
glTranslatef(-3.0, 1.2, -26.0);
glScalef(2.1, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(-3.0, 1.6, -26.0);
glScalef(2.1, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(-3.0, 2.0, -26.0);
glScalef(2.1, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(-3.0, 0.0, -26.0);
glScalef(2.1, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(-3.0, -0.4, -26.0);
glScalef(2.1, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(-3.0, -0.8, -26.0);
glScalef(2.1, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(-3.0, -1.2, -26.0);
glScalef(2.1, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(-3.0, -1.6, -26.0);
glScalef(2.1, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

// ################## PORTAO FRONTAL 1 ABAIXO ##################
glPushMatrix();
glTranslatef(-1.7, 0.0, -0.7);
glRotatef(-90.0, 0.0, 1.0, 0.0);

/*estacas horizontais portao*/
glColor3f(1.0, 1.0, 1.0);

glPushMatrix();
glTranslatef(0.0, 0.3, 2.7);
glScalef(5.8, 0.2, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 0.8, 2.7);
glScalef(5.8, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 1.3, 2.7);
glScalef(5.8, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 1.8, 2.7);
glScalef(5.8, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 2.3, 2.7);
glScalef(5.8, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 2.8, 2.7);
glScalef(5.8, 0.2, 0.1);
glutSolidCube(1.0);
glPopMatrix();

/*estacas verticais portao*/
glPushMatrix();
glTranslatef(-3.0, 1.5, 2.7);
glScalef(0.2, 2.8, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(3.0, 1.5, 2.7);
glScalef(0.2, 2.8, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPopMatrix();
// ################## PORTAO FRONTAL 1 ACIMA ##################

// ################## PORTAO FRONTAL 2 ABAIXO ##################
glPushMatrix();
glTranslatef(-1.7, 0.0, -6.9);
glRotatef(-90.0, 0.0, 1.0, 0.0);

/*estacas horizontais portao*/
glColor3f(1.0, 1.0, 1.0);

glPushMatrix();
glTranslatef(0.0, 0.3, 2.7);
glScalef(5.8, 0.2, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 0.8, 2.7);
glScalef(5.8, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 1.3, 2.7);
glScalef(5.8, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 1.8, 2.7);
glScalef(5.8, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 2.3, 2.7);
glScalef(5.8, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 2.8, 2.7);
glScalef(5.8, 0.2, 0.1);
glutSolidCube(1.0);
glPopMatrix();

/*estacas verticais portao*/
glPushMatrix();
glTranslatef(-3.0, 1.5, 2.7);
glScalef(0.2, 2.8, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(3.0, 1.5, 2.7);
glScalef(0.2, 2.8, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPopMatrix();
// ################## PORTAO FRONTAL 2 ACIMA ##################

// ################## PORTAO ENTRE PILASTRAS LATERAIS ABAIXO ##################
glPushMatrix();
glTranslatef(-0.6, 0.0, -0.2);

/*estacas horizontais portao*/
glColor3f(1.0, 1.0, 1.0);

glPushMatrix();
glTranslatef(0.0, 0.3, 2.7);
glScalef(5.8, 0.2, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 0.8, 2.7);
glScalef(5.8, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 1.3, 2.7);
glScalef(5.8, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 1.8, 2.7);
glScalef(5.8, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 2.3, 2.7);
glScalef(5.8, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 2.8, 2.7);
glScalef(5.8, 0.2, 0.1);
glutSolidCube(1.0);
glPopMatrix();

/*estacas verticais portao*/
glPushMatrix();
glTranslatef(-3.0, 1.5, 2.7);
glScalef(0.2, 2.8, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(3.0, 1.5, 2.7);
glScalef(0.2, 2.8, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPopMatrix();
// ################## PORTAO ENTRE PILASTRAS LATERAIS ACIMA ##################

// ################## PILASTRA 1 ABAIXO ##################
glColor4f(0.5, 0.2, 0.0, 0.0);
glPushMatrix();
// altura = altura_chao/2 + altura_obj/2
glTranslatef(-4.2, 2.2, 2.5);
glScalef(1.2, 4.2, 0.2);
glutSolidCube(1.0);
glPopMatrix();

//detalhes pilastra 1
glColor4f(0.6, 0.3, 0.0, 0.0);
//linha 0
//cima
glPushMatrix();
glTranslatef(-4.5, 0.4, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//baixo
glPushMatrix();
glTranslatef(-4.2, 0.4, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//cima
glPushMatrix();
glTranslatef(-3.9, 0.4, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//linha 1
//baixo
glPushMatrix();
glTranslatef(-4.5, 0.8, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//cima
glPushMatrix();
glTranslatef(-4.2, 0.8, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//baixo
glPushMatrix();
glTranslatef(-3.9, 0.8, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//linha 3
//cima
glPushMatrix();
glTranslatef(-4.5, 1.2, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//baixo
glPushMatrix();
glTranslatef(-4.2, 1.2, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//cima
glPushMatrix();
glTranslatef(-3.9, 1.2, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//linha 4
//baixo
glPushMatrix();
glTranslatef(-4.5, 1.6, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//cima
glPushMatrix();
glTranslatef(-4.2, 1.6, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//baixo
glPushMatrix();
glTranslatef(-3.9, 1.6, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//linha 5
//cima
glPushMatrix();
glTranslatef(-4.5, 2.0, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//baixo
glPushMatrix();
glTranslatef(-4.2, 2.0, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//cima
glPushMatrix();
glTranslatef(-3.9, 2.0, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//linha 6
//baixo
glPushMatrix();
glTranslatef(-4.5, 2.4, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//cima
glPushMatrix();
glTranslatef(-4.2, 2.4, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//baixo
glPushMatrix();
glTranslatef(-3.9, 2.4, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//linha 7
//cima
glPushMatrix();
glTranslatef(-4.5, 2.8, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//baixo
glPushMatrix();
glTranslatef(-4.2, 2.8, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//cima
glPushMatrix();
glTranslatef(-3.9, 2.8, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//linha 8
//baixo
glPushMatrix();
glTranslatef(-4.5, 3.2, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//cima
glPushMatrix();
glTranslatef(-4.2, 3.2, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//baixo
glPushMatrix();
glTranslatef(-3.9, 3.2, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//linha 9
//cima
glPushMatrix();
glTranslatef(-4.5, 3.6, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//baixo
glPushMatrix();
glTranslatef(-4.2, 3.6, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//cima
glPushMatrix();
glTranslatef(-3.9, 3.6, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//linha 10
//baixo
glPushMatrix();
glTranslatef(-4.5, 4.0, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//cima
glPushMatrix();
glTranslatef(-4.2, 4.0, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//baixo
glPushMatrix();
glTranslatef(-3.9, 4.0, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

// ################## PILASTRA 1 ACIMA ##################

// ################## PILASTRA 2 ABAIXO ##################
glColor4f(0.5, 0.2, 0.0, 0.0);
glPushMatrix();
// altura = altura_chao/2 + altura_obj/2
glTranslatef(3.0, 2.2, 2.5);
glScalef(1.2, 4.2, 0.2);
glutSolidCube(1.0);
glPopMatrix();

//detalhes pilastra 2
glColor4f(0.6, 0.3, 0.0, 0.0);
//linha 0
//cima
glPushMatrix();
glTranslatef(3.3, 0.4, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//baixo
glPushMatrix();
glTranslatef(3.0, 0.4, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//cima
glPushMatrix();
glTranslatef(2.7, 0.4, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//linha 1
//baixo
glPushMatrix();
glTranslatef(3.3, 0.8, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//cima
glPushMatrix();
glTranslatef(3.0, 0.8, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//baixo
glPushMatrix();
glTranslatef(2.7, 0.8, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//linha 3
//cima
glPushMatrix();
glTranslatef(3.3, 1.2, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//baixo
glPushMatrix();
glTranslatef(3.0, 1.2, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//cima
glPushMatrix();
glTranslatef(2.7, 1.2, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//linha 4
//baixo
glPushMatrix();
glTranslatef(3.3, 1.6, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//cima
glPushMatrix();
glTranslatef(3.0, 1.6, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//baixo
glPushMatrix();
glTranslatef(2.7, 1.6, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//linha 5
//cima
glPushMatrix();
glTranslatef(3.3, 2.0, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//baixo
glPushMatrix();
glTranslatef(3.0, 2.0, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//cima
glPushMatrix();
glTranslatef(2.7, 2.0, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//linha 6
//baixo
glPushMatrix();
glTranslatef(3.3, 2.4, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//cima
glPushMatrix();
glTranslatef(3.0, 2.4, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//baixo
glPushMatrix();
glTranslatef(2.7, 2.4, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//linha 7
//cima
glPushMatrix();
glTranslatef(3.3, 2.8, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//baixo
glPushMatrix();
glTranslatef(3.0, 2.8, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//cima
glPushMatrix();
glTranslatef(2.7, 2.8, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//linha 8
//baixo
glPushMatrix();
glTranslatef(3.3, 3.2, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//cima
glPushMatrix();
glTranslatef(3.0, 3.2, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//baixo
glPushMatrix();
glTranslatef(2.7, 3.2, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//linha 9
//cima
glPushMatrix();
glTranslatef(3.3, 3.6, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//baixo
glPushMatrix();
glTranslatef(3.0, 3.6, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//cima
glPushMatrix();
glTranslatef(2.7, 3.6, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//linha 10
//baixo
glPushMatrix();
glTranslatef(3.3, 4.0, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//cima
glPushMatrix();
glTranslatef(3.0, 4.0, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

//baixo
glPushMatrix();
glTranslatef(2.7, 4.0, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.18);
glutSolidTetrahedron();
glPopMatrix();

/*estaca lado esquerdo frente*/
glColor3f(1.0, 1.0, 0.0);
glPushMatrix();
glTranslatef(-2.5, 0.7, 3.0);
glScalef(0.2, 1.2, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(-2.5, 0.7, 7.0);
glScalef(0.2, 1.2, 0.1);
glutSolidCube(1.0);
glPopMatrix();


/*estaca lado direito frente*/
glPushMatrix();
glTranslatef(2.5, 0.7, 3.0);
glScalef(0.2, 1.2, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(2.5, 0.7, 7.0);
glScalef(0.2, 1.2, 0.1);
glutSolidCube(1.0);
glPopMatrix();

//lateral direita
glColor3f(1.0, 1.0, 1.0);

glPushMatrix();
glTranslatef(2.5, 1.2, 4.9);
glScalef(0.1, 0.1, 3.8);
glutSolidCube(1.0);
glPopMatrix();

glPopMatrix();



  glutSwapBuffers();
}

void reshape (int w, int h){
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 40.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
glTranslatef(0.0, -2.0, -12.0);
}
void keyboard(unsigned char key, int x, int y){
  switch (key) {
case 'w':
zoom += 2;
glutPostRedisplay();
break;
case 's':
zoom -= 2;
glutPostRedisplay();
break;
case 'a':
lat += 2;
glutPostRedisplay();
break;
case 'd':
lat -= 2;
glutPostRedisplay();
break;
case 'r':
rot = (rot+5) % 360;
glutPostRedisplay();
break;
case 'R':
rot = (rot-5) % 360;
glutPostRedisplay();
break;
  case 27:                                         // tecla Esc (encerra o programa)
	exit(0);
	break;
  }
}

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glEnable(GL_DEPTH_TEST);
  glutInitWindowSize (500, 500); 
  glutInitWindowPosition (100, 100);
  glutCreateWindow ("Atividade 2 - OpenGL");
  init ();
  glutDisplayFunc(display); 
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}
