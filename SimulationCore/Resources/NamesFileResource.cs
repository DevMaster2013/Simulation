using SimulationCore.Core;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace SimulationCore.Resources
{
    public class NamesFileResource : Resource
    {
        #region Private Data Members
        private List<string> _names;
        #endregion

        #region Constructors
        public NamesFileResource()
            : base()
        {
            Names = new List<string>();
        }
        #endregion

        #region Public Properties
        public List<string> Names {
            get {
                return _names;
            }

            protected set {
                _names = value;
            }
        }
        #endregion

        #region Public Methods        
        public bool AddName(string name)
        {
            if (Names.Contains(name))
                return false;

            Names.Add(name);
            return true;
        }
        public string GetRandomName()
        {
            return RandomSelector.SelectRandomSample(Names);
        }
        #endregion

        #region Implementing Abstract Resource File
        protected override bool loadFileData(FileStream fs)
        {
            Names.Clear();
            StreamReader sr = new StreamReader(fs);
            while (!sr.EndOfStream)
            {
                string name = sr.ReadLine();
                AddName(name);
            }
            sr.Close();
            return true;
        }

        protected override bool saveFileData(FileStream fs)
        {
            StreamWriter sw = new StreamWriter(fs);
            foreach (string name in Names)
                sw.WriteLine(name);
            sw.Close();
            return true;
        }
        #endregion
    }
}
