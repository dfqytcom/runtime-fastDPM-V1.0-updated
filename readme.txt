文件夹中有两个工程：
一：
1: testLib 为C++封装后的工程。
2：运行环境VS2013、opencv2.4.13。
3：封装后的工程文件如下：
    PM_type.h、FastDPM.h、 person_final.txt（模型文件）、FastDPM-2014-May.dll、test-lib0.dll


二：
1：testDLL为JAVA环境下的封装测试工程。
2: 将工程目录test-lib\test-lib0\x64\Release目录下的.dll和.lib文件拷贝至C:\Program Files\Java\jre1.8.0_121\bin目录下。
3：将person_final.txt（模型文件）拷贝至JAVA的testDLL工程目录中。本工程为：testdll\testDLL目录下。
4：在eclipse下（JAVA  jre1.8.0_25）运行。

