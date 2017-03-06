using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Core.States
{
    public class StateMachine<T> where T : class
    {
        #region Protected Data Members
        protected T _controlledObject;
        protected string _name;
        protected State<T> _currentState;
        protected Dictionary<string, State<T>> _states;
        protected Dictionary<string, List<KeyValuePair<State<T>, StateTransition<T>>>> _stateTransitions;
        #endregion

        #region Constructors
        public StateMachine(string name, T obj)
        {
            _name = name;
            _controlledObject = obj;
            _currentState = null;
            _states = new Dictionary<string, State<T>>();
            _stateTransitions = new Dictionary<string, List<KeyValuePair<State<T>, StateTransition<T>>>>();
        }
        #endregion

        #region Public Methods
        public void AddState(State<T> state)
        {
            if (GetState(state.Name) == null)
            {
                state.OwnerStateMachine = this;
                _states.Add(state.Name, state);
                _stateTransitions.Add(state.Name, new List<KeyValuePair<State<T>, StateTransition<T>>>());
            }
        }
        public void AddStateTransition(State<T> fromState, State<T> toState, StateTransition<T> guard)
        {
            AddStateTransition(fromState.Name, toState.Name, guard);
        }
        public void AddStateTransition(string fromState, string toState, StateTransition<T> guard)
        {
            var existingTransition = GetStateTransition(fromState, toState);
            if (existingTransition == null)
            {
                _stateTransitions[fromState].Add(new KeyValuePair<State<T>, StateTransition<T>>(GetState(toState), guard));
            }
        }
        public State<T> GetState(string stateName)
        {
            if (_states.ContainsKey(stateName))
                return _states[stateName];
            return null;
        }
        public List<KeyValuePair<State<T>, StateTransition<T>>> GetStateTransitons(State<T> fromState)
        {
            return GetStateTransitons(fromState.Name);
        }
        public List<KeyValuePair<State<T>, StateTransition<T>>> GetStateTransitons(string fromState)
        {
            if (_stateTransitions.ContainsKey(fromState))
                return _stateTransitions[fromState];
            return null;
        }
        public StateTransition<T> GetStateTransition(string fromState, string toState)
        {
            var stateTransitions = GetStateTransitons(fromState);
            var found = stateTransitions.FindIndex(x => x.Key.Name == toState);
            if (found >= 0)
                return stateTransitions[found].Value;
            return null;
        }
        public StateTransition<T> GetStateTransition(State<T> fromState, State<T> toState)
        {
            return GetStateTransition(fromState.Name, toState.Name);
        }
        public void UpdateStateMachine(double elapsedSeconds)
        {
            if (_currentState != null)
                _currentState.Execute(elapsedSeconds);

            checkTransitions();
        }
        public void ChangeState(string stateName)
        {
            if (GetState(stateName) == null)
                return;

            if (_currentState != null)
                _currentState.Exit();
            _currentState = GetState(stateName);
            _currentState.Enter();
        }
        public void ChangeState(State<T> newState)
        {
            ChangeState(newState.Name);
        }
        #endregion

        #region Public Properties
        public string Name { get { return _name; } set { _name = value; } }
        public T Controlled { get { return _controlledObject; } set { _controlledObject = value; } }
        public State<T> CurrentState {
            get {
                return _currentState;
            }
            set {
                ChangeState(value);
            }
        }
        #endregion

        #region Protected Methods
        protected void checkTransitions()
        {
            var stateTransitions = GetStateTransitons(_currentState);
            foreach (var sTrans in stateTransitions)
            {
                if (sTrans.Value.CheckTransition())
                {
                    CurrentState = sTrans.Key;
                    return;
                }
            }
        }
        #endregion
    }
}
