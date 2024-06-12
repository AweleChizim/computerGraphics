#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<stb/stb_image.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>


#include"Texture.h"
#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"
#include"Camera.h"

GLfloat vertices[] =
{//     COORDINATES     /        COLORS      /		TexCoord  //
	-0.5f, 0.0f,  0.5f,     0.96f, 0.76f, 0.76f,	0.0f, 0.0f, //0
	-0.5f, 0.0f, -0.5f,     0.96f, 0.76f, 0.76f,	0.0f, 0.0f, //1
	 0.5f, 0.0f, -0.5f,     0.96f, 0.76f, 0.76f,	0.0f, 0.0f, //2
	 0.5f, 0.0f,  0.5f,     0.96f, 0.76f, 0.76f,	0.0f, 0.0f, //3
	-0.5f, 0.8f,  0.5f,     0.96f, 0.76f, 0.76f,	0.0f, 0.0f, //4
	-0.5f, 0.8f, -0.5f,     0.96f, 0.76f, 0.76f,	0.0f, 0.0f, //5
	 0.5f, 0.8f, -0.5f,     0.96f, 0.76f, 0.76f,	0.0f, 0.0f, //6
	 0.5f, 0.8f,  0.5f,     0.96f, 0.76f, 0.76f,	0.0f, 0.0f, //7
	 0.0f, 1.4f,  0.0f,     0.36f, 0.25f, 0.20f,	2.5f, 5.0f, //8
	-0.3f, 0.7f, -0.51f,     0.08f, 0.05f, 0.03f,	5.0f, 0.0f, //9
	-0.1f, 0.7f, -0.51f,     0.08f, 0.05f, 0.03f,	0.0f, 0.0f, //10
    -0.3f, 0.5f, -0.51f,     0.08f, 0.05f, 0.03f,	5.0f, 0.0f, //11
	-0.1f, 0.5f, -0.51f,     0.08f, 0.05f, 0.03f,	0.0f, 0.0f, //12
	 0.3f, 0.7f, -0.51f,     0.08f, 0.05f, 0.03f,	5.0f, 0.0f, //13
	 0.1f, 0.7f, -0.51f,     0.08f, 0.05f, 0.03f,	0.0f, 0.0f, //14
	 0.3f, 0.5f, -0.51f,     0.08f, 0.05f, 0.03f,	5.0f, 0.0f, //15
	 0.1f, 0.5f, -0.51f,     0.08f, 0.05f, 0.03f,	0.0f, 0.0f, //16
	-0.3f, 0.7f,  0.51f,     0.08f, 0.05f, 0.03f,	5.0f, 0.0f, //17
	-0.1f, 0.7f,  0.51f,     0.08f, 0.05f, 0.03f,	0.0f, 0.0f, //18
	-0.3f, 0.5f,  0.51f,     0.08f, 0.05f, 0.03f,	5.0f, 0.0f, //19
	-0.1f, 0.5f,  0.51f,     0.08f, 0.05f, 0.03f,	0.0f, 0.0f, //20
	 0.3f, 0.7f,  0.51f,     0.08f, 0.05f, 0.03f,	5.0f, 0.0f, //21
	 0.1f, 0.7f,  0.51f,     0.08f, 0.05f, 0.03f,	0.0f, 0.0f, //22
	 0.3f, 0.5f,  0.51f,     0.08f, 0.05f, 0.03f,	5.0f, 0.0f, //23
	 0.1f, 0.5f,  0.51f,     0.08f, 0.05f, 0.03f,	0.0f, 0.0f, //24
	-0.1f, 0.3f,  0.51f,     0.08f, 0.05f, 0.03f,	5.0f, 0.0f, //25
	 0.1f, 0.3f,  0.51f,     0.08f, 0.05f, 0.03f,	0.0f, 0.0f, //26
	-0.1f, 0.0f,  0.51f,     0.08f, 0.05f, 0.03f,	5.0f, 0.0f, //27
	 0.1f, 0.0f,  0.51f,     0.08f, 0.05f, 0.03f,	0.0f, 0.0f, //28
	-0.7f, 0.7f,  0.6f,     0.36f, 0.25f, 0.20f,	0.0f, 0.0f, //29
	-0.7f, 0.7f, -0.6f,     0.36f, 0.25f, 0.20f,	5.0f, 0.0f, //30
	 0.7f, 0.7f, -0.6f,     0.36f, 0.25f, 0.20f,	0.0f, 0.0f, //31
	 0.7f, 0.7f,  0.6f,     0.36f, 0.25f, 0.20f,	5.0f, 0.0f, //32
	-0.05f, 0.25f, 0.515f,     1.08f, 1.05f, 1.03f,		5.0f, 0.0f, //33
	 0.05f, 0.25f, 0.515f,     1.08f, 1.05f, 1.03f,		0.0f, 0.0f, //34
	-0.05f, 0.05f, 0.515f,     1.08f, 1.05f, 1.03f,		5.0f, 0.0f, //35
	 0.05f, 0.05f, 0.515f,     1.08f, 1.05f, 1.03f,		0.0f, 0.0f, //36
	-0.25f, 0.68f, -0.515f,     0.75f, 0.79f, 0.80f,		0.0f, 0.0f, //37
	-0.15f, 0.68f, -0.515f,     0.75f, 0.79f, 0.80f,		0.0f, 0.0f, //38
	-0.25f, 0.52f, -0.515f,     0.75f, 0.79f, 0.80f,		0.0f, 0.0f, //39
	-0.15f, 0.52f, -0.515f,     0.75f, 0.79f, 0.80f,		0.0f, 0.0f, //40
	 0.25f, 0.68f, -0.515f,     0.75f, 0.79f, 0.80f,		0.0f, 0.0f, //41
	 0.15f, 0.68f, -0.515f,     0.75f, 0.79f, 0.80f,		0.0f, 0.0f, //42
	 0.25f, 0.52f, -0.515f,     0.75f, 0.79f, 0.80f,		0.0f, 0.0f, //43
	 0.15f, 0.52f, -0.515f,     0.75f, 0.79f, 0.80f,		0.0f, 0.0f, //44
	-0.25f, 0.68f,  0.515f,     0.75f, 0.79f, 0.80f,		0.0f, 0.0f, //45
	-0.15f, 0.68f,  0.515f,     0.75f, 0.79f, 0.80f,		0.0f, 0.0f, //46
	-0.25f, 0.52f,  0.515f,     0.75f, 0.79f, 0.80f,		0.0f, 0.0f, //47
	-0.15f, 0.52f,  0.515f,     0.75f, 0.79f, 0.80f,		0.0f, 0.0f, //48
	 0.25f, 0.68f,  0.515f,     0.75f, 0.79f, 0.80f,		0.0f, 0.0f, //49
	 0.15f, 0.68f,  0.515f,     0.75f, 0.79f, 0.80f,		0.0f, 0.0f, //50
	 0.25f, 0.52f,  0.515f,     0.75f, 0.79f, 0.80f,		0.0f, 0.0f, //51
	 0.15f, 0.52f,  0.515f,     0.75f, 0.79f, 0.80f,		0.0f, 0.0f, //52



};

