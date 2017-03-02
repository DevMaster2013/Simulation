﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Systems
{
    public class CivilizationSystem
    {
        #region Constructors
        public CivilizationSystem()
        {

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
    }
}
