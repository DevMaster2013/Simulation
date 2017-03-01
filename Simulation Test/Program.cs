using SimulationCore.Core;
using SimulationCore.Resources;
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
            GameTimeSettings.InitializeGameTime();
            ResourceManager.LoadAllResources();

            SocialSystem social = new SocialSystem();
            var ahmedRecord = social.HumanRecords.CreateRecord(null, "Ahmed", HumanSex.Male);
            var saraRecord = social.HumanRecords.CreateRecord(null, "Sara", HumanSex.Female);

            GameTimeSettings.CurrentGameTime = new DateTime(0001, 1, 30, 12, 0, 0);

            Man ahmed = ahmedRecord.Human as Man;
            Woman sara = saraRecord.Human as Woman;

            while (social.MarriageRecords.GetRecord(ahmed) == null)
                ahmed.Marry();
            sara.ProduceBaby();
            ahmed.Divorce();
            sara.ProduceBaby();
            while (social.MarriageRecords.GetRecord(ahmed) == null)
                ahmed.Marry();
            sara.ProduceBaby();

            ahmed.Die();
            sara.Die();
        }
    }
}

