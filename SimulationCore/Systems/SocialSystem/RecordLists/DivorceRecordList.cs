using SimulationCore.Core;
using SimulationCore.Systems.SocialSystem.Records;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Systems.SocialSystem.RecordLists
{
    public class DivorceRecordList : SystemRecordList<DivorceRecord>
    {
        #region Constructors
        public DivorceRecordList()
            : base()
        {
        }
        #endregion

        #region Public Methods
        public DivorceRecord GetRecord(Human human)
        {
            return _records.Find(x => (x.MarriageRecord.HusbandRecord.Human == human || x.MarriageRecord.WifeRecord.Human == human));
        }
        public override void AddRecord(DivorceRecord record)
        {
            base.AddRecord(record);
            record.MarriageRecord.RecordState = RecordState.Obselete;            
        }
        #endregion
    }
}
