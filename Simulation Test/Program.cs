using SimulationCore.Systems.SocialSystem;
using SimulationCore.Systems.SocialSystem.Records;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;

namespace Simulation_Test
{
    class Program
    {
        static void Main(string[] args)
        {
            Man ahmed = new Man("Ahmed");
            Woman sara = new Woman("Sara");
            
            SocialSystem social = new SocialSystem();
            social.HumanRecords.AddRecord(new HumanRecord(ahmed, null));
            social.HumanRecords.AddRecord(new HumanRecord(sara, null));

            ahmed.Marry();
            sara.ProduceBaby();
            ahmed.Divorce();
            ahmed.Die();
            sara.Die();
        }
    }
}

