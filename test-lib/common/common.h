#ifndef COMMON_H
#define COMMON_H


#include <iostream>
#include<jni.h>
using namespace std;


/*
	turn jstring to string
*/
string jstringToString(JNIEnv * env, jstring src);

/*
	turn string to jstring
*/
jstring stringToJstring(JNIEnv *env, string src);

/*
 turn string to int
*/
int stringToInt(string src);

/*
	turn int to string
*/
string intToString(const int &int_temp);


/*
//һά����
int callbackMethod1(int num, vector<int> vArray);

//��ά����
int callbackMethod2(int num, vector<vector<int> > vArray)
*/

#endif //COMMON_H_