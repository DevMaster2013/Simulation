using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Systems.SocialSystem.HumanStates
{
    public class HumanDiedState : HumanBaseState
    {
        public HumanDiedState(Human controlledObject) : base(controlledObject)
        {
        }

        public override void Enter()
        {
            base.Enter();

            if (Controlled.SocialSystem.DieRecords.CreateRecord(Controlled) == null)
                throw new Exception("The human is already died");
        }

        protected override void checkTranstions()
        {            
        }
    }
}
