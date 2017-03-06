using SimulationCore.Civilization;
using SimulationCore.Systems.SocialSystem.Records;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Systems.SocialSystem.RecordLists
{
    public class SystemRecordList <T> 
        where T : SystemRecord
    {
        #region Private Variables
        protected List<T> _records;
        protected CivilizationManager _civilManager;        
        #endregion

        #region Constructors
        public SystemRecordList(CivilizationManager civilManager)
        {
            CivilManager = civilManager;
            _records = new List<T>();
        }
        #endregion

        #region Public Methods
        public virtual void AddRecord(T record)
        {
            if (record.RecordState == RecordState.Inavlid)
                throw new ArgumentException("Cannot add an invalid Record");

            _records.Add(record);
        }
        public void RemoveObseleteRecords()
        {
            _records.RemoveAll(x => x.RecordState == RecordState.Obselete);
        }
        public List<T> GetValidRecords()
        {
            return _records.FindAll(x => x.RecordState == RecordState.Valid);
        }
        #endregion

        #region Public Properties
        public CivilizationManager CivilManager {
            get {
                return _civilManager;
            }

            set {
                _civilManager = value;
            }
        }
        #endregion
    }
}
