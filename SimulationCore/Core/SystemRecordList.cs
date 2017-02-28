using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Core
{
    public class SystemRecordList <T> 
        where T : SystemRecord
    {
        #region Private Variables
        protected List<T> _records;
        #endregion

        #region Constructors
        public SystemRecordList()
        {
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
    }
}
