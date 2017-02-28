using SimulationCore.Systems.SocialSystem.RecordLists;
using SimulationCore.Systems.SocialSystem.Records;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Systems.SocialSystem
{
    public class SocialSystem
    {
        #region Private Variables
        private MarriageRecordList _marriageRecords;
        private DivorceRecordList _divorceRecords;
        private HumanRecordList _humanRecords;
        private DieRecordList _dieRecords;        
        #endregion

        #region Constructors
        public SocialSystem()
        {
            MarriageRecords = new MarriageRecordList();
            DivorceRecords = new DivorceRecordList();
            HumanRecords = new HumanRecordList();
            DieRecords = new DieRecordList();
        }
        #endregion

        #region Public Properties
        public MarriageRecordList MarriageRecords {
            get {
                return _marriageRecords;
            }

            protected set {
                _marriageRecords = value;
            }
        }

        public DivorceRecordList DivorceRecords {
            get {
                return _divorceRecords;
            }

            protected set {
                _divorceRecords = value;
            }
        }

        public HumanRecordList HumanRecords {
            get {
                return _humanRecords;
            }

            protected set {
                _humanRecords = value;
            }
        }

        public DieRecordList DieRecords {
            get {
                return _dieRecords;
            }

            protected set {
                _dieRecords = value;
            }
        }
        #endregion

        #region Public Methods
        public void CleanSystem()
        {
            MarriageRecords.RemoveObseleteRecords();
            DivorceRecords.RemoveObseleteRecords();
            HumanRecords.RemoveObseleteRecords();
            DieRecords.RemoveObseleteRecords();
        }
        public List<Woman> GetSuitableWomenForMarriage(Man man)
        {
            // TODO : Implement GetSuitableWomenForMarriage
            throw new NotImplementedException("GetSuitableWomenForMarriage not Implemented");
        }
        #endregion
    }
}
