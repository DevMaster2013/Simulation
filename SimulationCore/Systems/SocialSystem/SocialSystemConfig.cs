using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Systems.SocialSystem
{
    public class SocialSystemConfig
    {
        #region Private Member Variables
        private double _minimumManMarriageAge;
        private double _minimumWomanMarriageAge;
        private double _maximumAge;
        #endregion

        #region Constructors
        public SocialSystemConfig()
        {
            MinimumManMarriageAge = 16.0;
            MinimumWomanMarriageAge = 16.0;
            MaximumAge = 100.0;
        }
        #endregion

        #region Public Properties
        public double MinimumManMarriageAge {
            get {
                return _minimumManMarriageAge;
            }

            set {
                _minimumManMarriageAge = value;
            }
        }
        public double MinimumWomanMarriageAge {
            get {
                return _minimumWomanMarriageAge;
            }

            set {
                _minimumWomanMarriageAge = value;
            }
        }

        public double MaximumAge {
            get {
                return _maximumAge;
            }

            set {
                _maximumAge = value;
            }
        }
        #endregion
    }
}
