using SimulationCore.Civilization;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Core
{
    public static class GameManager
    {
        #region Static Member Variables
        private static Dictionary<string, CivilizationManager> _civilizations;
        #endregion

        #region Public Methods
        public static bool StartManager()
        {
            _civilizations = new Dictionary<string, CivilizationManager>();

            _civilizations.Add("Egypt", new CivilizationManager(new Civilization.Civilization("Egypt")));
            _civilizations.Add("Israel", new CivilizationManager(new Civilization.Civilization("Israel")));

            foreach (var civil in _civilizations)
                if (!civil.Value.StartManager())
                    return false;

            return true;
        }
        public static bool ShutdownManager()
        {
            foreach (var civil in _civilizations)
                if (!civil.Value.ShutdownManager())
                    return false;

            return true;
        }
        public static CivilizationManager GetCivilization(string name)
        {
            if (_civilizations.ContainsKey(name))
                return _civilizations[name];
            return null;
        }
        public static void UpdateGame(double elapsedSeconds)
        {
            GameTimeSettings.UpdateGameTime(elapsedSeconds);

            foreach (var civil in _civilizations)
                civil.Value.UpdateManager(elapsedSeconds);                    
        }
        #endregion
    }
}
