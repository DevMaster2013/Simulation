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
        protected string _name;
        protected StateMachine<T> _ownerStateMachine;
        #endregion

        #region Constructors
        public State(StateMachine<T> owner, string name, T obj)
        {
            Name = name;
            Controlled = obj;
            OwnerStateMachine = owner;
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
        public string Name { get { return _name; } set { _name = value; } }
        public StateMachine<T> OwnerStateMachine { get { return _ownerStateMachine; } set { _ownerStateMachine = value; } }
        #endregion
    }
}
