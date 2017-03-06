using SimulationCore.Civilization;
using SimulationCore.Core;
using SimulationCore.Systems.SocialSystem.RecordLists;
using SimulationCore.Systems.SocialSystem.Records;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Systems.SocialSystem
{
    public class SocialSystem : CivilizationSystem
    {
        #region Private Variables
        private MarriageRecordList _marriageRecords;
        private DivorceRecordList _divorceRecords;
        private HumanRecordList _humanRecords;
        private DieRecordList _dieRecords;

        private SocialSystemConfig _config;
        #endregion

        #region Constructors
        public SocialSystem(CivilizationManager civilManager)
            : base(civilManager)
        {
            MarriageRecords = new MarriageRecordList(civilManager);
            DivorceRecords = new DivorceRecordList(civilManager);
            HumanRecords = new HumanRecordList(civilManager);
            DieRecords = new DieRecordList(civilManager);
            _config = new SocialSystemConfig();
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

        public SocialSystemConfig Config {
            get {
                return _config;
            }

            set {
                _config = value;
            }
        }
        #endregion

        #region Public Overrided Methods
        public override bool InitializeSystem()
        {
            HumanSex sex = RandomSelector.GetRandomEnumValue<HumanSex>();
            var family1Husband = HumanRecords.CreateRecord(null, RandomSelector.GetRandomName(HumanSex.Male), HumanSex.Male);
            var family1Wife = HumanRecords.CreateRecord(null, RandomSelector.GetRandomName(HumanSex.Female), HumanSex.Female);

            var family2Husband = HumanRecords.CreateRecord(null, RandomSelector.GetRandomName(HumanSex.Male), HumanSex.Male);
            var family2Wife = HumanRecords.CreateRecord(null, RandomSelector.GetRandomName(HumanSex.Female), HumanSex.Female);

            MarriageRecords.CreateRecord(family1Husband.Human as Man, family1Wife.Human as Woman);
            MarriageRecords.CreateRecord(family2Husband.Human as Man, family2Wife.Human as Woman);

            return base.InitializeSystem();
        }
        public override bool FininalizeSystem()
        {
            MarriageRecords.RemoveObseleteRecords();
            DivorceRecords.RemoveObseleteRecords();
            HumanRecords.RemoveObseleteRecords();
            DieRecords.RemoveObseleteRecords();

            return base.FininalizeSystem();
        }
        public override void UpdateSystem(double elapsedSeconds)
        {           
            base.UpdateSystem(elapsedSeconds);

            updateHumanRecords(elapsedSeconds);
        }
        #endregion

        #region Public Methods
        public List<Woman> GetSuitableWomenForMarriage(Man man)
        {
            List<Woman> suitableWomen = new List<Woman>();

            var unMarriedWomen = HumanRecords.GetUnmarriedWomenRecords();
            var manRecord = HumanRecords.GetRecord(man);
            var manFamilyTree = new FamilyTree(CivilManager, manRecord);
            foreach (var woman in unMarriedWomen)
            {
                int level;
                var foundNode = manFamilyTree.FindHuman(woman.Human, out level);
                if (foundNode != null && level == 1)
                    suitableWomen.Add((Woman)foundNode.Data.Human);
                else if (foundNode == null)
                    suitableWomen.Add((Woman)woman.Human);
            }

            return suitableWomen;
        }
        #endregion

        #region Private Methods
        private void updateHumanRecords(double elapsedSeconds)
        {
            var validRecords = HumanRecords.GetValidRecords();
            foreach (var record in validRecords)
                record.Human.Update(elapsedSeconds);
        }
        #endregion
    }
}
