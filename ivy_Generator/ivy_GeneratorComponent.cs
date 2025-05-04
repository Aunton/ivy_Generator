using Grasshopper;
using Grasshopper.Kernel;
using Rhino.FileIO;
using Rhino.Geometry;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Runtime.InteropServices;
using System.Windows.Forms;

namespace ivy_Generator
{
    public class ivy_GeneratorComponent : GH_Component
    {
        /// <summary>
        /// Each implementation of GH_Component must provide a public 
        /// constructor without any arguments.
        /// Category represents the Tab in which the component will appear, 
        /// Subcategory the panel. If you use non-existing tab or panel names, 
        /// new tabs/panels will automatically be created.
        /// </summary>
        public ivy_GeneratorComponent()
          : base("ivy_Generator", "ivy",
            "Description",
            "ivy", "Generator")
        {
        }

        /// <summary>
        /// Registers all the input parameters for this component.
        /// </summary>
        protected override void RegisterInputParams(GH_Component.GH_InputParamManager pManager)
        {
            pManager.AddBooleanParameter("bool", "", "", GH_ParamAccess.item);


            pManager.AddPointParameter("point", "", "", GH_ParamAccess.item);
            pManager.AddMeshParameter("mesh", "", "", GH_ParamAccess.list);
            pManager.AddNumberParameter("ivySize", "", "", 0, 0.0135);
            pManager.AddNumberParameter("primaryWeight", "", "", 0, 0.5);
            pManager.AddNumberParameter("randomWeight", "", "", 0, 0.2);
            pManager.AddNumberParameter("gravityWeight", "", "", 0, 1.0);
            pManager.AddNumberParameter("adhesionWeight", "", "", 0, 0.1);
            pManager.AddNumberParameter("branchingProbability", "", "", 0, 0.95);
            pManager.AddNumberParameter("maxFloatLength", "", "", 0, 0.1);
            pManager.AddNumberParameter("MaxAdhesionDistance", "", "", 0, 0.1);
            pManager.AddNumberParameter("ivyBranchSize", "", "", 0, 0.15);
            pManager.AddNumberParameter("ivyLeafSize", "", "", 0, 1.5);
            pManager.AddNumberParameter("leafProbability", "", "", 0, 0.7);
            pManager[3].Optional = true;
            pManager[4].Optional = true;
            pManager[5].Optional = true;
            pManager[6].Optional = true;
            pManager[7].Optional = true;
            pManager[8].Optional = true;
            pManager[9].Optional = true;
            pManager[10].Optional = true;
            pManager[11].Optional = true;
            pManager[12].Optional = true;
            pManager[13].Optional = true;
        }

        void ho(object s, EventArgs e)
        {

            //   f=false;
        }
        /// <summary>
        /// Registers all the output parameters for this component.
        /// </summary>
        protected override void RegisterOutputParams(GH_Component.GH_OutputParamManager pManager)
        {
            pManager.AddPointParameter("points", "p", "points", GH_ParamAccess.list);
            this.Params.Input[1].ObjectChanged += ho; this.Params.Input[2].ObjectChanged += ho;
            pManager.AddTextParameter("name", "n", "objname", GH_ParamAccess.item);
            
        }

        /// <summary>
        /// This is the method that actually does the work.
        /// </summary>
        /// <param name="DA">The DA object can be used to retrieve data from input parameters and 
        /// to store data in output parameters.</param>
        //清除所有数据
        protected override void AppendAdditionalComponentMenuItems(System.Windows.Forms.ToolStripDropDown menu)
        {
            // Append the item to the menu, making sure it's always enabled and checked if Absolute is True.
            ToolStripMenuItem item = Menu_AppendItem(menu, "clean_mesh", Menu_AbsoluteClicked, true, false);
            // Specifically assign a tooltip text to the menu item.
            item.ToolTipText = "clean";
        }

        private void Menu_AbsoluteClicked(object sender, EventArgs e)
        {
            f = false;
        }

