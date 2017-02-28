using SimulationCore.Core;
using SimulationCore.Systems.SocialSystem.Records;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Systems.SocialSystem.RecordLists
{
    public class MarriageRecordList : SystemRecordList<MarriageRecord>
    {
        #region Constructors
        public MarriageRecordList()
            : base()
        {
        }
        #endregion

        #region Public Methods
        public MarriageRecord GetRecord(Human human)
        {
            return _records.Find(x => (x.HusbandRecord.Human == human || x.WifeRecord.Human == human));
        }
        #endregion
    }
}
