using SimulationCore.Civilization;
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
        public Man(CivilizationManager civilManager, string name)
            : base(civilManager, name, HumanSex.Male)
        {
        }
        #endregion

        #region Public Methods
        public void Divorce()
        {
            SocialSystem socialSystem = CivilManager.GetSystem<SocialSystem>();

            var marriageRecord = socialSystem.MarriageRecords.GetRecord(this);
            if (marriageRecord != null)
            {
                socialSystem.DivorceRecords.CreateRecord(marriageRecord);
            }
            else
            {
                // TODO : the man is not married or spouse is died
            }
        }
        #endregion
    }
}
