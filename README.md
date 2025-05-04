# ivy_Generator
 Ivy generating in grassh
This is a Grasshopper port of the Ivy Generator, and includes a C++ dll.
Download the project file and open "ivy.sln" with VisualStudio2019. You will see two projects in the solution. Set the platform of the "core" C++ project to "X64"
This "core" project generates a c++ dll file and exports some functions, including all the functions of ivy_Generator:
	//set imported obj's location, vast variety of parameter(ivySize......) and start point,
dllexport  int set(char* str1, float aa, float bb, float cc, float dd, float ee, float ff, float gg, float hh, float ii, float jj, float kk, Vector3d2 v);
	//growth step by step
dllexport  int update_();
	//output ivy model,output_path means location str
dllexport  int birth_(char* output_path);
	//show every update point
dllexport int show_step_point(Vector3d2* s);
	//get the generated obj name
dllexport const char* objname();
