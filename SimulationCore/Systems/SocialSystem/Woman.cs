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
            var marriageRecord = SocialSystem.MarriageRecords.GetRecord(this);
            var dieRecord = SocialSystem.DieRecords.GetRecord(this);
            if (marriageRecord == null || marriageRecord.RecordState == RecordState.Obselete ||
                dieRecord != null)
            {
                return;
            }

            HumanSex childSex = RandomSelector.GetRandomEnumValue<HumanSex>();
            string childName = RandomSelector.GetRandomName(childSex);
            SocialSystem.HumanRecords.CreateRecord(marriageRecord, childName, childSex);
        }
        public override void Update(double elapsedSeconds)
        {
            base.Update(elapsedSeconds);
        }
        #endregion
    }
}
