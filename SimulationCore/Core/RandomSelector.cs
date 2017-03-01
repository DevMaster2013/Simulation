using SimulationCore.Resources;
using SimulationCore.Systems.SocialSystem;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Core
{
    public static class RandomSelector
    {
        #region Static Public Variables
        public static T SelectRandomSample<T>(IEnumerable<T> collection)
        {
            Random random = new Random((int)DateTime.Now.Ticks);
            int index = random.Next(0, collection.Count());
            return collection.ElementAt(index);
        }
        public static bool SelectRandomCondition()
        {
            Random random = new Random((int)DateTime.Now.Ticks);
            return random.NextDouble() > 0.5 ? true : false;
        }
        public static double GetRandomDouble(double maxValue = 1.0)
        {
            Random random = new Random((int)DateTime.Now.Ticks);
            return random.NextDouble() * maxValue;
        }
        public static T GetRandomEnumValue<T> ()
        {
            Random random = new Random((int)DateTime.Now.Ticks);
            Array values = Enum.GetValues(typeof(T));
            int index = random.Next(0, values.Length);
            return (T)values.GetValue(index);
        }
        public static string GetRandomName(HumanSex sex)
        {
            NamesFileResource resource = ResourceManager.GetResource<NamesFileResource>(sex == HumanSex.Female ? "FemaleNames" : "MaleNames");
            return resource.GetRandomName();
        }
        #endregion
    }
}