// Indices for vertices order
GLuint indices[] =
{
    0, 1, 2, //down square
	0, 2, 3, //down square
	4, 5, 6, //up square & roof base
	4, 6, 7, //up square & roof base
	0, 1, 4, //left square
	1, 5, 4, //left square
	2, 3, 6, //right square
	3, 6, 7, //right square
	1, 2, 5, //back square
	2, 6, 5, //back square
	0, 3, 4, //front square
	3, 4, 7, //front square
	29, 30, 8, //left roof side 1
	30, 31, 8, //back roof side 2
	31, 32, 8, //right roof side 3
	32, 29, 8,  //front roof side 4
	9, 10, 11, //back window frame 1
	10, 12, 11, //back window frame 1
	13, 14, 15, //back window frame 2
	14, 16, 15, //back window frame 2
	17, 18, 19, //front window frame 1
	18, 20, 19, //front window frame 1
	21, 22, 23, //front window frame 2
	22, 24, 23, //front window frame 2
	25, 26, 27, //door frame
	26, 28, 27, //door frame
	33, 34, 35, //door
	34, 36, 35, //door
	37, 38, 39, //back window 1
	38, 40, 39, //back window 1
	41, 42, 43, //back window 2
	42, 44, 43, //back window 2
	45, 46, 47, //front window 1
	46, 48, 47, //front window 1
	49, 50, 51, //front window 2
	50, 52, 51, //front window 2


};

