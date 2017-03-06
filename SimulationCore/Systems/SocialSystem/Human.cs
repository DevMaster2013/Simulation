using SimulationCore.Civilization;
using SimulationCore.Core;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Systems.SocialSystem
{
    public enum HumanSex : short
    {
        Male,
        Female
    }

    public class Human
    {
        #region Protected Member Variables
        protected string _name;
        protected HumanSex _sex;
        protected double _dieAge;
        protected HumanStateMachine _stateMachine;
        protected CivilizationManager _civilManager;
        #endregion

        #region Constructors
        public Human(CivilizationManager civilManager, string name, HumanSex sex)
        {
            CivilManager = civilManager;
            Name = name;
            Sex = sex;
            DieAge = RandomSelector.GetRandomDouble(CivilManager.GetSystem<SocialSystem>().Config.MaximumAge);
            _stateMachine = new HumanStateMachine(this);
        }
        #endregion

        #region Public Properties
        public string Name
        {
            get
            {
                return _name;
            }

            set
            {
                _name = value;
            }
        }
        public HumanSex Sex
        {
            get
            {
                return _sex;
            }

            set
            {
                _sex = value;
            }
        }
        public TimeSpan Age {
            get {
                var record = CivilManager.GetSystem<SocialSystem>().HumanRecords.GetRecord(this);
                return GameTimeSettings.CurrentGameTime - record.RecordDate;
            }
        }
        public double DieAge
        {
            get
            {
                return _dieAge;
            }

            set
            {
                _dieAge = value;
            }
        }
        public CivilizationManager CivilManager {
            get {
                return _civilManager;
            }

            set {
                _civilManager = value;
            }
        }
        #endregion

        #region Public Methods
        public virtual void Update(double elapsedSeconds)
        {
            _stateMachine.UpdateStateMachine(elapsedSeconds);
        }
        #endregion
    }
}
