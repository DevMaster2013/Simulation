using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Core
{
    public static class GameTimeSettings
    {
        #region Private Static Variables
        private static DateTime _startingGameTime;
        private static DateTime _currentGameTime;
        private static double _timeScale;
        #endregion

        #region Public Static Properties
        public static DateTime StartingGameTime {
            get {
                return _startingGameTime;
            }
            set {
                _startingGameTime = value;
            }
        }
        public static DateTime CurrentGameTime {
            get {
                return _currentGameTime;
            }
            set {
                _currentGameTime = value;
            }
        }
        public static double TimeScale { 
            get {
                return _timeScale;
            }
            set {
                _timeScale = value;
            }
        }
        #endregion

        #region Public Static Methods
        public static void InitializeGameTime()
        {
            _timeScale = 24.0;      // One Day = One Hour
            _currentGameTime = _startingGameTime = new DateTime(1, 1, 1, 12, 0, 0);

        }
        public static void UpdateGameTime(double elapsedTime)
        {
            double gameTimeIncreaseAmount = _timeScale * elapsedTime;
            _currentGameTime += TimeSpan.FromSeconds(gameTimeIncreaseAmount);
        }
        #endregion
    }
}
