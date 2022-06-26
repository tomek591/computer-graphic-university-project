/*
Niniejszy program jest wolnym oprogramowaniem; możesz go
rozprowadzać dalej i / lub modyfikować na warunkach Powszechnej
Licencji Publicznej GNU, wydanej przez Fundację Wolnego
Oprogramowania - według wersji 2 tej Licencji lub(według twojego
wyboru) którejś z późniejszych wersji.

Niniejszy program rozpowszechniany jest z nadzieją, iż będzie on
użyteczny - jednak BEZ JAKIEJKOLWIEK GWARANCJI, nawet domyślnej
gwarancji PRZYDATNOŚCI HANDLOWEJ albo PRZYDATNOŚCI DO OKREŚLONYCH
ZASTOSOWAŃ.W celu uzyskania bliższych informacji sięgnij do
Powszechnej Licencji Publicznej GNU.

Z pewnością wraz z niniejszym programem otrzymałeś też egzemplarz
Powszechnej Licencji Publicznej GNU(GNU General Public License);
jeśli nie - napisz do Free Software Foundation, Inc., 59 Temple
Place, Fifth Floor, Boston, MA  02110 - 1301  USA
*/

#define GLM_FORCE_RADIANS
#define GLM_FORCE_SWIZZLE

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdlib.h>
#include <stdio.h>
#include "constants.h"
#include "lodepng.h"
#include "shaderprogram.h"
#include "myCube.h"
#include "myTeapot.h"
#include "blockade.h"
#include "ground.h" // import
#include "rock.h"
#include "leftTrack.h"
#include "rightTrack.h"
#include "cannon.h"
#include "tank.h"

float speed_x=0;
float speed_y=0;
float aspectRatio=1;

bool isWPressed = false;
bool isSPressed = false;
bool isAPressed = false;
bool isDPressed = false;
bool isEPressed = false;
bool isQPressed = false;
float tankX = 0;
float tankZ = 0;;
float tankAngleY = 0;
int tankSpeed = 10;
int tankAngleSpeed = 2;
float cannonAngleY = 0;
int cannonAngleSpeed = 2;
float leftTrackOffset = 0;
float rightTrackOffset = 0;
float trackOffsetSpeed = 2;


ShaderProgram *sp;
ShaderProgram *tracksp;
GLuint groundTex; //Uchwyt
GLuint rockTex; //Uchwyt
GLuint trackTex; //Uchwyt
GLuint tankTex; //Uchwyt

//Odkomentuj, żeby rysować kostkę
/*
float* vertices = myCubeVertices;
float* normals = myCubeNormals;
float* texCoords = myCubeTexCoords;
float* colors = myCubeColors;
int vertexCount = myCubeVertexCount;
*/

//Odkomentuj, żeby rysować czajnik
//float* vertices = myTeapotVertices;
//float* normals = myTeapotNormals;
//float* texCoords = myTeapotTexCoords;
//float* colors = myTeapotColors;
//int vertexCount = myTeapotVertexCount;





//Odkomentuj, żeby rysować kostkę

/*
float* vertices = blokadaVertices;
float* normals = blokadaVertexNormals;
float* texCoords = blokadaTexCoords;
float* colors = myCubeColors;
int vertexCount = blokadaVertexCount;
s
int* indexes = blokadaIndexes;
unsigned int indexCount = blokadaindexCount;
*/

/*
float* vertices = groundVertices;
float* normals = groundVertexNormals;
float* texCoords = groundTexCoords;
int vertexCount = groundVertexCount;
int* indexes = groundIndexes;
unsigned int indexCount = groundIndexCount;float* colors = groundColors;
*/




/*
float* vertices = rockVertices;
float* normals = rockVertexNormals;
float* texCoords = rockTexCoords;
int vertexCount = rockVertexCount;
int* indexes = rockIndexes;
unsigned int indexCount = rockIndexCount;
float* colors = groundColors;


*/
//Procedura obsługi błędów
void error_callback(int error, const char* description) {
	fputs(description, stderr);
}


