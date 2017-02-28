using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Core
{
    public class MultiTreeNode<T>
    {
        #region Private Members
        private T _data;
        private List<MultiTreeNode<T>> _cildren;
        #endregion

        #region Constructors
        public MultiTreeNode(T data)
        {
            Data = data;
            _cildren = new List<MultiTreeNode<T>>();

        }
        #endregion

        #region Public Properties
        public T Data
        {
            get
            {
                return _data;
            }

            set
            {
                _data = value;
            }
        }

        public List<MultiTreeNode<T>> Cildren
        {
            get
            {
                return _cildren;
            }

            protected set
            {
                _cildren = value;
            }
        }
        #endregion
    }
}
