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

bool boton1 = false;
int boton2=0;

static void SiRatonMueve(int evt, int x, int y, int flags, void* param){
	
	//cout << "X: " << x << endl;
	//cout << "Y: " << y << endl;

	switch(evt)
	{
		case CV_EVENT_LBUTTONDOWN :
				cout << "X: " << x << endl;
				cout << "Y: " << y << endl;

				if(x>25 && x<175 && y>30 && y<130){
					boton1 =  true;
				}
			else if(x>25 && x<175 && y>160 && y<260){
					boton2++;
					if(boton2 > 3) boton2=0;				
				}

				break;
		default : 
				break;
	}

}


int main( void ){
//Variables
int temp=0;
char buffer[20];
int indice = 0;

//Mat nomb(y,x,size, color);
Mat M1(400,400,CV_8UC3,Scalar(255, 255, 255));
Mat M2(150,150,CV_8UC3,Scalar(0, 255, 0));
Mat M3(100,150,CV_8UC3,Scalar(0, 0, 255));
Mat imagen;
Mat imagen_peq;
Mat M2A(150,150,CV_8UC3,Scalar(124, 255,62));
Mat M2B(150,150,CV_8UC3,Scalar(12, 25, 100));
Mat M2C(150,150,CV_8UC3,Scalar(120, 255, 0));
Mat M2D(150,150,CV_8UC3,Scalar(0, 0, 0));


//Rect Nom(Point(x,y), Size(x,y));
Rect R1(Point(25,30),  Size(150,100));   
Rect R2(Point(25,160), Size(150,100));
Rect R3(Point(25,290), Size(150,100));
Rect R4(Point(200,30), Size(150,150));
Rect R5(Point(200,210),Size(150,150));

//origen.copyTo(destino(roi));
M2.copyTo(M1(R4));
M2.copyTo(M1(R5));
M3.copyTo(M1(R1));
M3.copyTo(M1(R2));
M3.copyTo(M1(R3));

VideoCapture camara(0);
if(!camara.isOpened()) return 0;

	namedWindow("V1",1);
	cvSetMouseCallback(	"V1",
											SiRatonMueve, 
											&temp );

	for(;;){
		camara >> imagen;

		resize(		imagen, 
							imagen_peq, 
							Size(150,150), 
							0,0,
							INTER_LINEAR);

		imagen_peq.copyTo(M1(R4));
		if(boton1){
			sprintf(buffer,"Img%d.jpg", indice);

			imwrite(buffer, imagen);
			boton1 = false;
			indice++;

		}
		switch(boton2){
			case 0:	M2A.copyTo(M1(R5));			break;
			case 1: M2B.copyTo(M1(R5));			break;
			case 2:	M2C.copyTo(M1(R5));			break;
			case 3:	M2D.copyTo(M1(R5));			break;
			default: 	cout << "Error 401" << endl;	
		}


		imshow("V1", M1);
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
		Scalar(70,150,200),
		oediv);
    NOmbre_Matriz_Guardar_Imagen = imread("imagen1.png");
    
    imwrite("HOla.jpg", video);
    
    resize(video, temporal, Size(250,150), 0,0,INTER_LINEAR);
    
    GaussianBlur(temporal, blur, Size(5, 5), 2, 2);
    
    Rect R1(Point(10,10), Size(200,100));
    
    createTrackbar("SatMin", "ControlCasa-V0.111", &SatMin, 255);
    
    cvSetMouseCallback("ControlCasa-V0.111",SiRatonMueve, &temp );
    
    temporal.copyTo(plantilla(R4));

 Rect R1(Point(25,30),  Size(150,100));
    Rect R2(Point(25,160), Size(150,100));
    Rect R3(Point(25,290), Size(150,100));
    Rect R4(Point(200,30), Size(150,150));
    Rect R5(Point(200,210),Size(150,150));
*/
