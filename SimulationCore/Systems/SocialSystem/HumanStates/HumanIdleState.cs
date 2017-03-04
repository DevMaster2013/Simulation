using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Systems.SocialSystem.HumanStates
{
    public class HumanIdleState : HumanBaseState
    {
        public HumanIdleState(Human controlledObject) : base(controlledObject)
        {
        }

        protected override void checkTranstions()
        {
            base.checkTranstions();
        }
    }
}