void keyCallback(GLFWwindow* window,int key,int scancode,int action,int mods) {
    if (action==GLFW_PRESS) {
        if (key==GLFW_KEY_LEFT) speed_x=-PI/2;
        if (key==GLFW_KEY_RIGHT) speed_x=PI/2;
        if (key==GLFW_KEY_UP) speed_y=PI/2;
        if (key==GLFW_KEY_DOWN) speed_y=-PI/2;

		
		if (key == GLFW_KEY_W) isWPressed = true;
		if (key == GLFW_KEY_S) isSPressed = true;
		if (key == GLFW_KEY_A) isAPressed = true;
		if (key == GLFW_KEY_D) isDPressed = true;
		if (key == GLFW_KEY_E) isEPressed = true;
		if (key == GLFW_KEY_Q) isQPressed = true;
	}
    if (action==GLFW_RELEASE) {

		if (key == GLFW_KEY_LEFT) speed_x = 0;
		if (key == GLFW_KEY_RIGHT) speed_x = 0;
		if (key == GLFW_KEY_UP) speed_y = 0;
		if (key == GLFW_KEY_DOWN) speed_y = 0;


        if (key== GLFW_KEY_W) isWPressed =false;
        if (key==GLFW_KEY_S) isSPressed = false;
        if (key==GLFW_KEY_A) isAPressed = false;
        if (key==GLFW_KEY_D) isDPressed = false;
		if (key == GLFW_KEY_E) isEPressed = false;
		if (key == GLFW_KEY_Q) isQPressed = false;
    }






}
GLuint readTexture(const char* filename) {
	GLuint tex;
	glActiveTexture(GL_TEXTURE0);

	//Wczytanie do pamięci komputera
	std::vector<unsigned char> image;   //Alokuj wektor do wczytania obrazka
	unsigned width, height;   //Zmienne do których wczytamy wymiary obrazka
	//Wczytaj obrazek
	unsigned error = lodepng::decode(image, width, height, filename);

	//Import do pamięci karty graficznej
	glGenTextures(1, &tex); //Zainicjuj jeden uchwyt
	glBindTexture(GL_TEXTURE_2D, tex); //Uaktywnij uchwyt
	//Wczytaj obrazek do pamięci KG skojarzonej z uchwytem
	glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, (unsigned char*)image.data());
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
		GL_NEAREST_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return tex;
}


void windowResizeCallback(GLFWwindow* window,int width,int height) {
    if (height==0) return;
    aspectRatio=(float)width/(float)height;
    glViewport(0,0,width,height);
}

//Procedura inicjująca
void initOpenGLProgram(GLFWwindow* window) {
	//************Tutaj umieszczaj kod, który należy wykonać raz, na początku programu************
	glClearColor(0,0,0,1);
	glEnable(GL_DEPTH_TEST);
	glfwSetWindowSizeCallback(window,windowResizeCallback);
	glfwSetKeyCallback(window,keyCallback);
	//Wczytanie i import obrazka – w initOpenGLProgram
	
	groundTex = readTexture("grasslight-big.png");
	rockTex = readTexture("rockDIFFUSE.png");
	trackTex = readTexture("tracks.png");
	tankTex = readTexture("tank.png");

	sp=new ShaderProgram("v_simplest.glsl",NULL,"f_simplest.glsl");
	tracksp = new ShaderProgram("v_track.glsl", NULL, "f_track.glsl");
}


//Zwolnienie zasobów zajętych przez program
void freeOpenGLProgram(GLFWwindow* window) {
    //************Tutaj umieszczaj kod, który należy wykonać po zakończeniu pętli głównej************
	//Usunięcie tekstury z pamięci karty graficznej – w freeOpenGLProgram
	glDeleteTextures(1, &groundTex);
	glDeleteTextures(1, &rockTex);
	glDeleteTextures(1, &trackTex);
	glDeleteTextures(1, &tankTex);
    delete sp;
	delete tracksp;
}


