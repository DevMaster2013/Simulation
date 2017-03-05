
using SimulationCore.Core;
using SimulationCore.Core.States;
using SimulationCore.Systems.SocialSystem;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Threading;

namespace Simulation_Test
{
    //#region Testing New State Machine

    //#region State Machine
    //public class FileStreamStateMachine : StateMachine<String>
    //{
    //    public FileStreamStateMachine(String obj) : base(obj)
    //    {
    //    }

    //    public Dictionary<State<String>, List<StateTransition<String>>> StatesMap
    //    {
    //        get
    //        {
    //            return _stateMap;
    //        }
    //    }

    //    protected override void buildStateMachine()
    //    {
    //        base.buildStateMachine();

    //        var idleState = new MyIdleState(_controlledObject);
    //        var walkState = new MyWalkState(_controlledObject);
    //        var runState = new MyRunState(_controlledObject);
    //        var lookState = new MyLookState(_controlledObject);

    //        _stateMap[idleState] = new List<StateTransition<String>>();
    //        _stateMap[walkState] = new List<StateTransition<String>>();
    //        _stateMap[runState] = new List<StateTransition<String>>();
    //        _stateMap[lookState] = new List<StateTransition<String>>();

    //        _stateMap[idleState].Add(new Idle2LookTransition(idleState, lookState));
    //        _stateMap[idleState].Add(new Idle2RunTransition(idleState, runState));
    //        _stateMap[idleState].Add(new Idle2WalkTransition(idleState, walkState));

    //        _stateMap[walkState].Add(new Walk2LookTransition(walkState, lookState));
    //        _stateMap[walkState].Add(new Walk2RunTransition(walkState, runState));
    //        _stateMap[walkState].Add(new Walk2IdleTransition(walkState, idleState));

    //        _stateMap[runState].Add(new Run2LookTransition(runState, lookState));
    //        _stateMap[runState].Add(new Run2WalkTransition(runState, walkState));
    //        _stateMap[runState].Add(new Run2IdleTransition(runState, idleState));

    //        _stateMap[lookState].Add(new Look2RunTransition(lookState, runState));
    //        _stateMap[lookState].Add(new Look2WalkTransition(lookState, walkState));
    //        _stateMap[lookState].Add(new Look2IdleTransition(lookState, idleState));

    //        _currentState = idleState;
    //    }
    //}

    //#endregion

    //#region States
    //public class MyIdleState : State<String>
    //{
    //    public MyIdleState(String obj) : base(obj)
    //    {
    //    }

    //    public override void Enter()
    //    {
    //        Console.WriteLine("Enter Idle State");
    //        base.Enter();
    //    }

    //    public override void Execute(double elapsedSeconds)
    //    {
    //        Console.Write("I am in Idle State");
    //        base.Execute(elapsedSeconds);
    //    }

    //    public override void Exit()
    //    {
    //        Console.WriteLine("Exit Idle State");
    //        base.Exit();
    //    }
    //}

    //public class MyWalkState : State<String>
    //{
    //    public MyWalkState(String obj) : base(obj)
    //    {
    //    }

    //    public override void Enter()
    //    {
    //        Console.WriteLine("Enter Walk State");
    //        base.Enter();
    //    }

    //    public override void Execute(double elapsedSeconds)
    //    {
    //        Console.Write("I am in Walk State");
    //        base.Execute(elapsedSeconds);
    //    }

    //    public override void Exit()
    //    {
    //        Console.WriteLine("Exit Walk State");
    //        base.Exit();
    //    }
    //}

    //public class MyRunState : State<String>
    //{
    //    public MyRunState(String obj) : base(obj)
    //    {
    //    }

    //    public override void Enter()
    //    {
    //        Console.WriteLine("Enter Run State");
    //        base.Enter();
    //    }

    //    public override void Execute(double elapsedSeconds)
    //    {
    //        Console.Write("I am in Run State");
    //        base.Execute(elapsedSeconds);
    //    }

    //    public override void Exit()
    //    {
    //        Console.WriteLine("Exit Run State");
    //        base.Exit();
    //    }
    //}

    //public class MyLookState : State<String>
    //{
    //    public MyLookState(String obj) : base(obj)
    //    {
    //    }

    //    public override void Enter()
    //    {
    //        Console.WriteLine("Enter Look State");
    //        base.Enter();
    //    }

    //    public override void Execute(double elapsedSeconds)
    //    {
    //        Console.Write("I am in Look State");
    //        base.Execute(elapsedSeconds);
    //    }

