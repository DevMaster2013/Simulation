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
        #region Private Members
        private SocialSystem _socialSystem;
        #endregion

        #region Constructors
        public HumanRecordList(SocialSystem socialSystem)
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
        public HumanRecord CreateRecord(MarriageRecord marriageRecord, string name, HumanSex sex)
        {
            Human human;
            if (sex == HumanSex.Male)
                human = new Man(SocialSystem, name);
            else
                human = new Woman(SocialSystem, name);

            HumanRecord record = new HumanRecord(human, marriageRecord);
            AddRecord(record);
            return record;
        }
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
        public List<HumanRecord> GetGrandFathers(HumanRecord human, uint level)
        {
            List<HumanRecord> grandFathers = new List<HumanRecord>();

            uint currentDepth = level;
            HumanRecord currentRecord = human;
            while (currentDepth > 0 && currentRecord.MarriageRecord != null)
            {
                currentRecord = currentRecord.MarriageRecord.HusbandRecord;
                grandFathers.Add(currentRecord);
                currentDepth--;
            }

            return grandFathers;
        }
        public List<HumanRecord> GetSiblings(HumanRecord human)
        {
            return _records.FindAll(x => human.MarriageRecord == x.MarriageRecord);
        }
        public List<HumanRecord> GetChildren(HumanRecord human)
        {
            return _records.FindAll(x => (x.MarriageRecord.HusbandRecord == human || x.MarriageRecord.WifeRecord == human));
        }
        #endregion
    }
}
