
using SimulationCore.Core;
using SimulationCore.Core.States;
using SimulationCore.Systems.SocialSystem;
using System;
using System.Diagnostics;
using System.Threading;

namespace Simulation_Test
{
    #region Test State Machine
    class ControlledObject
    {
        private StateMachine<ControlledObject> _stateMachine;

        public ControlledObject()
        {
            _stateMachine = new StateMachine<ControlledObject>(this, new IdleState(this));
        }

        public double RandomNumber {
            get {
                return new Random().NextDouble();
            }
        }

        public void Run()
        {
            new Thread( delegate()
            {
                while (true)
                {
                    _stateMachine.UpdateStateMachine(0);
                    Thread.Sleep(500);
                }
            }).Start();
        }

        public void Idle()
        {
            Console.WriteLine("I am Idle");
        }

        public void Walk()
        {
            Console.WriteLine("I am Walking");
        }

        public void Running()
        {
            Console.WriteLine("I am Running");
        }

        public void Looking()
        {
            Console.WriteLine("I am Looking");
        }
    }

    class IdleState : State<ControlledObject>
    {        
        public IdleState(ControlledObject controlledObject) : base(controlledObject)
        {
        }

        public override void Enter()
        {
            base.Enter();
            Console.WriteLine("Entering Idle State");
        }

        public override void Execute(double elapsedSeconds)
        {
            Controlled.Idle();
            base.Execute(elapsedSeconds);
        }

        public override void Exit()
        {            
            Console.WriteLine("Exiting Idle State");
            base.Exit();
        }

        protected override void checkTranstions()
        {
            if (Controlled.RandomNumber > 0.5)
                transTo(new WakilngState(Controlled));
        }
    }

    class WakilngState : State<ControlledObject>
    {
        public WakilngState(ControlledObject controlledObject) : base(controlledObject)
        {
        }

        public override void Enter()
        {
            base.Enter();
            Console.WriteLine("Entering Wakilng State");
        }

        public override void Execute(double elapsedSeconds)
        {
            Controlled.Walk();
            base.Execute(elapsedSeconds);
        }

        public override void Exit()
        {
            Console.WriteLine("Exiting Wakilng State");
            base.Exit();
        }

        protected override void checkTranstions()
        {
            if (Controlled.RandomNumber > 0.5)
                transTo(new RunningState(Controlled));
            else if (Controlled.RandomNumber < 0.1)
                transTo(new IdleState(Controlled));
        }
    }

    class RunningState : State<ControlledObject>
    {
        public RunningState(ControlledObject controlledObject) : base(controlledObject)
        {
        }

        public override void Enter()
        {
            base.Enter();
            Console.WriteLine("Entering Running State");
        }

        public override void Execute(double elapsedSeconds)
        {
            Controlled.Running();
            base.Execute(elapsedSeconds);            
        }

        public override void Exit()
        {
            Console.WriteLine("Exiting Running State");
            base.Exit();
        }

        protected override void checkTranstions()
        {
            if (Controlled.RandomNumber > 0.5)
                transTo(new LookingState(Controlled));
            else if (Controlled.RandomNumber < 0.1)
                transTo(new IdleState(Controlled));
            else if (Controlled.RandomNumber < 0.3)
                transTo(new RunningState(Controlled));
        }
    }

    class LookingState : State<ControlledObject>
    {
        public LookingState(ControlledObject controlledObject) : base(controlledObject)
        {
        }

        public override void Enter()
        {
            base.Enter();
            Console.WriteLine("Entering Looking State");
        }

        public override void Execute(double elapsedSeconds)
        {
            Controlled.Looking();
            base.Execute(elapsedSeconds);
        }

        public override void Exit()
        {
            Console.WriteLine("Exiting Looking State");
            base.Exit();
        }

        protected override void checkTranstions()
        {
            if (Controlled.RandomNumber > 0.5)
                transTo(new IdleState(Controlled));
            else if (Controlled.RandomNumber < 0.1)
                transTo(new WakilngState(Controlled));
            else if (Controlled.RandomNumber < 0.3)
                transTo(new RunningState(Controlled));
        }
    }
    #endregion

    class Program
    {
        static void Main(string[] args)
        {
            ControlledObject obj = new ControlledObject();
            obj.Run();
        }

        static void RunGame()
        {
            GameManager.StartManager();
            Stopwatch clock = new Stopwatch();
            clock.Start();
            while (true)
            {
                var elapsed = clock.Elapsed.TotalSeconds;
                clock.Reset(); clock.Start();

                var before = clock.Elapsed.TotalSeconds;
                GameManager.UpdateGame(elapsed);

                var after = clock.Elapsed.TotalSeconds;
                Thread.Sleep((int)(100 - ((after - before) * 1000)));
            }
        }
    }
}

