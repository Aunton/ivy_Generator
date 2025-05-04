using Grasshopper;
using Grasshopper.Kernel;
using System;
using System.Drawing;

namespace ivy_Generator
{
    public class ivy_GeneratorInfo : GH_AssemblyInfo
    {
        public override string Name => "ivy_Generator";

        //Return a 24x24 pixel bitmap to represent this GHA library.
        public override Bitmap Icon => null;

        //Return a short string describing the purpose of this GHA library.
        public override string Description => "";

        public override Guid Id => new Guid("F2DD12B6-6EF3-4490-9A12-5E17A9B153FD");

        //Return a string identifying you or your company.
        public override string AuthorName => "";

        //Return a string representing your preferred contact details.
        public override string AuthorContact => "";
    }
}