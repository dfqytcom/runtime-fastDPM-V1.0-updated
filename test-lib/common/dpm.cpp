#pragma execution_character_set("utf-8") //默认使用UTF8 
#include "FastDPM.h"
#include <conio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using namespace cv;
//#pragma comment(lib, "FastDPM-2014-May.lib")


#include "jni.h"  
#include "jni_md.h"  
#include "com_utry_javaCallDLL_AlgorithmDLL.h" 
#include "common.h"

JNIEXPORT jfloatArray JNICALL Java_com_utry_javaCallDLL_AlgorithmDLL_DPM(JNIEnv *env, jobject obj, jstring s, jstring model_txt){

	string img_namePath = jstringToString(env, s);
	string model_Path = jstringToString(env, model_txt);
	FastDPM	PM(model_Path);

	jfloatArray resultAll=env->NewFloatArray(49);//新建一个jfloatArray;
	jfloat buf[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


	//定义一个jint类型的buffer把原始的数组copy到这个buf中去

	//Mat	img_uint8 = imread(img_namePath.c_str())
	IplImage *img0 = cvLoadImage(img_namePath.c_str(), 1);
	cv::Mat img_uint8(img0, 0);
	if (img_uint8.empty()){
		cout << "Cannot get image " << img_namePath << endl;
	}

	Mat	img = PM.prepareImg(img_uint8);
	PM.detect(img, -1.0f, true, true);
	cvWaitKey(1);
	cout << "------------------------------------------------------------" << endl;
	
	/*vector<FLOATS_7>::iterator it;
	for (it = PM.detections.begin(); it != PM.detections.end(); it++)
		cout << "result is:  " << PM.detections[0][6] << endl;*/

	/*for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++) buf[i*7+j] = PM.detections[i][j];
		env->SetFloatArrayRegion(resultAll, 0, 49, buf);//将buf中的值复制到jintArray中去，数组copy
	}
	
	//return (jfloat)PM.detections[0][6];*/
	return resultAll;
}



JNIEXPORT jint JNICALL Java_com_utry_javaCallDLL_AlgorithmDLL_DPMbool(JNIEnv *env, jobject obj, jstring s, jstring model_txt){

	string img_namePath = jstringToString(env, s);
	string model_Path = jstringToString(env, model_txt);
	FastDPM	PM(model_Path);

	jfloatArray resultAll = env->NewFloatArray(49);//新建一个jfloatArray;
	jfloat buf[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	//定义一个jint类型的buffer把原始的数组copy到这个buf中去

	//Mat	img_uint8 = imread(img_namePath.c_str())
	IplImage *img0 = cvLoadImage(img_namePath.c_str(), 1);
	cv::Mat img_uint8(img0, 0);
	if (img_uint8.empty()){
		cout << "Cannot get image " << img_namePath << endl;
	}

	Mat	img = PM.prepareImg(img_uint8);
	PM.detect(img, -1.0f, true, true);
	cvWaitKey(1);
	cout << "------------------------------------------------------------" << endl;

	/*vector<FLOATS_7>::iterator it;
	for (it = PM.detections.begin(); it != PM.detections.end(); it++)
		cout << "result is:  " << PM.detections[0][6] << endl;*/

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++) buf[i * 7 + j] = PM.detections[i][j];
		env->SetFloatArrayRegion(resultAll, 0, 49, buf);//将buf中的值复制到jintArray中去，数组copy
	}
	
	//env->ReleaseFloatArrayElements(resultAll, buf, 0);
	return (jint)PM.detections[0][5];
}



JNIEXPORT std::vector<FLOATS_7> JNICALL Java_com_utry_javaCallDLL_AlgorithmDLL_DPMvector(JNIEnv *env, jobject obj, jstring s, jstring model_txt){

	string img_namePath = jstringToString(env, s);
	string model_Path = jstringToString(env, model_txt);
	FastDPM	PM(model_Path);
	std::vector<FLOATS_7> resultS;
	

	//定义一个jint类型的buffer把原始的数组copy到这个buf中去

	//Mat	img_uint8 = imread(img_namePath.c_str())
	IplImage *img0 = cvLoadImage(img_namePath.c_str(), 1);
	cv::Mat img_uint8(img0, 0);
	if (img_uint8.empty()){
		cout << "Cannot get image " << img_namePath << endl;
	}

	Mat	img = PM.prepareImg(img_uint8);
	resultS=PM.detect(img, -1.0f, true, true);
	cvWaitKey(1);
	cout << "------------------------------------------------------------" << endl;

	/*vector<FLOATS_7>::iterator it;
	for (it = PM.detections.begin(); it != PM.detections.end(); it++)
		cout << "result is:  " << PM.detections[0][6] << endl;

	//return (jfloat)PM.detections[0][6];*/
	return PM.detections;
}

