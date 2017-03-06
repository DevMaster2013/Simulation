using SimulationCore.Core.States;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Systems.SocialSystem.HumanStates.Transitions
{
    public class ToDieTransition : StateTransition<Human>
    {
        #region Constructors
        public ToDieTransition(Human obj) : base("ToDie", obj)
        {
        }
        #endregion

        #region Public Methods
        public override bool CheckTransition()
        {
            return Controlled.Age.TotalDays >= Controlled.DieAge;
        }
        #endregion
    }
}
