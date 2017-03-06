using SimulationCore.Core.States;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Systems.SocialSystem.HumanStates
{
    public class HumanIdleState : State<Human>
    {
        #region Constructors
        public HumanIdleState(StateMachine<Human> ownerSM, Human controlledObject) : base(ownerSM, "Idle", controlledObject)
        {
        }
        #endregion
    }
}
