using SimulationCore.Core;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Systems.SocialSystem
{
    public class Woman : Human
    {
        #region Constructors
        public Woman(SocialSystem socialSystem, string name)
            : base(socialSystem, name, HumanSex.Female)
        {
        }
        #endregion

        #region Public Methods
        public bool ResponseForMarriageProposal(Man man)
        {
            return RandomSelector.SelectRandomCondition();
        }
        public void ProduceBaby()
        {
            // TODO : Implement ProduceBaby
            throw new NotImplementedException("ProduceBaby not Implemented");
        }
        #endregion

        #region Private Methods
        private void acceptProposal(Man man)
        {
            // TODO : Implement acceptProposal
            throw new NotImplementedException("acceptProposal not Implemented");
        }
        private void refuseProposal(Man man)
        {
            // TODO : Implement refuseProposal
            throw new NotImplementedException("refuseProposal not Implemented");
        }
        #endregion
    }
}
