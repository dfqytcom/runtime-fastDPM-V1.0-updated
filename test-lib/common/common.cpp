#include "common.h"
#include <Windows.h>
#include <sstream>
#include <vector>

/*
	char* to jstring
	
*/
jstring charsTojstring(JNIEnv* env, const char* str)
{//gb2312  to  utf8/16
	jstring rtn = 0;
	int slen = strlen(str);
	unsigned short * buffer = 0;
	if (slen == 0)
		rtn = (env)->NewStringUTF(str);
	else
	{
		int length = MultiByteToWideChar(CP_ACP, 0, (LPCSTR)str, slen, NULL, 0);
		buffer = (unsigned short *)malloc(length * 2 + 1);
		if (MultiByteToWideChar(CP_ACP, 0, (LPCSTR)str, slen, (LPWSTR)buffer, length) >0)
			rtn = (env)->NewString((jchar*)buffer, length);
	}
	if (buffer){

		free(buffer);
		
	}
	
	return rtn;
}
/*
	jstring to char*
*/
char* jstringToChars(JNIEnv *env, jstring jstr)
{ //UTF8/16 to gb2312
	
	int length = (env)->GetStringLength(jstr);
	const jchar* jcstr = (env)->GetStringChars(jstr, 0);

	int clen = WideCharToMultiByte(CP_ACP, 0, (LPCWSTR)jcstr, length, NULL, 0, NULL, NULL);

	char* rtn = (char*)malloc(clen);
	//更正。作者原来用的是(char*)malloc( length*2+1 )，当java字符串中同时包含汉字和英文字母时，所需缓冲区大小并不是2倍关系。
	int size = 0;
	size = WideCharToMultiByte(CP_ACP, 0, (LPCWSTR)jcstr, length, rtn, clen, NULL, NULL);
	if (size <= 0)
		return NULL;
	//释放新建的jstring
	//cout << "释放JNIenv" << endl;
	(env)->ReleaseStringChars(jstr, jcstr);
	
	//cout << "释放JNIenv成功了 ^^ " << endl;

	rtn[size] = 0;
	return rtn;
}
/*
turn jstring to string
*/
string jstringToString(JNIEnv * env, jstring src)
{
	//jstring to char *
	const char * ch = jstringToChars(env, src);

	//char* to string
	string result = string(ch);

	return result;
}
/*
turn string to jstring
*/
jstring stringToJstring(JNIEnv *env, string src)
{
	//string to char*
	const char* ch = src.c_str();
	//char* to jstring
	jstring result = charsTojstring(env, ch);

	return result;
}

/*
turn string to int
*/
int stringToInt(string src){

	int result = 0;
	stringstream ss;
	ss << src;
	ss >> result;
	return result;

}

/*
turn int to string
*/
string intToString(const int &int_temp)
{
	stringstream stream;
	string result;
	stream << int_temp;
	result = stream.str();   //此处也可以用 stream>>string_temp  
	return result;
}


/*
int callbackMethod1(int num, vector<int> vArray)
{
	int ret = 0;
	int needsDetach;
	JNIEnv *env = getJNIEnv(&needsDetach);
	jintArray jArray = env->NewIntArray(num);
	jint *jnum = new jint[num];
	for (int i = 0; i < num; ++i)
	{
		*(jnum + i) = vArray[i];
	}
	env->SetIntArrayRegion(jArray, 0, num, jnum);
	//现在得到了我们要的jArray，也就是回调函数中返回到Java端的int数组,回调中的参数为(int a,int[] b);JNI中的类型为"I[I"
	env->CallVoidMethod(mobj, mid, num, jArray);
	jthrowable exception = env->ExceptionOccurred();
	if (exception)
	{
		env->ExceptionDescribe();
		ret = -1;
	}
	delete[] jnum;
	return ret;
}

//二维数组
int callbackMethod2(int num, vector<vector<int> > vArray)
{
	int ret = 0;
	int needsDetach;
	JNIEnv *env = getJNIEnv(&needsDetach);
	jobjectArray jOArray;
	jclass intArrCls = env->FindClass("[I");
	jOArray = env->NewObjectArray(num, intArrCls, 0);
	//二维数组长度为2，循环赋值
	for (int i = 0; i < num; i++)
	{
		jint tmp[2];
		jintArray jiarr = env->NewIntArray(2);
		for (int j = 0; j < 2; j++) {
			tmp[j] = vArray[i][j];
		}
		env->SetIntArrayRegion(jiarr, 0, 2, tmp);
		env->SetObjectArrayElement(jOArray, i, jiarr);
		env->DeleteLocalRef(jiarr);
	}
	//回调中的参数为(int a,int[] b);JNI中的类型为"I[[I"
	env->CallVoidMethod(mobj, mid, num, jOArray);
	jthrowable exception = env->ExceptionOccurred();
	if (exception)
	{
		env->ExceptionDescribe();
		ret = -1;
	}
	return ret;
}
*/