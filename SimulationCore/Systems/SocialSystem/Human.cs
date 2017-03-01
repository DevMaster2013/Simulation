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
        protected SocialSystem _socialSystem;
        protected double _dieAge;
        #endregion

        #region Constructors
        public Human(SocialSystem socialSystem, string name, HumanSex sex)
        {
            Name = name;
            Sex = sex;
            SocialSystem = socialSystem;
            _dieAge = RandomSelector.GetRandomDouble(SocialSystem.Config.MaximumAge);
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
        public SocialSystem SocialSystem
        {
            get
            {
                return _socialSystem;
            }

            set
            {
                _socialSystem = value;
            }
        }

        public TimeSpan Age {
            get {
                var record = SocialSystem.HumanRecords.GetRecord(this);
                return GameTimeSettings.CurrentGameTime - record.RecordDate;
            }
        }
        #endregion

        #region Public Methods
        public virtual void Update(double elapsedSeconds)
        {
            checkDead();
        }
        public void Die()
        {            
            if (SocialSystem.DieRecords.CreateRecord(this) == null)
            {
                // TODO : The human is already died
            }
        }
        #endregion

        #region Protected Methods
        protected void checkDead()
        {
            if (Age.TotalDays >= _dieAge)
                Die();
        }
        #endregion
    }
}
