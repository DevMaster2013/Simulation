using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Civilization
{
    public class Civilization
    {
        #region Private Data Members
        private string _name;
        #endregion

        #region Constructors
        public Civilization(string name)
        {
            _name = name;
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
        #endregion
    }
}
