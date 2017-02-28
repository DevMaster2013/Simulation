using SimulationCore.Core;
using SimulationCore.Systems.SocialSystem.Records;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Systems.SocialSystem
{
    public class FamilyTree
    {
        #region Private Member Variables
        private HumanRecord _humanRecord;
        private uint _maxDepth;
        private MultiTree<HumanRecord> _tree;
        #endregion

        #region Constructors
        public FamilyTree(HumanRecord record)
            : this(record, 2)
        {
        }
        public FamilyTree(HumanRecord record, uint maxDepth)
        {
            _tree = new MultiTree<HumanRecord>();
            HumanRecord = record;
            MaxDepth = maxDepth;
        }
        #endregion

        #region Public Properties
        public HumanRecord HumanRecord {
            get {
                return _humanRecord;
            }

            set {
                _humanRecord = value;
                buildFamilyTree();
            }
        }

        public uint MaxDepth {
            get {
                return _maxDepth;
            }

            set {
                _maxDepth = value;
                buildFamilyTree();
            }
        }
        #endregion

        #region Private Methods
        private void buildFamilyTree()
        {

        }
        #endregion
    }
}
