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
            SocialSystem social = new SocialSystem();
            var ahmedRecord = social.HumanRecords.CreateRecord(null, "Ahmed", HumanSex.Male);
            var saraRecord = social.HumanRecords.CreateRecord(null, "Sara", HumanSex.Female);

            ((Man)(ahmedRecord.Human)).Marry();
            /*
            ((Woman)(ahmedRecord.Human)).ProduceBaby();
            ((Man)(ahmedRecord.Human)).Divorce();

            ahmedRecord.Human.Die();
            saraRecord.Human.Die();
            */
        }
    }
}

