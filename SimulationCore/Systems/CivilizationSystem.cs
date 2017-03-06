using SimulationCore.Civilization;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Systems
{
    public class CivilizationSystem
    {
        #region Protected Variables
        protected CivilizationManager _civilManager;
        #endregion

        #region Constructors
        public CivilizationSystem(CivilizationManager civilManager)
        {
            CivilManager = civilManager;
        }
        #endregion

        #region Public Virtual Functions
        public virtual bool InitializeSystem()
        {
            return true;
        }
        public virtual bool FininalizeSystem()
        {
            return true;
        }
        public virtual void UpdateSystem(double elapsedSeconds)
        {

        }
        #endregion

        #region Public Properties
        public CivilizationManager CivilManager {
            get {
                return _civilManager;
            }
            protected set {
                _civilManager = value;
            }
        }
        #endregion
    }
}
