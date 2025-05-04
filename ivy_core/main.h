// pch.h: 这是预编译标头文件。
// 下方列出的文件仅编译一次，提高了将来生成的生成性能。
// 这还将影响 IntelliSense 性能，包括代码完成和许多代码浏览功能。
// 但是，如果此处列出的文件中的任何一个在生成之间有更新，它们全部都将被重新编译。
// 请勿在此处添加要频繁更新的文件，这将使得性能优势无效。





#define DLLEXPORT __declspec(dllexport)

#include "Vector3d.h"
#include "BasicMesh.h"
#include <vector>
#include "Ivy.h"
#ifdef __cplusplus
extern "C" {
#endif
   // IvyRoot2* mainnww()；

	//this is test
	DLLEXPORT int mainnww(IvyRoot2* roots27, char* outdata);
	//set imported obj's location, vast variety of parameter(ivySize......) and start point,
	DLLEXPORT  int set(char* str1, float aa, float bb, float cc, float dd, float ee, float ff, float gg, float hh, float ii, float jj, float kk, Vector3d2 v);
	//growth step by step
	DLLEXPORT  int update_();
	//output ivy model,str1 means location str
	DLLEXPORT  int birth_(char* str1);
	//show every update point
	DLLEXPORT  int show_step_point(Vector3d2* s);
	//the obj name
	DLLEXPORT const char* objname();
#ifdef __cplusplus
}
#endif
// 添加要在此处预编译的标头
//#include "framework.h"