int main() 
{
	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFWwindow object of 800 by 800 pixels, naming it "YoutubeOpenGL"
	GLFWwindow* window = glfwCreateWindow(800, 800, "ProjectOpenGL", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, 800, 800);



	// Generates Shader object using shaders default.vert and default.frag
	Shader shaderProgram("default.vert", "default.frag");


	// Generates Vertex Array Object and binds it
	VAO VAO1;
	VAO1.Bind();

	// Generates Vertex Buffer Object and links it to vertices
	VBO VBO1(vertices, sizeof(vertices));
	// Generates Element Buffer Object and links it to indices
	EBO EBO1(indices, sizeof(indices));

	// Links VBO attributes such as coordinates and colors to VAO
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	// Unbind all to prevent accidentally modifying them
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	// Gets ID of uniform called "scale"
	GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");

	// Texture
	Texture brickTex("texture.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	brickTex.texUnit(shaderProgram, "tex0", 0);
	Texture grassTex("texture.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	grassTex.texUnit(shaderProgram, "tex1", 0);

	// Variables that help the rotation of the pyramid
	float rotation = 0.0f;
	double prevTime = glfwGetTime();

	// Enables the Depth Buffer
	glEnable(GL_DEPTH_TEST);

	//Creates camera object
	//Camera camera(800, 800, glm::vec3(0.0f, 0.0f, 2.0f));

	
	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		// Specify the color of the background
		glClearColor(0.50f, 0.50f, 0.50f, 1.0f);
		// Clean the back buffer and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// Tell OpenGL which Shader Program we want to use
		shaderProgram.Activate();

		// Simple timer
		double crntTime = glfwGetTime();
		if (crntTime - prevTime >= 1/60.0)
		{
			rotation += 0.5f;
			prevTime = crntTime;
		}

		// Initializes matrices so they are not the null matrix
		glm::mat4 model = glm::mat4(1.0f);
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 proj = glm::mat4(1.0f);
		glm::mat4 scale = glm::mat4(1.0f);

		// Assigns different transformations to each matrix
		model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 1.0f, 0.0f));
		view = glm::translate(view, glm::vec3(0.0f, -0.5f, -2.0f));
		proj = glm::perspective(glm::radians(45.0f), (float)800 / 800, 0.1f, 100.0f);
		model = glm::scale(model, glm::vec3(0.8f, 0.8f, 0.8f));


		// Outputs the matrices into the Vertex Shader
		int modelLoc = glGetUniformLocation(shaderProgram.ID, "model");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		int viewLoc = glGetUniformLocation(shaderProgram.ID, "view");
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		int projLoc = glGetUniformLocation(shaderProgram.ID, "proj");
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));


		// Assigns a value to the uniform; NOTE: Must always be done after activating the Shader Program
		glUniform1f(uniID, 0.3f);

		/*// Handles camera inputs
		camera.Inputs(window);
		// Updates and exports the camera matrix to the Vertex Shader
		camera.Matrix(45.0f, 0.1f, 100.0f, shaderProgram, "camMatrix");
		*/

		// Binds texture so that is appears in rendering
		brickTex.Bind();
		grassTex.Bind();
		// Bind the VAO so OpenGL knows to use it
		VAO1.Bind();
		// Draw primitives, number of indices, datatype of indices, index of indices
		glDrawElements(GL_TRIANGLES, 150, GL_UNSIGNED_INT, 0);
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}

	// Delete all the objects we've created
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	brickTex.Delete();
	grassTex.Delete();
	shaderProgram.Delete();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}