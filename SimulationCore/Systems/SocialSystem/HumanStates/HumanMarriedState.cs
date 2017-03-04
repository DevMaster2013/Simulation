using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Systems.SocialSystem.HumanStates
{
    public class HumanMarriedState : HumanBaseState
    {
        private Woman _wife;

        public HumanMarriedState(Human controlledObject, Woman wife) : base(controlledObject)
        {
            _wife = wife;
        }

        public override void Enter()
        {
            Controlled.SocialSystem.MarriageRecords.CreateRecord((Man)Controlled, Wife);
            base.Enter();
        }

        public Woman Wife
        {
            get
            {
                return _wife;
            }

            set
            {
                _wife = value;
            }
        }

        protected override void checkTranstions()
        {
            base.checkTranstions();
        }
    }
}
