using SimulationCore.Systems;
using SimulationCore.Systems.SocialSystem;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Civilization
{
    public class CivilizationManager
    {
        #region Private Variables
        private Dictionary<string, CivilizationSystem> _civilizationSystems;
        private Civilization _civilization;        
        #endregion

        #region Constructors
        public CivilizationManager(Civilization civil)
        {
            _civilizationSystems = new Dictionary<string, CivilizationSystem>();
            Civilization = civil;
        }
        #endregion

        #region Public Properties
        public Civilization Civilization
        {
            get
            {
                return _civilization;
            }

            set
            {
                _civilization = value;
            }
        }
        #endregion

        #region Public Methods
        public bool StartManager()
        {
            _civilizationSystems.Add(typeof(SocialSystem).Name, new SocialSystem());

            foreach (var system in _civilizationSystems)
                if (!system.Value.InitializeSystem())
                    return false;
            return true;
        }
        public bool ShutdownManager()
        {
            foreach (var system in _civilizationSystems)
                if (!system.Value.FininalizeSystem())
                    return false;
            return true;
        }
        public T GetSystem<T>() where T : CivilizationSystem
        {
            string typeName = typeof(T).Name;
            if (_civilizationSystems.ContainsKey(typeName))
                return _civilizationSystems[typeName] as T;
            return null;
        }
        public void UpdateManager(double elapsedSeconds)
        {
            foreach (var system in _civilizationSystems)
                system.Value.UpdateSystem(elapsedSeconds);
        }
        #endregion
    }
}
