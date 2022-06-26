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

int myCubeRightVertexCount = 6;

float myCubeRightVertices[] = {

	
	
	//�ciana 3 //prawa
	-1.0f,-1.0f,-1.0f,1.0f,
	1.0f,-1.0f, 1.0f,1.0f,
	1.0f,-1.0f,-1.0f,1.0f,

	-1.0f,-1.0f,-1.0f,1.0f,
	-1.0f,-1.0f, 1.0f,1.0f,
	1.0f,-1.0f, 1.0f,1.0f,

	

};


float myCubeRightColors[] = {

	
	//�ciana 3
	0.0f,0.0f,1.0f,1.0f,
	0.0f,0.0f,1.0f,1.0f,
	0.0f,0.0f,1.0f,1.0f,

	0.0f,0.0f,1.0f,1.0f,
	0.0f,0.0f,1.0f,1.0f,
	0.0f,0.0f,1.0f,1.0f,

	
};

float myCubeRightNormals[] = {


	
	//�ciana 3
	0.0f,-1.0f, 0.0f,0.0f,
	0.0f,-1.0f, 0.0f,0.0f,
	0.0f,-1.0f, 0.0f,0.0f,

	0.0f,-1.0f, 0.0f,0.0f,
	0.0f,-1.0f, 0.0f,0.0f,
	0.0f,-1.0f, 0.0f,0.0f,

	

};

float myCubeRightVertexNormals[] = {

	
	//�ciana 3
	-1.0f,-1.0f,-1.0f,0.0f,
	1.0f,-1.0f, 1.0f,0.0f,
	1.0f,-1.0f,-1.0f,0.0f,

	-1.0f,-1.0f,-1.0f,0.0f,
	-1.0f,-1.0f, 1.0f,0.0f,
	1.0f,-1.0f, 1.0f,0.0f,

	
};

float myCubeRightTexCoords[] = {


	//�ciana 3
	1.0f,1.0f, 0.0f,0.0f, 0.0f,1.0f,
	1.0f,1.0f, 1.0f,0.0f, 0.0f,0.0f,

	
};

float myCubeRightC1[] = {

	
	//�ciana 3
	-1.000000f,-0.000000f,0.000000f,0.000000f,
	-1.000000f,-0.000000f,0.000000f,0.000000f,
	-1.000000f,-0.000000f,0.000000f,0.000000f,
	-1.000000f,-0.000000f,0.000000f,0.000000f,
	-1.000000f,-0.000000f,0.000000f,0.000000f,
	-1.000000f,-0.000000f,0.000000f,0.000000f,
	

};
float myCubeRightC2[] = {


	
	//�ciana 3
	-0.000000f,0.000000f,-1.000000f,0.000000f,
	-0.000000f,0.000000f,-1.000000f,0.000000f,
	-0.000000f,0.000000f,-1.000000f,0.000000f,
	-0.000000f,0.000000f,-1.000000f,0.000000f,
	-0.000000f,0.000000f,-1.000000f,0.000000f,
	-0.000000f,0.000000f,-1.000000f,0.000000f,
	

};
float myCubeRightC3[] = {


	//�ciana 3
	0.000000f,-1.000000f,0.000000f,0.000000f,
	0.000000f,-1.000000f,0.000000f,0.000000f,
	0.000000f,-1.000000f,0.000000f,0.000000f,
	0.000000f,-1.000000f,0.000000f,0.000000f,
	0.000000f,-1.000000f,0.000000f,0.000000f,
	0.000000f,-1.000000f,0.000000f,0.000000f,
	
};



#endif // MYCUBE_H_INCLUDED

