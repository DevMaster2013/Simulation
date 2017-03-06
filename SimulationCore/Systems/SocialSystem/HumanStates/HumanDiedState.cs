using SimulationCore.Core.States;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Systems.SocialSystem.HumanStates
{
    public class HumanDiedState : State<Human>
    {
        #region Constructors
        public HumanDiedState(StateMachine<Human> ownerSM, Human controlledObject) : base(ownerSM, "Died", controlledObject)
        {
        }
        #endregion

        #region Public Methods
        public override void Enter()
        {
            base.Enter();

            SocialSystem socialSystem = Controlled.CivilManager.GetSystem<SocialSystem>();
            if (socialSystem.DieRecords.CreateRecord(Controlled) == null)
                throw new Exception("The human is already died");
        }
        #endregion
    }
}
