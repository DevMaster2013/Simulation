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
        #region Private Members
        private SocialSystem _socialSystem;
        #endregion

        #region Constructors
        public MarriageRecordList(SocialSystem socialSystem)
            : base()
        {
            SocialSystem = socialSystem;
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
        public MarriageRecord CreateRecord(Man husband, Woman wife)
        {
            var husbandRecord = SocialSystem.HumanRecords.GetRecord(husband);
            var wifeRecord = SocialSystem.HumanRecords.GetRecord(wife);
            MarriageRecord record = new MarriageRecord(husbandRecord, wifeRecord);
            AddRecord(record);
            return record;
        }
        public MarriageRecord GetRecord(Human human)
        {
            return _records.Find(x => (x.HusbandRecord.Human == human || x.WifeRecord.Human == human) && (x.RecordState != RecordState.Obselete));
        }
        #endregion
    }
}
