using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace SimulationCore.Resources
{
    public static class ResourceManager
    {
        #region Private Variables
        private static Dictionary<string, Resource> _resources = new Dictionary<string, Resource>();
        #endregion

        #region Public Methods
        public static void AddResource(string name, Resource resource)
        {
            if (!_resources.ContainsKey(name))
            {
                _resources.Add(name, resource);
            }
            else
            {
                throw new Exception("There are resource with the same name");
            }
        }
        public static T GetResource<T>(string name) where T : Resource
        {
            if (_resources.ContainsKey(name))
            {
                return _resources[name] as T;
            }
            else
            {
                throw new Exception("There are resource with the same name");
            }
        }
        public static bool LoadAllResources()
        {
            string resourcesPath = "..\\..\\..\\Data\\";
            if (!loadNamesResources(resourcesPath + "Names"))
                return false;
            return true;
        }
        #endregion

        #region Private Methods
        private static bool loadNamesResources(string namesPath)
        {
            var fileNames = Directory.GetFiles(namesPath, "*.sim");
            foreach(var name in fileNames)
            {
                NamesFileResource resource = new NamesFileResource();
                if (!resource.Load(name))
                    return false;

                string resName = Path.GetFileNameWithoutExtension(name);
                AddResource(resName, resource);
            }

            return true;
        }
        #endregion
    }
}