//Procedura rysująca zawartość sceny
void drawScene(GLFWwindow* window,float angle_x,float angle_y) {
	//************Tutaj umieszczaj kod rysujący obraz******************l
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::mat4 V = glm::lookAt(
		glm::vec3(tankX - cos(cannonAngleY +tankAngleY) * 20, 15, tankZ - 20* sin(cannonAngleY + tankAngleY) ),//z 
		glm::vec3(tankX + cos(cannonAngleY + tankAngleY) * 20, 0, tankZ + 20 * sin(cannonAngleY + tankAngleY)),//na
		glm::vec3(0.0f, 1.0f, 0.0f)); //Wylicz macierz widoku
	//	glm::vec3(cameraX,  -100.0f, cameraZ),
	//	glm::vec3(0.0f, 0.0f, 0.0f),
    //     glm::vec3(0.0f,1.0f,0.0f)); //Wylicz macierz widoku

    glm::mat4 P=glm::perspective(50.0f*PI/180.0f, aspectRatio, 0.01f, 1000.0f); //Wylicz macierz rzutowania


    glm::mat4 Mground=glm::mat4(1.0f);
	Mground =glm::rotate(Mground,angle_y,glm::vec3(1.0f,0.0f,0.0f)); //Wylicz macierz modelu
	Mground =glm::rotate(Mground,angle_x,glm::vec3(0.0f,1.0f,0.0f)); //Wylicz macierz modelu

    sp->use();//Aktywacja programu cieniującego
    //Przeslij parametry programu cieniującego do karty graficznej
    glUniformMatrix4fv(sp->u("P"),1,false,glm::value_ptr(P));
    glUniformMatrix4fv(sp->u("V"),1,false,glm::value_ptr(V));
    glUniformMatrix4fv(sp->u("M"),1,false,glm::value_ptr(Mground));

    glEnableVertexAttribArray(sp->a("vertex"));  //Włącz przesyłanie danych do atrybutu vertex
    glVertexAttribPointer(sp->a("vertex"),4,GL_FLOAT,false,0, groundVertices); //Wskaż tablicę z danymi dla atrybutu vertex

	//glEnableVertexAttribArray(sp->a("color"));  //Włącz przesyłanie danych do atrybutu vertex
	//glVertexAttribPointer(sp->a("color"), 4, GL_FLOAT, false, 0, colors); //Wskaż tablicę z danymi dla atrybutu vertex

	glEnableVertexAttribArray(sp->a("texCoord"));
	glVertexAttribPointer(sp->a("texCoord"), 2, GL_FLOAT, false, 0, groundTexCoords);


	glActiveTexture(GL_TEXTURE0); glBindTexture(GL_TEXTURE_2D, groundTex);
	glUniform1i(sp->u("tex"), 0);


   // glDrawArrays(GL_TRIANGLES,0,vertexCount); //Narysuj obiekt
	glDrawArrays(GL_TRIANGLES,0,groundVertexCount);

    glDisableVertexAttribArray(sp->a("vertex"));  //Wyłącz przesyłanie danych do atrybutu vertex
	glDisableVertexAttribArray(sp->a("texCoord"));

	//allTank =========================================================================================
	glm::mat4 MallTank= glm::mat4(1.0f);
	MallTank = glm::translate(MallTank, glm::vec3(tankX, 0.0f, tankZ)); //Wylicz macierz modelu
	MallTank = glm::rotate(MallTank, -PI/2 -tankAngleY, glm::vec3(0.0f, 1.0f, 0.0f)); //Wylicz macierz modelu

	//leftTrack=========================================================================================

	glm::mat4 MtrackL = MallTank;

	MtrackL = glm::rotate(MtrackL, angle_y, glm::vec3(1.0f, 0.0f, 0.0f)); //Wylicz macierz modelu
	MtrackL = glm::rotate(MtrackL, angle_x, glm::vec3(0.0f, 1.0f, 0.0f)); //Wylicz macierz modelu

	tracksp->use();//Aktywacja programu cieniującego
	//Przeslij parametry programu cieniującego do karty graficznej
	glUniformMatrix4fv(tracksp->u("P"), 1, false, glm::value_ptr(P));
	glUniformMatrix4fv(tracksp->u("V"), 1, false, glm::value_ptr(V));
	glUniformMatrix4fv(tracksp->u("M"), 1, false, glm::value_ptr(MtrackL));

	glEnableVertexAttribArray(tracksp->a("vertex"));  //Włącz przesyłanie danych do atrybutu vertex
	glVertexAttribPointer(tracksp->a("vertex"), 4, GL_FLOAT, false, 0, leftTrackVertices); //Wskaż tablicę z danymi dla atrybutu vertex

	//glEnableVertexAttribArray(sp->a("color"));  //Włącz przesyłanie danych do atrybutu vertex
	//glVertexAttribPointer(sp->a("color"), 4, GL_FLOAT, false, 0, colors); //Wskaż tablicę z danymi dla atrybutu vertex

	glEnableVertexAttribArray(tracksp->a("texCoord"));
	glVertexAttribPointer(tracksp->a("texCoord"), 2, GL_FLOAT, false, 0, leftTrackTexCoords);


	glActiveTexture(GL_TEXTURE0); glBindTexture(GL_TEXTURE_2D, trackTex);
	glUniform1i(tracksp->u("tex"), 0);
	glUniform1f(tracksp->u("offset"), leftTrackOffset);


	// glDrawArrays(GL_TRIANGLES,0,vertexCount); //Narysuj obiekt
	glDrawArrays(GL_TRIANGLES, 0, leftTrackVertexCount);

	glDisableVertexAttribArray(tracksp->a("vertex"));  //Wyłącz przesyłanie danych do atrybutu vertex
	glDisableVertexAttribArray(tracksp->a("texCoord"));
	//rightTrack=========================================================================================

	glm::mat4 MtrackR = MallTank;
	MtrackR = glm::rotate(MtrackR, angle_y, glm::vec3(1.0f, 0.0f, 0.0f)); //Wylicz macierz modelu
	MtrackR = glm::rotate(MtrackR, angle_x, glm::vec3(0.0f, 1.0f, 0.0f)); //Wylicz macierz modelu

	tracksp->use();//Aktywacja programu cieniującego
	//Przeslij parametry programu cieniującego do karty graficznej
	glUniformMatrix4fv(tracksp->u("P"), 1, false, glm::value_ptr(P));
	glUniformMatrix4fv(tracksp->u("V"), 1, false, glm::value_ptr(V));
	glUniformMatrix4fv(tracksp->u("M"), 1, false, glm::value_ptr(MtrackR));

	glEnableVertexAttribArray(tracksp->a("vertex"));  //Włącz przesyłanie danych do atrybutu vertex
	glVertexAttribPointer(tracksp->a("vertex"), 4, GL_FLOAT, false, 0, rightTrackVertices); //Wskaż tablicę z danymi dla atrybutu vertex

	//glEnableVertexAttribArray(sp->a("color"));  //Włącz przesyłanie danych do atrybutu vertex
	//glVertexAttribPointer(sp->a("color"), 4, GL_FLOAT, false, 0, colors); //Wskaż tablicę z danymi dla atrybutu vertex

	glEnableVertexAttribArray(tracksp->a("texCoord"));
	glVertexAttribPointer(tracksp->a("texCoord"), 2, GL_FLOAT, false, 0, rightTrackTexCoords);


	glActiveTexture(GL_TEXTURE0); glBindTexture(GL_TEXTURE_2D, trackTex);
	glUniform1i(tracksp->u("tex"), 0);
	glUniform1f(tracksp->u("offset"), rightTrackOffset);

	// glDrawArrays(GL_TRIANGLES,0,vertexCount); //Narysuj obiekt
	glDrawArrays(GL_TRIANGLES, 0, rightTrackVertexCount);

	glDisableVertexAttribArray(tracksp->a("vertex"));  //Wyłącz przesyłanie danych do atrybutu vertex
	glDisableVertexAttribArray(tracksp->a("texCoord"));
	//tank=========================================================================================

	glm::mat4 Mtank = MallTank;
	Mtank = glm::rotate(Mtank, angle_y, glm::vec3(1.0f, 0.0f, 0.0f)); //Wylicz macierz modelu
	Mtank = glm::rotate(Mtank, angle_x, glm::vec3(0.0f, 1.0f, 0.0f)); //Wylicz macierz modelu

	sp->use();//Aktywacja programu cieniującego
	//Przeslij parametry programu cieniującego do karty graficznej
	glUniformMatrix4fv(sp->u("P"), 1, false, glm::value_ptr(P));
	glUniformMatrix4fv(sp->u("V"), 1, false, glm::value_ptr(V));
	glUniformMatrix4fv(sp->u("M"), 1, false, glm::value_ptr(Mtank));

	glEnableVertexAttribArray(sp->a("vertex"));  //Włącz przesyłanie danych do atrybutu vertex
	glVertexAttribPointer(sp->a("vertex"), 4, GL_FLOAT, false, 0, tankVertices); //Wskaż tablicę z danymi dla atrybutu vertex

	//glEnableVertexAttribArray(sp->a("color"));  //Włącz przesyłanie danych do atrybutu vertex
	//glVertexAttribPointer(sp->a("color"), 4, GL_FLOAT, false, 0, colors); //Wskaż tablicę z danymi dla atrybutu vertex

	glEnableVertexAttribArray(sp->a("texCoord"));
	glVertexAttribPointer(sp->a("texCoord"), 2, GL_FLOAT, false, 0, tankTexCoords);


	glActiveTexture(GL_TEXTURE0); glBindTexture(GL_TEXTURE_2D, tankTex);
	glUniform1i(sp->u("tex"), 0);


	// glDrawArrays(GL_TRIANGLES,0,vertexCount); //Narysuj obiekt
	glDrawArrays(GL_TRIANGLES, 0, tankVertexCount);

	glDisableVertexAttribArray(sp->a("vertex"));  //Wyłącz przesyłanie danych do atrybutu vertex
	glDisableVertexAttribArray(sp->a("texCoord"));
	//cannon=========================================================================================

	glm::mat4 Mcannon = MallTank;
	Mcannon = glm::rotate(Mcannon, -cannonAngleY, glm::vec3(0.0f, 1.0f, 0.0f));
	
	Mcannon = glm::rotate(Mcannon, angle_y, glm::vec3(1.0f, 0.0f, 0.0f)); //Wylicz macierz modelu
	Mcannon = glm::rotate(Mcannon, angle_x, glm::vec3(0.0f, 1.0f, 0.0f)); //Wylicz macierz modelu

	sp->use();//Aktywacja programu cieniującego
	//Przeslij parametry programu cieniującego do karty graficznej
	glUniformMatrix4fv(sp->u("P"), 1, false, glm::value_ptr(P));
	glUniformMatrix4fv(sp->u("V"), 1, false, glm::value_ptr(V));
	glUniformMatrix4fv(sp->u("M"), 1, false, glm::value_ptr(Mcannon));

	glEnableVertexAttribArray(sp->a("vertex"));  //Włącz przesyłanie danych do atrybutu vertex
	glVertexAttribPointer(sp->a("vertex"), 4, GL_FLOAT, false, 0, cannonVertices); //Wskaż tablicę z danymi dla atrybutu vertex

	//glEnableVertexAttribArray(sp->a("color"));  //Włącz przesyłanie danych do atrybutu vertex
	//glVertexAttribPointer(sp->a("color"), 4, GL_FLOAT, false, 0, colors); //Wskaż tablicę z danymi dla atrybutu vertex

	glEnableVertexAttribArray(sp->a("texCoord"));
	glVertexAttribPointer(sp->a("texCoord"), 2, GL_FLOAT, false, 0, cannonTexCoords);


	glActiveTexture(GL_TEXTURE0); glBindTexture(GL_TEXTURE_2D, tankTex);
	glUniform1i(sp->u("tex"), 0);


	// glDrawArrays(GL_TRIANGLES,0,vertexCount); //Narysuj obiekt
	glDrawArrays(GL_TRIANGLES, 0, cannonVertexCount);

	glDisableVertexAttribArray(sp->a("vertex"));  //Wyłącz przesyłanie danych do atrybutu vertex
	glDisableVertexAttribArray(sp->a("texCoord"));
	//kamień ====================================================================================
	glm::mat4 Mrock = glm::mat4(1.0f);
	Mrock = glm::rotate(Mrock, angle_y, glm::vec3(1.0f, 0.0f, 0.0f)); //Wylicz macierz modelu
	Mrock = glm::rotate(Mrock, angle_x, glm::vec3(0.0f, 1.0f, 0.0f)); //Wylicz macierz modelu
	Mrock = glm::translate(Mrock, glm::vec3(-100, 0, -100));

	sp->use();//Aktywacja programu cieniującego
	//Przeslij parametry programu cieniującego do karty graficznej
	glUniformMatrix4fv(sp->u("P"), 1, false, glm::value_ptr(P));
	glUniformMatrix4fv(sp->u("V"), 1, false, glm::value_ptr(V));
	glUniformMatrix4fv(sp->u("M"), 1, false, glm::value_ptr(Mrock));

	glEnableVertexAttribArray(sp->a("vertex"));  //Włącz przesyłanie danych do atrybutu vertex
	glVertexAttribPointer(sp->a("vertex"), 4, GL_FLOAT, false, 0, rockVertices); //Wskaż tablicę z danymi dla atrybutu vertex

	//glEnableVertexAttribArray(sp->a("color"));  //Włącz przesyłanie danych do atrybutu vertex
	//glVertexAttribPointer(sp->a("color"), 4, GL_FLOAT, false, 0, colors); //Wskaż tablicę z danymi dla atrybutu vertex

	glEnableVertexAttribArray(sp->a("texCoord"));
	glVertexAttribPointer(sp->a("texCoord"), 2, GL_FLOAT, false, 0, rockTexCoords);


	glActiveTexture(GL_TEXTURE0); glBindTexture(GL_TEXTURE_2D, rockTex);
	glUniform1i(sp->u("tex"), 0);


	// glDrawArrays(GL_TRIANGLES,0,vertexCount); //Narysuj obiekt
	//glDrawElements(GL_TRIANGLES, cubeIndexCount, GL_UNSIGNED_INT, rockIndexes);
	glDrawArrays(GL_TRIANGLES,0, rockVertexCount); //Narysuj obiekt
	int i;
	for (i = 1; i <= 13; i++)
	{
		Mrock = glm::translate(Mrock, glm::vec3(15.0f, 0.0f, 0.0f));
		Mrock = glm::rotate(Mrock, i * 5.0f, glm::vec3(0.0f, 1.0f, 0.0f)); //Wylicz macierz modelu
		glUniformMatrix4fv(sp->u("M"), 1, false, glm::value_ptr(Mrock));
		glDrawArrays(GL_TRIANGLES, 0, rockVertexCount); //Narysuj obiekt
		Mrock = glm::rotate(Mrock, i * -5.0f, glm::vec3(0.0f, 1.0f, 0.0f)); //Wylicz macierz modelu

	}
	Mrock = glm::mat4(1.0f);
	Mrock = glm::translate(Mrock, glm::vec3(-100, 0, -100));
	for (i = 1; i <= 13; i++)
	{
		Mrock = glm::translate(Mrock, glm::vec3(0.0f, 0.0f, 15.0f));
		Mrock = glm::rotate(Mrock, i * 5.0f, glm::vec3(0.0f, 0.0f, 1.0f)); //Wylicz macierz modelu
		glUniformMatrix4fv(sp->u("M"), 1, false, glm::value_ptr(Mrock));
		glDrawArrays(GL_TRIANGLES, 0, rockVertexCount); //Narysuj obiekt
		Mrock = glm::rotate(Mrock, i * -5.0f, glm::vec3(0.0f, 0.0f, 1.0f)); //Wylicz macierz modelu

	}
	Mrock = glm::mat4(1.0f);
	Mrock = glm::translate(Mrock, glm::vec3(100, 0, 100));
	for (i = 1; i <= 12; i++)
	{
		Mrock = glm::translate(Mrock, glm::vec3(-15.0f, 0.0f, 0.0f));
		Mrock = glm::rotate(Mrock, i * 0.5f, glm::vec3(0.0f, 1.0f, 0.0f)); //Wylicz macierz modelu
		glUniformMatrix4fv(sp->u("M"), 1, false, glm::value_ptr(Mrock));
		glDrawArrays(GL_TRIANGLES, 0, rockVertexCount); //Narysuj obiekt
		Mrock = glm::rotate(Mrock, i * -0.5f, glm::vec3(0.0f, 1.0f, 0.0f)); //Wylicz macierz modelu

	}
	Mrock = glm::mat4(1.0f);
	Mrock = glm::translate(Mrock, glm::vec3(100, 0, 100));
	for (i = 1; i <= 12; i++)
	{
		Mrock = glm::translate(Mrock, glm::vec3(0.0f, 0.0f, -15.0f));
		Mrock = glm::rotate(Mrock, i * 0.5f, glm::vec3(0.0f, 1.0f, 0.0f)); //Wylicz macierz modelu
		glUniformMatrix4fv(sp->u("M"), 1, false, glm::value_ptr(Mrock));
		glDrawArrays(GL_TRIANGLES, 0, rockVertexCount); //Narysuj obiekt
		Mrock = glm::rotate(Mrock, i * -0.5f, glm::vec3(0.0f, 1.0f, 0.0f)); //Wylicz macierz modelu

	}
	
	 glDisableVertexAttribArray(sp->a("vertex"));  //Wyłącz przesyłanie danych do atrybutu vertex
	glDisableVertexAttribArray(sp->a("texCoord"));


    glfwSwapBuffers(window); //Przerzuć tylny bufor na przedni
}


