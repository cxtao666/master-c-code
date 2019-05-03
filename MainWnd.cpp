// MainWnd.cpp: implementation of the CMainWnd class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MainWnd.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CMainWnd::CMainWnd():
	m_hWnd(NULL),
	m_fAngle(0.0f),
	m_hRC(NULL)
{
}

CMainWnd::~CMainWnd()
{
}

//
// GLCube()
// Renders a cube.
//
void GLCube(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2)
{
	glBegin(GL_POLYGON);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(x2, y2, z2);
	glVertex3f(x1, y2, z2);
	glVertex3f(x1, y1, z2);
	glVertex3f(x2, y1, z2);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(x2, y2, z1);
	glVertex3f(x2, y1, z1);
	glVertex3f(x1, y1, z1);
	glVertex3f(x1, y2, z1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(x1, y2, z2);
	glVertex3f(x1, y2, z1);
	glVertex3f(x1, y1, z1);
	glVertex3f(x1, y1, z2);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(x2, y2, z2);
	glVertex3f(x2, y1, z2);
	glVertex3f(x2, y1, z1);
	glVertex3f(x2, y2, z1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(x1, y2, z1);
	glVertex3f(x1, y2, z2);
	glVertex3f(x2, y2, z2);
	glVertex3f(x2, y2, z1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(x1, y1, z1);
	glVertex3f(x2, y1, z1);
	glVertex3f(x2, y1, z2);
	glVertex3f(x1, y1, z2);
	glEnd();
}

//
// InitScene()
// Called when the OpenGL RC has been created. Sets the initial state for
// the OpenGL scene.
//
void CMainWnd::InitScene()
{
	glClearColor(0.000f, 0.000f, 1.000f, 1.0f); //Background color

	// TODO: Replace the following sample code with your initialization code.

	// Activate lighting and a light source
  glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
  glEnable(GL_DEPTH_TEST);

	// Define material parameters
	static GLfloat glfMatAmbient[] = {0.000f, 0.450f, 1.000f, 1.0f};
	static GLfloat glfMatDiffuse[] = {0.000f, 0.000f, 0.580f, 1.0f};
	static GLfloat glfMatSpecular[]= {1.000f, 1.000f, 1.000f, 1.0f};
	static GLfloat glfMatEmission[]= {0.000f, 0.000f, 0.000f, 1.0f};
	static GLfloat fShininess = 128.000f;

	// Set material parameters
	glMaterialfv(GL_FRONT, GL_AMBIENT,  glfMatAmbient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE,  glfMatDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, glfMatSpecular);
	glMaterialfv(GL_FRONT, GL_EMISSION, glfMatEmission);
	glMaterialf(GL_FRONT, GL_SHININESS, fShininess);
}

//
// KillScene()
// Called when the OpenGL RC is about to be destroyed. 
//
void CMainWnd::KillScene()
{
	// TODO: Use KillScene to free resources.
}

//
// DrawScene()
// Called each time the OpenGL scene has to be drawn.
//
void CMainWnd::DrawScene()
{
	// TODO: Replace the following sample code with your code to draw the scene.

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear buffers
  glLoadIdentity(); // Load identity matrix

	// Add a light source
	GLfloat glfLight[] = {-4.0f, 4.0f, 4.0f, 0.0f};
	glLightfv(GL_LIGHT0, GL_POSITION, glfLight);
 
	// Position and rotate the camera
  glTranslatef(0.0f, 0.0f, -5.0f);	
	glRotatef(30.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(m_fAngle, 0.0f, 1.0f, 0.0f);

	// Draw a cube
	static GLfloat r = .7f;
	GLCube(-r, -r, -r, r, r, r);

  glFlush();
}

//
// Tick()
// The applications "heartbeat" function. Called before another frame needs
// to be drawn. Use this function to calculate new positions for objects in 
// the scene, for instance. Set bRedrawScene = FALSE if the scene should not be 
// redrawn.
//
void CMainWnd::Tick(BOOL &bRedrawScene)
{
	m_fAngle+= 1; // Add some rotation to the cube
}

