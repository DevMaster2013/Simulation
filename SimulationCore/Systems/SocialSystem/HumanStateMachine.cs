using SimulationCore.Core.States;
using SimulationCore.Systems.SocialSystem.HumanStates;
using SimulationCore.Systems.SocialSystem.HumanStates.Transitions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Systems.SocialSystem
{
    public class HumanStateMachine : StateMachine<Human>
    {
        #region Private Variables
        private HumanIdleState _idleState;
        private HumanDiedState _diedState;
        private SeekingWifeState _seekWifeState;
        #endregion

        #region Constructors
        public HumanStateMachine(Human obj) : base("BaseHumanStateMachine", obj)
        {
            buildStateMachine();
        }
        #endregion

        #region Private Methods
        private void buildStateMachine()
        {
            // Declare States
            _idleState = new HumanIdleState(this, Controlled);
            _diedState = new HumanDiedState(this, Controlled);

            // Add States
            AddState(_idleState);
            AddState(_diedState);

            // Add Transitions
            AddStateTransition(_idleState, _diedState, new ToDieTransition(Controlled));

            // Add Specific Man States
            if (Controlled.Sex == HumanSex.Male)
            {
                // Declare States
                _seekWifeState = new SeekingWifeState(this, Controlled);

                // Add States
                AddState(_seekWifeState);

                // Add Transitions
                AddStateTransition(_idleState, _seekWifeState, new IdleToSeekWifeTransition(Controlled));
            }
            else  // Add Specific Woman States
            {

            }

            // Set Current State
            ChangeState(_idleState);
        }
        #endregion
    }
}