    //    public override void Exit()
    //    {
    //        Console.WriteLine("Exit Look State");
    //        base.Exit();
    //    }
    //}

    //#endregion

    //#region State Transitions
    //public class Idle2WalkTransition : StateTransition<String>
    //{
    //    public Idle2WalkTransition(State<string> from, State<string> to) : base(from, to)
    //    {
    //    }
    //    public override bool CheckTransition()
    //    {
    //        Random rand = new Random();
    //        return rand.NextDouble() > 0.9;
    //    }
    //}

    //public class Idle2RunTransition : StateTransition<String>
    //{
    //    public Idle2RunTransition(State<string> from, State<string> to) : base(from, to)
    //    {
    //    }
    //    public override bool CheckTransition()
    //    {
    //        Random rand = new Random();
    //        return rand.NextDouble() > 0.95;
    //    }
    //}

    //public class Idle2LookTransition : StateTransition<String>
    //{
    //    public Idle2LookTransition(State<string> from, State<string> to) : base(from, to)
    //    {
    //    }
    //    public override bool CheckTransition()
    //    {
    //        Random rand = new Random();
    //        return rand.NextDouble() > 0.98;
    //    }
    //}

    //public class Walk2IdleTransition : StateTransition<String>
    //{
    //    public Walk2IdleTransition(State<string> from, State<string> to) : base(from, to)
    //    {
    //    }
    //    public override bool CheckTransition()
    //    {
    //        Random rand = new Random();
    //        return rand.NextDouble() > 0.9;
    //    }
    //}

    //public class Walk2RunTransition : StateTransition<String>
    //{
    //    public Walk2RunTransition(State<string> from, State<string> to) : base(from, to)
    //    {
    //    }
    //    public override bool CheckTransition()
    //    {
    //        Random rand = new Random();
    //        return rand.NextDouble() > 0.95;
    //    }
    //}

    //public class Walk2LookTransition : StateTransition<String>
    //{
    //    public Walk2LookTransition(State<string> from, State<string> to) : base(from, to)
    //    {
    //    }
    //    public override bool CheckTransition()
    //    {
    //        Random rand = new Random();
    //        return rand.NextDouble() > 0.98;
    //    }
    //}

    //public class Run2IdleTransition : StateTransition<String>
    //{
    //    public Run2IdleTransition(State<string> from, State<string> to) : base(from, to)
    //    {
    //    }
    //    public override bool CheckTransition()
    //    {
    //        Random rand = new Random();
    //        return rand.NextDouble() > 0.9;
    //    }
    //}

    //public class Run2WalkTransition : StateTransition<String>
    //{
    //    public Run2WalkTransition(State<string> from, State<string> to) : base(from, to)
    //    {
    //    }
    //    public override bool CheckTransition()
    //    {
    //        Random rand = new Random();
    //        return rand.NextDouble() > 0.95;
    //    }
    //}

    //public class Run2LookTransition : StateTransition<String>
    //{
    //    public Run2LookTransition(State<string> from, State<string> to) : base(from, to)
    //    {
    //    }
    //    public override bool CheckTransition()
    //    {
    //        Random rand = new Random();
    //        return rand.NextDouble() > 0.98;
    //    }
    //}

    //public class Look2IdleTransition : StateTransition<String>
    //{
    //    public Look2IdleTransition(State<string> from, State<string> to) : base(from, to)
    //    {
    //    }
    //    public override bool CheckTransition()
    //    {
    //        Random rand = new Random();
    //        return rand.NextDouble() > 0.9;
    //    }
    //}

    //public class Look2WalkTransition : StateTransition<String>
    //{
    //    public Look2WalkTransition(State<string> from, State<string> to) : base(from, to)
    //    {
    //    }
    //    public override bool CheckTransition()
    //    {
    //        Random rand = new Random();
    //        return rand.NextDouble() > 0.95;
    //    }
    //}

    //public class Look2RunTransition : StateTransition<String>
    //{
    //    public Look2RunTransition(State<string> from, State<string> to) : base(from, to)
    //    {
    //    }
    //    public override bool CheckTransition()
    //    {
    //        Random rand = new Random();
    //        return rand.NextDouble() > 0.98;
    //    }
    //}
    //#endregion

    //#endregion

    //#region Test State Machine
    //class ControlledObject
    //{
    //    private StateMachine<ControlledObject> _stateMachine;

    //    public ControlledObject()
    //    {
    //        _stateMachine = new StateMachine<ControlledObject>(this, new IdleState(this));
    //    }

