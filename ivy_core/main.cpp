// pch.cpp: 与预编译标头对应的源文件

#include "main.h"
#include"nameuuid.h"
// 当使用预编译的头时，需要使用此源文件，编译才能成功。
#include "ivygenerator.h"
#include "OBJLoader.h"
#include "SetupWidget.h"
#include "Common.h"
#include "Vector3d.h"
#include "BasicMesh.h"
#include <vector>
#include<string>

#include <ctime>
#include <cstdlib>
using namespace std;

SetupWidget g = SetupWidget();

char* str2;


void multiple_seed(Vector3d seedPos)
{
    Common::ivy.multiple_seed(seedPos);
}

//[DllImport("Dll3.dll")]
//private static extern int set([In][Out] string str1, float aa, float bb, float cc, float dd, float ee, float ff, float gg, float hh, float ii, float jj, float kk, [In][Out] ivy_GeneratorComponent.Vector3d2 v);
int set(char* str1 , float aa, float bb, float cc, float dd, float ee, float ff, float gg, float hh, float ii, float jj, float kk, Vector3d2 v)
{

    str2 = str1;
    Common::mesh.reset();
    g.onImportObj(str1);
    Common::ivy.resetSettings();
    Common::ivy.seed(Vector3d(v.x,v.y,v.z));// (0, -0.335936, 0));
    for (int i = 0; i < 100; ++i)
    {
        double ab,a,b;
        srand((unsigned)time(NULL));
        a = -100, b = 100;
        ab  = a + (b - a) * (rand() / (RAND_MAX + 1.0));
        //multiple_seed(Vector3d(v.x + ab, v.y, v.z ));
    }
    Common::ivy.setSet(aa, bb, cc, dd, ee, ff, gg, hh, ii, jj, kk);
    Common::mesh.prepareData();

    Common::mesh.calculateVertexNormals();
    return 0;
}

int birth_(char* str3)
{
    g.onBirth();
    g.onExportObj(str3);
    return 1;
}






int update_()
{




    g.onGrow();
    return 0;

}




int show_step_point(Vector3d2* s)
{
   
    std::vector<IvyRoot> roots_ = Common::ivy.roots;
  //  std::vector<IvyRoot2> roots2;
  //  LPCSTR
        // IvyRoot2 roots2[30];

 //   cout << "short 类型所占内存空间为： " << sizeof(IvyNode2) << endl;
   // return  sizeof(IvyNode2);
    int j = 0; int vv = 0;
    string kk = std::to_string(Common::ivy.roots.size());
    for (std::vector<IvyRoot>::iterator root = Common::ivy.roots.begin(); root != Common::ivy.roots.end(); ++root)
    {

        //  IvyNode2 node3[100000]; 
        int i = 0;
      //  IvyRoot2 r2 = IvyRoot2();
        for (std::vector<IvyNode>::iterator node = root->nodes.begin(); node != root->nodes.end(); ++node)
        {  
            IvyNode2 node2 = IvyNode2();
            Vector3d2 v;
            v.x = node->pos.x; v.y = node->pos.y; v.z = node->pos.z;
            node2.pos = v;
            s[i] = v;
        //    Vector3d2 v2;
         //   v2.x = node->primaryDir.x; v2.y = node->primaryDir.y;v2.z= node->primaryDir.z;
         //   node2.primaryDir = v2; 
        //    Vector3d2 v3;
         //   v3.x = node->adhesionVector.x, v3.y = node->adhesionVector.y; v3.z = node->adhesionVector.z;
        //    node2.adhesionVector = v3;
         //   Vector3d2 v4;
       //     v4.x = node->smoothAdhesionVector.x; v4.y = node->smoothAdhesionVector.y; v4.z = node->smoothAdhesionVector.z;
       //     node2.smoothAdhesionVector = v4;
        //    node2.length = node->length;
        //    node2.floatingLength = node->floatingLength;
       //     node2.climb = node->climb;
        //   r2.nodes[i] = node2;

        //   roots2[j].nodes[i].pos.x = r2.nodes[i].pos.x;
        //   roots2[j].nodes[i].pos.y = r2.nodes[i].pos.y;
         //  roots2[j].nodes[i].pos.z = r2.nodes[i].pos.z;
         
           i++;
           vv++;
        }
       
       
      //  r2.alive = root->alive;
       // r2.nodes = node3;
     //   r2.parents = root->parents;
       // r2.n2 = new IvyNode2[node3.size()];
      //  memcpy(r2.n2, &node3[0], node3.size() * sizeof(IvyNode2));
     
        j++;
    }
    return  vv;
}
 

