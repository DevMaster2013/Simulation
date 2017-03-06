using SimulationCore.Civilization;
using SimulationCore.Core;
using SimulationCore.Systems.SocialSystem.Records;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Systems.SocialSystem
{
    public class Woman : Human
    {
        #region Constructors
        public Woman(CivilizationManager civilManager, string name)
            : base(civilManager, name, HumanSex.Female)
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
            SocialSystem socialSystem = CivilManager.GetSystem<SocialSystem>();

            var marriageRecord = socialSystem.MarriageRecords.GetRecord(this);
            var dieRecord = socialSystem.DieRecords.GetRecord(this);
            if (marriageRecord == null || marriageRecord.RecordState == RecordState.Obselete ||
                dieRecord != null)
            {
                return;
            }

            HumanSex childSex = RandomSelector.GetRandomEnumValue<HumanSex>();
            string childName = RandomSelector.GetRandomName(childSex);
            socialSystem.HumanRecords.CreateRecord(marriageRecord, childName, childSex);
        }
        #endregion
    }
}
