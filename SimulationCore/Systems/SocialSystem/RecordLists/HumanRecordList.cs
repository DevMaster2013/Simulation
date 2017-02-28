using SimulationCore.Core;
using SimulationCore.Systems.SocialSystem.Records;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Systems.SocialSystem.RecordLists
{
    public class HumanRecordList : SystemRecordList<HumanRecord>
    {
        #region Constructors
        public HumanRecordList()
            : base()
        {
        }
        #endregion

        #region Public Methods
        public HumanRecord GetRecord(Human human)
        {
            return _records.Find(x => x.Human == human);
        }
        public List<HumanRecord> GetUnmarriedMenRecords()
        {
            return _records.FindAll(x => x.Human.Sex == HumanSex.Male);
        }
        public List<HumanRecord> GetUnmarriedWomenRecords()
        {
            return _records.FindAll(x => x.Human.Sex == HumanSex.Female);            
        }
        #endregion
    }
}
