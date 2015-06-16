/*
	EXPLICAR QUE HACE PROGRAMA.
	AUTOR:
	COMPILAR: 
		
		g++ -Wall -o imagen plantilla.cpp `pkg-config --cflags --libs opencv`


*/



#include<opencv2/core/core.hpp>
#include<opencv2/ml/ml.hpp>
#include<opencv/cv.h>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/video/background_segm.hpp>
#include<cmath>

#include <iostream>

#include<fstream>

#include <stdio.h>    
#include <stdlib.h> 
#include <stdint.h>   
#include <string.h>   
#include <unistd.h>   
#include <fcntl.h>   
#include <errno.h>    
#include <termios.h>  
#include <sys/ioctl.h>

using namespace cv;
using namespace std;

static void SiRatonMueve(int evt, int x, int y, int flags, void* param){
	switch(evt)
	{
		case CV_EVENT_LBUTTONDOWN :

				break;
		default : 
				break;
	}

}


int main( void ){
	//Variables para barras de desplazamiento
	int ColorMin = 0, ColorMax = 255;
	int SatMin = 0	, SatMax = 255;
	int IntMin = 0	, IntMax = 255;

	//Declarar una matriz
	Mat imagen;
	Mat imagen2; 
	Mat imagen3;

	//Declaro el objeto camara
  VideoCapture camara(0); 

	//Crear una ventana
	namedWindow("V4",1);

	//Crear una barra
	createTrackbar(	"ColorMinimo", 
									"V4",
									&ColorMin, 
									255);

	createTrackbar(	"ColorMaximo", 
									"V4",
									&ColorMax, 
									255);

	createTrackbar(	"SaturacionMinimo", 
									"V4",
									&SatMin, 
									255);

	createTrackbar(	"SaturacionMaximo", 
									"V4",
									&SatMax, 
									255);

	createTrackbar(	"IntensidadMin", 
									"V4",
									&IntMin, 
									255);

	createTrackbar(	"IntensidadMax", 
									"V4",
									&IntMax, 
									255);

	for(;;){

		//Guardar en una matriz la imagen de cam
		camara >> imagen;
		
		GaussianBlur(		imagen, 
										imagen2, 
										Size(5, 5), 50, 50);
cvtColor(imagen2, imagen2, CV_BGR2HSV, 0);	
//	cvtColor(imagen2, imagen2, CV_BGR2GRAY, 0);



	
		inRange(		imagen2,
								Scalar(ColorMin,SatMin,IntMin),
								Scalar(ColorMax,SatMax,IntMax),
								imagen3);


	
		//Funcion para imagen guardada en matriz
		//imshow(A,B); 
		// A = "nombre de la ventana"
		// B = nombre_de_la_matriz
		
		imshow( "V1"    , imagen   );
		imshow( "V2" 		, imagen2);
		imshow( "V3"		, imagen3);

		//Esperar a presionar cualquier tecla	
		// para terminar el programa
		if(waitKey(30)>0) break;
	}
	


return(0);
}

//  Mat imagen(100,100,CV_8UC3,Scalar(0, 255, 0));
//	imshow("NombreVentana", NombreMatriz);
//	waitKey( 0 );
//  VideoCapture cam(0);
//  if(cam.isOpened()) return -1;
//  cam >> video;
/*
    cvtColor(video, video, CV_BGR2HSV, 0);	
		inRange(video,
		Scalar(0,0,50),
		Scalar(70,150,200),oediv);
    NOmbre_Matriz_Guardar_Imagen = imread("imagen1.png");
    
    imwrite("HOla.jpg", video);
    
    resize(video, temporal, Size(250,150), 0,0,INTER_LINEAR);
    
    GaussianBlur(temporal, blur, Size(5, 5), 2, 2);
    
    Rect R1(Point(10,10), Size(200,100));
    
    createTrackbar("SatMin", "ControlCasa-V0.111", &SatMin, 255);
    
    cvSetMouseCallback("ControlCasa-V0.111",SiRatonMueve, &temp );
    
    temporal.copyTo(plantilla(R4));
*/
