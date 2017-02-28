using SimulationCore.Core;
using SimulationCore.Systems.SocialSystem.Records;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Systems.SocialSystem
{
    public class Man : Human
    {
        #region Constructors
        public Man(SocialSystem socialSystem, string name)
            : base(socialSystem, name, HumanSex.Male)
        {
        }
        #endregion

        #region Public Methods
        public void Marry()
        {            
            var suitableWomen = SocialSystem.GetSuitableWomenForMarriage(this);
            var selectedWife = RandomSelector.SelectRandomSample(suitableWomen);
            var accepted = selectedWife.ResponseForMarriageProposal(this);
            if (accepted)
                SocialSystem.MarriageRecords.CreateRecord(this, selectedWife);
        }
        public void Divorce()
        {
            // TODO : Implement Divorce
            throw new NotImplementedException("Divorce not Implemented");
        }
        #endregion
    }
}
