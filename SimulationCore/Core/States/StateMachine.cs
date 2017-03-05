using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Core.States
{
    public class StateMachine<T> where T : class
    {
        #region Protected Data Members
        protected State<T> _currentState;
        protected T _controlledObject;
        protected Dictionary<State<T>, List<StateTransition<T>>> _stateMap;
        #endregion

        #region Constructors
        public StateMachine(T controlled)
        {
            _controlledObject = controlled;
        }
        #endregion

        #region Public Methods
        public void Start()
        {
            buildStateMachine();
            if (_currentState != null)
                _currentState.Enter();
        }
        public void UpdateStateMachine(double elapsedSeconds)
        {
            if (_currentState != null)
                _currentState.Execute(elapsedSeconds);

            checkTransformations();
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

        #region Protected Methods
        protected void checkTransformations()
        {
            if (_stateMap.ContainsKey(_currentState))
            {
                foreach (var trans in _stateMap[_currentState])
                {
                    if (trans.CheckTransition())
                    {
                        var transition = trans as StateTransition<T>;
                        _currentState.Exit();
                        _currentState = transition.To;
                        _currentState.Enter();
                        return;
                    }
                }
            }
        }
        protected virtual void buildStateMachine()
        {
            _stateMap = new Dictionary<State<T>, List<StateTransition<T>>>();
        }
        #endregion
    }
}
