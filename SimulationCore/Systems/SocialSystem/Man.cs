using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Systems.SocialSystem
{
    public class Man : Human
    {
        #region Constructors
        public Man(string name)
            : base(name, HumanSex.Male)
        {
        }
        #endregion

        #region Public Methods
        public void Marry()
        {
            // TODO : Implement Marry
            throw new NotImplementedException("Marry not Implemented");
        }
        public void Divorce()
        {
            // TODO : Implement Divorce
            throw new NotImplementedException("Divorce not Implemented");
        }
        #endregion
    }
}
