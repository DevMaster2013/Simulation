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
            bool accepted = false;
            Woman selectedWife = null;
            while (!accepted && suitableWomen.Count > 0)
            {
                selectedWife = RandomSelector.SelectRandomSample(suitableWomen);
                suitableWomen.Remove(selectedWife);
                accepted = selectedWife.ResponseForMarriageProposal(this);
            }

            if (accepted)
                SocialSystem.MarriageRecords.CreateRecord(this, selectedWife);
        }
        public void Divorce()
        {
            var marriageRecord = SocialSystem.MarriageRecords.GetRecord(this);
            if (marriageRecord != null)
            {
                SocialSystem.DivorceRecords.CreateRecord(marriageRecord);
            }
            else
            {
                // TODO : the man is not married or spouse is died
            }
        }
        #endregion
    }
}
