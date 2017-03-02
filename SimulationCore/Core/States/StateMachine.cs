using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Core.States
{
    public class StateMachine<T> where T : class
    {
        #region Private Data Members
        private State<T> _currentState;
        private T _controlledObject;
        #endregion

        #region Constructors
        public StateMachine(T controlled, State<T> initialState)
        {
            _controlledObject = controlled;
            switchStates(initialState);
        }
        #endregion

        #region Public Methods
        public void UpdateStateMachine(double elapsedSeconds)
        {
            if (_currentState != null)
                _currentState.Execute(elapsedSeconds);
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

            #region Private Methods
        private void switchStates(State<T> to)
        {
            if (_currentState != null)
            {
                _currentState.OnStateTransition -= _currentState_OnStateTransition;
                _currentState.Exit();
            }

            if (to != null)
            {
                to.Enter();
                to.OnStateTransition += _currentState_OnStateTransition;
            }

            _currentState = to;
        }
        #endregion

        #region Event Handlers
        private void _currentState_OnStateTransition(State<T> from, State<T> to)
        {
            if (from == _currentState)
                switchStates(to);
        }
        #endregion
    }
}
