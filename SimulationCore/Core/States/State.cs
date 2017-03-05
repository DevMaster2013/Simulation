using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Core.States
{
    public abstract class State<T> where T : class
    {
        #region Private Members
        private T _controlledObject;
        #endregion

        #region Constructors
        public State(T controlledObject)
        {
            Controlled = controlledObject;
        }
        #endregion

        #region Public Methods
        public virtual void Enter()
        {
        }
        public virtual void Execute(double elapsedSeconds)
        {
        }
        public virtual void Exit()
        {
        }
        #endregion

        #region Public Properties
        public T Controlled {
            get {
                return _controlledObject;
            }
            set {
                _controlledObject = value;
            }
        }
        #endregion
    }
}
