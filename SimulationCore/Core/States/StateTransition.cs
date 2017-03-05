using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SimulationCore.Core.States
{
    public class StateTransition<T> where T : class
    {
        #region Protected Members
        protected State<T> _from;
        protected State<T> _to;
        #endregion

        #region Public Properties
        public State<T> From {
            get {
                return _from;
            }

            set {
                _from = value;
            }
        }

        public State<T> To {
            get {
                return _to;
            }

            set {
                _to = value;
            }
        }
        #endregion

        #region Constructors
        public StateTransition(State<T> from, State<T> to)
        {
            From = from;
            To = to;
        }
        #endregion

        #region Public Methods
        public virtual bool CheckTransition()
        {
            return true;
        }
        #endregion
    }
}