        bool g = false;
        List<Point3d> pp;
        Vector3d2[] ss;
        bool f = false;
        List<Mesh> in_mesh = new List<Mesh> { };
        string path;
        Vector3d2 vv2;
        Point3d v = new Point3d();
        protected override void SolveInstance(IGH_DataAccess DA)
        {
            //把纹理图片写入本地
            string in_name = "MeshA02";
            string in_path = Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData) + @"\\Grasshopper\6.dll";
            path = System.IO.Path.GetDirectoryName(in_path) + "\\" + in_name + ".obj";
            if (!Directory.Exists(System.IO.Path.GetDirectoryName(in_path) + "\\textures"))
            {
                Directory.CreateDirectory(System.IO.Path.GetDirectoryName(in_path) + "\\textures");
                Bitmap i1 = ivy_Generator.Properties.Resources.efeu1;
                i1.Save(System.IO.Path.GetDirectoryName(in_path) + "\\textures\\" + "efeu1.png");

                Bitmap i2 = ivy_Generator.Properties.Resources.efeu0;
                i2.Save(System.IO.Path.GetDirectoryName(in_path) + "\\textures\\" + "efeu0.png");

                Bitmap i3 = ivy_Generator.Properties.Resources.efeu_branch;
                i3.Save(System.IO.Path.GetDirectoryName(in_path) + "\\textures\\" + "efeu_branch.png");
                









            }


            if (in_mesh.Count == 0)
            {


            }
            int count = this.in_mesh.Count;
            double value = 0.0135;
            double num = 0.5;
            double num2 = 0.2;
            double num3 = 1.0;
            double num4 = 0.1;
            double num5 = 0.95;
            double num6 = 0.1;
            double num7 = 0.1;
            double num8 = 0.15;
            double num9 = 1.5;
            double num10 = 0.7;
            float aa = 0.0135f;
            float bb = 0.5f;
            float cc = 0.2f;
            float dd = 1f;
            float ee = 0.1f;
            float ff = 0.95f;
            float gg = 0.1f;
            float hh = 0.1f;
            float ii = 0.15f;
            float jj = 1.5f;
            float kk = 0.7f;
            DA.GetData<double>(3, ref value);
            aa = Convert.ToSingle(value);
            DA.GetData<double>(4, ref num);
            bb = (float)num;
            DA.GetData<double>(5, ref num2);
            cc = (float)num2;
            DA.GetData<double>(6, ref num3);
            dd = (float)num3;
            DA.GetData<double>(7, ref num4);
            ee = (float)num4;
            DA.GetData<double>(8, ref num5);
            ff = (float)num5;
            DA.GetData<double>(9, ref num6);
            gg = (float)num6;
            DA.GetData<double>(10, ref num7);
            hh = (float)num7;
            DA.GetData<double>(11, ref num8);
            ii = (float)num8;
            DA.GetData<double>(12, ref num9);
            jj = (float)num9;
            DA.GetData<double>(13, ref num10);
            kk = (float)num10;
            DA.GetData<bool>(0, ref this.g);





















