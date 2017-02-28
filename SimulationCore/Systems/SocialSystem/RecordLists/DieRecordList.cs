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
        #region Constructors
        public DieRecordList()
            : base()
        {
        }
        #endregion

        #region Public Methods
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
