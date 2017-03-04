using SimulationCore.Core.States;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Systems.SocialSystem.HumanStates
{
    public class HumanBaseState : State<Human>
    {
        public HumanBaseState(Human controlledObject) : base(controlledObject)
        {
        }

        protected override void checkTranstions()
        {
            if (Controlled.Age.TotalDays >= Controlled.DieAge)
                transTo(new HumanDiedState(Controlled));

            if ((Controlled.SocialSystem.MarriageRecords.GetRecord(Controlled) == null) && (Controlled.Sex == HumanSex.Male))
                transTo(new SeekingWifeState(Controlled));
        }
    }
}
