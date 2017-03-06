using SimulationCore.Core;
using SimulationCore.Core.States;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Systems.SocialSystem.HumanStates
{
    public class SeekingWifeState : State<Human>
    {
        #region Constructors
        public SeekingWifeState(StateMachine<Human> ownerSM, Human controlledObject) : base(ownerSM, "SeekWife", controlledObject)
        {
        }
        #endregion

        #region Public Methods
        public override void Enter()
        {
            SocialSystem socialSystem = Controlled.CivilManager.GetSystem<SocialSystem>();

            var suitableWomen = socialSystem.GetSuitableWomenForMarriage((Man)Controlled);
            bool accepted = false;
            Woman selectedWife = null;
            while (!accepted && suitableWomen.Count > 0)
            {
                selectedWife = RandomSelector.SelectRandomSample(suitableWomen);
                suitableWomen.Remove(selectedWife);
                accepted = selectedWife.ResponseForMarriageProposal((Man)Controlled);
            }

            base.Enter();
        }
        #endregion
    }
}
