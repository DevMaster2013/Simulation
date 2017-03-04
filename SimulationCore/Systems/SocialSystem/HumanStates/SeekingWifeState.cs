using SimulationCore.Core;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Systems.SocialSystem.HumanStates
{
    public class SeekingWifeState : HumanBaseState
    {
        private static double _lastTimeSeekingWife = 0;
        private static double _restTimeAfterFailingSeeking = 172800;    // 2 Days

        public SeekingWifeState(Human controlledObject) : base(controlledObject)
        {
            _lastTimeSeekingWife = 0;
        }

        public override void Execute(double elapsedSeconds)
        {
            _lastTimeSeekingWife += elapsedSeconds * GameTimeSettings.TimeScale;
            base.Execute(elapsedSeconds);
        }

        protected override void checkTranstions()
        {
            if (_lastTimeSeekingWife >= _restTimeAfterFailingSeeking)
            {
                var suitableWomen = Controlled.SocialSystem.GetSuitableWomenForMarriage((Man)Controlled);
                bool accepted = false;
                Woman selectedWife = null;
                while (!accepted && suitableWomen.Count > 0)
                {
                    selectedWife = RandomSelector.SelectRandomSample(suitableWomen);
                    suitableWomen.Remove(selectedWife);
                    accepted = selectedWife.ResponseForMarriageProposal((Man)Controlled);
                }

                if (accepted)
                    transTo(new HumanMarriedState(Controlled, selectedWife));

                _lastTimeSeekingWife = 0;
            }

            base.checkTranstions();
        }
    }
}
