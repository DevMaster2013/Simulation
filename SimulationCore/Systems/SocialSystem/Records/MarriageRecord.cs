using SimulationCore.Core;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Systems.SocialSystem.Records
{
    public class MarriageRecord : SystemRecord
    {
        #region Private Variables
        private HumanRecord _husbandRecord;
        private HumanRecord _wifeRecord;
        #endregion

        #region Constructors
        public MarriageRecord(HumanRecord husband, HumanRecord wife)
            : base()
        {
            HusbandRecord = husband;
            WifeRecord = wife;
            RecordState = RecordState.Valid;
        }
        public MarriageRecord(HumanRecord husband, HumanRecord wife, DateTime recordDate)
            : base(recordDate)
        {
            HusbandRecord = husband;
            WifeRecord = wife;
            RecordState = RecordState.Valid;
        }        
        #endregion

        #region Public Properties
        public HumanRecord HusbandRecord {
            get {
                return _husbandRecord;
            }

            set {
                _husbandRecord = value;
            }
        }
        public HumanRecord WifeRecord {
            get {
                return _wifeRecord;
            }

            set {
                _wifeRecord = value;
            }
        }
        #endregion
    }
}
