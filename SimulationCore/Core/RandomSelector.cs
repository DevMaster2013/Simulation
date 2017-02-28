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
        #endregion
    }
}
