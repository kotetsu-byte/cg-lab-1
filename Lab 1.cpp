#include "GL\glew.h";
#include "GLFW\glfw3.h";
#include <iostream>

using namespace std;

int main()
{
	if (!glfwInit())
	{
		cerr << "Failed to initialize GLFW" << endl;
		return 1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "Lab 1", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;

	GLenum enm = glewInit();

	if (enm != GLEW_OK)
	{
		cerr << "Failed to initialize GLEW: " << glewGetErrorString(enm) << endl;
		return 1;
	}

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.2f);
		glColor3f(0.6f, 0.2f, 0.3f);
		glVertex2f(-0.5f, 0.2f);
		glVertex2f(0.5f, 0.2f);
		glEnd();

		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.2f);
		glColor3f(0.6f, 0.2f, 0.3f);
		glVertex2f(0.5f, 0.2f);
		glVertex2f(0.5f, -0.2f);
		glEnd();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}