            DA.GetData(0, ref g);
            Point3d pp2 = new Point3d();
            DA.GetData(1, ref pp2);
            List<Mesh> m = new List<Mesh> { };
            DA.GetDataList(2, m);
            if (!f || !(pp2.X == v.X && pp2.Y == v.Y && pp2.Z == v.Z))
            {
                v = pp2;

                in_mesh = m;
                //   path = System.IO.Path.GetDirectoryName(in_path) + "\\" + in_name + ".obj";
                int faceCount = 0;
                //模型写入本地
                using (StreamWriter writer = new StreamWriter(path))
                {
                    for (int n = 0; n < in_mesh.Count; n++)
                    {
                        List<String> vert = new List<String>();
                        List<String> face = new List<String>();

                        in_mesh[n].Faces.ConvertQuadsToTriangles();
                        BoundingBox bbox = in_mesh[n].GetBoundingBox(true);

                        for (int i = 0; i < in_mesh[n].Vertices.Count; i++)
                        {
                            vert.Add(String.Format("v {0} {1} {2}", in_mesh[n].Vertices[i].X, in_mesh[n].Vertices[i].Z, -in_mesh[n].Vertices[i].Y));
                        }

                        for (int i = 0; i < in_mesh[n].TextureCoordinates.Count; i++)
                        {
                            double tx = in_mesh[n].TextureCoordinates[i].X;
                            double ty = in_mesh[n].TextureCoordinates[i].Y;
                            vert.Add(String.Format("vt " + tx.ToString("F6") + " " + ty.ToString("F6")));
                        }

                        for (int i = 0; i < in_mesh[n].Normals.Count; i++)
                        {
                            vert.Add(String.Format("vn {0} {1} {2}", in_mesh[n].Normals[i].X, in_mesh[n].Normals[i].Z, -in_mesh[n].Normals[i].Y));
                        }

                        for (int i = 0; i < in_mesh[n].Faces.Count; i++)
                        {
                            MeshFace f = in_mesh[n].Faces.GetFace(i);
                            int fa = f.A + 1 + faceCount;
                            int fb = f.B + 1 + faceCount;
                            int fc = f.C + 1 + faceCount;
                            string fas = fa.ToString();
                            string fbs = fb.ToString();
                            string fcs = fc.ToString();
                            face.Add(String.Format("f " + fas + "/" + fas + "/" + fas + " " + fbs + "/" + fbs + "/" + fbs + " " + fcs + "/" + fcs + "/" + fcs));
                        }

                        for (int i = 0; i < vert.Count; i++)
                        {
                            writer.WriteLine(vert[i]);
                        }

                        writer.WriteLine("");
                        writer.WriteLine("g " + in_name + n.ToString());

                        for (int i = 0; i < face.Count; i++)
                        {
                            writer.WriteLine(face[i]);
                        }
                        faceCount += in_mesh[n].Vertices.Count;
                    }
                }

















                pp = new List<Point3d> { };
                ss = new Vector3d2[10000000];
                Vector3d2 vv2=new Vector3d2();
                // vv2.x = -0.650833f; vv2.y = 0.559154f; vv2.z = 0;
                vv2.x = (float)pp2.X; vv2.y = (float)pp2.Z; vv2.z = -(float)pp2.Y;
                //在c++里面设置生长参数,读取mesh
                set(path, aa, bb, cc, dd, ee, ff, gg, hh, ii, jj, kk, vv2); f = true;
            }
            if (!g)
            {
                //一步一步生长
                update_();
                //返回每次更新后点的坐标
                int s2 = show_step_point(ss);




                for (int i = 0; i < s2; i++)
                {
                    pp.Add(new Point3d(ss[i].x, -ss[i].z, ss[i].y));

                }
            }

            DA.SetDataList(0, pp);
            FileObjReadOptions fileObjReadOptions = new FileObjReadOptions(new FileReadOptions
            {
                BatchMode = true,
                ImportMode = true
            });
            fileObjReadOptions.MapYtoZ = true;
            fileObjReadOptions.IgnoreTextures = false;
            fileObjReadOptions.DisplayColorFromObjMaterial = true;
            if (g)

            {    //c++模型导出本地
                birth_(path);

                try { FileObj.Read(path + ".obj", Rhino.RhinoDoc.ActiveDoc, fileObjReadOptions); } catch { }
                Rhino.RhinoDoc doc = Rhino.RhinoDoc.ActiveDoc;

                foreach (Rhino.DocObjects.Material i in doc.Materials)



                {

                    if (i.Name == "leaf_young" || i.Name == "leaf_adult")

                        i.AlphaTransparency = true; i.CommitChanges();
                }

            }
            IntPtr ptr = objname();
            string msg = Marshal.PtrToStringAnsi(ptr);
            DA.SetData(1, msg);


        }

