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
        public DieRecordList(SocialSystem socialSystem)
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
