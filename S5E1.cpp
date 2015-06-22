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
bool boton2 = false;
bool boton3 = false;
bool boton4 = false;
bool boton5 = false;
bool bandera = false;
bool bandera2 = false;


int cuenta=0;

static void SiRatonMueve(int evt, int x, int y, int flags, void* param){
	
	//cout << "X: " << x << endl;
	//cout << "Y: " << y << endl;

	switch(evt)
	{
		case CV_EVENT_LBUTTONDOWN :
				cout << "X: " << x << endl;
				cout << "Y: " << y << endl;

				if(x>10 && x<400 && y>10 && y<100){
					if(boton1) cuenta++;					
					boton1 = !boton1;
					
					//cuenta++;
				}
		else if(x>10 && x<400 && y>110 && y<200){
				if(boton2) cuenta--;
				boton2 = !boton2;
				//cuenta--;	
				}
	else if(x>10 && x<400 && y>310 && y<400){
				
				bandera=true;
				boton3 = !boton3;
					
				}
	else if(x>10 && x<400 && y>410 && y<500){
					cuenta = 0;
					boton4 = !boton4;
				}
	else if(x>10 && x<400 && y>510 && y<600){
					boton5 = !boton5;
					bandera2=true;


				}

				break;
		default : 
				break;
	}

}


int main( void ){
//Variables
//Mat nomb(y,x,size, color);
Mat M1(610,800,	CV_8UC3,Scalar(255, 255, 255));
Mat M2(590,380, CV_8UC3,Scalar(255,0,0));
Mat M3(90,390,CV_8UC3,Scalar(255,0,0));
Mat M3A(90,390,CV_8UC3,Scalar(0,255,0));


Mat temporal;


Rect R1(Point(10,10),Size(390,90));
Rect R2(Point(10,110),Size(390,90));
Rect R3(Point(10,210),Size(390,90));
Rect R4(Point(10,310),Size(390,90));
Rect R5(Point(10,410),Size(390,90));
Rect R6(Point(10,510),Size(390,90));
Rect R7(Point(410,10),Size(380,590));


M2.copyTo(M1(R7));
M3.copyTo(M1(R1));
M3.copyTo(M1(R2));
M3.copyTo(M1(R3));
M3.copyTo(M1(R4));
M3.copyTo(M1(R5));
M3.copyTo(M1(R6));

	putText(		M1,
							"#4",
							Point2f(10,220),
							FONT_HERSHEY_PLAIN,
							1,
							Scalar(255,255,255),
							1);
	

		
	namedWindow("V1",1);
		int temp=0;
		int i=0;
	 cvSetMouseCallback(	"V1",
												SiRatonMueve, 
												&temp );
	char buffer[30];
	for(;;){
		

		
	

		sprintf(buffer,"# %d", cuenta);
		M3.copyTo(M1(R3));
		putText(		M1,
							buffer,
							Point2f(150,250),
							FONT_HERSHEY_PLAIN,
							3,
							Scalar(255,255,255),
							1);	


		if(boton1) M3A.copyTo(M1(R1));
		else M3.copyTo(M1(R1));
		
		if(boton2) M3A.copyTo(M1(R2));
		else M3.copyTo(M1(R2));
		
		if(boton3){
				M3A.copyTo(M1(R4));
				if(bandera){
					  M2.copyTo(M1(R7));
						for(i=0; i<cuenta; i++){
						circle(	M1,
								Point((rand() % 380 + 410), 
								( rand() % 580 + 10)),
								5,
								Scalar(0,255,0),
								CV_FILLED,
								8,
								0);


						}
						
						bandera=0;
				

				}


		}
		else 	M3.copyTo(M1(R4));

		if(boton4) M3A.copyTo(M1(R5));
		else M3.copyTo(M1(R5));
	
		if(boton5) { M3A.copyTo(M1(R6));
				if(bandera2){

					imwrite("m1.jpg", M1);
system("mpack -s subject m1.jpg ruben.estrada@hetpro.com.mx");
			bandera2=false;
					}



		}
		else	M3.copyTo(M1(R6));
		

putText(		M1,
							"UP",
							Point2f(50,70),
							FONT_HERSHEY_PLAIN,
							5,
							Scalar(255,255,255),
							1);

putText(		M1,
							"DOWN",
							Point2f(50,170),
							FONT_HERSHEY_PLAIN,
							5,
							Scalar(255,255,255),
							1);

putText(		M1,
							"OK",
							Point2f(50,370),
							FONT_HERSHEY_PLAIN,
							5,
							Scalar(255,255,255),
							1);

putText(		M1,
							"CLEAR",
							Point2f(50,470),
							FONT_HERSHEY_PLAIN,
							5,
							Scalar(255,255,255),
							1);

putText(		M1,
							"SEND",
							Point2f(50,570),
							FONT_HERSHEY_PLAIN,
							5,
							Scalar(255,255,255),
							1);
			
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