    //    public double RandomNumber
    //    {
    //        get
    //        {
    //            return new Random().NextDouble();
    //        }
    //    }

    //    public void Run()
    //    {
    //        new Thread(delegate ()
    //       {
    //           while (true)
    //           {
    //               _stateMachine.UpdateStateMachine(0);
    //               Thread.Sleep(500);
    //           }
    //       }).Start();
    //    }

    //    public void Idle()
    //    {
    //        Console.WriteLine("I am Idle");
    //    }

    //    public void Walk()
    //    {
    //        Console.WriteLine("I am Walking");
    //    }

    //    public void Running()
    //    {
    //        Console.WriteLine("I am Running");
    //    }

    //    public void Looking()
    //    {
    //        Console.WriteLine("I am Looking");
    //    }
    //}

    //class IdleState : State<ControlledObject>
    //{
    //    public IdleState(ControlledObject controlledObject) : base(controlledObject)
    //    {
    //    }

    //    public override void Enter()
    //    {
    //        base.Enter();
    //        Console.WriteLine("Entering Idle State");
    //    }

    //    public override void Execute(double elapsedSeconds)
    //    {
    //        Controlled.Idle();
    //        base.Execute(elapsedSeconds);
    //    }

    //    public override void Exit()
    //    {
    //        Console.WriteLine("Exiting Idle State");
    //        base.Exit();
    //    }

    //    protected override void checkTranstions()
    //    {
    //        if (Controlled.RandomNumber > 0.5)
    //            transTo(new WakilngState(Controlled));
    //    }
    //}

    //class WakilngState : State<ControlledObject>
    //{
    //    public WakilngState(ControlledObject controlledObject) : base(controlledObject)
    //    {
    //    }

    //    public override void Enter()
    //    {
    //        base.Enter();
    //        Console.WriteLine("Entering Wakilng State");
    //    }

    //    public override void Execute(double elapsedSeconds)
    //    {
    //        Controlled.Walk();
    //        base.Execute(elapsedSeconds);
    //    }

    //    public override void Exit()
    //    {
    //        Console.WriteLine("Exiting Wakilng State");
    //        base.Exit();
    //    }

    //    protected override void checkTranstions()
    //    {
    //        if (Controlled.RandomNumber > 0.5)
    //            transTo(new RunningState(Controlled));
    //        else if (Controlled.RandomNumber < 0.1)
    //            transTo(new IdleState(Controlled));
    //    }
    //}

    //class RunningState : State<ControlledObject>
    //{
    //    public RunningState(ControlledObject controlledObject) : base(controlledObject)
    //    {
    //    }

    //    public override void Enter()
    //    {
    //        base.Enter();
    //        Console.WriteLine("Entering Running State");
    //    }

    //    public override void Execute(double elapsedSeconds)
    //    {
    //        Controlled.Running();
    //        base.Execute(elapsedSeconds);
    //    }

    //    public override void Exit()
    //    {
    //        Console.WriteLine("Exiting Running State");
    //        base.Exit();
    //    }

    //    protected override void checkTranstions()
    //    {
    //        if (Controlled.RandomNumber > 0.5)
    //            transTo(new LookingState(Controlled));
    //        else if (Controlled.RandomNumber < 0.1)
    //            transTo(new IdleState(Controlled));
    //        else if (Controlled.RandomNumber < 0.3)
    //            transTo(new RunningState(Controlled));
    //    }
    //}

    //class LookingState : State<ControlledObject>
    //{
    //    public LookingState(ControlledObject controlledObject) : base(controlledObject)
    //    {
    //    }

    //    public override void Enter()
    //    {
    //        base.Enter();
    //        Console.WriteLine("Entering Looking State");
    //    }

    //    public override void Execute(double elapsedSeconds)
    //    {
    //        Controlled.Looking();
    //        base.Execute(elapsedSeconds);
    //    }

    //    public override void Exit()
    //    {
    //        Console.WriteLine("Exiting Looking State");
    //        base.Exit();
    //    }

    //    protected override void checkTranstions()
    //    {
    //        if (Controlled.RandomNumber > 0.5)
    //            transTo(new IdleState(Controlled));
    //        else if (Controlled.RandomNumber < 0.1)
    //            transTo(new WakilngState(Controlled));
    //        else if (Controlled.RandomNumber < 0.3)
    //            transTo(new RunningState(Controlled));
    //    }
    //}
    //#endregion

    class Program
    {
        static void Main(string[] args)
        {
            TestingStateMachine.Test();
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

