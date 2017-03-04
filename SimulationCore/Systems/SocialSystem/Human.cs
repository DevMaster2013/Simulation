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
        private double dieAge;
        #endregion

        #region Constructors
        public Human(SocialSystem socialSystem, string name, HumanSex sex)
        {
            Name = name;
            Sex = sex;
            SocialSystem = socialSystem;
            DieAge = RandomSelector.GetRandomDouble(SocialSystem.Config.MaximumAge);
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
        public double DieAge
        {
            get
            {
                return dieAge;
            }

            set
            {
                dieAge = value;
            }
        }
        #endregion

        #region Public Methods
        public virtual void Update(double elapsedSeconds)
        {
        }
        #endregion
    }
}
