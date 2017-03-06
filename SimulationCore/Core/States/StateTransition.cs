using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Core.States
{
    public abstract class StateTransition<T> where T : class
    {
        #region Protected Members
        protected T _controlledObject;
        protected string _name;
        #endregion

        #region Public Properties
        public string Name { get { return _name; } set { _name = value; } }
        public T Controlled { get { return _controlledObject; } set { _controlledObject = value; } }
        #endregion

        #region Constructors
        public StateTransition(string name, T obj)
        {
            Name = name;
            Controlled = obj;
        }
        #endregion

        #region Public Methods
        public abstract bool CheckTransition();
        #endregion
    }
}
