using SimulationCore.Civilization;
using SimulationCore.Core;
using SimulationCore.Systems.SocialSystem.Records;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Systems.SocialSystem.RecordLists
{
    public class DieRecordList : SystemRecordList<DieRecord>
    {
        #region Private Members
        private SocialSystem _socialSystem;
        #endregion

        #region Constructors
        public DieRecordList(CivilizationManager civilManager)
            : base(civilManager)
        {
            SocialSystem = CivilManager.GetSystem<SocialSystem>();
        }
        #endregion

        #region Public Properties
        public SocialSystem SocialSystem
        {
            get
            {
                return _socialSystem;
            }

            set
            {
                _socialSystem = value;
            }
        }
        #endregion

        #region Public Methods
        public DieRecord CreateRecord(Human human)
        {            
            var humanRecord = SocialSystem.HumanRecords.GetRecord(human);
            if (humanRecord.RecordState == RecordState.Obselete)
                return null;

            DieRecord record = new DieRecord(humanRecord);
            AddRecord(record);
            return record;
        }
        public DieRecord GetRecord(Human human)
        {
            return _records.Find(x => (x.HumanRecord.Human == human || x.HumanRecord.Human == human));
        }
        public override void AddRecord(DieRecord record)
        {
            base.AddRecord(record);
            record.HumanRecord.RecordState = RecordState.Obselete;
        }
        #endregion
    }
}
