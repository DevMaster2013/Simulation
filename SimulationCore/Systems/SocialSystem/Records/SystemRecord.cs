using SimulationCore.Core;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Systems.SocialSystem.Records
{
    public enum RecordState : short
    {
        Inavlid,
        Valid,
        Obselete
    }

    public class SystemRecord
    {
        #region Static Protected Variables
        protected static ulong currentRecordID = 0;
        #endregion

        #region Protected Member Variables
        protected DateTime _recordDate;
        protected ulong _recordID;
        protected RecordState _recordState = RecordState.Inavlid;
        #endregion

        #region Constructors
        public SystemRecord()
            : this(GameTimeSettings.CurrentGameTime)
        {
        }
        public SystemRecord(DateTime recordDate)
        {
            RecordDate = recordDate;
            RecordID = currentRecordID++;
            RecordState = RecordState.Inavlid;
        }
        #endregion

        #region Public Properties
        public DateTime RecordDate {
            get {
                return _recordDate;
            }

            protected set {
                _recordDate = value;
            }
        }
        public ulong RecordID {
            get {
                return _recordID;
            }

            protected set {
                _recordID = value;
            }
        }
        public RecordState RecordState {
            get {
                return _recordState;
            }

            set {
                _recordState = value;
            }
        }
        #endregion
    }
}
