using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace Simulation_Test
{
    #region Messaging Framework
    public class Notification
    {
        private double _delayTime;

        public Notification()
        {
            DelayTime = 0;
        }

        public double DelayTime {
            get {
                return _delayTime;
            }

            set {
                _delayTime = value;
            }
        }
    }

    public interface INotifyReciever
    {
        void HandleNotification(Notification notif);
    }

    public static class NotifyManager
    {
        private static Queue<Notification> _notifications = new Queue<Notification>();
        private static List<INotifyReciever> _notifyRecievers = new List<INotifyReciever>();

        public static void Update(double elapsedSeconds)
        {
            while (_notifications.Count > 0)
            {
                var notif = _notifications.Dequeue();
                notif.DelayTime -= elapsedSeconds;
                if (notif.DelayTime < 0)
                {
                    foreach (var rec in _notifyRecievers)
                        rec.HandleNotification(notif);
                }
            }
        }
        public static void AddNotifyReciever(INotifyReciever rec)
        {
            _notifyRecievers.Add(rec);
        }
        public static void Notify(Notification notif)
        {
            _notifications.Enqueue(notif);
        }
    }    
    #endregion

    #region State Framework
    public abstract class StateTransition<T>
    {
        protected T _object;
        protected string _name;
        public StateTransition(string name, T obj)
        {
            _name = name;
            _object = obj;
        }
        public abstract bool CheckTransition();        
        public string Name { get { return _name; } set { _name = value; } }
        public T Object { get { return _object; } set { _object = value; } }
    }    

    public class State<T> : INotifyReciever
    {
        protected T _object;
        protected string _name;
        protected StateMachine<T> _ownerStateMachine;
        public State(string name, T obj)
        {
            _name = name;
            _object = obj;
        }

        public virtual void Enter()
        {
        }
        public virtual void Execute(double elapsedSeconds)
        {
        }
        public virtual void Exit()
        {
        }

        public virtual void HandleNotification(Notification notif)
        {
            
        }

        public string Name { get { return _name; } set { _name = value; } }
        public T Object { get { return _object; } set { _object = value; } }
        public StateMachine<T> OwnerStateMachine { get { return _ownerStateMachine; } set { _ownerStateMachine = value; } }
    }

    public class StateMachine<T> : INotifyReciever
    {
        #region Protected Data Members
        protected T _object;
        protected string _name;
        protected State<T> _currentState;
        protected Dictionary<string, State<T>> _states;
        protected Dictionary<string, List<KeyValuePair<State<T>, StateTransition<T>>>> _stateTransitions;
        #endregion
        #region Constructors
        public StateMachine(string name, T obj)
        {
            _name = name;
            _object = obj;
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
        public void HandleNotification(Notification notif)
        {
            foreach(var state in _states)
            {
                state.Value.HandleNotification(notif);
            }
        }
        #endregion
        #region Public Properties
        public string Name { get { return _name; } set { _name = value; } }
        public T Object { get { return _object; } set { _object = value; } }
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
    #endregion

    #region Test Classes 
    public class AttackNotification : Notification
    {
        public StateObject Target;
        public StateObject Enemy;

        public AttackNotification(StateObject Target, StateObject Enemy)
        {
            this.Target = Target;
            this.Enemy = Enemy;
        }
    }
    public class AttackFinished : Notification
    {
        public StateObject Enemy;
        public AttackFinished(StateObject Enemy)
        {
            this.Enemy = Enemy;
        }
    }
    public class StateObject : INotifyReciever
    {
        private StateMachine<StateObject> _myStateMachine;
        public double LifeTime = 0;
        public StateObject AnotherObject;
        private string _name;

        public string Name {
            get {
                return _name;
            }

            set {
                _name = value;
            }
        }

        public StateObject(string name)
        {
            Name = name;
            _myStateMachine = new StateMachine<StateObject>("StateObject SM", this);

            _myStateMachine.AddState(new IdleState(this));
            _myStateMachine.AddState(new WalkState(this));
            _myStateMachine.AddState(new RunState(this));
            _myStateMachine.AddState(new AttakState(this));

            _myStateMachine.AddStateTransition("Idle", "Walk", new IdleWalkTransition(this));
            _myStateMachine.AddStateTransition("Walk", "Idle", new WalkIdleTransition(this));
            _myStateMachine.AddStateTransition("Walk", "Attak", new WalkAttackTransition(this));
            _myStateMachine.AddStateTransition("Run", "Idle", new RunIdleTransition(this));

            _myStateMachine.ChangeState("Idle");
        }
        public void HandleNotification(Notification notif)
        {
            _myStateMachine.HandleNotification(notif);    
        }
        public void Update(double elapsedSeconds)
        {
            LifeTime += elapsedSeconds;
            _myStateMachine.UpdateStateMachine(elapsedSeconds);
        }
    }
    public class IdleState : State<StateObject>
    {
        public IdleState(StateObject obj) : base("Idle", obj)
        {
        }
        public override void Enter()
        {
            Console.WriteLine("{0} : Enter Idle State", Object.Name);
            base.Enter();
        }
        public override void Execute(double elapsedSeconds)
        {
            Console.WriteLine("{0} : In Idle State", Object.Name);
            base.Execute(elapsedSeconds);
        }
        public override void Exit()
        {
            Console.WriteLine("{0} : Exit Idle State", Object.Name);
            base.Exit();
        }
    }
    public class WalkState : State<StateObject>
    {
        public WalkState(StateObject obj) : base("Walk", obj)
        {
        }

        public override void HandleNotification(Notification notif)
        {
            base.HandleNotification(notif);

            if (notif is AttackNotification)
            {
                AttackNotification n = notif as AttackNotification;
                if (n.Target == Object)
                {
                    OwnerStateMachine.ChangeState("Run");
                }
            }
        }

        public override void Enter()
        {
            Console.WriteLine("{0} : Enter Walk State", Object.Name);
            base.Enter();
        }
        public override void Execute(double elapsedSeconds)
        {
            Console.WriteLine("{0} : In Walk State", Object.Name);
            base.Execute(elapsedSeconds);
        }
        public override void Exit()
        {
            Console.WriteLine("{0} : Exit Walk State", Object.Name);
            base.Exit();
        }
    }
    public class RunState : State<StateObject>
    {
        public RunState(StateObject obj) : base("Run", obj)
        {
        }

        public override void Enter()
        {
            Console.WriteLine("{0} : Enter Run State", Object.Name);
            base.Enter();
        }
        public override void Execute(double elapsedSeconds)
        {
            Console.WriteLine("{0} : In Run State", Object.Name);
            base.Execute(elapsedSeconds);
        }
        public override void Exit()
        {
            Console.WriteLine("{0} : Exit Run State", Object.Name);
            base.Exit();
        }
    }
    public class AttakState : State<StateObject>
    {
        public AttakState(StateObject obj) : base("Attak", obj)
        {
        }
        public override void Execute(double elapsedSeconds)
        {
            Console.WriteLine("{0} Attacking {1}", Object.Name, Object.AnotherObject.Name);
            NotifyManager.Notify(new AttackNotification(Object.AnotherObject, Object));
            Object.LifeTime = 0;
        }

        public override void HandleNotification(Notification notif)
        {
            base.HandleNotification(notif);

            if (notif is AttackNotification)
            {
                AttackNotification n = notif as AttackNotification;
                if (n.Enemy == Object)
                {
                    OwnerStateMachine.ChangeState("Walk");
                    Object.LifeTime = 0;
                }
            }
        }

        public override void Enter()
        {
            Console.WriteLine("{0} : Enter Attack State", Object.Name);
            base.Enter();
        }
        public override void Exit()
        {
            Console.WriteLine("{0} : Exit Attack State", Object.Name);
            base.Exit();
        }
    }

    #region Transisions
    public class IdleWalkTransition : StateTransition<StateObject>
    {
        public IdleWalkTransition(StateObject obj) : base("IdleWalk", obj)
        {
        }        
        public override bool CheckTransition()
        {
            return Object.LifeTime > 5;
        }
    }
    public class WalkIdleTransition : StateTransition<StateObject>
    {
        public WalkIdleTransition(StateObject obj) : base("WalkIdle", obj)
        {
        }        
        public override bool CheckTransition()
        {
            return false;
        }
    }
    public class WalkAttackTransition : StateTransition<StateObject>
    {
        double attackTime;

        public WalkAttackTransition(StateObject obj) : base("WalkAttack", obj)
        {
            attackTime = (new Random().Next() % 5) + 5;
        }
        public override bool CheckTransition()
        {
            return Object.LifeTime > attackTime && Object.Name == "Object1";
        }
    }
    public class RunIdleTransition : StateTransition<StateObject>
    {
        public RunIdleTransition(StateObject obj) : base("RunIdle", obj)
        {            
        }
        public override bool CheckTransition()
        {
            if (Object.LifeTime > 20)
            {
                Object.LifeTime = 0;
                return true;
            }
            return false;
        }
    }
    #endregion
    #endregion

    public class TestingStateMachine
    {
        public static void Test()
        {
            StateObject stateObject1 = new StateObject("Object1");
            StateObject stateObject2 = new StateObject("Object2");

            stateObject1.AnotherObject = stateObject2;
            stateObject2.AnotherObject = stateObject1;

            NotifyManager.AddNotifyReciever(stateObject1);
            NotifyManager.AddNotifyReciever(stateObject2);

            while (true)
            {
                stateObject1.Update(1);
                stateObject2.Update(1);

                NotifyManager.Update(1);
                Thread.Sleep(1000);
            }
        }
    }
}
