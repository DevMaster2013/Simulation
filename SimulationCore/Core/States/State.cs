using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Core.States
{
    #region Public Delegates
    public delegate void OnStateTransitionHandler<T>(State<T> from, State<T> to) where T : class;
    #endregion

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

        #region Public Events
        public event OnStateTransitionHandler<T> OnStateTransition;
        #endregion

        #region Public Methods
        public virtual void Enter()
        {
        }
        public virtual void Execute(double elapsedSeconds)
        {
            checkTranstions();
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

        #region Protected Overrided Methods
        protected abstract void checkTranstions();
        protected void transTo(State<T> anotherState)
        {
            if (OnStateTransition != null)
                OnStateTransition(this, anotherState);
        }
        #endregion
    }
}
