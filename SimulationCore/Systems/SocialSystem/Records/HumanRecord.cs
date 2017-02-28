using SimulationCore.Core;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Systems.SocialSystem.Records
{
    public class HumanRecord : SystemRecord
    {
        #region Private Variables
        private Human _human;
        private MarriageRecord _marriageRecord;
        #endregion

        #region Constructors
        public HumanRecord(Human human, MarriageRecord record)
            : base()
        {
            MarriageRecord = record;
            RecordState = RecordState.Valid;
            Human = human;
        }
        public HumanRecord(Human human, MarriageRecord record, DateTime recordDate)
            : base(recordDate)
        {
            MarriageRecord = record;
            RecordState = RecordState.Valid;
            Human = human;
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
        public Human Human {
            get {
                return _human;
            }

            protected set {
                _human = value;
            }
        }
        #endregion
    }
}