        /// <summary>
        /// Provides an Icon for every component that will be visible in the User Interface.
        /// Icons need to be 24x24 pixels.
        /// You can add image files to your project resources and access them like this:
        /// return Resources.IconForThisComponent;
        /// </summary>
        protected override System.Drawing.Bitmap Icon => ivy_Generator.Properties.Resources._53e22;//                       null;

        /// <summary>
        /// Each component must have a unique Guid to identify it. 
        /// It is vital this Guid doesn't change otherwise old ghx files 
        /// that use the old ID will partially fail during loading.
        /// </summary>

        struct Vector3d2  //12
        {


            public float x;
            public float y;
            public float z;
            public IntPtr next;

            // Vector3d2() { this.x = 0.0f; this.y = (0.0f); z = (0.0f);}

            // Vector3d2(float x1, float y1, float z1) {x = x1;y = y1;z = z1;}
        };


        /** an ivy node */
        struct IvyNode2  //12*4+12=60
        {
            //List<Vector3d2>

            //  IvyNode2() {climb = false; length = 0.0f; floatingLength = 0.0f; }

            /** node position */
            public Vector3d2 pos;

            /** primary grow direction, a weighted sum of the previous directions */
            Vector3d2 primaryDir;

            /** adhesion vector as a result from other scene objects */
            Vector3d2 adhesionVector;

            /** a smoothed adhesion vector computed and used during the birth phase,
               since the ivy leaves are align by the adhesion vector, this smoothed vector
               allows for smooth transitions of leaf alignment */
            public Vector3d2 smoothAdhesionVector;

            /** length of the associated ivy branch at this node */
            float length;

            /** length at the last node that was climbing */
            float floatingLength;

            /** climbing state */
            bool climb;
        };
        struct IvyRoot2
        {

            // IvyRoot2(int z){this.nodes = new IvyNode2[100];}

            /** a number of nodes */
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 3000)]
            public IvyNode2[] nodes;// = new IvyNode2[100];

            // IvyNode2* n2;
            /** alive state */
            public bool alive;

            /** number of parents, represents the level in the root hierarchy */
            public int parents;
        };

      public const string dll = @"..\..\..\..\x64\Debug\";
        [DllImport( dll + @"core.dll")]
        unsafe private extern static int mainnww([In, Out] IvyRoot2[] r, IntPtr buf);


        //[DllImport(@"core.dll")]
       // unsafe private extern static int set([In, Out] string str1, [In, Out] Vector3d2 v);

        [DllImport(dll+"core.dll")]
        private static extern int set([In][Out] string str1, float aa, float bb, float cc, float dd, float ee, float ff, float gg, float hh, float ii, float jj, float kk, [In][Out] ivy_GeneratorComponent.Vector3d2 v);


        [DllImport(dll+@"core.dll")]
        unsafe private extern static int update_();




        [DllImport(dll+@"core.dll")]
        unsafe private extern static int birth_([In, Out] string d);


        [DllImport(dll+@"core.dll")]
        unsafe private extern static int show_step_point([In, Out] Vector3d2[] s);

        [DllImport(dll+@"core.dll", CharSet = CharSet.Ansi)]
        unsafe private extern static IntPtr objname();



        static void Main2()
        {
            Vector3d2[] ss = new Vector3d2[10000];
            Vector3d2 vv2;
            vv2.x = -0.650833f; vv2.y = 0.559154f; vv2.z = 0;
           // set("D:\\MeshA01.obj", vv2);
            for (int u = 300; u > 0; u--)
            {
                update_();
            }
            int s2 = show_step_point(ss);

            birth_("");







            /********************************************************************************************************************/










        }

        /// <summary>
        /// Each component must have a unique Guid to identify it. 
        /// It is vital this Guid doesn't change otherwise old ghx files 
        /// that use the old ID will partially fail during loading.
        /// </summary>
        public override Guid ComponentGuid => new Guid("89C4E8B6-569B-471B-8C12-73A0B92175BF");
    }
}