const char* objname()
{
    char f[20] = "";
    char* t =(char*) name::uuid_.c_str();
   // strcpy(f, name::uuid_.c_str());
    return t;
}





int mainnww(IvyRoot2* roots2, char* outdata)
{
  

    Common::mesh.prepareData();

    Common::mesh.calculateVertexNormals();

    // Common::mesh.prepareData();

 //

     //for (int u = 300; u > 0; u--)
  //   {
   //      g.onGrow();
  //   }
    // g.onGrow(); g.onGrow(); g.onGrow(); 
    std::vector<IvyRoot> roots_ = Common::ivy.roots;
    //  std::vector<IvyRoot2> roots2;
    //  LPCSTR
          // IvyRoot2 roots2[30];

   // cout << "short 类型所占内存空间为： " << sizeof(IvyNode2) << endl;
    // return  sizeof(IvyNode2);
    int j = 0;
    string kk = std::to_string(Common::ivy.roots.size());
    for (std::vector<IvyRoot>::iterator root = Common::ivy.roots.begin(); root != Common::ivy.roots.end(); ++root)
    {

        //  IvyNode2 node3[100000]; 
        int i = 0;
        IvyRoot2 r2 = IvyRoot2();
        for (std::vector<IvyNode>::iterator node = root->nodes.begin(); node != root->nodes.end(); ++node)
        {
            if (i == 0) {
                string jk = std::to_string(root->nodes.size());
                kk += "_";
                kk += jk;
            }

            IvyNode2 node2 = IvyNode2();
            Vector3d2 v;
            v.x = node->pos.x; v.y = node->pos.y; v.z = node->pos.z;
            node2.pos = v;
            Vector3d2 v2;
            v2.x = node->primaryDir.x; v2.y = node->primaryDir.y; v2.z = node->primaryDir.z;
            node2.primaryDir = v2;
            Vector3d2 v3;
            v3.x = node->adhesionVector.x, v3.y = node->adhesionVector.y; v3.z = node->adhesionVector.z;
            node2.adhesionVector = v3;
            Vector3d2 v4;
            v4.x = node->smoothAdhesionVector.x; v4.y = node->smoothAdhesionVector.y; v4.z = node->smoothAdhesionVector.z;
            node2.smoothAdhesionVector = v4;
            node2.length = node->length;
            node2.floatingLength = node->floatingLength;
            node2.climb = node->climb;
            r2.nodes[i] = node2;

            //   roots2[j].nodes[i].pos.x = r2.nodes[i].pos.x;
            //   roots2[j].nodes[i].pos.y = r2.nodes[i].pos.y;
             //  roots2[j].nodes[i].pos.z = r2.nodes[i].pos.z;

            i++;

        }


        r2.alive = root->alive;
        // r2.nodes = node3;
        r2.parents = root->parents;
        // r2.n2 = new IvyNode2[node3.size()];
       //  memcpy(r2.n2, &node3[0], node3.size() * sizeof(IvyNode2));
        roots2[j] = r2;
        j++;
    }
    // roots2[0].nodes[0].pos.z = 9;
    // roots2_ = new IvyRoot2[roots2.size()];
   //  memcpy(roots2_, &roots2[0], roots2.size() * sizeof(IvyRoot2));
     // 
    char* str1 = (char*)kk.data();

    while ('\0' != *str1)
    {
        *outdata = *str1;
        outdata++;
        str1++;
    }
    *outdata = '\0';

















    outdata = str1;
    // *outdata ='8';
     //strcpy_s(outdata, strlen(str1)+1, str1);
    g.onBirth();
    char sa[100] = "";
    g.onExportObj(sa);
    return  1;
}