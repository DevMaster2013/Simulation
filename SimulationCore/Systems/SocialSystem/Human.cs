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
        protected HumanSex sex;
        private SocialSystem socialSystem;
        #endregion

        #region Constructors
        public Human(SocialSystem socialSystem, string name, HumanSex sex)
        {
            Name = name;
            Sex = sex;
            SocialSystem = socialSystem;
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
                return sex;
            }

            set
            {
                sex = value;
            }
        }
        protected SocialSystem SocialSystem
        {
            get
            {
                return socialSystem;
            }

            set
            {
                socialSystem = value;
            }
        }
        #endregion

        #region Public Methods
        public void Die()
        {
            // TODO : Implement Die
            throw new NotImplementedException("Die not Implemented");

        }
        #endregion
    }
}
