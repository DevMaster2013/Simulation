using SimulationCore.Core;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Systems.SocialSystem.Records
{
    public class DivorceRecord : SystemRecord
    {
        #region Private Variables
        private MarriageRecord _marriageRecord;
        #endregion

        #region Constructors
        public DivorceRecord(MarriageRecord record)
            : base()
        {
            MarriageRecord = record;
            RecordState = RecordState.Valid;
        }
        public DivorceRecord(MarriageRecord record, DateTime recordDate)
            : base(recordDate)
        {
            MarriageRecord = record;
            RecordState = RecordState.Valid;
        }
        #endregion

        #region Public Properties
        public MarriageRecord MarriageRecord {
            get {
                return _marriageRecord;
            }

            protected set {
                _marriageRecord = value;
            }
        }
        #endregion
    }
}
