#ifndef MYCUBE_H_INCLUDED
#define MYCUBEFRONT_H_INCLUDED


//myCubeVertices - homogeniczne wspó³rzêdne wierzcho³ków w przestrzeni modelu
//myCubeNormals - homogeniczne wektory normalne œcian (per wierzcho³ek) w przestrzeni modelu
//myCubeVertexNormals - homogeniczne wektory normalne wierzcho³ków w przestrzeni modelu
//myCubeTexCoords - wspó³rzêdne teksturowania
//myCubeColors - kolory wierzcho³ków
//myCubeC1 - kolumna macierzy TBN^-1
//myCubeC2 - kolumna macierzy TBN^-1
//myCubeC3 - kolumna macierzy TBN^-1

int myCubeLeftVertexCount = 6;

float myCubeLeftVertices[] = {

	

	//Œciana 4 //lewa
	-1.0f, 1.0f, 1.0f,1.0f,
	1.0f, 1.0f,-1.0f,1.0f,
	1.0f, 1.0f, 1.0f,1.0f,

	-1.0f, 1.0f, 1.0f,1.0f,
	-1.0f, 1.0f,-1.0f,1.0f,
	1.0f, 1.0f,-1.0f,1.0f,


};


float myCubeLeftColors[] = {

	

	//Œciana 4
	1.0f,1.0f,0.0f,1.0f,
	1.0f,1.0f,0.0f,1.0f,
	1.0f,1.0f,0.0f,1.0f,

	1.0f,1.0f,0.0f,1.0f,
	1.0f,1.0f,0.0f,1.0f,
	1.0f,1.0f,0.0f,1.0f,

	
};

float myCubeLeftNormals[] = {



	//Œciana 4
	0.0f, 1.0f, 0.0f,0.0f,
	0.0f, 1.0f, 0.0f,0.0f,
	0.0f, 1.0f, 0.0f,0.0f,

	0.0f, 1.0f, 0.0f,0.0f,
	0.0f, 1.0f, 0.0f,0.0f,
	0.0f, 1.0f, 0.0f,0.0f,

	

};

float myCubeLeftVertexNormals[] = {

	

	//Œciana 4
	-1.0f, 1.0f, 1.0f,0.0f,
	1.0f, 1.0f,-1.0f,0.0f,
	1.0f, 1.0f, 1.0f,0.0f,

	-1.0f, 1.0f, 1.0f,0.0f,
	-1.0f, 1.0f,-1.0f,0.0f,
	1.0f, 1.0f,-1.0f,0.0f,

	
};

float myCubeLeftTexCoords[] = {


	

	//Œciana 4
	1.0f,1.0f, 0.0f,0.0f, 0.0f,1.0f,
	1.0f,1.0f, 1.0f,0.0f, 0.0f,0.0f,

	
};

float myCubeLefttC1[] = {

	
	//Œciana 4
	-1.000000f,0.000000f,-0.000000f,0.000000f,
	-1.000000f,0.000000f,-0.000000f,0.000000f,
	-1.000000f,0.000000f,-0.000000f,0.000000f,
	-1.000000f,-0.000000f,0.000000f,0.000000f,
	-1.000000f,-0.000000f,0.000000f,0.000000f,
	-1.000000f,-0.000000f,0.000000f,0.000000f,

};
float myCubeLeftC2[] = {


	
	//Œciana 4
	-0.000000f,0.000000f,1.000000f,0.000000f,
	-0.000000f,0.000000f,1.000000f,0.000000f,
	-0.000000f,0.000000f,1.000000f,0.000000f,
	0.000000f,0.000000f,1.000000f,0.000000f,
	0.000000f,0.000000f,1.000000f,0.000000f,
	0.000000f,0.000000f,1.000000f,0.000000f,

};
float myCubeLeftC3[] = {

	
	//Œciana 4
	0.000000f,1.000000f,0.000000f,0.000000f,
	0.000000f,1.000000f,0.000000f,0.000000f,
	0.000000f,1.000000f,0.000000f,0.000000f,
	0.000000f,1.000000f,0.000000f,0.000000f,
	0.000000f,1.000000f,0.000000f,0.000000f,
	0.000000f,1.000000f,0.000000f,0.000000f,


};



#endif // MYCUBE_H_INCLUDED#pragma once