int main(void)
{
	GLFWwindow* window; //Wskaźnik na obiekt reprezentujący okno

	glfwSetErrorCallback(error_callback);//Zarejestruj procedurę obsługi błędów

	if (!glfwInit()) { //Zainicjuj bibliotekę GLFW
		fprintf(stderr, "Nie można zainicjować GLFW.\n");
		exit(EXIT_FAILURE);
	}

	window = glfwCreateWindow(500, 500, "OpenGL", NULL, NULL);  //Utwórz okno 500x500 o tytule "OpenGL" i kontekst OpenGL.

	if (!window) //Jeżeli okna nie udało się utworzyć, to zamknij program
	{
		fprintf(stderr, "Nie można utworzyć okna.\n");
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window); //Od tego momentu kontekst okna staje się aktywny i polecenia OpenGL będą dotyczyć właśnie jego.
	glfwSwapInterval(1); //Czekaj na 1 powrót plamki przed pokazaniem ukrytego bufora

	if (glewInit() != GLEW_OK) { //Zainicjuj bibliotekę GLEW
		fprintf(stderr, "Nie można zainicjować GLEW.\n");
		exit(EXIT_FAILURE);
	}

	initOpenGLProgram(window); //Operacje inicjujące

	//Główna pętla
	float angle_x=0; //Aktualny kąt obrotu obiektu
	float angle_y=0; //Aktualny kąt obrotu obiektu


	glfwSetTime(0); //Zeruj timer
	while (!glfwWindowShouldClose(window)) //Tak długo jak okno nie powinno zostać zamknięte
	{
        angle_x+=speed_x*glfwGetTime(); //Zwiększ/zmniejsz kąt obrotu na podstawie prędkości i czasu jaki upłynał od poprzedniej klatki
        angle_y+=speed_y*glfwGetTime(); //Zwiększ/zmniejsz kąt obrotu na podstawie prędkości i czasu jaki upłynał od poprzedniej klatki

		if (isWPressed) {
			
			tankZ += tankSpeed* sin(tankAngleY) * glfwGetTime();
			tankX += tankSpeed* cos(tankAngleY) * glfwGetTime();
			leftTrackOffset += trackOffsetSpeed * glfwGetTime();
			rightTrackOffset += trackOffsetSpeed * glfwGetTime();
		}

		else if(isSPressed) {
			tankZ -= tankSpeed * sin(tankAngleY) * glfwGetTime();
			tankX -= tankSpeed * cos(tankAngleY) * glfwGetTime();
			leftTrackOffset -= trackOffsetSpeed * glfwGetTime();
			rightTrackOffset -= trackOffsetSpeed * glfwGetTime();

		}

		if (isAPressed) {
			tankAngleY -= tankAngleSpeed * glfwGetTime();
			leftTrackOffset -= trackOffsetSpeed * glfwGetTime();
			rightTrackOffset += trackOffsetSpeed * glfwGetTime();

		}
		else if (isDPressed) {
			tankAngleY += tankAngleSpeed * glfwGetTime();
			leftTrackOffset += trackOffsetSpeed * glfwGetTime();
			rightTrackOffset -= trackOffsetSpeed * glfwGetTime();

		}
		if (isEPressed) {
			cannonAngleY += cannonAngleSpeed * glfwGetTime();
		}
		else if (isQPressed) {
			cannonAngleY -= cannonAngleSpeed * glfwGetTime();
		}

        glfwSetTime(0); //Zeruj timer
		drawScene(window,angle_x,angle_y); //Wykonaj procedurę rysującą
		glfwPollEvents(); //Wykonaj procedury callback w zalezności od zdarzeń jakie zaszły.
	}

	freeOpenGLProgram(window);

	glfwDestroyWindow(window); //Usuń kontekst OpenGL i okno
	glfwTerminate(); //Zwolnij zasoby zajęte przez GLFW
	exit(EXIT_SUCCESS);
}
