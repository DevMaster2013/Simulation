using SimulationCore.Civilization;
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
        private MultiTreeNode<HumanRecord> _tree;
        private CivilizationManager _civilManager;
        #endregion

        #region Constructors
        public FamilyTree(CivilizationManager civilManager, HumanRecord record)
            : this(civilManager, record, 2)
        {
        }
        public FamilyTree(CivilizationManager civilManager, HumanRecord record, uint maxDepth)
        {
            MaxDepth = maxDepth;
            HumanRecord = record;
            CivilManager = civilManager;
            BuildFamilyTree();
        }
        #endregion

        #region Public Properties
        public HumanRecord HumanRecord
        {
            get
            {
                return _humanRecord;
            }

            set
            {
                _humanRecord = value;
            }
        }

        public uint MaxDepth
        {
            get
            {
                return _maxDepth;
            }

            set
            {
                _maxDepth = value;
            }
        }
        public CivilizationManager CivilManager {
            get
            {
                return _civilManager;
            }

            set
            {
                _civilManager = value;
            }
        }
        #endregion

        #region Public Methods
        public void BuildFamilyTree()
        {
            SocialSystem socialSystem = CivilManager.GetSystem<SocialSystem>();

            _tree = new MultiTreeNode<HumanRecord>(null);

            if (HumanRecord.MarriageRecord != null)
            {
                var grandFathers = socialSystem.HumanRecords.GetGrandFathers(HumanRecord, MaxDepth);
                for (int i = grandFathers.Count - 1; i >= 0; i--)
                {
                    var grandNode = new MultiTreeNode<HumanRecord>(grandFathers[i]);
                    _tree.Cildren.Add(grandNode);

                    var siblings = socialSystem.HumanRecords.GetSiblings(grandFathers[i]);
                    foreach (var sibling in siblings)
                    {
                        var siblingNode = new MultiTreeNode<HumanRecord>(sibling);
                        _tree.Cildren.Add(siblingNode);
                        addHumanChilds(siblingNode, MaxDepth);
                    }

                    addHumanChilds(grandNode, MaxDepth);
                }
            }
            else
            {
                var selfNode = new MultiTreeNode<HumanRecord>(HumanRecord);
                _tree.Cildren.Add(selfNode);
                addHumanChilds(selfNode, MaxDepth);
            }
        }
        public MultiTreeNode<HumanRecord> FindHuman(Human human, out int level)
        {
            level = (int)(-MaxDepth);
            return findNode(_tree, human, ref level);
        }
        #endregion

        #region Private Methods
        private void addHumanChilds(MultiTreeNode<HumanRecord> node, uint depth)
        {
            SocialSystem socialSystem = CivilManager.GetSystem<SocialSystem>();

            if (depth == 0)
                return;

            var children = socialSystem.HumanRecords.GetChildren(node.Data);
            foreach (var child in children)
            {
                var childNode = new MultiTreeNode<HumanRecord>(child);
                node.Cildren.Add(childNode);
                addHumanChilds(childNode, depth - 1);
            }
        }
        private MultiTreeNode<HumanRecord> findNode(MultiTreeNode<HumanRecord> node, Human human, ref int level)
        {
            if (node.Data == null)
                return null;

            if (human == node.Data.Human)
                return node;

            foreach (var childNode in node.Cildren)
            {
                level++;
                var curNode = findNode(childNode, human, ref level);
                if (curNode != null)
                    return curNode;
            }

            return null;
        }
        #endregion
    }
}
