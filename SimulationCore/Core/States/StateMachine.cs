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
            if (CurrentState != null)
                CurrentState.Execute(elapsedSeconds);
        }
        #endregion

        #region Public Properties
        public T Controlled
        {
            get
            {
                return _controlledObject;
            }
            set
            {
                _controlledObject = value;
            }
        }
        public State<T> CurrentState
        {
            get
            {
                return _currentState;
            }

            set
            {
                _currentState = value;
            }
        }
        #endregion

        #region Private Methods
        private void switchStates(State<T> to)
        {
            if (CurrentState != null)
            {
                CurrentState.OnStateTransition -= _currentState_OnStateTransition;
                CurrentState.Exit();
            }

            if (to != null)
            {
                to.Enter();
                to.OnStateTransition += _currentState_OnStateTransition;
            }

            CurrentState = to;
        }
        #endregion

        #region Event Handlers
        private void _currentState_OnStateTransition(State<T> from, State<T> to)
        {
            if (from == CurrentState)
                switchStates(to);
        }
        #endregion
    }
}
