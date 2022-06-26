#ifndef MYCUBE_H_INCLUDED
#define MYCUBEFRONT_H_INCLUDED


//myCubeVertices - homogeniczne wsp�rz�dne wierzcho�k�w w przestrzeni modelu
//myCubeNormals - homogeniczne wektory normalne �cian (per wierzcho�ek) w przestrzeni modelu
//myCubeVertexNormals - homogeniczne wektory normalne wierzcho�k�w w przestrzeni modelu
//myCubeTexCoords - wsp�rz�dne teksturowania
//myCubeColors - kolory wierzcho�k�w
//myCubeC1 - kolumna macierzy TBN^-1
//myCubeC2 - kolumna macierzy TBN^-1
//myCubeC3 - kolumna macierzy TBN^-1

int myCubeLeftVertexCount = 6;

float myCubeLeftVertices[] = {

	

	//�ciana 4 //lewa
	-1.0f, 1.0f, 1.0f,1.0f,
	1.0f, 1.0f,-1.0f,1.0f,
	1.0f, 1.0f, 1.0f,1.0f,

	-1.0f, 1.0f, 1.0f,1.0f,
	-1.0f, 1.0f,-1.0f,1.0f,
	1.0f, 1.0f,-1.0f,1.0f,


};


float myCubeLeftColors[] = {

	

	//�ciana 4
	1.0f,1.0f,0.0f,1.0f,
	1.0f,1.0f,0.0f,1.0f,
	1.0f,1.0f,0.0f,1.0f,

	1.0f,1.0f,0.0f,1.0f,
	1.0f,1.0f,0.0f,1.0f,
	1.0f,1.0f,0.0f,1.0f,

	
};

float myCubeLeftNormals[] = {



	//�ciana 4
	0.0f, 1.0f, 0.0f,0.0f,
	0.0f, 1.0f, 0.0f,0.0f,
	0.0f, 1.0f, 0.0f,0.0f,

	0.0f, 1.0f, 0.0f,0.0f,
	0.0f, 1.0f, 0.0f,0.0f,
	0.0f, 1.0f, 0.0f,0.0f,

	

};

float myCubeLeftVertexNormals[] = {

	

	//�ciana 4
	-1.0f, 1.0f, 1.0f,0.0f,
	1.0f, 1.0f,-1.0f,0.0f,
	1.0f, 1.0f, 1.0f,0.0f,

	-1.0f, 1.0f, 1.0f,0.0f,
	-1.0f, 1.0f,-1.0f,0.0f,
	1.0f, 1.0f,-1.0f,0.0f,

	
};

float myCubeLeftTexCoords[] = {


	

	//�ciana 4
	1.0f,1.0f, 0.0f,0.0f, 0.0f,1.0f,
	1.0f,1.0f, 1.0f,0.0f, 0.0f,0.0f,

	
};

float myCubeLefttC1[] = {

	
	//�ciana 4
	-1.000000f,0.000000f,-0.000000f,0.000000f,
	-1.000000f,0.000000f,-0.000000f,0.000000f,
	-1.000000f,0.000000f,-0.000000f,0.000000f,
	-1.000000f,-0.000000f,0.000000f,0.000000f,
	-1.000000f,-0.000000f,0.000000f,0.000000f,
	-1.000000f,-0.000000f,0.000000f,0.000000f,

};
float myCubeLeftC2[] = {


	
	//�ciana 4
	-0.000000f,0.000000f,1.000000f,0.000000f,
	-0.000000f,0.000000f,1.000000f,0.000000f,
	-0.000000f,0.000000f,1.000000f,0.000000f,
	0.000000f,0.000000f,1.000000f,0.000000f,
	0.000000f,0.000000f,1.000000f,0.000000f,
	0.000000f,0.000000f,1.000000f,0.000000f,

};
float myCubeLeftC3[] = {

	
	//�ciana 4
	0.000000f,1.000000f,0.000000f,0.000000f,
	0.000000f,1.000000f,0.000000f,0.000000f,
	0.000000f,1.000000f,0.000000f,0.000000f,
	0.000000f,1.000000f,0.000000f,0.000000f,
	0.000000f,1.000000f,0.000000f,0.000000f,
	0.000000f,1.000000f,0.000000f,0.000000f,


};



#endif // MYCUBE_H_INCLUDED#pragma once
