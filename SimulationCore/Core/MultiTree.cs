using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Core
{
    public class MultiTree<T>
    {
        #region Private Variables
        private MultiTreeNode<T> _root;
        #endregion

        #region Constructors
        public MultiTree()
        {
            _root = null;
        }
        #endregion

        #region Public Properties
        public MultiTreeNode<T> RootNode
        {
            get
            {
                return _root;
            }
            protected set
            {
                _root = value;
            }
        }
        #endregion

        #region Public Methods
        public MultiTreeNode<T> Add(T parent, T data)
        {

        }
        public MultiTreeNode<T> Find(T data)
        {

        }
        #endregion

        #region Private Methods
        #endregion
    }
}
