using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace SimulationCore.Resources
{
    public abstract class Resource
    {
        #region Protected Variables
        protected string _resourceFileName;
        #endregion

        #region Constructors
        public Resource()
        {
            ResourceFileName = "";
        }
        public Resource(string fileName)
        {
            ResourceFileName = fileName;
        }
        #endregion

        #region Public Properties
        public string ResourceFileName {
            get {
                return _resourceFileName;
            }
            protected set {
                _resourceFileName = value;
            }
        }
        #endregion

        #region Public Methods
        public bool Load(string fileName)
        {
            ResourceFileName = fileName;

            FileStream fs = new FileStream(fileName, FileMode.Open, FileAccess.Read);
            bool result = loadFileData(fs);
            fs.Close();

            return result;
        }
        public bool Save(string fileName)
        {
            ResourceFileName = fileName;

            FileStream fs = new FileStream(fileName, FileMode.Create, FileAccess.Write);
            bool result = saveFileData(fs);
            fs.Close();

            return result;
        }
        #endregion

        #region Abstract Protected Methods
        protected abstract bool loadFileData(FileStream fs);
        protected abstract bool saveFileData(FileStream fs);
        #endregion
    }
}
