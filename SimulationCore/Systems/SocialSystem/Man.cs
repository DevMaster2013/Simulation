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
