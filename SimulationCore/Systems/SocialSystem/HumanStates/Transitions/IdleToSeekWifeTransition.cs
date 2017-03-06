using SimulationCore.Core;
using SimulationCore.Core.States;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Systems.SocialSystem.HumanStates.Transitions
{
    class IdleToSeekWifeTransition : StateTransition<Human>
    {
        #region Private Variables
        private DateTime _timeOfLastSeek;
        #endregion

        #region Constructors
        public IdleToSeekWifeTransition(Human obj) : base("IdleToSeekWife", obj)
        {
            _timeOfLastSeek = GameTimeSettings.CurrentGameTime;
        }
        #endregion

        #region Public Methods
        public override bool CheckTransition()
        {
            bool pass = false;
            TimeSpan elapsedTiem = GameTimeSettings.CurrentGameTime - _timeOfLastSeek;
            if (elapsedTiem.TotalDays >= 1)
            {
                SocialSystem socialSystem = Controlled.CivilManager.GetSystem<SocialSystem>();

                bool isMarried = socialSystem.MarriageRecords.GetRecord(Controlled) != null;
                pass = (Controlled.Age.TotalDays > 16) && (!isMarried);
                _timeOfLastSeek = GameTimeSettings.CurrentGameTime;
            }

            return pass;
        }
        #endregion
    }
}
