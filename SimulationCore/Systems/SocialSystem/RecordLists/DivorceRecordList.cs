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
        #region Private Members
        private SocialSystem _socialSystem;
        #endregion

        #region Constructors
        public DivorceRecordList(SocialSystem socialSystem)
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
