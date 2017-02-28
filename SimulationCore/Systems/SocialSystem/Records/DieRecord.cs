using SimulationCore.Core;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Systems.SocialSystem.Records
{
    public class DieRecord : SystemRecord
    {
        #region Private Variables
        private HumanRecord _humanRecord;
        #endregion

        #region Constructors
        public DieRecord(HumanRecord human)
            : base()
        {
            RecordState = RecordState.Valid;
            HumanRecord = human;
        }
        public DieRecord(HumanRecord human, DateTime recordDate)
            : base(recordDate)
        {
            RecordState = RecordState.Valid;
            HumanRecord = human;
        }
        #endregion

        #region Public Properties
        public HumanRecord HumanRecord {
            get {
                return _humanRecord;
            }

            protected set {
                _humanRecord = value;
            }
        }
        #endregion
    }
}
