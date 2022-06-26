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

int myCubeRightVertexCount = 6;

float myCubeRightVertices[] = {

	
	
	//Œciana 3 //prawa
	-1.0f,-1.0f,-1.0f,1.0f,
	1.0f,-1.0f, 1.0f,1.0f,
	1.0f,-1.0f,-1.0f,1.0f,

	-1.0f,-1.0f,-1.0f,1.0f,
	-1.0f,-1.0f, 1.0f,1.0f,
	1.0f,-1.0f, 1.0f,1.0f,

	

};


float myCubeRightColors[] = {

	
	//Œciana 3
	0.0f,0.0f,1.0f,1.0f,
	0.0f,0.0f,1.0f,1.0f,
	0.0f,0.0f,1.0f,1.0f,

	0.0f,0.0f,1.0f,1.0f,
	0.0f,0.0f,1.0f,1.0f,
	0.0f,0.0f,1.0f,1.0f,

	
};

float myCubeRightNormals[] = {


	
	//Œciana 3
	0.0f,-1.0f, 0.0f,0.0f,
	0.0f,-1.0f, 0.0f,0.0f,
	0.0f,-1.0f, 0.0f,0.0f,

	0.0f,-1.0f, 0.0f,0.0f,
	0.0f,-1.0f, 0.0f,0.0f,
	0.0f,-1.0f, 0.0f,0.0f,

	

};

float myCubeRightVertexNormals[] = {

	
	//Œciana 3
	-1.0f,-1.0f,-1.0f,0.0f,
	1.0f,-1.0f, 1.0f,0.0f,
	1.0f,-1.0f,-1.0f,0.0f,

	-1.0f,-1.0f,-1.0f,0.0f,
	-1.0f,-1.0f, 1.0f,0.0f,
	1.0f,-1.0f, 1.0f,0.0f,

	
};

float myCubeRightTexCoords[] = {


	//Œciana 3
	1.0f,1.0f, 0.0f,0.0f, 0.0f,1.0f,
	1.0f,1.0f, 1.0f,0.0f, 0.0f,0.0f,

	
};

float myCubeRightC1[] = {

	
	//Œciana 3
	-1.000000f,-0.000000f,0.000000f,0.000000f,
	-1.000000f,-0.000000f,0.000000f,0.000000f,
	-1.000000f,-0.000000f,0.000000f,0.000000f,
	-1.000000f,-0.000000f,0.000000f,0.000000f,
	-1.000000f,-0.000000f,0.000000f,0.000000f,
	-1.000000f,-0.000000f,0.000000f,0.000000f,
	

};
float myCubeRightC2[] = {


	
	//Œciana 3
	-0.000000f,0.000000f,-1.000000f,0.000000f,
	-0.000000f,0.000000f,-1.000000f,0.000000f,
	-0.000000f,0.000000f,-1.000000f,0.000000f,
	-0.000000f,0.000000f,-1.000000f,0.000000f,
	-0.000000f,0.000000f,-1.000000f,0.000000f,
	-0.000000f,0.000000f,-1.000000f,0.000000f,
	

};
float myCubeRightC3[] = {


	//Œciana 3
	0.000000f,-1.000000f,0.000000f,0.000000f,
	0.000000f,-1.000000f,0.000000f,0.000000f,
	0.000000f,-1.000000f,0.000000f,0.000000f,
	0.000000f,-1.000000f,0.000000f,0.000000f,
	0.000000f,-1.000000f,0.000000f,0.000000f,
	0.000000f,-1.000000f,0.000000f,0.000000f,
	
};



#endif // MYCUBE_H_INCLUDED

