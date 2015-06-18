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
#include <chrono>
#include <thread>

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
bool boton3 = false;
bool bandera=false;

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

					if(boton2 > 2) boton2=0;
					boton2++;				
				}
			else if(x>25 && x<175 && y>290 && y<390){
					boton3 = !boton3;
				}

				break;
		default : 
				break;
	}

}


int main( void ){
//Variables
//Mat nomb(y,x,size, color);
Mat M1(35,390,	CV_8UC3,Scalar(0, 255, 255));
Mat M2(60,180,	CV_8UC3,Scalar(0, 255, 0));
Mat M3(150,550,	CV_8UC3,Scalar(0, 0, 255));
Mat M4(150,150, CV_8UC3,Scalar(0,0,255));
Mat M5(330,730, CV_8UC3,Scalar(255,255,255));
Mat M6(150,150, CV_8UC3,Scalar(0,0,255));


Rect R1(Point(10,10),Size(390,35));
Rect R2(Point(10,55),Size(390,35));
Rect R3(Point(10,100),Size(180,60));
Rect R4(Point(220,100),Size(180,60));
Rect R5(Point(10,170),Size(550,150));
Rect R6(Point(410,10),Size(150,150));
Rect R7(Point(570,10),Size(150,150));
Rect R8(Point(570,170),Size(150,150));

M1.copyTo(M5(R1));
M1.copyTo(M5(R2));
M2.copyTo(M5(R3));
M2.copyTo(M5(R4));
M3.copyTo(M5(R5));
M4.copyTo(M5(R6));
M4.copyTo(M5(R7));
M4.copyTo(M5(R8));


	putText(		M5,
							"Ssdfasfd",
							Point2f(10,200),
							FONT_HERSHEY_PLAIN,
							1,
							Scalar(255,255,255),
							1);

		imshow("V1", M5);

	for(;;){
		
		

	//Retardo un segundo
		std::this_thread::sleep_until(
        std::chrono::system_clock::now() + std::chrono::seconds(1));
		
	

		if(!bandera){
		M6.copyTo(M5(R8));
		bandera=true;
		}
		else{
		M4.copyTo(M5(R8));
		bandera=false;
		}
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
